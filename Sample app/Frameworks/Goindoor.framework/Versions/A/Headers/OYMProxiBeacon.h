//
//  OYMProxiBeacon.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 28/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPROXIBEACON_H
#define INDOOR_OYMPROXIBEACON_H

#import "OYMBeacon.h"
#import "OYMConstant.h"

/** String containing the Asset type */
static NSString * const kOYMProxiBeaconType = @"PROXIBEACON";

/** Key to retrieve the Asset place */
static NSString *const kOYMProxiBeaconKeyPlace = @"place";

@interface OYMProxiBeacon : OYMBeacon <OYMJsonProtocol>
@property(nonatomic) NSString *place;

@end

#endif