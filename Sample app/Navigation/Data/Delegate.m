//
//  Delegate.m
//  indoor
//
//  Created by onyourmap on 14/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "Delegate.h"

static Delegate* deg = nil;

@implementation Delegate

#pragma mark Private static constants
static NSString *const kOYMIndoorNavigationUserPrefix = @"user@indoor.";
static NSString *const kOYMIndoorNavigationUserKey = @"OYM_PREFS_USER";
static NSString *const kOYMIndoorNavigationPasswordKey = @"OYM_PREFS_PASSWORD";
static NSString *const kOYMIndoorNavigationAutologinKey = @"OYM_PREFS_AUTOLOGIN";
static NSString *const kOYMIndoorNavigationErrorUsername = @"unknown username";
static NSString *const kOYMIndoorNavigationErrorPassword = @"invalid password";
static NSString *const kOYMIndoorNavigationUrl = @"https://indoor.onyourmap.com:8443/links";

static NSString *const kOYMIndoorNavigationNotificationKeyMessage = @"msg";


@synthesize gs, vc, locManager, reachability;

+ (instancetype) get {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        deg = [Delegate new];
        deg.locManager = [CLLocationManager new];
        deg.locManager.delegate = deg;
        
        // Initialize Reachability
        deg.reachability = [OYMReachability reachabilityWithHostname:@"www.google.com"];
    });
    
    return deg;
}


- (void) checkLocationServices {
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        CLAuthorizationStatus status = [CLLocationManager authorizationStatus];
        if (![CLLocationManager locationServicesEnabled]) {
            [(SplashViewController*)vc promptEnableLocationServices];
        } else if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")) {
            
            if (status == kCLAuthorizationStatusDenied || status == kCLAuthorizationStatusRestricted) {
                [(SplashViewController*)vc onLocationServicesChecked:NO];
            } else if (status != kCLAuthorizationStatusAuthorizedAlways) {
                [locManager requestAlwaysAuthorization];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            }
        } else {
            if (status == kCLAuthorizationStatusNotDetermined) {
                [locManager startUpdatingLocation];
            } else if (status != kCLAuthorizationStatusAuthorizedAlways) {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:NO];
            }
        }
    }
    
}

- (void) recheckLocationServices {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        CLAuthorizationStatus status = [CLLocationManager authorizationStatus];
        if (status != kCLAuthorizationStatusAuthorizedAlways) {
            [((MapViewController*)vc) onLogout:nil];
            [[[UIAlertView alloc] initWithTitle:NSLocalizedString(@"FSLocServicesErrorTitle", nil) message:NSLocalizedString(@"FSLocServicesErrorMessage", nil) delegate:nil cancelButtonTitle:NSLocalizedString(@"ok", nil) otherButtonTitles:nil] show];
        }
    }
}


- (BOOL) areCredentialsAvailable {
    NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
    BOOL al = [prefs boolForKey:kOYMIndoorNavigationAutologinKey];
    if (al) {
        user = [prefs stringForKey:kOYMIndoorNavigationUserKey];
        password = [prefs stringForKey:kOYMIndoorNavigationPasswordKey];
        return YES;
    } else {
        return NO;
    }
}

- (void) disableAutologin {
    NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
    [prefs setBool:NO forKey:kOYMIndoorNavigationAutologinKey];
    [prefs synchronize];
}

-(void)start {
    [deg.reachability startNotifier];
    [[NSNotificationCenter defaultCenter] addObserver:deg selector:@selector(reachabilityDidChange:) name:kReachabilityChangedNotification object:nil];
    
    gs = [GlobalState get];
    gs.indoorLib = [[OYMIndoorLocationLib alloc] initWithUrl:kOYMIndoorNavigationUrl andUser:user andPassword:password withDelegate:self];
    gs.links = [[OYMIndoorRouting alloc] initWithUrl:kOYMIndoorNavigationUrl andUser:user andPassword:password andDelegate:self];
}

