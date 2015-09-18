//
//  OYMDataLinks.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 01/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMDATALINKS_H
#define INDOOR_OYMDATALINKS_H

#import <Foundation/Foundation.h>

#import <Links/links.h>

#import "OYMDataServer.h"
#import "OYMDataHandler.h"
#import "OYMBeacon.h"
#import "OYMBuilding.h"

@protocol DataLinksBuilder;

#pragma mark Public Constants
/** Key to retrieve the Building ID from properties */
static NSString *const kOYMDataLinksPropBuilding = @"properties.building";
/** Key to retrieve the type from properties */
static NSString *const kOYMDataLinksPropType = @"properties.type";
/** Key to retrieve the Floor ID from properties */
static NSString *const kOYMDataLinksPropFloor = @"properties.floor";
/** Key to retrieve the Floor ID from properties */
static NSString *const kOYMDataLinksPropFloornumber = @"properties.floornumber";
/** Key to retrieve the name from properties */
static NSString *const kOYMDataLinksPropName = @"properties.name";
/** Key to retrieve the device ID from properties */
static NSString* const kOYMDataLinksPropDeviceId = @"properties.deviceId";

/** String containing the IBeacon type */
#define kOYMDataLinksTypeIbeacon kOYMBeaconType
/** String containing the Building type */
#define kOYMDataLinksTypeBuilding kOYMBuildingType
/** String containing the Floor type */
#define kOYMDataLinksTypeFloor kOYMFloorType
/** String containing the Asset type */
#define kOYMDataLinksTypeAsset kOYMAssetType
/** String containing the Place type */
#define kOYMDataLinksTypePlace kOYMPlaceType
/** String containing the Edge type */
#define kOYMDataLinksTypeEdge kOYMEdgeType
/** String containing the Notification type */
#define kOYMDataLinksTypeNotification kOYMNotificationType
/** String containing the Settings type */
#define kOYMDataLinksTypeSettings kOYMSettingsType
/** String containing the IndoorLocationSettings type */
#define kOYMDataLinksTypeIndoorLocationSettings kOYMLocationSettingsType
/** String containing the IndoorLocationSettings type */
#define kOYMDataLinksTypeUserProfile kOYMUserProfileType

static NSString *const kOYMDataLinksKeyConnect = @"OYMConnect";

static NSString *const kOYMDataLinksKeyGetBeacons = @"OYMGetBeacons";
static NSString *const kOYMDataLinksKeyGetBuildings = @"OYMGetBuilding";
static NSString *const kOYMDataLinksKeyGetFloors = @"OYMGetFloors";
static NSString *const kOYMDataLinksKeyGetAssets = @"OYMGetAssets";
static NSString *const kOYMDataLinksKeyGetPlaces = @"OYMGetPlaces";
static NSString *const kOYMDataLinksKeyGetNotifications = @"OYMGetNotifications";
static NSString *const kOYMDataLinksKeyGetSettings = @"OYMGetSettings";
static NSString *const kOYMDataLinksKeyGetEdges = @"OYMGetEdges";
static NSString *const kOYMDataLinksKeyGetIndoorLocationSettings = @"OYMGetIndoorLocationSettings";
static NSString *const kOYMDataLinksKeyGetUserProfile = @"OYMGetUserProfile";
static NSString *const kOYMDataLinksKeyAutoconnect = @"OYMAutoconnect";
static NSString *const kOYMDataLinksKeyGetBuildingShapes = @"OYMGetBuildingShapes";
static NSString *const kOYMDataLinksKeyUpdateBuilding = @"OYMUpdateBuilding";
static NSString *const kOYMDataLinksKeyGetFloorsPrivate = @"OYMGetFloorsPrivate";
static NSString *const kOYMDataLinksKeyAddIbeacon = @"OYMAddIbeacon";
static NSString *const kOYMDataLinksKeyDeleteIbeacon = @"OYMDeleteIbeacon";
static NSString *const kOYMDataLinksKeyUpdateIbeacon = @"OYMUpdateIbeacon";
static NSString *const kOYMDataLinksKeyUpdateIbeaconPosition = @"OYMUpdateIbeaconPosition";
static NSString *const kOYMDataLinksKeyUpdateIbeaconStatus = @"OYMUpdateIbeaconStatus";
static NSString *const kOYMDataLinksKeyGetEdgesRouting = @"OYMGetEdgesRouting";

static NSString *const kOYMDataLinksKeySearch = @"OYMIndoorSearch";
static NSString *const kOYMDataLinksKeySearchBlock = @"“OYMIndoorSearchBlock”";

static NSString *const kOYMDataLinksGetEvents = @"OYMIndoorGetEvents";
static NSString *const kOYMDataLinksUpdateEvents = @"OYMIndoorUpdateEvents";

#define OYMLinksStatusOk 200

@class OYMDataHandler;

@interface OYMDataLinks : NSObject <LinksProtocol, OYMDataServer>
{
    @package
    OYMDataHandler *dataHandler;
    OYMLinks *oymLinks;
    NSString *sessionId;
    NSString *username;
    NSString *password;
    NSString *workspace;
    void (^connectCallback)(BOOL, NSString *);

    BOOL isDisconnecting;
}

+(OYMDataLinks *)dataLinksWithBlock:(void(^)(id<DataLinksBuilder> builder))block;
/**
 *  Method to perform searches in the server.
 *
 * @param _sessionId Session ID.
 * @param query Search Request to be performed.
 * @param callBackBlocks call back with Results list Array and success flag.
 */
- (void)searchesWithSession:(NSString *)_sessionId andSearchQuery:(OYMSearchQuery *)query withBlock:(void(^)(NSArray *resultList, BOOL success))callBackBlocks;

@end

@protocol DataLinksBuilder <NSObject>

- (void)setDataHandler:(OYMDataHandler *)dh;
/**
 *  Sets the Goindoor backend URL.
 */
- (void)setUrl:(NSString *)_url;
/**
 *  Sets the account.
 */
- (void)setAccount:(NSString *)_account;
/**
 *  Sets the profile to be used. Default is 'user'.
 */
- (void)setProfile:(NSString *)_profile;
/**
 *  Sets the password.
 */
- (void)setPassword:(NSString *)_password;
/**
 *  Creates a {@link OYMDataLinks} with the arguments supplied to this builder. It will
 * attempt to connect to the database and the outcome will be shown in the provided
 * connect callback
 *
 * @return A OYMDataLinks object
 */
- (OYMDataLinks *)build;

@end

#endif