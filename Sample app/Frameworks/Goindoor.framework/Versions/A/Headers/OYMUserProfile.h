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

#import <Links/links.h>

#import "OYMSettings.h"

#pragma mark Public constants
/** String containing the UserProfile type */
static NSString* const kOYMUserProfileType = @"USERPROFILE";

/** Key to retrieve the iOS Device ID from the {@link Item} */
static NSString* const kOYMUserProfileKeyDeviceId = @"deviceId";
/** Key to retrieve the type from the {@link Item} */
static NSString* const kOYMUserProfileKeyType = @"type";
/** Key to retrieve the App package name from the {@link Item} */
static NSString* const kOYMUserProfileKeyAppName = @"appName";
/** Key to retrieve the Routes from the {@link Item} */
static NSString* const kOYMUserProfileKeyRoutes = @"routes";
/** Key to retrieve the Building ID from the {@link Item} */
static NSString* const kOYMUserProfileKeyBuilding = @"building";
/** Key to retrieve the Floor ID from the {@link Item} */
static NSString* const kOYMUserProfileKeyFloor = @"floor";

/** Key to retrieve the device ID from properties */
static NSString* const kOYMUserProfileJsonRoutesCount = @"routesCount";
/** Key to retrieve the device ID from properties */
static NSString* const kOYMUserProfileJsonRoutesArray = @"routesArray";

/** Key to retrieve the type from properties */
static NSString* const kOYMUserProfilePropType = @"properties.type";
/** Key to retrieve the device ID from properties */
static NSString* const kOYMUserProfilePropDeviceId = @"properties.deviceId";
/** Key to retrieve the routes from properties */
static NSString* const kOYMUserProfilePropRoutes = @"properties.routes";
/** Key to retrieve the app name from properties */
static NSString* const kOYMUserProfilePropAppName = @"properties.appName";

/** Event prefix ID */
static NSString* const kOYMUserProfileEventIdPrefix = @"EVENT-";

/** Exception message when the iOS Device ID has not been set */
//static NSString* const kOYMUserProfileExceptionNoDeviceId = @"device ID has not been set";


/**
 *  This class includes all the information regarding the user profile to log
 * information in the server.
 */
@interface OYMUserProfile : NSObject
{
    @private
    NSString *deviceId;
    NSString *workspace;
    OYMSettings *settings;
    NSMutableDictionary *smProps;
    NSMutableDictionary *navProps;    
    NSMutableDictionary *smPropsOrphan;
    NSMutableDictionary *navPropsOrphan;
}

/** String containing the application bundle identifier */
@property (readonly) NSString *appName;
@property (readonly) OYMLinksItem *item;

# pragma mark Constructors
/**
 *  OYMUserProfile constructor.
 *
 * @param _workSpace username prefix
 * @param _settings OYMSettings containing the OYMLinksItem properties value
 * @return OYMUserProfile Object
 */
- (instancetype) initWithWorkSpace:(NSString *)_workSpace andSettings:(OYMSettings *)_settings;
/**
 *  OYMUserProfile constructor.
 *
 * @param _item OYMLinksItem containg the UserProfile Object
 * @param _workSpace username prefix
 * @param _settings OYMSettings containing the OYMLinksItem properties value
 * @return OYMUserProfile Object
 */
- (instancetype) initWithItem:(OYMLinksItem *)_item workSpace:(NSString *)_workSpace andSettings:(OYMSettings *)_settings;

/**
 *  Setter for the {@link Item}.
 *
 * @param item OYMLinksItem to be set
 */
- (void) setItem:(OYMLinksItem *)item ;
/**
 *  Getter for the {@link Item}
 *
 * @return The OYMLinksItem Object
 */
- (OYMLinksItem *) item ;

@end

@interface OYMUserProfile (Protected)
/**
 *  This method update the live properties internally. It shall not be used.
 *
 * @param time  NSDate object
 * @param x WGS84 Longitude to be logged
 * @param y WGS84 Latitude to be logged
 */
- (void) updateLiveWithTime:(NSDate *)time x:(double)x andY:(double)y;
/**
 *  This method update the live properties internally. It shall not be used.
 *
 * @param time  NSDate object
 * @param x WGS84 Longitude to be logged
 * @param y WGS84 Latitude to be logged
 * @param buildingId Building ID to be logged
 * @param floorId Floor ID to be logged
 */
- (void) updateLiveWithTime:(NSDate *)time x:(double)x Y:(double)y buildingId:(NSString *)buildingId andFloorId:(NSString *)floorId;

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