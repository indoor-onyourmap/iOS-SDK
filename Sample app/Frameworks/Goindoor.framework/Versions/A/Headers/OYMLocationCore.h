//
//  OYMLocationCore.h
//  Goindoor
//
//  Created by onyourmap on 16/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONCORE_H
#define INDOOR_OYMINDOORLOCATIONCORE_H

#import <Foundation/Foundation.h>

#import "CLBeacon+Identifier.h"
#import "OYMBeacon+Beacon.h"

#import "OYMLocationDelegate.h"
#import "OYMLocationNotifications.h"
#import "OYMLocationSettings.h"
#import "OYMLocationAssets.h"
#import "OYMLocationMaintenance.h"

#import "ESSEddystone.h"
#import "ESSBeaconScanner.h"
#import "ESSBeaconInfo+Identifier.h"


#pragma mark Public constants
static long const kOYMLocationCoreDefaultRefresh = 1000; // msec
static long const kOYMLocationCoreDbUpdate = 15; // Minutes

#pragma mark Public macros
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define MSEC_TO_SEC(v) v/1000

NS_ASSUME_NONNULL_BEGIN
@class OYMLocationNotifications, OYMDataHandler, OYMGoIndoor, OYMLocationMaintenance, OYMLocationAssets;

/**
 *  This class handles the Goindoor positioning service. Inner methods shall not
 * be accessed to ensure the correct functionality.
 */
@interface OYMLocationCore : NSObject <CLLocationManagerDelegate> {
@private
    NSString* url;
    NSString* username;
    NSString* password;
    // Refresh time in msec
    long refresh;
    id<OYMLocationDelegate> delegate;
    __strong CLLocationManager* locationManager;
    
    OYMGoIndoor *goIndoor;
    
    // Data
    NSDictionary* dbSnapshot;
    long dbPeriod;
    NSMutableDictionary* emittingBeacons;
    NSMutableDictionary* emittingPossibleAssets;
    
    OYMLocationResult* applePos;
    OYMLocationResult* lastPos;
    double lastPosFilter[2];
    long applePosTime;
    long lastPosTime;
    long timeFloorChanged;
    NSNumber *lastFloor;
    NSString *lastFloorId;
    long timeLastKnownIbeacon;
    long timeLastProxiBeacon;
    
    NSDictionary *buildingDict;
    int geofenceCount;
    NSMutableArray* geofencesBuildingsId;
    NSMutableArray* ibeaconRegions;
    NSMutableArray* buildingRegions;
    CLBeaconRegion* unknownRegion;
    NSMutableDictionary* unknownIbeacons;
    
    OYMLocationNotifications* notifications;
    OYMLocationMaintenance *maintenance;
    OYMLocationAssets *assets;
    
    // Timers
    NSTimer* timerGetIbeacons;
    NSTimer* timerPos;
    NSTimer* timerStopScan;
    NSTimer* timerUnknownQuery;
    NSTimer* timerStopUnknownScan;
    NSTimer* timerRescan;
    
    // Thresholds
    OYMLocationSettings* settings;
    
    // Flags
    BOOL isRunning;
    BOOL isScanStarted;
    BOOL isUnknownScanStarted;
    BOOL isUnknownBeingRetrieved;
    
    dispatch_queue_t queue;
}

@property (nonatomic, assign) int type;

#pragma mark Constructors
- (instancetype) initWithUrl:(NSString*)webUrl andUser:(NSString*)user andPassword:(NSString*)pwd andRefresh:(long)ref andType:(int)newType andGoIndoor:(OYMGoIndoor *)go andCBOptions:(nullable NSDictionary<NSString *, id> *)options withDelegate:(id<OYMLocationDelegate>)deleg;

#pragma mark Instance methods
- (BOOL) startWithIndorLocationSettings:(OYMLocationSettings*)se ;

- (void) stop;

@end
NS_ASSUME_NONNULL_END
#endif
