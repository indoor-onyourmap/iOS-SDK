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

@interface OYMCircle : OYMGeometry

@property (nonatomic) NS_ARRAY_OF(OYMLatLng*) *coordinates;
@property (nonatomic) double radius;

- (instancetype) initWithCoords:(NS_ARRAY_OF(OYMLatLng*)*)_coordinate andRadius:(double)_radius;

@end

#endif