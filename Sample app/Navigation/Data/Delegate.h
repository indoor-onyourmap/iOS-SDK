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


@interface Delegate : NSObject <OYMIndoorRoutingDelegate, OYMIndoorLocationDelegate, CLLocationManagerDelegate> {
    @private
    NSString* user;
    NSString* password;
}

@property GlobalState* gs;
@property UIViewController* vc;
@property (strong) CLLocationManager* locManager;

+ (instancetype) get;

- (void) checkLocationServices;
- (BOOL) areCredentialsAvailable;
- (void) disableAutologin;
- (void) start;
- (void) startWithAccount:(NSString*)a andPassword:(NSString*)p;
- (void) stop;

@end
#endif