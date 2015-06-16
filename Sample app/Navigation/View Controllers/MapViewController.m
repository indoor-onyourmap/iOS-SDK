//
//  MapViewController.m
//  indoor
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "MapViewController.h"


@implementation MapViewController

#pragma mark Private constants
static float const kOYMMapCircleStroke = 3;
static float const kOYMMapRouteWidth = 6;
static float const kOYMMapTiltNavigation = 30;
static float const kOYMMapMetersDefault = 30;

static float const kOYMRouteArrivalThreshold = 2;

static int const kOYMTagAlertMenuOnNav = 1;

static float const kOYMViewBarConstraint = 72;


@synthesize mapView;
@synthesize fub, fubConstraint, fubDestination, fubLocal, fubLevelBox, fubLevel, fubNumber;
@synthesize fbb, fbbConstraint, fbbImage, fbbDistance, fbbInstruction;
@synthesize toolbar;


#pragma mark View
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // Set theme
    [self setTheme];
    
    // Prepare view
    [self hideUpperBar];
    [self hideBottomBar];
    [self setMarkerImage];
    [self prepareToolbar];
    fubDestination.text = NSLocalizedString(@"FUBYouAre", nil);
    fubLevel.text = NSLocalizedString(@"FUBLevel", nil);
    [self prepareBottomBar];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}


- (void) setTheme {
    fubDestination.textColor = [Colors primary];
    fubLocal.textColor = [Colors primary];
    fubLevel.textColor = [Colors textPrimary];
    fubNumber.textColor = [Colors textPrimary];
    
    toolbar.tintColor = [Colors primary];
    
    [fubLevelBox setNeedsDisplay];
    [fub setNeedsDisplay];
    
}

- (void) prepareToolbar {
    toolbar.hidden = YES;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(toogleToolbar)];
    tap.numberOfTapsRequired = 1;
    tap.numberOfTouchesRequired = 3;
    [self.view addGestureRecognizer:tap];
}

- (void) toogleToolbar {
    if (toolbar.isHidden) {
        toolbar.hidden = NO;
    } else {
        toolbar.hidden = YES;
    }
}

- (void) changeToFloor:(int) floornumber {
    if (tileOverlay) {
        [mapView removeOverlay:tileOverlay];
    }
    for (OYMFloor* f in floors) {
        if ([f.floor intValue] == currentLocation.floornumber) {
            tileOverlay = f.tileProvider;
            [mapView addOverlay:tileOverlay level:MKOverlayLevelAboveLabels];
            currentFloor = @(floornumber);
            break;
        }
    }
}

- (void) updateBottomBar:(OYMRouteProjectedPoint*)rpp {
    int dist = (int) (instruction.distance - [rpp.distanceFromStart doubleValue]);
    fbbDistance.text = [OYMInstructionAdapter getDistanceString:dist];
    fbbInstruction.text = [OYMInstructionAdapter getStringForInstruction:instruction];
    fbbImage.image = [OYMInstructionAdapter getImageForInstruction:instruction];
}

- (void) showUpperBar {   
    if (building == nil) {
        [self hideUpperBar];
    } else {
        [fub setNeedsDisplay];
        fub.hidden = NO;
        fubConstraint.constant = kOYMViewBarConstraint;
        fubLevelBox.hidden = YES;
    }
}

- (void) showUpperBarWithFloor:(NSNumber*)floor {
    if (building == nil) {
        [self hideUpperBar];
    } else {
        fubNumber.text = [floor stringValue];
        [fub setNeedsDisplay];
        [fubLevelBox setNeedsDisplay];
        fub.hidden = NO;
        fubConstraint.constant = kOYMViewBarConstraint;
        fubLevelBox.hidden = NO;
    }
}

- (void) hideUpperBar {
    fubConstraint.constant = 0;
    fub.hidden = YES;
}

- (void) prepareBottomBar {
    UITapGestureRecognizer *t = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(onFbbTap:)];
    UILongPressGestureRecognizer *lp = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(onFbbLongPress:)];
    [fbb addGestureRecognizer:t];
    [fbb addGestureRecognizer:lp];
}

- (void) showBottomBar {
    fbbConstraint.constant = kOYMViewBarConstraint;
    fbb.hidden = NO;
    isFbbShown = YES;
    toolbar.hidden = YES;
    [fbb setNeedsDisplay];
}

- (void) hideBottomBar {
    fbbConstraint.constant = 0;
    fbb.hidden = YES;
    isFbbShown = NO;
}

