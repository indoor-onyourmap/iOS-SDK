//
//  OYMLocationDelegate.h
//  Goindoor
//
//  Created by onyourmap on 15/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONDELEGATE_H
#define INDOOR_OYMINDOORLOCATIONDELEGATE_H

#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMLocationResult.h"
#import "OYMNotificationResult.h"


/**
 *  This delegate will provide feedback to the user regarding the Goindoor location library.
 */
@protocol OYMLocationDelegate <NSObject>

@required
/**
 *  This method is called when the Goindoor location service has been
 * correctly started.
 */
- (void) didStartSuccessfully;
/**
 *  This method is called when an exception is thrown when trying to
 * start the Goindoor location service.
 */
- (void) didFailStarting;
/**
 *  This method is called when a new position is available.
 *
 * @param location User position
 */
- (void) onLocation:(OYMLocationResult*)location;
/**
 *  This method is callen when a notification is triggered.
 *
 * @param notification Notification triggered
 */
- (void) onNotification:(OYMNotificationResult*)notification;


@optional
/**
 *  This method is called when the app has not the right authorisation for the Location Services.
 *
 * @param current Current Authorisation Permission
 */
- (void) locationAlwaysAuthorizationRequired:(CLAuthorizationStatus)current;
/**
 *  This method is called when the Location Services are disabled.
 */
- (void) locationServicesAreDisabled;
/**
 *  This method is called when the Core Blueooth Central Manager state has changed.
 *
 * @param state The new Core Blueooth Central Manager state
 */
- (void) centralManagerDidChangeState:(enum CBCentralManagerState)state;

@end
#endif