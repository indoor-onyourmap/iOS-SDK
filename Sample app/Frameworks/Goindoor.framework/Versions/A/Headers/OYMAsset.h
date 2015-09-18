//
//  OYMAsset.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 03/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMASSET_H
#define INDOOR_OYMASSET_H

#import <Foundation/Foundation.h>

#import "OYMBeacon.h"

/** String containing the Asset type */
static NSString* const kOYMAssetType = @"ASSET";

@interface OYMAsset : OYMBeacon

/** The Asset accuracy in meters */
@property (nonatomic, assign) int accuracy;
/** The Asset accuracy timestamp */
@property (nonatomic) NSDate *timestamp;
/** The Asset name */
@property (nonatomic) NSString *name;
/** The Asset place ID */
@property (nonatomic) NSString *place;
/** The Asset properties */
@property (nonatomic) NSDictionary *properties;

/**
 *  OYMAsset constructor.
 *
 * @param item {@link OYMLinksItem} containing the OYMAsset object
 */
- (instancetype) initWithItem:(OYMLinksItem *)item;

- (instancetype) initWithBeacon:(OYMBeacon *)beacon;

/**
 *  This method creates an {@link OYMLinksItem} object from an OYMAsset object.
 *
 * @return The equivalent {@link OYMLinksItem} object
 */

-(OYMLinksItem *)toItem;

/**
 *  This method updates the location and accuracy of the asset internally.
 *
 * @param x Longitude
 * @param y Latitude
 * @param accuracy Accuracy in meters
 */
- (void) updatePositionX:(NSNumber *)_x andY:(NSNumber *)_y andAccuracy:(int)_accuracy;

@end

#endif