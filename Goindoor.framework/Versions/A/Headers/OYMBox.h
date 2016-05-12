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

/**
 *  A bounding box, defined by its bottom left corner and its upper right corner.
 */
@interface OYMBox : OYMGeometry

/** WGS84 bottom left position */
@property (nonatomic) OYMLatLng *bottomLeft;
/** WGS84 upper right position */
@property (nonatomic) OYMLatLng *upperRight;

/**
 *  Default construction.
 *
 * @param bl WGS84 bottom left position
 * @param ur WGS84 upper right position
 */
- (instancetype)initWithBottomLeft:(OYMLatLng*)bl andUpperRight:(OYMLatLng*)ur;

@end

#endif