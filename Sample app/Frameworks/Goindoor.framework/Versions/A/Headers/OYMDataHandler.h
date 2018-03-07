//
//  OYMDataHandler.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 01/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMDATAHANDLER_H
#define INDOOR_OYMDATAHANDLER_H

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <ZipZap/ZipZap.h>

#import "OYMReachability.h"

#import "OYMGoIndoor.h"
#import "OYMDataServer.h"
#import "OYMSettings.h"
#import "OYMLocationSettings.h"
#import "OYMUserProfile.h"
#import "OYMAsset.h"
#import "OYMProxiBeacon.h"
#import "OYMDataWebservice.h"
#import "OYMNotification.h"
#import "OYMPlace.h"
#import "OYMEdge.h"
#import "OYMBuilding.h"
#import "OYMCombination.h"

static const int STATUS_UPDATED                 = 0b000000000000;
static const int STATUS_UPDATE_ALL              = 0b111111111111;
static const int STATUS_UPDATE_BEACONS          = 0b000000000001;
static const int STATUS_UPDATE_BUILDINGS        = 0b000000000010;
static const int STATUS_UPDATE_ASSETS           = 0b000000000100;
static const int STATUS_UPDATE_PLACES           = 0b000000001000;
static const int STATUS_UPDATE_NOTIFICATIONS    = 0b000000010000;
static const int STATUS_UPDATE_SETTINGS         = 0b000000100000;
static const int STATUS_UPDATE_EDGES            = 0b000001000000;
static const int STATUS_UPDATE_INDOOR_SETTINGS  = 0b000010000000;
static const int STATUS_UPDATE_USER_PROFILE     = 0b000100000000;
static const int STATUS_UPDATE_PROXIBEACON      = 0b001000000000;
static const int STATUS_UPDATE_COMBINATIONS     = 0b010000000000;
static const int STATUS_UPDATE_INDICATORS       = 0b100000000000;

@class OYMGoIndoor;

@interface OYMDataHandler : NSObject

- (instancetype) init:(OYMGoIndoor *)_go;

- (id<OYMDataServer>) getDataServer;

- (void) disconnect;

- (void) triggerUpdate;

- (OYMGoIndoor *) getGo ;

- (NSString *) getToken;

// Beacon

- (NS_ARRAY_OF(OYMBeacon*)*) getBeacons ;

- (OYMBeacon *) getBeacon:(NSString *)identifier ;

- (NS_ARRAY_OF(OYMBeacon*)*) getBeacons:(NS_ARRAY_OF(NSString*)*)identifiers ;

- (void) setBeacons:(NS_ARRAY_OF(OYMBeacon*)*)_beacons andEtag:(NSString *)_etag ;

// Buildings

- (NS_ARRAY_OF(OYMBuilding*)*) getBuildings ;

- (OYMBuilding *) getBuilding:(NSString *)identifier ;

- (NS_ARRAY_OF(OYMBuilding*)*) getBuildings:(NS_ARRAY_OF(NSString*)*)identifiers ;

- (void) setBuildings:(NS_ARRAY_OF(OYMBuilding*)*)_buildings andEtag:(NSString *)_etag ;

// Assets

- (NS_ARRAY_OF(OYMAsset*)*) getAssets ;

- (OYMAsset *) getAsset:(NSString *)identifier ;

- (void) setAssets:(NS_ARRAY_OF(OYMAsset*)*)_assets andEtag:(NSString *)_etag ;

// Places
- (OYMPlace*) getPlace:(NSString*)identifier;

- (NS_ARRAY_OF(OYMPlace*)*) getPlaces ;

- (void) setPlaces:(NS_ARRAY_OF(OYMPlace*)*)_places andEtag:(NSString *)_etag ;

// Notifications

- (NS_ARRAY_OF(OYMNotification*)*) getNotifications ;

- (void) setNotifications:(NS_ARRAY_OF(OYMNotification*)*)_notifications andEtag:(NSString *)_etag ;

// Settings

- (OYMSettings *) getSettings ;

- (void) setSettings:(OYMSettings *)_settings andEtag:(NSString *)_etag ;

// Edges

- (NS_ARRAY_OF(OYMEdge*)*) getEdges ;

- (void) setEdges:(NS_ARRAY_OF(OYMEdge*)*)_edges andEtag:(NSString *)_etag ;

// IndoorSettings

- (OYMLocationSettings *) getIndoorLocationSettings ;

- (void) setIndoorLocationSettings:(OYMLocationSettings *)_settings andEtag:(NSString *)_etag ;

// UserProfile

- (OYMUserProfile *) getUserProfile ;

- (void) setUserProfile:(OYMUserProfile *)_userProfile andEtag:(NSString *)_etag  ;

- (void) setUserProfile:(OYMUserProfile *)_userProfile andEtag:(NSString *)_etag updating:(BOOL)_updating;

- (void) updateUserProfile:(OYMUserProfile *)up ;

// ProxiBeacon

- (NS_ARRAY_OF(OYMProxiBeacon*)*) getProxiBeacons;

- (OYMProxiBeacon*) getProxiBeacon:(NSString *)identifier;

- (void) setProxiBeacons:(NS_ARRAY_OF(OYMProxiBeacon*)*)_beacons andEtag:(NSString *)_etag ;

// Indicators

- (OYMIndicator*) getIndicator:(NSString*)_uuid;
- (void) setIndicators:(NSData*)_data andEtag:(NSString *)_etag ;

// Combinations
- (NS_ARRAY_OF(OYMCombination*)*) getCombinations;
- (OYMCombination*) getCombination:(NSString*)_uuid;
- (void) setCombinations:(NS_ARRAY_OF(OYMCombination*)*)_data andEtag:(NSString *)_etag ;

@end

#endif
