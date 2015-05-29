//
//  OYMInstructionAdapter.h
//  indoor
//
//  Created by Joan Comellas on 17/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINSTRUCTIONADAPTER_H
#define INDOOR_OYMINSTRUCTIONADAPTER_H


#import <Foundation/Foundation.h>
@import UIKit;

#import "OYMInstruction.h"


@interface OYMInstructionAdapter : NSObject

+ (NSString*) getStringForInstruction:(OYMInstruction*) inst;
+ (NSString*) getDistanceString:(int) dist;
+ (UIImage*) getImageForInstruction:(OYMInstruction*) inst;


@end
#endif