- (void) drawAnimatedMarkerWithCoord:(CLLocationCoordinate2D)coord andAccuracy:(double)accuracy {
    //TODO: Animate & circle
    
    if (markerPos != nil) {
        [markerPos setCoordinate:coord];
        [mapView removeOverlay:circlePos];
        [self handleCircleWithCoord:coord andAccuracy:accuracy];
    } else {
        markerPos = [[OYMAnnotation alloc] initWithLocation:coord andImage:markerImage];
        [mapView addAnnotation:markerPos];
        [self setCircleWithCoord:coord andAccuracy:accuracy];
    }
}

- (void) setCircleWithCoord:(CLLocationCoordinate2D)coord andAccuracy:(double)accuracy {
    circlePos = [MKCircle circleWithCenterCoordinate:coord radius:accuracy];
    [mapView addOverlay:circlePos];
}

- (void) handleCircleWithCoord:(CLLocationCoordinate2D)coord andAccuracy:(double)accuracy {
    if (!isNavigation) {
        if (!circlePos) {
            [self setCircleWithCoord:coord andAccuracy:accuracy];
        } else {
            [self setCircleWithCoord:coord andAccuracy:accuracy];
        }
    } else {
        [mapView removeOverlay:circlePos];
        circlePos = nil;
    }
}

- (void) drawUserPositionWithCoord:(CLLocationCoordinate2D)coord andAccuracy:(double)accuracy {
    if (isMapUpdated && markerImage != nil) {
        [self drawAnimatedMarkerWithCoord:coord andAccuracy:accuracy];
        if (isCameraUpdated) {
            [self animateCameraWithPoint:coord animated:YES];
        }
    }
}

- (void) drawRoutePositionWithPoint:(OYMRouteProjectedPoint*)projPoint andAccuracy:(double) accuracy {
    if (isMapUpdated && markerImage != nil) {
        // Draw projected point
        [self drawAnimatedMarkerWithCoord:[projPoint getCLLocationCoordinate2D] andAccuracy:accuracy];
        // Update camera
        MKMapCamera* cam = [MKMapCamera camera];
        cam.heading = [projPoint.bearing doubleValue];
        cam.centerCoordinate = [projPoint getCLLocationCoordinate2D];
        cam.altitude = mapView.camera.altitude;
        [self animateCamera:cam animated:NO];
    }
}

- (void) drawRouteInFloor:(int) floornumber {
    if (mapRoute) {
        [mapView removeOverlays:mapRoute];
    }
    NSMutableArray* mapRouteMut = [NSMutableArray new];
    NSMutableArray* mut = [NSMutableArray new];
    for (OYMRoutePoint* rp in [GlobalState get].route.route) {
        if ([rp.floornumber intValue] == floornumber) {
            [mut addObject:rp];
        } else if ([mut count] != 0) {
            CLLocationCoordinate2D c[[mut count]];
            for (int i = 0; i < [mut count]; i++) {
                c[i] = [(OYMRoutePoint*)[mut objectAtIndex:i] getCLLocationCoordinate2D];
            }
            [mapRouteMut addObject:[MKPolyline polylineWithCoordinates:c count:[mut count]]];
            mut = [NSMutableArray new];
        }
    }
    if ([mut count] != 0) {
        CLLocationCoordinate2D c[[mut count]];
        for (int i = 0; i < [mut count]; i++) {
            c[i] = [(OYMRoutePoint*)[mut objectAtIndex:i] getCLLocationCoordinate2D];
        }
        [mapRouteMut addObject:[MKPolyline polylineWithCoordinates:c count:[mut count]]];
    }
    
    mapRoute = [NSArray arrayWithArray:mapRouteMut];
    [mapView addOverlays:mapRoute];
}

- (void) removeRoute {
    [mapView removeOverlays:mapRoute];
    mapRoute = nil;
}

- (void) animateCamera:(MKMapCamera*)camera animated:(BOOL)animated{
    [mapView setCamera:camera animated:animated];
}

- (void) animateCameraWithPoint:(CLLocationCoordinate2D)point animated:(BOOL)animated{
    MKMapCamera* camera = [MKMapCamera camera];
    camera.centerCoordinate = point;
    camera.pitch = 0;
    [self animateCamera:camera animated:animated];
}

