//
//  OYMCombination.h
//  Goindoor
//
//  Created by Joan Marc Comellas on 14/11/16.
//  Copyright © 2016 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMCOMBINATION_H
#define INDOOR_OYMCOMBINATION_H


#import <Foundation/Foundation.h>

#import "OYMJsonProtocol.h"


static NSString *const kOYMCombinationKeyId = @"id";
static NSString *const kOYMCombinationKeyBuilding = @"building";
static NSString *const kOYMCombinationKeyIndicator = @"indicator";
static NSString *const kOYMCombinationKeyEdges = @"edges";


@interface OYMCombination : NSObject <OYMJsonProtocol>

/** Automatically generated UUID */
@property (readonly) NSString* uuid;
/** Building ID */
@property (readonly) NSString* building;
/** Indicator ID */
@property (readonly) NSString* indicator;
/** Edge array */
@property (readonly) NSArray<NSString*>* edges;


@end
#endif
