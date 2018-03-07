//
//  OYMIndicator.h
//  Goindoor
//
//  Created by Joan Comellas on 09/08/16.
//  Copyright © 2016 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDICATOR_H
#define INDOOR_OYMINDICATOR_H

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "OYMJsonProtocol.h"


/**
 *  This class includes all the information regarding indicators that can be present in the routing.
 */
@interface OYMIndicator : NSObject <OYMJsonProtocol>

/** Automatically generated UUID */
@property (readonly, nonnull) NSString *uuid;
/** Indicator text */
@property (nonatomic, nullable) NSString *text;
/** Indicator image */
@property (nullable) UIImage *image;
@property BOOL important;

/**
 *  Indicator constructor.
 *
 * @param _uuid Indicator UUID
 */
- (nullable instancetype) initWithUuid:(nonnull NSString*)_uuid;

@end
#endif
