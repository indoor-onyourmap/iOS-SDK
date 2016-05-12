//
//  OYMPolyline.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 16/02/16.
//  Copyright © 2016 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPOLYLINE_H
#define INDOOR_OYMPOLYLINE_H

#import "OYMGeometry.h"

/**
 *  A line geometry, defined by a list of points
 */
@interface OYMPolyline : OYMGeometry

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
