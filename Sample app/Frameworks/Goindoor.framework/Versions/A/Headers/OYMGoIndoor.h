//
//  OYMGoIndoor.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 31/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMGOINDOOR_H
#define INDOOR_OYMGOINDOOR_H

#import <Foundation/Foundation.h>
#import "OYMConstant.h"

#import "OYMSettings.h"
#import "OYMUserProfile.h"
#import "OYMDataHandler.h"
#import "OYMLogger.h"
#import "OYMRouting.h"
#import "OYMLocationCore.h"
#import "OYMAsset.h"
#import "OYMNotification.h"
#import "OYMProxiBeacon.h"

@protocol GoIndoorBuilder;

/** Variable defining the default location update rate in msec */
static long const kOYMGoIndoorDefaultLocationRefresh = 2000; //msec
static long const kOYMGoIndoorDefaultUpdateTime = 60 * 15; //15 mins
static NSString* const kOYMGoIndoorDefaultWsUrl = @"https://indoor.onyourmap.com/ws/v2";

/**
 *  Annotation defining the possible algorithms to be used
 */
typedef NS_ENUM(int, OYMGoIndoorLocationType) {
    /** Weighted average */
    kOYMGoIndoorLocationTypeAverage = 0,
    /** Closest iBeacon */
    kOYMGoIndoorLocationTypeClosest = 1,
    /** Weighted average with projection to the closest edge */
    kOYMGoIndoorLocationTypeProject = 2
};
/**
 *  Annotation defining the database update policy
 */
typedef NS_ENUM(int, OYMGoIndoorUpdate) {
    /** Weighted average */
    kOYMGoIndoorUpdateNo = 0,
    /** Closest iBeacon */
    kOYMGoIndoorUpdateWifi = 1,
    /** Weighted average with projection to the closest edge */
    kOYMGoIndoorUpdateMobile = 1 << 1
};

static const NSString* kOYMGoIndoorLocationKeyRefresh = @"OYMRefresh";
static const NSString* kOYMGoIndoorLocationKeyType = @"OYMType";

@class OYMDataHandler, OYMLogger, OYMBuilding, OYMLocationCore;

@interface OYMGoIndoor : NSObject
{
    @package
    BOOL isReady;
    BOOL isLocationRunning;
    
    NSString *url;
    NSString *profile;
    NSString *account;
    NSString *password;
    void (^connectCallback)(BOOL succeed, NSString *message);
    OYMGoIndoorLocationType locationType;
    long locationUpdate;
    OYMGoIndoorUpdate updatePolicy;
    long updateTime;
    
    NSString *workspace;
    OYMDataHandler *dataHandler;
    OYMLogger *logger;
    OYMLocationCore *core;

}

/**
*  Creates a OYMGoIndoor Object with the arguments supplied to this GoIndoorBuilder.
*
* @return A OYMGoIndoor object
*/
+ (OYMGoIndoor *) goIndoorWithBlock:(void(^)(id<GoIndoorBuilder> builder))block ;

/**
 *  This method will disconnect the location provider and closes the session to the server.
 */
- (void) disconnect ;
/**
 *  Method to start the Goindoor location with the default rate.
 *
 * @param br OYMLocationBroadcast to handle the output from the library
 */
- (void) startLocate:(id<OYMLocationDelegate>)_delegate ;
/**
 *  Method to stop the Goindoor location
 */
- (void) stopLocate ;
/**
 *  This method computes a route between two given points.
 *
 * @param start Departure point
 * @param destination Destination point
 * @return A OYMRoute object describing the route between the given points
 */
- (OYMRoute *) computeRouteFrom:(OYMRoutePoint *)start to:(OYMRoutePoint *)destination ;
/**
 *  Getter for the logger object. It can be used to log position and routes in the server.
 *
 * @return The OYMLogger object
 */
- (OYMLogger *) getLogger ;

/**
 *  Getter for the beacon list.
 *
 * @return Returns The beacons list
 */
- (NS_ARRAY_OF(OYMBeacon*) *) getBeacons ;
/**
 *  Getter for the beacon list.
 *
 * @param identifier Building or floor ID whose beacons need to be retrieved
 * @return Returns The beacons list
 */
- (NS_ARRAY_OF(OYMBeacon*) *) getBeacon:(NSString *)identifier ;
/**
 *  Getter for the beacon list.
 *
 * @param identifiers Building or floor IDs whose beacons need to be retrieved
 * @return Returns The beacons list
 */
- (NS_ARRAY_OF(OYMBeacon*) *) getBeacons:(NSArray *)identifiers ;

/**
 *  Getter for the building list.
 *
 * @return Returns The buildings list
 */
- (NS_ARRAY_OF(OYMBuilding*) *) getBuildings ;
/**
 *  Getter for the building list.
 *
 * @param identifier Building ID to be retrieved
 * @return Returns The buildings list
 */
- (OYMBuilding *) getBuilding:(NSString *)identifier ;
/**
 *  Getter for the building list.
 *
 * @param identifiers Building IDs to be retrieved
 * @return Returns The buildings list
 */
- (NS_ARRAY_OF(OYMBuilding*) *) getBuildings:(NSArray *)identifiers ;

/**
 *  Getter for the asset list.
 *
 * @return Returns The asset list
 */
- (NS_ARRAY_OF(OYMAsset*) *) getAssets ;
/**
 *  Getter for the asset list.
 *
 * @param identifiers Building or floor ID whose assets need to be retrieved
 * @return Returns The assets list
 */
- (NS_ARRAY_OF(OYMAsset*) *) getAsset:(NSString *)identifier ;
/**
 *  Getter for the asset list.
 *
 * @param identifiers Building or floor IDs whose assets need to be retrieved
 * @return Returns The assets list
 */
