//
//  OYMIndoor.h
//  indoor
//
//  Created by onyourmap on 11/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOOR_H
#define INDOOR_OYMINDOOR_H

#import <Foundation/Foundation.h>

#import <Links/links.h>

#import "OYMBuilding.h"
#import "OYMFloor.h"
#import "OYMIbeacon.h"
#import "OYMIndoorDelegate.h"

#pragma mark Public constants
/** Key to retrieve the Building ID from properties */
static NSString *const kOYMIndoorPropBuilding = @"properties.building";
/** Key to retrieve the type from properties */
static NSString *const kOYMIndoorPropType = @"properties.type";
/** Key to retrieve the Floor ID from properties */
static NSString *const kOYMIndoorPropFloor = @"properties.floor";
/** Key to retrieve the Floor ID from properties */
static NSString *const kOYMIndoorPropFloornumber = @"properties.floornumber";
/** Key to retrieve the name from properties */
static NSString *const kOYMIndoorPropName = @"properties.name";

/** String containing the IBeacon type */
#define kOYMIndoorTypeIbeacon kOYMIbeaconType
/** String containing the Building type */
#define kOYMIndoorTypeBuilding kOYMBuildingType
/** String containing the Floor type */
#define kOYMIndoorTypeFloor kOYMFloorType

/** RSSI value to identify that an iBeacon is in the immediate range */
static int const kOYMIndoorRssiImmediateThreshold = -55;
/** Time delay to ensure that only one iBeacon is detected in immediate range */
static long const kOYMIndoorScanDelayAfterImmediate = 3000; // msec
/** Time delay to detect iBeacons */
static long const kOYMIndoorScanDelayNoImmediate = 10000; // msec

/** Default number of reconnection attempts */
static int const kOYMIndoorDefaultReconnectAttempts = 3;
/** Exception message when the connection to the server cannot be reestablished */
static NSString *const kOYMIndoorExceptionImpossibleConnect = @"Impossible to connect";
/** Exception message when there are no buildings saved in the server */
static NSString *const kOYMIndoorExceptionNoBuildings = @"No Buildings";

/** Message retrieved from links when the session has expired */
static NSString *const kOYMIndoorLinksSessionExpired = @"session expired";
static int const kOYMIndoorLinksMaxBucketSize = 10000;

static NSString *const kOYMIndoorKeyConnect = @"OYMConnect";
static NSString *const kOYMIndoorKeyAutoconnect = @"OYMAutoconnect";
static NSString *const kOYMIndoorKeyGetBuildingSearch = @"OYMGetBuildingSearch";
static NSString *const kOYMIndoorKeyGetBuildingShapes = @"OYMGetBuildingShapes";
static NSString *const kOYMIndoorKeyUpdateBuilding = @"OYMUpdateBuilding";
static NSString *const kOYMIndoorKeyGetFloors = @"OYMGetFloors";
static NSString *const kOYMIndoorKeyGetFloorsPrivate = @"OYMGetFloorsPrivate";
static NSString *const kOYMIndoorKeyGetIbeacons = @"OYMGetIbeacons";
static NSString *const kOYMIndoorKeyAddIbeacon = @"OYMAddIbeacon";
static NSString *const kOYMIndoorKeyDeleteIbeacon = @"OYMDeleteIbeacon";
static NSString *const kOYMIndoorKeyUpdateIbeacon = @"OYMUpdateIbeacon";


static NSString *const kOYMIndoorKeyUpdateIbeaconPosition = @"OYMUpdateIbeaconPosition";
static NSString *const kOYMIndoorKeyUpdateIbeaconStatus = @"OYMUpdateIbeaconStatus";


#define OYMLinksStatusOk 200


/**
 *  This class includes all the interface with the server, its calls and its
 * callbacks.
 */
@interface OYMIndoor : NSObject <LinksProtocol> {
    @protected
    OYMLinks *oymLinks;
    NSString *sessionId;
    NSString *username;
    NSString *password;
    NSString *workspace;
    int reconnectMaxAttemps;
    int reconnectCurrentAttempt;
    id<OYMIndoorDelegate> delegate;
}


