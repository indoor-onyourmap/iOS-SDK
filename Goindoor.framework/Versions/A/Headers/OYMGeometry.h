//
//  OYMGeometry.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 27/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMGEOMETRY_H
#define INDOOR_OYMGEOMETRY_H

#import <Foundation/Foundation.h>

#import <CoreLocation/CoreLocation.h>

#import "OYMConstant.h"
#import "OYMJsonProtocol.h"

static NSString * const TYPE_BOX = @"box";
static NSString * const TYPE_CIRCLE = @"circle";
static NSString * const TYPE_POINT = @"point";
static NSString * const TYPE_POLYGON = @"polygon";
static NSString * const TYPE_POLYLINE = @"polyline";

/**
 *  This class encapsulates a WGS84 Latitude and Longitude in one object.
 */
@interface OYMLatLng : NSObject

/** WGS84 Longitude */
@property (nonatomic) double longitude;
/** WGS84 Latitude */
@property (nonatomic) double latitude;
/**
 *  Default constructor.
 *
 * @param lat WGS84 Latitude
 * @param lon WGS84 Longitude
 */
- (instancetype) initWithLatitude:(double)lat andLongitude:(double)lon;
/**
 *  Getter for the CLLocationCoordinate2D object.
 *
 * @return The corresponding CLLocationCoordinate2D object
 */
- (CLLocationCoordinate2D) getCLLocationCoordinate2D;

@end

/**
 *  This abstract class includes all the geometry information.
 */
@interface OYMGeometry : NSObject<OYMJsonProtocol>
@property (nonatomic) NSString *type;

- (NS_ARRAY_OF(NSNumber*)*) latLngSingleSerializer:(OYMLatLng*)latLng;
- (OYMLatLng*) latLngSingleDeserializer:(NS_ARRAY_OF(NSNumber*)*)jp;
- (NS_ARRAY_OF(NSNumber*)*) latLngArraySerializer:(NS_ARRAY_OF(OYMLatLng*)*)value;
- (NS_ARRAY_OF(OYMLatLng*)*) latLngArrayDeserializer:(NS_ARRAY_OF(NSNumber*)*)jp;

@end

#endif