//
//  OYMBox.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 27/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMBOX_H
#define INDOOR_OYMBOX_H

#import "OYMGeometry.h"

@interface OYMBox : OYMGeometry

@property (nonatomic) OYMLatLng *bottomLeft;
@property (nonatomic) OYMLatLng *upperRight;

- (instancetype)initWithBottomLeft:(OYMLatLng*)bl andUpperRight:(OYMLatLng*)ur;

@end

#endif