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

#import <Links/links.h>

#import "NSData+Hex.h"
#import "ESSEddystone.h"


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

/** Key to retrieve the Beacon major from the {@link Item} */
static NSString *const kOYMBeaconKeyMajor = @"major";
/** Key to retrieve the Beacon minor from the {@link Item} */
static NSString *const kOYMBeaconKeyMinor = @"minor";
/** Key to retrieve the Beacon transmission power from the {@link Item} */
static NSString *const kOYMBeaconKeyTx = @"tx";
/** Key to retrieve the Beacon proximity UUID from the {@link Item} */
static NSString *const kOYMBeaconKeyUuid = @"proximityUUID";
/** Key to retrieve the Beacon {@link Building} ID from the {@link Item} */
static NSString *const kOYMBeaconKeyBuilding = @"building";
/** Key to retrieve the Beacon {@link Floor} ID from the {@link Item} */
static NSString *const kOYMBeaconKeyFloor = @"floor";
/** Key to retrieve the Beacon {@link Floor} number from the {@link Item} */
static NSString *const kOYMBeaconKeyFloorNumber = @"floornumber";
/** Key to retrieve the Beacon type from the {@link Item} */
static NSString *const kOYMBeaconKeyType = @"type";
/** Key to retrieve the Beacon status from the {@link Item} */
static NSString *const kOYMBeaconKeyStatus = @"status";
/** Key to retrieve the Beacon warning counter from the {@link Item} */
static NSString *const kOYMBeaconKeyWarningCounter = @"warningCounter";

/**
 *  This class includes all the information regarding the Beacon Items stored
 * in Links.
 */
@interface OYMBeacon : NSObject

#pragma mark Properties
/** OYMLinksItem ID */
@property NSString *uuid;
/** WGS84 Longitude */
@property NSNumber *x;
/** WGS84 Latitude */
@property NSNumber *y;
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
@property NSString *type;
/** Scan Date */
@property NSString *scanDate;
/** Variable defining the Beacon status, if &lt;1 can be used */
@property int status;
/** Warning counter */
@property int warningCounter;

#pragma mark Constructors
/**
 *  Beacon constructor.
 *
 * @param item OYMLinksItem containing the Beacon object
 */
- (instancetype)initWithItem:(OYMLinksItem*)item;
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
/**
 *  This method creates an OYMLinksItem object from an Beacon object.
 *
 * @return The equivalent OYMLinksItem object
 */
- (OYMLinksItem*)toItem;

@end
#endif