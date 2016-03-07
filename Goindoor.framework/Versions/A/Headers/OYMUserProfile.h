//
//  OYMUserProfile.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 05/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMUSERPROFILE_H
#define INDOOR_OYMUSERPROFILE_H

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "OYMSettings.h"

#pragma mark Public constants
/** String containing the UserProfile type */
static NSString* const kOYMUserProfileType = @"USERPROFILE";

static NSString* const kOYMUserProfileKeyUUID = @"id";
static NSString* const kOYMUserProfileKeyLatitude = @"latitude";
static NSString* const kOYMUserProfileKeyLongitude = @"longitude";
static NSString* const kOYMUserProfileKeyProperties = @"properties";
static NSString* const kOYMUserProfileKeySettings = @"settings";

/** Key to retrieve the iOS Device ID */
static NSString* const kOYMUserProfileKeyDevice = @"device";
/** Key to retrieve the type */
static NSString* const kOYMUserProfileKeyType = @"type";
/** Key to retrieve the App package name */
static NSString* const kOYMUserProfileKeyAppName = @"appName";
/** Key to retrieve the Routes */
static NSString* const kOYMUserProfileKeyRoutes = @"routes";
/** Key to retrieve the Building ID */
static NSString* const kOYMUserProfileKeyBuilding = @"building";
/** Key to retrieve the Floor ID */
static NSString* const kOYMUserProfileKeyFloor = @"floor";

/** Key to retrieve the device ID from properties */
static NSString* const kOYMUserProfileJsonRoutesCount = @"routesCount";
/** Key to retrieve the device ID from properties */
static NSString* const kOYMUserProfileJsonRoutesArray = @"routesArray";


/**
 *  This class includes all the information regarding the user profile to log
 * information in the server.
 */
@interface OYMUserProfile : NSObject <OYMJsonProtocol>
{
    @package
    NSString *uuid;
    NSString *routes;
    @private
    NSString *device;
    double latitude;
    double longitude;
    NSString *building;
    NSString *floor;
    NS_MUTABLE_DICTIONARY_OF(NSString*, NSString*) *properties;
 
    OYMSettings *settings;
    NS_MUTABLE_DICTIONARY_OF(NSString *, OYMUserValue*) *smProps;
    NS_MUTABLE_DICTIONARY_OF(NSString *, OYMUserValue*) *navProps;
    NS_MUTABLE_DICTIONARY_OF(NSString *, NSString*) *smPropsOrphan;
    NS_MUTABLE_DICTIONARY_OF(NSString *, NSString*) *navPropsOrphan;
}

/** String containing the application bundle identifier */
@property (readonly) NSString *appName;

# pragma mark Constructors

- (instancetype) initWithAppName:(NSString *)_appName andDevice:(NSString *)_device;

- (void) setSettings:(OYMSettings *)_settings;

- (void) addSettings: (OYMSettings *)_settings;

@end

@interface OYMUserProfile (Protected)
/**
 *  This method update the live properties internally. It shall not be used.
 *
 * @param _latitude WGS84 Latitude to be logged
 * @param _longitude WGS84 Longitude to be logged
 * @param _time NSString following ISO-8601 standard: yyyy-MM-dd'T'HH:mm'Z'
 */
- (void) updateLive:(double)_latitude andLongitude:(double)_longitude andTime:(NSString*)_time ;
/**
 *  This method update the live properties internally. It shall not be used.
 *
 * @param _latitude WGS84 Latitude to be logged
 * @param _longitude WGS84 Longitude to be logged
 * @param _time String following ISO-8601 standard: yyyy-MM-dd'T'HH:mm'Z'
 * @param _building Building ID to be logged
 * @param _floor Floor ID to be logged
 */
- (void) updateLive:(double)_latitude andLongitude:(double)_longitude andTime:(NSString*)_time andBuilding:(NSString *)_building andFloor:(NSString *)_floor;

//Stats

- (void) putStatsPropWithKey:(NSString *)key andValue:(OYMUserValue *)userValue;

- (OYMUserValue *) getStatsPropForKey:(NSString *)key;

- (void) removeStatsPropForKey:(NSString *)key;

- (NSDictionary *) getAllStatsProp;

- (NSArray *) getStatsKeys;

//Nav

- (void) putNavPropWithKey:(NSString *)key andValue:(OYMUserValue *)userValue;

- (OYMUserValue *) getNavPropForKey:(NSString *)key;

- (void) removeNavPropForKey:(NSString *)key;

- (NSDictionary *) getAllNavProp;

- (NSArray *) getNavKeys;

@end
#endif