//
//  OYMBeacon.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 03/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMBEACON_H
#define INDOOR_OYMBEACON_H

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "OYMConstant.h"

#import "NSData+Hex.h"
#import "ESSEddystone.h"

#import "OYMJsonProtocol.h"

# pragma mark Public constants
/** String containing the Beacon type */
static NSString *const kOYMBeaconType = @"IBEACON";

typedef NS_ENUM(int, BeaconStatus) {
    kOYMBeaconStatusOk = 0, /** Beacon is working */
    kOYMBeaconStatusLowBattery = -1, /** Beacon battery is low */
    kOYMBeaconStatusLost = 1, /** Beacon is lost */
    kOYMBeaconStatusNeedsMaintenance = 2, /** Beacon needs maintenance */
    kOYMBeaconStatusOutOfOrder = 3, /** Beacon is out of order */
    kOYMBeaconStatusNoBattery = 4  /** Beacon battery is empty */
};

/** String containing part of the iBeacon header */
static NSString *const kOYMBeaconIbeaconHeader1 = @"02";
/** String containing part of the iBeacon header */
static NSString *const kOYMBeaconIbeaconHeader2 = @"0215";

/** String containing part of the Eddystone Beacon header */
static NSString *const kOYMBeaconEddystoneHeader1 = @"0201060303AAFE";
/** String containing part of the Eddystone Beacon header */
static NSString *const kOYMBeaconEddystoneHeader2 = @"16AAFE";
/** String containing the Eddystone-UID Frame Type */
static NSString *const kOYMBeaconEddystoneFrameUID = @"00";

/** Key to retrieve the Beacon uuid */
static NSString *const kOYMBeaconKeyId = @"id";
/** Key to retrieve the Beacon major */
static NSString *const kOYMBeaconKeyMajor = @"major";
/** Key to retrieve the Beacon minor */
static NSString *const kOYMBeaconKeyMinor = @"minor";
/** Key to retrieve the Beacon longitude */
static NSString *const kOYMBeaconKeyLongitude = @"longitude";
/** Key to retrieve the Beacon latitude */
static NSString *const kOYMBeaconKeyLatitude = @"latitude";
/** Key to retrieve the Beacon transmission power */
static NSString *const kOYMBeaconKeyTx = @"tx";
/** Key to retrieve the Beacon proximity UUID */
static NSString *const kOYMBeaconKeyUuid = @"uuid";
/** Key to retrieve the Beacon Building ID */
static NSString *const kOYMBeaconKeyBuilding = @"building";
/** Key to retrieve the Beacon Floor ID */
static NSString *const kOYMBeaconKeyFloor = @"floor";
/** Key to retrieve the Beacon Floor number */
static NSString *const kOYMBeaconKeyFloorNumber = @"floorNumber";
/** Key to retrieve the Beacon type */
static NSString *const kOYMBeaconKeyType = @"type";
/** Key to retrieve the Beacon status */
static NSString *const kOYMBeaconKeyStatus = @"status";
/** Key to retrieve the Beacon warning counter */
static NSString *const kOYMBeaconKeyWarningCounter = @"warningCounter";
/** Key to retrieve the Beacon ScanDate */
static NSString *const kOYMBeaconKeyScanDate = @"scanDate";

/**
 *  This class includes all the information regarding the Beacon Items stored.
 */
@interface OYMBeacon : NSObject <OYMJsonProtocol>

#pragma mark Properties
/** Automatically generated UUID */
@property NSString *uuid;
/** WGS84 Longitude */
@property (nonatomic) NSNumber *x DEPRECATED_MSG_ATTRIBUTE("Use longitude instead.");
/** WGS84 Latitude */
@property (nonatomic) NSNumber *y  DEPRECATED_MSG_ATTRIBUTE("Use latitude instead.");
/** WGS84 Longitude */
@property NSNumber *longitude;
/** WGS84 Latitude */
@property NSNumber *latitude;
/** Beacon major */
@property NSNumber *major;
/** Beacon minor */
@property NSNumber *minor;
/** Transmission power at 1m */
@property NSNumber *txPower;
/** Beacon proximity UUID */
@property NSString *uuidBeacon;
/** Building ID */
@property NSString *building;
/** Floor ID */
@property NSString *floor;
/** Floor number */
@property NSNumber *floorNumber;
/** String defining the Beacon type */
@property NSString *type DEPRECATED_ATTRIBUTE;
/** Scan Date */
@property NSString *scanDate;
/** Variable defining the Beacon status, if &lt;1 can be used */
@property int status;
/** Warning counter */
@property int warningCounter;

#pragma mark Constructors

/**
 *  Eddystone Beacon partial constructor. Should not be used.
 *
 * @param eddystone Eddystone Beacon
 */
- (instancetype) initWithEddystone:(ESSBeaconInfo *)eddystone __deprecated_msg("Partial constructor");

#pragma mark Class methods
/**
 *  This methods sort an array of OYMBeacon according to its minor number.
 *
 * @param Beacons Array of OYMBeacon
 * @return A sorted array, <tt>nil</tt> if a problem arouse while sorting
 */
+ (NSArray*) sort:(NSArray*)Beacons;


#pragma mark Instance methods
/**
 *  This method provides an identifier for the Beacon that can be used
 * across the different platforms.
 *
 * @return A unique Beacon identifier
 */
- (NSString*)getIdentifier;

@end
#endif