- (void) setMarkerImage {
    CGSize canvas = CGSizeMake(16, 16);
    CGRect rect = CGRectMake(0, 0, canvas.width, canvas.height);
    rect = CGRectInset(rect, 1, 1);
    UIGraphicsBeginImageContextWithOptions(canvas, NO, [UIScreen mainScreen].scale);
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, [Colors userPosition].CGColor);
    CGContextSetStrokeColorWithColor(ctx, [UIColor whiteColor].CGColor);
    CGContextSetLineWidth(ctx, 2);
    CGContextFillEllipseInRect(ctx, rect);
    CGContextStrokeEllipseInRect(ctx, rect);
    markerImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
}

- (void) onLongPress:(UIGestureRecognizer*)gr {
    if (!isNavigation && isBuildingReady && isNavigationReady) {
        if (gr.state == UIGestureRecognizerStateBegan) {
            CGPoint p = [gr locationInView:mapView];
            CLLocationCoordinate2D t = [mapView convertPoint:p toCoordinateFromView:mapView];
            [self startNavInitForPoint:[[OYMRoutePoint alloc] initWithX:@(t.longitude) andY:@(t.latitude) andFloornumber:currentFloor andBuildingId:building.uuid] andTitle:NSLocalizedString(@"AMCustomDest", nil)];
        }
    }
}

- (void) onFubLongPress:(UIGestureRecognizer*)gr {
    if (isNavigationReady && !isNavigation && gr.state == UIGestureRecognizerStateBegan && [areas count] > 0) {
        if ([areas count] > 0) {
            UIActionSheet* as = [[UIActionSheet alloc] initWithTitle:NSLocalizedString(@"AMASPick", nil) delegate:self cancelButtonTitle:NSLocalizedString(@"cancel", nil) destructiveButtonTitle:nil otherButtonTitles:nil];
            for (OYMArea* a in areas) {
                [as addButtonWithTitle:a.name];
            }
            [as showInView:self.view];
        }
    }
}

- (void) onFbbTap:(UIGestureRecognizer*)gr {
    if (isNavigation && gr.state == UIGestureRecognizerStateEnded) {
        [self performSegueWithIdentifier:@"SegueMapInstructions" sender:self];
    }
}

- (void) onFbbLongPress:(UIGestureRecognizer*)gr {
    if (isNavigation && gr.state == UIGestureRecognizerStateBegan) {
        UIAlertView* menu = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"options", nil) message:nil delegate:self cancelButtonTitle:NSLocalizedString(@"cancel", nil) otherButtonTitles:NSLocalizedString(@"FDStop", nil), nil];
        menu.tintColor = [Colors primary];
        menu.tag = kOYMTagAlertMenuOnNav;
        [menu show];
    }
}


#pragma mark Data handling
- (void) enableRouting:(BOOL)succeed {
    if (succeed) {
        isNavigationReady = YES;
        UILongPressGestureRecognizer *lp = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(onLongPress:)];
        [mapView addGestureRecognizer:lp];
    } else {
        [self.view makeToast:[NSString localizedStringWithFormat:NSLocalizedString(@"AMTNoEdges", nil), building.name] duration:3.0 position:CSToastPositionBottom title:nil];
    }
}

- (void)setBuildings:(NSArray *)buildings {
    if (buildings == nil || [buildings count] == 0) {
        [self.view makeToast:NSLocalizedString(@"AMTNoBuildings", nil) duration:3.0 position:CSToastPositionBottom title:nil];
    } else {
        building = [buildings firstObject];
        fubLocal.text = building.name;
        
        // Prepare routing
        [GlobalState get].routing = [[OYMRouting alloc] initWithIndoor:[GlobalState get].links andBuilding:building.uuid andDelegate:[Delegate get]];
        [[GlobalState get].routing initRouting];
        
        isBuildingReady = YES;
        
        [[GlobalState get].links getAreasForUuid:building.uuid];
        
        floors = [building getFloorsList];
    }
}

- (void) setAreas:(NSArray *)ar {
    areas = ar;
    UILongPressGestureRecognizer *lp = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(onFubLongPress:)];
    [fub addGestureRecognizer:lp];
}


#pragma mark IBActions
- (void) onLogout:(id)sender {
    [[Delegate get] stop];
    [[Delegate get] disableAutologin];
    [self performSegueWithIdentifier:@"SegueMapLogout" sender:self];
}


