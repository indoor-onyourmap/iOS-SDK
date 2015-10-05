//
//  OYMLogger.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 05/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMLOGGER_H
#define INDOOR_OYMLOGGER_H

#import <Foundation/Foundation.h>

#import "OYMLocationResult.h"
#import "OYMRoute.h"
#import "OYMDataHandler.h"

static int const OYMLoggerThresholdRoutes = 10;

static NSString *const kOYMLoggerUpdateUserProfiles = @"OYMUpdateUserProfiles";
static NSString *const kOYMLoggerUpdateLiveUserProfile = @"OYMLoggerUpdateLiveUserProfile";

@class OYMDataHandler;
/**
 *  This class helps to log user information to the server.
 */
@interface OYMLogger : NSObject

@property (readonly) OYMDataHandler *dataHandler;

#pragma mark Constructors
/**
 *  OYMLogger constructor.
 *
 * @param dh OYMDataHandler
 */
- (instancetype) initWithDataHandler:(OYMDataHandler *)dh;

- (void) logPosition:(OYMLocationResult *)loc;
/**
 *  This method logs the position to the server.
 *
 * @param x WGS84 Longitude to be logged
 * @param y WGS84 Latitude to be logged
*/
- (void) logPositionX:(double)x andY:(double)y __deprecated_msg("Use logPosition:(OYMLocationResult *)} instead.");
/**
 *  This method logs the Route to the server.
 *
 * @param route Route to be logged
 */
- (void) logRoute:(OYMRoute *)route;
/**
 *  This method logs the Route to the server.
 *
 * @param jsonRoute Route to be logged
 */
- (void) logJsonRoute:(NSString *)jsonRoute;

/**
 *  This method retrieves all the stats keys for the user.
 *
 * @return A list of all the keys available
 */
- (NSArray *) getStatsKeys;
/**
 *  This method retrieves a stats key for the user.
 *
 * @param key Key to be retrieved
 * @return The value of the key if it exists, nil otherwise
 */
- (OYMUserValue *) getStatsProp:(NSString *)key;
/**
 *  This method stores a value for a given key.
 *
 * @param key Key to be stored
 * @param userValue Value to be stored
 */
- (void) putStatsPropKey:(NSString *)key andUserValue:(OYMUserValue *)userValue;
/**
 *  This method stores a bunch of stats key values pairs.
 *
 * @param values NSDictionary of key,values pairs to be stored
 */
- (void) putStatsProp:(NSDictionary *)values;

/**
 *  This method retrieves all the navigation keys for the user.
 *
 * @return A list of all the keys available
 */
- (NSArray *) getNavKeys;
/**
 *  This method retrieves a navigation key for the user.
 *
 * @param key Key to be retrieved
 * @return The value of the key if it exists, nil otherwise
 */
- (OYMUserValue *) getNavProp:(NSString *)key;
/**
 *  This method stores a value for a given key.
 *
 * @param key Key to be stored
 * @param userValue Value to be stored
 */
- (void) putNavPropKey:(NSString *)key andUserValue:(OYMUserValue *)userValue;
/**
 *  This method stores a bunch of stats key values pairs.
 *
 * @param values NSDictionary of key,values pairs to be stored
 */
- (void) putNavProp:(NSDictionary *)values;

@end

#endif