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

#import "OYMSettings.h"
#import "OYMUserProfile.h"
#import "OYMDataHandler.h"
#import "OYMLogger.h"
#import "OYMRouting.h"
#import "OYMLocationCore.h"

@protocol GoIndoorBuilder;

/** Variable defining the default location update rate in msec */
static const long kOYMGoIndoorDefaultLocationRefresh = 2000; //msec

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
    
    NSString *workspace;
    OYMDataHandler *dataHandler;
    OYMLogger *logger;
    OYMLocationCore *core;

}

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
- (NSArray *) getBeacons ;
/**
 *  Getter for the beacon list.
 *
 * @param identifier Building or floor ID whose beacons need to be retrieved
 * @return Returns The beacons list
 */
- (NSArray *) getBeacon:(NSString *)identifier ;
/**
 *  Getter for the beacon list.
 *
 * @param identifiers Building or floor IDs whose beacons need to be retrieved
 * @return Returns The beacons list
 */
- (NSArray *) getBeacons:(NSArray *)identifiers ;

/**
 *  Getter for the building list.
 *
 * @return Returns The buildings list
 */
- (NSArray *) getBuildings ;
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
- (NSArray *) getBuildings:(NSArray *)identifiers ;

/**
 *  Getter for the asset list.
 *
 * @return Returns The asset list
 */
- (NSArray *) getAssets ;
/**
 *  Getter for the asset list.
 *
 * @param identifiers Building or floor ID whose assets need to be retrieved
 * @return Returns The assets list
 */
- (NSArray *) getAsset:(NSString *)identifier ;
/**
 *  Getter for the asset list.
 *
 * @param identifiers Building or floor IDs whose assets need to be retrieved
 * @return Returns The assets list
 */
- (NSArray *) getAssets:(NSArray *)identifiers ;

/**
 *  Getter for the places list.
 *
 * @return Returns The places list
 */
- (NSArray *) getPlaces ;
/**
 *  Getter for the places list.
 *
 * @param identifiers Building or floor ID whose places need to be retrieved
 * @return Returns The places list
 */
- (NSArray *) getPlace:(NSString *)identifier ;
/**
 *  Getter for the building list.
 *
 * @param identifiers  Building or floor IDs whose places need to be retrieved
 * @return Returns The places list
 */
- (NSArray *) getPlaces:(NSArray *)identifiers ;
/**
 *  Getter for places inside a defined place.
 *
 * @param loc Location whose places needs to be retrieved
 * @param radius Radius from the location. If 0 it will returns the closest one
 * @param tags List of POI tags that should match in the search, it can be nil
 * @param filter Map of POI properties that should match in the search, it can be nil
 * @return The place list satisfying the criteria, sorted by distance
 */
- (NSArray *) getPlacesWithLocationResult:(OYMLocationResult *)loc andRadius:(int)radius andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
/**
 *  Getter for the place list.
 *
 * @param _ID Building or floor ID whose places need to be retrieved
 * @param tags List of POI tags that should match in the search, it can be nil
 * @param filter Map of POI properties that should match in the search, it can be nil
 * @return The place list satisfying the criteria
 */
- (NSArray *) getPlacesWithId:(NSString *)_ID andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
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
- (NSArray *) getPlacesWithLatitude:(double)latitude andLongitude:(double)longitude andRadius:(int)radius andFloorNumber:(int)floorNumber andBuilding:(NSString *)building andTags:(NSArray *)tags andFilter:(NSDictionary *)filter ;
/**
 *  Getter for the notification list.
 *
 * @return Returns The notifications list
 */
- (NSArray *) getNotifications ;
/**
 *  Getter for the notification list.
 *
 * @param identifier Building or floor ID whose notifications need to be retrieved
 * @return Returns The notifications list
*/
- (NSArray *) getNotification:(NSString *)identifier ;
/**
 *  Getter for the notification list.
 *
 * @param identifiers Building or floor IDs whose notifications need to be retrieved
 * @return Returns The notifications list
*/
- (NSArray *) getNotifications:(NSArray *)identifiers ;

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
 *  Sets the positioning type. Default is {@link #LOCATION_TYPE_AVERAGE}.
 */
- (void) setLocationType:(OYMGoIndoorLocationType)_type ;
/**
 *  Sets the update rate in msec. Default is {@link #DEFAULT_LOCATION_REFRESH}.
 */
- (void) setLocationUpdate:(long)_refresh ;

/**
 *  Creates a {@link OYMGoIndoor} with the arguments supplied to this builder. It will
 * attempt to connect to the database and the outcome will be shown in the provided
 * connect callback
 *
 * @return A OYMGoIndoor object
 */
- (OYMGoIndoor *) build ;

@end

#endif