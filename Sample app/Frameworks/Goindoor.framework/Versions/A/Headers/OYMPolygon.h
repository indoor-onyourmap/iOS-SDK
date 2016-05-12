//
//  OYMPolygon.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 27/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPOLYGON_H
#define INDOOR_OYMPOLYGON_H

#import "OYMGeometry.h"

/**
 *  A polygon geometry, defined by a list of points
 */
@interface OYMPolygon : OYMGeometry

/** WGS84 point list */
@property (nonatomic) NS_ARRAY_OF(OYMLatLng*) *coordinates;

/**
 *  Default constructor.
 *
 * @param _coordinate WGS84 point list
 */
- (instancetype) initWithCoords:(NS_ARRAY_OF(OYMLatLng*)*)_coordinate;

@end

#endif