//
//  OYMInstruction.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMInstruction_h
#define indoor_OYMInstruction_h

#import "OYMJsonProtocol.h"
#import "OYMDataHandler.h"
@class OYMDataHandler;
#import "OYMIndicator.h"


/** Enumeration containing all the instructions */
typedef enum {
    TURNLEFT,
    TURNRIGHT,
    DOWNSTAIRS,
    UPSTAIRS,
    DOWNELEVATOR,
    UPELEVATOR,
    DOWNESCALATOR,
    UPESCALATOR,
    ARRIVAL,
    STRAIGHT,
    
    TURNLEFTTHENLEFT,
    TURNLEFTTHENRIGHT,
    TURNRIGHTTHENLEFT,
    TURNRIGHTTHENRIGHT,
    TURNLEFTTHENDOWNSTAIRS,
    TURNRIGHTTHENDOWNSTAIRS,
    TURNLEFTTHENUPSTAIRS,
    TURNRIGHTTHENUPSTAIRS,
    TURNLEFTTHENDOWNELEVATOR,
    TURNRIGHTTHENDOWNELEVATOR,
    TURNLEFTTHENUPELEVATOR,
    TURNRIGHTTHENUPELEVATOR,
    TURNLEFTTHENDOWNESCALATOR,
    TURNRIGHTTHENDOWNESCALATOR,
    TURNLEFTTHENUPESCALATOR,
    TURNRIGHTTHENUPESCALATOR,
    STRAIGHTTHENDOWNSTAIRS,
    STRAIGHTTHENUPSTAIRS,
    STRAIGHTTHENDOWNELEVATOR,
    STRAIGHTTHENUPELEVATOR,
    STRAIGHTTHENDOWNESCALATOR,
    STRAIGHTTHENUPESCALATOR,
    
    CHANGEBUILDING,
    ENTERBUILDING,
    LEAVEBUILDING,
    TURNLEFTTHENENTERBUILDING,
    TURNRIGHTTHENENTERBUILDING,
    TURNLEFTTHENLEAVEBUILDING,
    TURNRIGHTTHENLEAVEBUILDING
    
}InstructionType;

 /** Key to retrieve the angle for the turn */
static NSString *const KEY_TURN_ANGLE = @"angle";
/** Key to retrieve the second angle for the turn */
static NSString *const KEY_TURN_ANGLE_2 = @"angle2";
 /** Key to retrieve the floorNumber */
static NSString *const KEY_FLOORNUMBER = @"floornumber";

static NSString *const kOYMInstructionKeyFromToSign = @"fromToSign";
static NSString *const kOYMInstructionKeyFromToHint = @"fromToHint";
static NSString *const kOYMInstructionKeyToFromSign = @"toFromSign";
static NSString *const kOYMInstructionKeyToFromHint = @"toFromHint";


/**
 *  This class defines an instruction to be used in the routing
 */
@interface OYMInstruction : NSObject <OYMJsonProtocol>

/** Distance from the start point */
@property double distance;
/** Instruction to apply at that distance */
@property InstructionType instruction;
/** Values retrieved for the instruction */
@property (nonatomic,strong) NSDictionary* props;

@property OYMIndicator *orientation;
@property OYMIndicator *destination;


/**
 *  Instruction constructor.
 *
 * @param distance Distance from the start point
 * @param instruction Instruction to apply at that distance
 * @param props Hashmap including extra values to complete the instruction
 */
-(id)initInstructionWithDistance:(double)distance type:(InstructionType)instruction props:(NSDictionary*)props;

+(NSArray*)generateRoadMap:(NSArray*)path withDataHandler:(OYMDataHandler*)dh;

-(NSString*)toString;

-(int)getFloornumber;
-(int)getTurnAngle;


@end


#endif
