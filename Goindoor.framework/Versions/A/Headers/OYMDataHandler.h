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

#import "OYMGoIndoor.h"
#import "OYMDataServer.h"
#import "OYMSettings.h"
#import "OYMLocationSettings.h"
#import "OYMUserProfile.h"
#import "OYMDataLinks.h"
#import "OYMAsset.h"
#import "OYMProxiBeacon.h"

static const int STATUS_UPDATED                 = 0b000000000000;
static const int STATUS_UPDATE_ALL              = 0b001111111111;
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

@class OYMGoIndoor;

@interface OYMDataHandler : NSObject

- (instancetype) init:(OYMGoIndoor *)_go;

- (void) disconnect;

- (OYMGoIndoor *) getGo ;

- (NSString *) getToken;

// Beacon

- (NSArray *) getBeacons ;

- (OYMBeacon *) getBeacon:(NSString *)identifier ;

- (NSArray *) getBeacons:(NSArray *)identifiers ;

- (void) setBeacons:(NSArray *)_beacons ;

// Buildings

- (NSArray *) getBuildings ;

- (OYMBuilding *) getBuilding:(NSString *)identifier ;

- (NSArray *) getBuildings:(NSArray *)identifiers ;

- (void) setBuildings:(NSArray *)_buildings ;

// Assets

- (NSArray *) getAssets ;

- (OYMAsset *) getAsset:(NSString *)identifier ;

- (void) setAssets:(NSArray *)_assets ;

// Places
- (NSArray *) getPlaces ;

- (void) setPlaces:(NSArray *)_places ;

// Notifications

- (NSArray *) getNotifications ;

- (void) setNotifications:(NSArray *)_notifications ;

// Settings

- (OYMSettings *) getSettings ;

- (void) setSettings:(OYMSettings *)_settings ;

// Edges

- (NSArray *) getEdges ;

- (void) setEdges:(NSArray *)_edges ;

// IndoorSettings

- (OYMLocationSettings *) getIndoorLocationSettings ;

- (void) setIndoorLocationSettings:(OYMLocationSettings *)_settings ;

// UserProfile

- (OYMUserProfile *) getUserProfile ;

- (void) setUserProfile:(OYMUserProfile *)_userProfile ;

- (void) updateUserProfile:(OYMUserProfile *)up ;

// ProxiBeacon

- (NS_ARRAY_OF(OYMProxiBeacon*)*)getProxiBeacons;

- (OYMProxiBeacon*) getProxiBeacon:(NSString *)identifier;

- (void) setProxiBeacons:(NS_ARRAY_OF(OYMProxiBeacon*)*)_beacons;

@end

#endif