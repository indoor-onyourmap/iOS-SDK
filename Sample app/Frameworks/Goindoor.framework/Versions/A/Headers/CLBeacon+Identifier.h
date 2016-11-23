//
//  CLBeacon.h
//  Goindoor
//
//  Created by onyourmap on 13/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_CLBEACON_IDENTIFIER_H
#define INDOOR_CLBEACON_IDENTIFIER_H

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/**
 *  This category will add a method to retrieve a unique CLBeacon identifier to be used in the Goindoor location SDK.
 */
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