- (NS_ARRAY_OF(OYMAsset*) *) getAssets:(NSArray *)identifiers ;

/**
 *  Getter for the places list.
 *
 * @return Returns The places list
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlaces ;
/**
 *  Getter for the places list.
 *
 * @param identifiers Building or floor ID whose places need to be retrieved
 * @return Returns The places list
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlace:(NSString *)identifier ;
/**
 *  Getter for the building list.
 *
 * @param identifiers  Building or floor IDs whose places need to be retrieved
 * @return Returns The places list
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlaces:(NSArray *)identifiers ;
/**
 *  Getter for places inside a defined place.
 *
 * @param loc Location whose places needs to be retrieved
 * @param radius Radius from the location. If 0 it will returns the closest one
 * @param tags List of POI tags that should match in the search, it can be nil
 * @param filter Map of POI properties that should match in the search, it can be nil
 * @return The place list satisfying the criteria, sorted by distance
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlacesWithLocationResult:(OYMLocationResult *)loc andRadius:(int)radius andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
/**
 *  Getter for the place list.
 *
 * @param _ID Building or floor ID whose places need to be retrieved
 * @param tags List of POI tags that should match in the search, it can be nil
 * @param filter Map of POI properties that should match in the search, it can be nil
 * @return The place list satisfying the criteria
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlacesWithId:(NSString *)_ID andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
/**
 *  Getter for the place list.
 *
 * @param latitude WGS84 latitude whose places needs to be retrieved
 * @param longitude WGS84 longitude whose places needs to be retrieved
 * @param radius Radius from the location. If 0 it will returns the closest one
 * @param floorNumber Floor number whose places needs to be retrieved
 * @param building Building ID whose places needs to be retrieved
 * @param tags List of POI tags that should match in the search, it can be nil
 * @param filter Map of POI properties that should match in the search, it can be nil
 * @return The place list satisfying the criteria, sorted by distance
 */
- (NS_ARRAY_OF(OYMPlace*) *) getPlacesWithLatitude:(double)latitude andLongitude:(double)longitude andRadius:(int)radius andFloorNumber:(int)floorNumber andBuilding:(NSString *)building andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
/**
 *  Getter for the notification list.
 *
 * @return Returns The notifications list
 */
- (NS_ARRAY_OF(OYMNotification*) *) getNotifications ;
/**
 *  Getter for the notification list.
 *
 * @param identifier Building or floor ID whose notifications need to be retrieved
 * @return Returns The notifications list
*/
- (NS_ARRAY_OF(OYMNotification*) *) getNotification:(NSString *)identifier ;
/**
 *  Getter for the notification list.
 *
 * @param identifiers Building or floor IDs whose notifications need to be retrieved
 * @return Returns The notifications list
*/
- (NS_ARRAY_OF(OYMNotification*) *) getNotifications:(NSArray *)identifiers ;

/**
 *  Getter for the settings.
 *
 * @return The settings object
 */
- (OYMSettings *) getSettings ;
/**
 *  Getter for the user profile.
 *
 * @return The user profile
 */
- (OYMUserProfile *) getUserProfile ;
/**
 *  Getter for the proxiBeacon list.
 *
 * @return The proxiBeacon list
 */
- (NS_ARRAY_OF(OYMProxiBeacon*)*) getProxiBeacons;

/**
 *  Sets the positioning type. It overrides the value given in the builder.
 *
 * @param type Location type to be applied
 */
- (void) setLocationType:(OYMGoIndoorLocationType)type;

/**
 *  Sets the minimum distance that should change the location result to be updated.
 *
 * @param dist Distance threshold
 */
- (void) setMinDistanceUpdate:(double)dist;

/**
 *  Sets the update policy. It overrides the value given in the builder.
 *
 * @param policy Update policy to be applied
 */
- (void) setUpdatePolicy:(OYMGoIndoorUpdate)policy;

/**
 *  Triggers an immediate update to the database. It assumes that the update policy is fulfilled.
 */
- (void) triggerUpdate;

@end


/**
 *  GoIndoorBuilder protocol for OYMGoIndoor.
 */
@protocol GoIndoorBuilder <NSObject>
/**
 *  Sets the Goindoor backend URL.
 */
- (void) setURL:(NSString *)_url ;
/**
 *  Sets the profile to be used. Default is user.
 */
- (void) setUser:(NSString *)_user ;
/**
 *  Sets the account.
 */
- (void) setAccount:(NSString *)_account ;
/**
 *  Sets the password.
 */
- (void) setPassword:(NSString *)_password ;
/**
 *  Sets the callback to handle the connection process.
 */
- (void) setConnectCallBack:(void(^)(BOOL succeed, NSString *message))_connectCallback ;
/**
 *  Sets the positioning type. Default is #kOYMGoIndoorLocationTypeAverage.
 */
- (void) setLocationType:(OYMGoIndoorLocationType)_type ;
/**
 *  Sets the update rate in msec. Default is #kOYMGoIndoorDefaultLocationRefresh.
 */
- (void) setLocationUpdate:(long)_refresh ;
/**
 *  Sets the update policy. Default is #(kOYMGoIndoorUpdateWifi | kOYMGoIndoorUpdateMobile).
 */
- (void) setUpdatePolicy:(OYMGoIndoorUpdate)policy;
/**
 *  Sets the database update rate in msec. Default is #kOYMGoIndoorDefaultUpdateTime.
 */
- (void) setDatabaseUpdate:(long)refresh;
/**
 *  Creates a OYMGoIndoor with the arguments supplied to this builder. It will
 * attempt to connect to the database and the outcome will be shown in the provided
 * connect callback
 *
 * @return A OYMGoIndoor object
 */
- (OYMGoIndoor *) build ;

@end

#endif