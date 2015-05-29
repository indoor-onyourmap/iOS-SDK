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
static NSString *const kOYMIndoorNavigationUrl = @"https://indoor.onyourmap.com:8443/links";

static NSString *const kOYMIndoorNavigationNotificationKeyMessage = @"msg";


@synthesize gs, vc, locManager;

+ (instancetype) get {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        deg = [Delegate new];
        deg.locManager = [CLLocationManager new];
        deg.locManager.delegate = deg;
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
            } else if ([CLLocationManager authorizationStatus] != kCLAuthorizationStatusAuthorizedAlways) {
                [locManager requestAlwaysAuthorization];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            }
        }
        else {
            if (status == kCLAuthorizationStatusNotDetermined) {
                [(SplashViewController*)vc onLocationServicesChecked:NO];
            } else {
                [(SplashViewController*)vc onLocationServicesChecked:YES];
            }
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
        [(SplashViewController*)vc showError:NSLocalizedString(@"FSConnectError", nil)];
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
    if (succeed && vc != nil && [vc isKindOfClass:[MapViewController class]]) {
        [(MapViewController*)vc enableRouting];
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


@end
