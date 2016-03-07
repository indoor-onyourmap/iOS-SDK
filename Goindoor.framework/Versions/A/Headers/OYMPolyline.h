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

@interface OYMPolyline : OYMGeometry

@property (nonatomic) NS_ARRAY_OF(OYMLatLng*) *coordinates;

- (instancetype) initWithCoords:(NS_ARRAY_OF(OYMLatLng*)*)_coordinate;

@end

#endif
