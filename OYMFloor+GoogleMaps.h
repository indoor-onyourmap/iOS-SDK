//
//  OYMFloor+GoogleMaps.h
//  Goindoor
//
//  Created by Joan Comellas on 23/03/16.
//  Copyright © 2016 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Goindoor/Goindoor.h>
@import GoogleMaps;


/**
    This category will provided an initialized GMSURLTileLayer to be used in Google Maps.
 */
@interface OYMFloor (GoogleMaps)

/**
   Property that will return a GMSURLTileLayer for the current floor.
 */
@property GMSURLTileLayer *tileProviderGoogle;


@end
