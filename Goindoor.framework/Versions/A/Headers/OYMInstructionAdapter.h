//
//  OYMInstructionAdapter.h
//  Goindoor
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

/**
 *  This method provides a human readable string for each instruction available.
 *
 * @param inst Instruction to be processed
 * @return The instruction string according to the object
 */
+ (NSString*) getStringForInstruction:(OYMInstruction*) inst;
/**
 *  This method provides a human readable string for a specified distance.
 *
 * @param dist Instruction distance
 * @return The distance string according to the object
 */
+ (NSString*) getDistanceString:(int) dist;
/**
 *  This method provides a default image for each instruction.
 *
 * @param inst Instruction to be processed
 * @return The image to be used
 */
+ (UIImage*) getImageForInstruction:(OYMInstruction*) inst;
/**
 *  This method provides a default image to be added as marker for each instruction.
 *
 * @param inst Instruction to be processed
 * @return The map image to be used
 */
+ (UIImage*) getMapImageForInstruction:(OYMInstruction*)inst;

+ (BOOL) isChangeInstruction:(OYMInstruction*)inst;
+ (NSString*) concatInstruction:(OYMInstruction*)ins1 and:(OYMInstruction*)ins2;

@end
#endif
