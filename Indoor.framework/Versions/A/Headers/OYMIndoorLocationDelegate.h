//
//  OYMIndoorLocationDelegate.h
//  indoor
//
//  Created by onyourmap on 15/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONDELEGATE_H
#define INDOOR_OYMINDOORLOCATIONDELEGATE_H

#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMIndoorLocation.h"

@protocol OYMIndoorLocationDelegate <NSObject>

@required
/**
 *  This method is called when the indoor location service has been
 * correctly started.
 */
- (void) didStartSuccessfully;
/**
 *  This method is called when an exception is thrown when trying to
 * start the indoor location service.
 */
- (void) didFailStarting;
/**
 *  This method is called when a new position is available.
 *
 * @param location User position
 */
- (void) onPositionUpdate:(OYMIndoorLocation*)location;


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

@end
#endif