#pragma mark StartNav
- (void) startNavInitForPoint:(OYMRoutePoint*)point andTitle:(NSString*)str {
    isStartNav = YES;
    destination = point;
    startNavTitle = str;
    
    // Tilt camera
    MKMapCamera* cam = [mapView camera];
    cam.pitch = kOYMMapTiltNavigation;
    [self animateCamera:cam animated:NO];
    
    // Set progress dialog
    startNavAlert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"AMGettingRoute", nil) message:nil delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    startNavAlert.tintColor = [Colors primary];
    [startNavAlert show];
    
    // Set FUB
    fubDestination.text = NSLocalizedString(@"AMDestination", nil);
    fubLocal.text = startNavTitle;
}

/**
 * @return If start Nav is finished
 */
- (BOOL) startNavBackground {
    if (currentLocation.type == kOYMIndoorLocationTypeIbeacon) {
        OYMRoutePoint* rp = [[OYMRoutePoint alloc] initWithX:@(currentLocation.longitude) andY:@(currentLocation.latitude) andFloornumber:@(currentLocation.floornumber) andBuildingId:currentLocation.buildingId];
        
        OYMRoute* r = [[GlobalState get].routing computeRouteFrom:rp to:destination];
        
        // onPostExecute
        if (r) {
            [GlobalState get].route = r;
            [self showUpperBar];
            isNavigation = YES;
            [startNavAlert dismissWithClickedButtonIndex:0 animated:YES];
            startNavAlert = nil;
            [self drawRouteInFloor:lastFloornumber];
        } else {
            [startNavAlert dismissWithClickedButtonIndex:0 animated:YES];
            startNavAlert = nil;
            NSString* title = [NSString localizedStringWithFormat:NSLocalizedStringFromTableInBundle(@"AMANoRoute", nil, [NSBundle mainBundle], nil), startNavTitle, nil];
            UIAlertView* alert = [[UIAlertView alloc] initWithTitle:title message:nil delegate:nil cancelButtonTitle:NSLocalizedString(@"ok", nil) otherButtonTitles:nil];
            [alert show];
            [self stopNavigation];
        }
        isStartNav = NO;
    }
    
    return !isStartNav;
}

- (void) stopNavigation {
    isNavigation = NO;
    MKMapCamera* cam = [MKMapCamera camera];
    cam.centerCoordinate = mapView.camera.centerCoordinate;
    cam.pitch = 0;
    cam.heading = 0;
    [self animateCamera:cam animated:NO];
    
    // Remove polyline
    [self removeRoute];
    
    fubDestination.text = NSLocalizedString(@"FUBYouAre", nil);
    fubLocal.text = building.name;
    // Handle FBB visibility
    [self hideBottomBar];
    
    destination = nil;
    startNavTitle = nil;
}


#pragma mark Pseudo OYMIndoorDelegate
- (void) onPositionUpdate:(OYMIndoorLocation*)loc {
    currentLocation = loc;
    
    // Change floor
    if (currentLocation.type == kOYMIndoorLocationTypeIbeacon && isMapUpdated && building) {
        if ([currentFloor intValue] != loc.floornumber || tileOverlay == nil) {
            [self changeToFloor:loc.floornumber];
        }
    }
    
    // Get Building
    if (loc.type == kOYMIndoorLocationTypeIbeacon && (building == nil || (building != nil && ![building.uuid isEqualToString:loc.buildingId] && isBuildingReady) )) {
        [[GlobalState get].links getBuildingsWithArray:@[loc.buildingId]];
        isBuildingReady = NO;
    }
    
    // Route being created
    if (isStartNav && ![self startNavBackground]) {
        return;
    }
    
    // Route created, nav set mode -> startNavBackground
    
    // Instruction mode -> Handled by changing view controllers
    
    
    if (isFirstMapUpdate) {
        isFirstMapUpdate = NO;
        [mapView setRegion:MKCoordinateRegionMakeWithDistance([loc getCoords], kOYMMapMetersDefault, kOYMMapMetersDefault) animated:YES];
    }
    
    // Handle FUB visibility
    if (isBuildingReady && loc.type == kOYMIndoorLocationTypeIbeacon) {
        [self showUpperBarWithFloor:@(loc.floornumber)];
    } else {
        [self hideUpperBar];
    }
    
    // Handle navigation
    if (isNavigation) {
        if (!isFbbShown) {
            [self showBottomBar];
        }
        
        // Get projected point
        OYMRoutingResult* rr = [[GlobalState get].route getProjectionForLocation:loc];
        OYMRouteProjectedPoint* projPoint = rr.projectedPoint;
        
        if (!rr.isRecomputeRequired) {
            // Check wrong projection
            if (projPoint == nil) {
                return;
            }
            
            // Get next instruction to show
            instruction = [[GlobalState get].route getRouteInstructionForLocation:loc];
            
            // Update FBB
            [self updateBottomBar:projPoint];
            
            // Check end route
            if (instruction.instruction == ARRIVAL && instruction.distance-kOYMRouteArrivalThreshold <= [projPoint.distanceFromStart doubleValue]) {
                [self stopNavigation];
                [self drawUserPositionWithCoord:[loc getCoords] andAccuracy:loc.accuracy];
            } else {
                // Update map position
                [self drawRoutePositionWithPoint:projPoint andAccuracy:loc.accuracy];
                
                // Update route
                if ((loc.type == kOYMIndoorLocationTypeIbeacon && (lastFloornumber != loc.floornumber)) || mapRoute == nil) {
                    [self drawRouteInFloor:loc.floornumber];
                    lastFloornumber = loc.floornumber;
                }
                
            }
        } else {
            [self startNavInitForPoint:destination andTitle:fubLocal.text];
            [self removeRoute];
        }
    } else {
        // Update map position
        [self drawUserPositionWithCoord:[loc getCoords] andAccuracy:loc.accuracy];
    }
}


