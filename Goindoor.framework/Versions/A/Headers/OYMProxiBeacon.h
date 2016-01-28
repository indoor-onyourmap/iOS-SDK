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

/** Key to retrieve the Asset place from the {@link Item} */
static NSString * const KEY_PLACE = @"place";

@interface OYMProxiBeacon : OYMBeacon
@property(nonatomic) NSString *place;
/**
 *  OYMProxiBeacon constructor.
 *
 * @param item {@link Item} containing the OYMProxiBeacon object
 */
- (instancetype)initWithItem:(OYMLinksItem *)item;

@end

#endif