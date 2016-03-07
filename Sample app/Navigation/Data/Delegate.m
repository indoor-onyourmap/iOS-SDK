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
        deg.reachability = [OYMReachability oymReachabilityWithHostName:@"www.google.com"];
    });
    
    return deg;
}


- (void) checkLocationServices {
    if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
        locationAuthStatus = [CLLocationManager authorizationStatus];
        if (![CLLocationManager locationServicesEnabled]) {
            [(SplashViewController*)vc promptEnableLocationServices];
        } else if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")) {
            
            if (locationAuthStatus == kCLAuthorizationStatusDenied || locationAuthStatus == kCLAuthorizationStatusRestricted) {
                [(SplashViewController*)vc onLocationServicesChecked:NO];
            } else if (locationAuthStatus != kCLAuthorizationStatusAuthorizedAlways) {
                [locManager requestAlwaysAuthorization];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            }
        } else {
            if (locationAuthStatus == kCLAuthorizationStatusNotDetermined) {
                [locManager startUpdatingLocation];
            } else if (locationAuthStatus == kCLAuthorizationStatusDenied || locationAuthStatus == kCLAuthorizationStatusRestricted) {
                [(SplashViewController*)vc onLocationServicesChecked:NO];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            }
        }
    }
}

- (void) recheckLocationServices {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        CLAuthorizationStatus status = [CLLocationManager authorizationStatus];
        if (status != kCLAuthorizationStatusAuthorizedAlways) {
            [((MapViewController*)vc) onLogout];
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
    [deg.reachability startOYMReachabilityNotifier];
    [[NSNotificationCenter defaultCenter] addObserver:deg selector:@selector(reachabilityDidChange:) name:kOYMReachabilityChangedNotification object:nil];
    
    gs = [GlobalState get];
    gs.go = [OYMGoIndoor goIndoorWithBlock:^(id<GoIndoorBuilder> builder) {
        [builder setAccount:user];
        [builder setPassword:password];
        [builder setConnectCallBack:^(BOOL succeed, NSString *message) {
            if (succeed) {
                // Store credentials
                NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
                [prefs setBool:YES forKey:kOYMIndoorNavigationAutologinKey];
                [prefs setObject:user forKey:kOYMIndoorNavigationUserKey];
                [prefs setObject:password forKey:kOYMIndoorNavigationPasswordKey];
                [prefs synchronize];
                
                [gs.go startLocate:self];
            } else {
                // Delete credentials
                NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
                [prefs setBool:NO forKey:kOYMIndoorNavigationAutologinKey];
                [prefs synchronize];
                
                if (vc != nil && [vc isKindOfClass:[SplashViewController class]]) {
                    if ([message isEqualToString:kOYMIndoorNavigationErrorUsername]) {
                        [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectUsernameError", nil)];
                    } else if ([message isEqualToString:kOYMIndoorNavigationErrorPassword]) {
                        [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectPasswordError", nil)];
                    } else {
                        [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectError", nil)];
                    }
                }
            }
        }];
    }];
}

- (void)startWithAccount:(NSString *)a andPassword:(NSString *)p {
//    user = [kOYMIndoorNavigationUserPrefix stringByAppendingString:a];
    user = a;
    password = p;
    [self start];
}

- (void)stop {
    [gs.go stopLocate];
    [gs.go disconnect];
    
    [deg.reachability stopOYMReachabilityNotifier];
    [[NSNotificationCenter defaultCenter] removeObserver:deg name:kOYMReachabilityChangedNotification object:nil];
}


#pragma mark OYMIndoorDelegate
- (void)loginSucceed {
    
}

#pragma mark OYMLocationDelegate
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

-(void)onLocation:(OYMLocationResult *)location {
    if (vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc onPositionUpdate:location];
    } else if (vc != nil && [vc isKindOfClass:[InstructionsViewController class]]) {
        [(InstructionsViewController*)vc onLocationUpdate:location];
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
        NSLog(@"locationManagerChange");
        if (status != locationAuthStatus) {
            [(SplashViewController*)vc onLocationServicesChecked:(status == kCLAuthorizationStatusAuthorizedAlways)];
        }
    }
}


#pragma mark Reachability
- (void)reachabilityDidChange:(NSNotification *)notification {
    OYMReachability* r = [notification object];
    if ([r currentOYMReachabilityStatus] == kOYMNetworkStatusNotReachable && vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [vc.view makeToast:NSLocalizedString(@"AMTNoInternet", nil) duration:3.0 position:CSToastPositionBottom title:nil];
    }
}


@end
