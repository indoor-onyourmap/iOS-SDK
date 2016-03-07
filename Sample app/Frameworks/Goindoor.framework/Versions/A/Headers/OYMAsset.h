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
#import "OYMUtils.h"
#import "OYMConstant.h"

/** String containing the Asset type */
static NSString* const kOYMAssetType = @"ASSET";

@interface OYMAsset : OYMBeacon <OYMJsonProtocol>

/** The Asset accuracy in meters */
@property (nonatomic, assign) int accuracy;
/** The Asset accuracy timestamp */
@property (nonatomic) NSString *timestamp DEPRECATED_MSG_ATTRIBUTE("Use accuracyTime instead.");
/** The Asset accuracy timestamp */
@property (nonatomic) NSString *accuracyTime;
/** The Asset name */
@property (nonatomic) NSString *name;
/** The Asset place ID */
@property (nonatomic) NSString *place;
/** The Asset properties */
@property (nonatomic) NS_DICTIONARY_OF(NSString*, NSString*) *properties;

- (instancetype) initWithBeacon:(OYMBeacon *)beacon;

/*
 *  This method updates the location and accuracy of the asset internally.
 *
 * @param x Longitude
 * @param y Latitude
 * @param accuracy Accuracy in meters
 */
- (void) updatePositionX:(NSNumber *)_x andY:(NSNumber *)_y andAccuracy:(int)_accuracy DEPRECATED_MSG_ATTRIBUTE("Use updateLatitude:andLongitude:andAccuracy: method instead.");
/**
 *  This method updates the location and accuracy of the asset internally.
 *
 * @param _latitude Latitude
 * @param _longitude Longitude
 * @param accuracy Accuracy in meters
 */
- (void) updateLatitude:(NSNumber *)_latitude andLongitude:(NSNumber *)_longitude andAccuracy:(int)_accuracy;

@end

#endif