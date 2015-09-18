//
//  ESSBeaconInfo+Identifier.h
//  Goindoor
//
//  Created by Joan Comellas on 17/07/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESSEddystone.h"
#import "OYMBeacon.h"


/**
 *  This category will add a method to retrieve a unique ESSBeaconInfo identifier to be used in the Goindoor location SDK.
 */
@interface ESSBeaconInfo (Identifier)

#pragma mark Instance methods
/**
 *  This method provides an identifier for the iBeacon that can be used
 * across the different platforms.
 *
 * @return A unique iBeacon identifier
 */
- (NSString*) getIdentifier;


@end
