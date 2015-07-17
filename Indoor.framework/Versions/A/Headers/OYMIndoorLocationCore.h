//
//  OYMIndoorLocationCore.h
//  indoor
//
//  Created by onyourmap on 16/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONCORE_H
#define INDOOR_OYMINDOORLOCATIONCORE_H

#import <Foundation/Foundation.h>

#import "CLBeacon+Identifier.h"
#import "OYMIbeacon+Beacon.h"

#import "OYMIndoorLoc.h"
#import "OYMIndoorLocationLib.h"
#import "OYMIndoorLocationDelegate.h"
#import "OYMIndoorLocationNotifications.h"

#import "ESSEddystone.h"
#import "ESSBeaconScanner.h"
#import "ESSBeaconInfo+Identifier.h"


#pragma mark Public constants
static long const kOYMIndoorLocationCoreDefaultRefresh = 1000; // msec
static long const kOYMIndoorLocationCoreDbUpdate = 15; // Minutes

#pragma mark Public macros
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define MSEC_TO_SEC(v) v/1000


/**
 *  This class handles the indoor positioning service. Inner methods shall not
 * be accessed to ensure the correct functionality.
 */
@interface OYMIndoorLocationCore : NSObject <OYMIndoorLocDelegate, CLLocationManagerDelegate> {
    @private
    NSString* url;
    NSString* username;
    NSString* password;
    // Refresh time in msec
    long refresh;
    int type;
    id<OYMIndoorLocationDelegate> delegate;
    OYMIndoorLoc *indoor;
    __strong CLLocationManager* locationManager;
    
    // Data
    NSDictionary* dbSnapshot;
    long dbPeriod;
    NSMutableDictionary* emittingBeacons;
    
    OYMIndoorLocation* applePos;
    OYMIndoorLocation* lastPos;
    double lastPosFilter[2];
    long applePosTime;
    long lastPosTime;
    long timeFloorChanged;
    NSNumber *lastFloor;
    long timeLastKnownIbeacon;
    
    NSDictionary *buildingDict;
    int geofenceCount;
    NSMutableArray* geofencesBuildingsId;
    NSMutableArray* ibeaconRegions;
    NSMutableArray* buildingRegions;
    CLBeaconRegion* unknownRegion;
    NSMutableDictionary* unknownIbeacons;
    
    OYMIndoorLocationNotifications* notifications;
    
    // Timers
    NSTimer* timerGetIbeacons;
    NSTimer* timerPos;
    NSTimer* timerStopScan;
    NSTimer* timerUnknownQuery;
    NSTimer* timerStopUnknownScan;
    NSTimer* timerRescan;
    
    // Thresholds
    OYMIndoorLocationSettings* settings;
    
    // Flags
    BOOL isRunning;
    BOOL isScanStarted;
    BOOL isUnknownScanStarted;
    BOOL isUnknownBeingRetrieved;
    
    dispatch_queue_t queue;
}


#pragma mark Constructors
- (instancetype) initWithUrl:(NSString*)webUrl andUser:(NSString*)user andPassword:(NSString*)pwd andRefresh:(long)ref andType:(int)newType withDelegate:(id<OYMIndoorLocationDelegate>)deleg andIndoor:(OYMIndoorLoc*)ind;

#pragma mark Instance methods
- (void) stop;

@end
#endif