- (void)startWithAccount:(NSString *)a andPassword:(NSString *)p {
    user = [kOYMIndoorNavigationUserPrefix stringByAppendingString:a];
    password = p;
    [self start];
}

- (void)stop {
    [gs.indoorLib stopLocate];
    [gs.links disconnect];
    
    [deg.reachability stopNotifier];
    [[NSNotificationCenter defaultCenter] removeObserver:deg name:kReachabilityChangedNotification object:nil];
}


#pragma mark OYMIndoorDelegate
- (void)didLoginSucceed {
    // Store credentials
    NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
    [prefs setBool:YES forKey:kOYMIndoorNavigationAutologinKey];
    [prefs setObject:user forKey:kOYMIndoorNavigationUserKey];
    [prefs setObject:password forKey:kOYMIndoorNavigationPasswordKey];
    [prefs synchronize];
    
    [gs.indoorLib startLocate];
}

- (void)didLoginFailedWithError:(NSString *)msg {
    // Delete credentials
    NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
    [prefs setBool:NO forKey:kOYMIndoorNavigationAutologinKey];
    [prefs synchronize];
    
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        if ([msg isEqualToString:kOYMIndoorNavigationErrorUsername]) {
            [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectUsernameError", nil)];
        } else if ([msg isEqualToString:kOYMIndoorNavigationErrorPassword]) {
            [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectPasswordError", nil)];
        } else {
            [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectError", nil)];
        }
    }
}

- (void)didGetBuildings:(NSArray *)buildings succeeded:(BOOL)succeed {
    if (succeed && vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc setBuildings:buildings];
    }
}

- (void)didGetAreas:(NSArray *)areas succeeded:(BOOL)succeed {
    if (succeed && vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc setAreas:areas];
    }
}


#pragma mark OYMIndoorLocationDelegate
- (void)didStartSuccessfully {
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        [(SplashViewController*)vc ready];
    }

}

-(void)didFailStarting {
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        [(SplashViewController*)vc showError:NSLocalizedString(@"SLibError", nil)];
    }
}

-(void)onPositionUpdate:(OYMIndoorLocation *)location {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc onPositionUpdate:location];
    } else if (vc != nil && [vc isKindOfClass:[InstructionsViewController class]]) {
        [(InstructionsViewController*)vc onLocationUpdate:location];
    }
}

- (void)didRoutingSucceed:(BOOL)succeed {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc enableRouting:succeed];
    }
}

- (void)onNotification:(OYMNotificationResult *)notification {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        NSString* msg = [notification.notification.properties objectForKey:kOYMIndoorNavigationNotificationKeyMessage];
        if (msg == nil) {
            if (notification.notification.action == ENTERING) {
                msg = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"AMNEnter", nil), notification.place.name];
            } else if (notification.notification.action == STAY) {
                msg = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"AMNStay", nil), notification.place.name];
            } else if (notification.notification.action == LEAVING) {
                msg = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"AMNLeave", nil), notification.place.name];
            } else if (notification.notification.action == NEARBY) {
                msg = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"AMNNearby", nil), notification.place.name];
            }
        }
        
        UILocalNotification* ln = [UILocalNotification new];
        ln.alertBody = msg;
        
        [[UIApplication sharedApplication] scheduleLocalNotification:ln];
    }
}

#pragma mark CLLocationManagerDelegate
-(void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        [(SplashViewController*)vc onLocationServicesChecked:(status == kCLAuthorizationStatusAuthorizedAlways)];
    }
}


#pragma mark Reachability
- (void)reachabilityDidChange:(NSNotification *)notification {
    OYMReachability* r = [notification object];
    if (![r isReachable] && vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [vc.view makeToast:NSLocalizedString(@"AMTNoInternet", nil) duration:3.0 position:CSToastPositionBottom title:nil];
    }
}


@end
