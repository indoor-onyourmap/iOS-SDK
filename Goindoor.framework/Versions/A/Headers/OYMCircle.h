//
//  OYMCircle.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 27/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMCIRCLE_H
#define INDOOR_OYMCIRCLE_H

#import "OYMGeometry.h"

/**
 *  A circle geometry, defined by its center and its radius.
 */
@interface OYMCircle : OYMGeometry

/** WGS84 center position */
@property (nonatomic) NS_ARRAY_OF(OYMLatLng*) *coordinates;
/** Radius in meters */
@property (nonatomic) double radius;

/**
 *  Default constructor.
 *
 * @param _coordinate WGS84 center position
 * @param _radius Radius in meters
 */
- (instancetype) initWithCoords:(NS_ARRAY_OF(OYMLatLng*)*)_coordinate andRadius:(double)_radius;

@end

#endif