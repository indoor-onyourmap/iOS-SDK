//
//  OYMLocationSettings.h
//  Goindoor
//
//  Created by onyourmap on 05/02/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONSETTINGS_H
#define INDOOR_OYMINDOORLOCATIONSETTINGS_H

#import <Foundation/Foundation.h>

#import <Links/links.h>


#pragma mark Public constants
// String containing the IBeacon type */
static NSString* const kOYMLocationSettingsType = @"INDOORLOCATIONSETTINGS";

// Key to retrieve the Accuracy threshold to change to GPS from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyAccuracy = @"gpsAccuracy";
// Key to retrieve the Filter alpha threshold from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyFilterAlpha = @"filterAlpha";
// Key to retrieve the Maximum distance between iBeacons threshold from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyMaxIbeaconDistance = @"maxIbeaconDistance";
// Key to retrieve the RSSI threshold from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyRssi = @"rssi";
// Key to retrieve the Time threshold to change to GPS from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyTime = @"gpsTime";
// Key to retrieve the Time threshold to change floors from the {@link Item} */
static NSString* const kOYMLocationSettingsKeyTimeChangeFloor = @"timeChangeFloor";
// Key to retrieve the time threshold to stop the BLE scan after not hearing any known iBeacon */
static NSString* const kOYMLocationSettingsKeyTimeLastKnown = @"timeLastKnown";
// Key to retrieve the time duration where a new unknown scan can be done */
static NSString* const kOYMLocationSettingsKeyTimeUnknownDiscovery = @"timeUnknownDiscovery";
// Key to retrieve the time threshold where the unknown queries can be done to the server */
static NSString* const kOYMLocationSettingsKeyTimeUnknownQuery = @"timeUnknownQuery";
// Key to retrieve the time threshold to perform a new unknown scan after stopping the BLE scan */
static NSString* const kOYMLocationSettingsKeyTimeUnknownRescan = @"timeUnknownRescan";
// Key to retrieve the time threshold to stop the known BLE scan */
static NSString* const kOYMLocationSettingsKeyTimeStopScan = @"timeStopScan";
// Key to retrieve the proximity UUID used in the scan */
static NSString* const kOYMLocationSettingsKeyUsedProximityUuid = @"usedProximityUuid";

static NSString* const kOYMLocationSettingsPropType = @"properties.type";


# pragma mark Macros
#define MIN_TO_MSEC(mi) mi*60*1000
#define SEC_TO_MSEC(se) se*1000


@interface OYMLocationSettings : NSObject

@property (readonly) double gpsAccuracy;
@property (readonly) long gpsTime;
@property (readonly) double filterAlpha;
@property (readonly) double maxIbeaconDistance;
@property (readonly) int rssi;
@property (readonly) long timeChangeFloor;
@property (readonly) long timeLastKnown;
@property (readonly) long timeUnknownDiscovery;
@property (readonly) long timeUnknownQuery;
@property (readonly) long timeUnknownRescan;
@property (readonly) long timeStopScan;
@property (readonly) NSUUID* usedProximityUuid;


#pragma mark Constructors
/**
 *  OYMLocationSettings constructor.
 *
 * @return Return the OYMLocationSettings Object
 */
- (instancetype) init;
/**
 *  OYMLocationSettings constructor.
 *
 * @param item {@link OYMLinksItem} containing the Settings object
 * @return Return the OYMLocationSettings Object
 */
- (instancetype) initWithItem:(OYMLinksItem*) item;


@end
#endif