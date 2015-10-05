//
//  MapViewController.h
//  indoor
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef NAV_MAPVIEWCONTROLLER_H
#define NAV_MAPVIEWCONTROLLER_H

#import <UIKit/UIKit.h>
@import CoreLocation;
@import MapKit;

#import <Goindoor/Goindoor.h>

#import "MainViewController.h"

#import "Delegate.h"
#import "GlobalState.h"
#import "SplashViewController.h"
#import "UpperBar.h"
#import "PrimaryBarView.h"
#import "OYMAnnotation.h"
#import "OYMLocationResult+CLLocation.h"
#import "UIView+Toast.h"


@interface MapViewController : MainViewController <MKMapViewDelegate, UIAlertViewDelegate, UIActionSheetDelegate> {
@private
    // View
    UIImage* markerImage;
    
    // Map
    OYMTileOverlay* tileOverlay;
    OYMAnnotation* markerPos;
    MKCircle* circlePos;
    NSArray* mapRoute;
    int lastFloorNumber;
    
    // Flags
    BOOL isMapStarted;
    BOOL isFirstMapUpdate;
    BOOL isMapUpdated;
    BOOL isFbbShown;
    BOOL isNavigation;
    BOOL isCameraUpdated;
    BOOL isSpinnerAvailable;
    BOOL isBuildingReady;
    
    // Stored position
    OYMAnnotation *storedMarker;
    OYMRoutePoint *storedPos;
        
    // Data
    OYMBuilding* building;
    NSNumber* currentFloor;
    
    // Demo
    NSMutableArray *markers;
    NSMutableArray *circles;
    
    // Stats
    int logCount;
    
    // Navigation
    BOOL isNavigationReady;
    OYMLocationResult* currentLocation;
    BOOL isStartNav;
    OYMRoutePoint* destination;
    NSString* startNavTitle;
    UIAlertView* startNavAlert;
    OYMInstruction* instruction;
    NSArray* areas;
    
    GlobalState *gs;
    
    CustomSingleItem *storeItem;
    CustomSingleItem *restoreItem;
    CustomSingleItem *deleteItem;
    CustomSingleItem *itemUserProfile;
}

// View
@property (strong, nonatomic) IBOutlet UpperBar* fub;
@property IBOutlet NSLayoutConstraint* fubConstraint;
@property IBOutlet UILabel* fubDestination;
@property IBOutlet UILabel* fubLocal;
@property IBOutlet PrimaryBarView* fubLevelBox;
@property IBOutlet UILabel* fubLevel;
@property IBOutlet UILabel* fubNumber;

@property (strong, nonatomic) IBOutlet PrimaryBarView* fbb;
@property IBOutlet NSLayoutConstraint* fbbConstraint;
@property IBOutlet UIImageView* fbbImage;
@property IBOutlet UILabel* fbbDistance;
@property IBOutlet UILabel* fbbInstruction;


// Map
@property(weak, nonatomic) IBOutlet MKMapView* mapView;


- (void)onLogout ;

- (void) onPositionUpdate:(OYMLocationResult*)loc;
   
@end
#endif