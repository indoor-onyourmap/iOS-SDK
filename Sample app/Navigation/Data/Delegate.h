//
//  Delegate.h
//  indoor
//
//  Created by onyourmap on 14/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef NAV_DELEGATE_H
#define NAV_DELEGATE_H

#import <Foundation/Foundation.h>
@import UIKit;
@import CoreLocation;

#import "GlobalState.h"
#import "SplashViewController.h"
#import "InstructionsViewController.h"
#import "Reachability.h"


@interface Delegate : NSObject <OYMLocationDelegate, CLLocationManagerDelegate> {
    @private
    NSString* user;
    NSString* password;
    CLAuthorizationStatus locationAuthStatus;
}

@property GlobalState* gs;
@property UIViewController* vc;
@property (strong) CLLocationManager* locManager;
@property OYMReachability* reachability;

+ (instancetype) get;

- (void) checkLocationServices;
- (void) recheckLocationServices;
- (BOOL) areCredentialsAvailable;
- (void) disableAutologin;
- (void) start;
- (void) startWithAccount:(NSString*)a andPassword:(NSString*)p;
- (void) stop;

// Reachability
- (void)reachabilityDidChange:(NSNotification *)notification;

@end
#endif