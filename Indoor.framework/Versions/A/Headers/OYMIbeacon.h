//
//  OYMIbeacon.h
//  indoor
//
//  Created by onyourmap on 10/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMIBEACON_H
#define INDOOR_OYMIBEACON_H

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import <Links/links.h>

#import "NSData+Hex.h"
#import "ESSEddystone.h"


# pragma mark Public constants
/** String containing the IBeacon type */
static NSString *const kOYMIbeaconType = @"IBEACON";

/** String containing the Eddystone Service UUID */
static NSString *const kOYMIbeaconEddystoneServiceUuid = @"FEAA";

/** Key to retrieve the IBeacon major from the {@link Item} */
static NSString *const kOYMIbeaconKeyMajor = @"major";
/** Key to retrieve the IBeacon minor from the {@link Item} */
static NSString *const kOYMIbeaconKeyMinor = @"minor";
/** Key to retrieve the IBeacon transmission power from the {@link Item} */
static NSString *const kOYMIbeaconKeyTx = @"tx";
/** Key to retrieve the IBeacon proximity UUID from the {@link Item} */
static NSString *const kOYMIbeaconKeyUuid = @"proximityUUID";
/** Key to retrieve the IBeacon {@link Building} ID from the {@link Item} */
static NSString *const kOYMIbeaconKeyBuilding = @"building";
/** Key to retrieve the IBeacon {@link Floor} ID from the {@link Item} */
static NSString *const kOYMIbeaconKeyFloor = @"floor";
/** Key to retrieve the IBeacon {@link Floor} number from the {@link Item} */
static NSString *const kOYMIbeaconKeyFloornumber = @"floornumber";
/** Key to retrieve the IBeacon type from the {@link Item} */
static NSString *const kOYMIbeaconKeyType = @"type";
/** Key to retrieve the IBeacon status from the {@link Item} */
static NSString *const kOYMIbeaconKeyStatus = @"status";

/** iBeacon is working */
static int const kOYMIbeaconStatusOk = 0;
/** iBeacon battery is low */
static int const kOYMIbeaconStatusLowBattery = -1;
/** iBeacon is lost */
static int const kOYMIbeaconStatusLost = 1;
/** iBeacon needs maintenance */
static int const kOYMIbeaconStatusNeedsMaintenance = 2;
/** iBeacon is out of order */
static int const kOYMIbeaconStatusOutOfOrder = 3;
/** iBeacon battery is empty */
static int const kOYMIbeaconStatusNoBattery = 4;

/**
 *  This class includes all the information regarding the iBeacon Items stored
 * in Links.
 */
@interface OYMIbeacon : NSObject 

#pragma mark Properties
/** OYMLinksItem ID */
@property NSString *uuid;
/** WGS84 Longitude */
@property NSNumber *x;
/** WGS84 Latitude */
@property NSNumber *y;
/** iBeacon major */
@property NSNumber *major;
/** iBeacon minor */
@property NSNumber *minor;
/** Transmission power at 1m */
@property NSNumber *txPower;
/** iBeacon proximity UUID */
@property NSString *uuidIbeacon;
/** Building ID */
@property NSString *building;
/** Floor ID */
@property NSString *floor;
/** Floor number */
@property NSNumber *floornumber;
/** String defining the Ibeacon type */
@property NSString *type;
/** Scan Date */
@property NSString *scanDate;
/** Variable defining the iBeacon status, if &lt;1 can be used */
@property int status;


#pragma mark Constructors
/**
 *  IBeacon constructor.
 *
 * @param item OYMLinksItem containing the IBeacon object
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
 *  This methods sort an array of OYMIbeacon according to its minor number.
 *
 * @param ibeacons Array of OYMIbeacon
 * @return A sorted array, <tt>nil</tt> if a problem arouse while sorting
 */
+ (NSArray*) sort:(NSArray*)ibeacons;


#pragma mark Instance methods
/**
 *  This method provides an identifier for the iBeacon that can be used
 * across the different platforms.
 *
 * @return A unique iBeacon identifier
 */
- (NSString*)getIdentifier;
/**
 *  This method creates an OYMLinksItem object from an IBeacon object.
 *
 * @return The equivalent OYMLinksItem object
 */
- (OYMLinksItem*)toItem;

@end
#endif