#pragma mark Constructors
/**
 *  Indoor constructor without reconnection.
 *
 * @param url URL to the server
 * @param user User name
 * @param pwd Password
 * @param deleg Delegate to handle the process
 */
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id<OYMIndoorDelegate>)deleg;
/**
 *  Indoor constructor with reconnection, kOYMIndoorDefaultReconnectAttempts attempts if enabled.
 *
 * @param url URL to the server
 * @param user User name
 * @param pwd Password
 * @param deleg Delegate to handle the process
 * @param ac Flag to enable autoconnect
 */
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id<OYMIndoorDelegate>)deleg withAutoconnect:(BOOL)ac;
/**
 *  Indoor constructor with reconnection.
 *
 * @param url URL to the server
 * @param user User name
 * @param pwd Password
 * @param deleg Delegate to handle the process
 * @param attempts Number of reconnection attempts
 */
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id<OYMIndoorDelegate>)deleg withAutoconnectAttempts:(int)attempts;


#pragma mark Instance methods
/**
 *  Method to disconnect from the server.
 */
- (void) disconnect;
/**
 *  Method to refresh the connection with the server.
 */
- (void) refresh;
/**
 *  Method to retrieve the building list.
 */
- (void) getBuildings;
/**
 *  Method to retrieve the building list.
 *
 * @param buildingIdList List of the Building ID that needs to be retrieved
 */
- (void) getBuildingsWithArray:(NSArray*)buildingIdList;
/**
 *  Method to retrieve the building list.
 *
 * @param boundingBox Bounding box to limit the search
 */
- (void) getBuildingsWithBoundingBox:(NSString*)boundingBox;
/**
 *  Method to retrieve the building list.
 *
 * @param buildingIdList List of the Building ID that needs to be retrieved
 * @param boundingBox Bounding box to limit the search
 */
- (void) getBuildingsWithArray:(NSArray *)buildingIdList andBoundingBox:(NSString*)boundingBox;
/**
 *  Method to retrieve the building list.
 *
 * @param buildingIdList List of the Building ID that needs to be retrieved
 * @param boundingBox Bounding box to limit the search
 * @param offset List offset to be retrieved
 * @param bucketSize Number of elements to be retrieved
 */
- (void) getBuildingsWithArray:(NSArray*)buildingIdList andBoundingBox:(NSString*)boundingBox andOffset:(int)offset andBucketSize:(int)bucketSize;
/**
 *  Method to add or update a building to the server.
 *
 * @param building Building to be added or updated
 */
- (void) updateBuilding:(OYMBuilding*)building;
/**
 *  Method to retrieve the floor list.
 *
 * @param building Building whose floors are needed
 */
- (void) getFloorsForBuilding:(OYMBuilding*)building;
/**
 *  Method to retrieve the iBeacon list.
 *
 * @param uuid Building or Floor ID whose iBeacons are requested
 */
- (void) getIbeaconsForUuid:(NSString*)uuid;
/**
 *  Method to retrieve the iBeacon list.
 *
 * @param ids Building or Floor ID array whose iBeacons are requested
 */
- (void) getIbeaconsForArray:(NSArray*) ids;

/**
 *  Method to add an iBeacon to the server.
 *
 * @param iBeacon iBeacon to be added
 */
- (void) addIbeacon:(OYMIbeacon*)iBeacon;
/**
 *  Method to remove an iBeacon from the server.
 *
 * @param iBeacon iBeacon to be removed
 */
- (void) deleteIbeacon:(OYMIbeacon*)iBeacon;
/**
 *  Method to update the live data properties from an iBeacon from the server.
 *
 * @param iBeacon iBeacon to be updated
 * @param type Information to be updated
 */
- (void) updateIbeacon:(OYMIbeacon*)iBeacon forType:(NSString*)type;

@end

#endif