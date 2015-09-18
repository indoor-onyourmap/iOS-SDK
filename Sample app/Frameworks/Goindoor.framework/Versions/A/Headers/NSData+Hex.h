//
//  NSData+Hex.h
//  Goindoor
//
//  Created by onyourmap on 16/07/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  This category will help providing a hex representation of the NSData object.
 */
@interface NSData (Hex)

#pragma mark Instance methods
/**
 *  This method provides the hex representation of the data.
 *
 * @return The hex representation of the object
 */
- (NSString*) hexString;

@end