#pragma mark MKMapViewDelegate
- (void)mapViewDidFinishLoadingMap:(MKMapView *)mapView {
    if (!isMapStarted) {
        isMapStarted = YES;
        isFirstMapUpdate = YES;
        [Delegate get].vc = self;
        // onMapLongClick -> Set in enableRouting
        
        // Check buildings
        [[GlobalState get].links getBuildings];
    }
    
}

- (MKOverlayRenderer *)mapView:(MKMapView *)mapView rendererForOverlay:(id<MKOverlay>)overlay {
    if ([overlay isKindOfClass:[MKTileOverlay class]]) {
        return [[MKTileOverlayRenderer alloc] initWithOverlay:overlay];
    } else if ([overlay isKindOfClass:[MKCircle class]]) {
        MKCircleRenderer* renderer = [[MKCircleRenderer alloc] initWithOverlay:overlay];
        renderer.fillColor = [UIColor clearColor];
        renderer.strokeColor = [Colors accentLight];
        renderer.lineWidth = kOYMMapCircleStroke;
        return renderer;
    } else if ([overlay isKindOfClass:[MKPolyline class]]) {
        MKPolylineRenderer* renderer = [[MKPolylineRenderer alloc] initWithPolyline:overlay];
        renderer.fillColor = [Colors accentDark];
        renderer.strokeColor = [Colors accentDark];
        renderer.lineWidth = kOYMMapRouteWidth;
        return renderer;
    }
    return nil;
}

-(MKAnnotationView *)mapView:(MKMapView *)map viewForAnnotation:(id<MKAnnotation>)annotation {
    if ([annotation isKindOfClass:[OYMAnnotation class]]) {
        OYMAnnotation* my = (OYMAnnotation*)annotation;
        MKAnnotationView* av = [OYMAnnotation getReusableViewForMap:map];
        if (av) {
            av.annotation = annotation;
        } else {
            av = my.view;
        }
        return av;
    }
    return nil;
}

- (void)mapView:(MKMapView *)mapView regionWillChangeAnimated:(BOOL)animated {
    isMapUpdated = NO;
}

- (void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated {
    isMapUpdated = YES;
}


#pragma mark UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex {
    if (alertView.tag == kOYMTagAlertMenuOnNav) {
        if (buttonIndex == 1) {
            [self stopNavigation];
        }
    }
}


#pragma mark UIActionSheetDelegate
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex {
    if (buttonIndex > 0) {
        OYMArea* area = [areas objectAtIndex:(buttonIndex-1)];
        OYMRoutePoint* rp = [[OYMRoutePoint alloc] initWithX:area.x andY:area.y andFloornumber:area.floornumber andBuildingId:area.building];
        [self startNavInitForPoint:rp andTitle:area.name];
    }
}

#pragma mark Navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
     if ([segue.identifier isEqualToString:@"SegueMapLogout"]) {
         [(SplashViewController*)segue.destinationViewController onBeingLoggedOut];
     } else if ([segue.identifier isEqualToString:@"SegueMapInstructions"]) {
         [(InstructionsViewController*)segue.destinationViewController setLocation:currentLocation];
     }
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 

@end


