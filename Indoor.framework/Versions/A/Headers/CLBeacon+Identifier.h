//
//  CLBeacon.h
//  indoor
//
//  Created by onyourmap on 13/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_CLBEACON_IDENTIFIER_H
#define INDOOR_CLBEACON_IDENTIFIER_H

#import <Foundation/Foundation.h>
@import CoreLocation;


@interface CLBeacon (Identifier)


#pragma mark Instance methods
/**
 *  This method provides an identifier for the iBeacon that can be used
 * across the different platforms.
 *
 * @return A unique iBeacon identifier
 */
- (NSString*) getIdentifier;

@end
#endif