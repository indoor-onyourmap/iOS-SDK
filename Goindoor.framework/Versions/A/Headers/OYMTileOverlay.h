//
//  OYMTileOverlay.h
//  Goindoor
//
//  Created by onyourmap on 20/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMTILEOVERLAY_H
#define INDOOR_OYMTILEOVERLAY_H

#import <MapKit/MapKit.h>

@interface OYMTileOverlay : MKTileOverlay {
@private
    NSString* floorId;
}


#pragma mark Constructors
- (instancetype) initWithFloorId:(NSString*)fId;


@end
#endif