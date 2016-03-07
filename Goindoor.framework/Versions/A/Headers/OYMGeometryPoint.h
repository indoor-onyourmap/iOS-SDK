//
//  OYMGeometryPoint.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 27/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMGEOMETRYPOINT_H
#define INDOOR_OYMGEOMETRYPOINT_H

#import "OYMGeometry.h"

@interface OYMGeometryPoint : OYMGeometry

@property (nonatomic) NS_ARRAY_OF(OYMLatLng*) *coordinates;

- (instancetype) initWithCoords:(NS_ARRAY_OF(OYMLatLng*)*)_coordinate;

@end

#endif