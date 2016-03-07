//
//  OYMNotificationTargets.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 03/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_NOTIFICATIONSTARGETS_H
#define INDOOR_NOTIFICATIONSTARGETS_H

#import "OYMUserValue.h"

#import "OYMUtils.h"
/*
 *  This class defines a value stored for notification targets.
 */
@interface OYMNotificationTargets : OYMUserValue

@property (readonly) BOOL mandatory;
@property (readonly) Operation operation;
@property (readonly) id endValue;

#pragma mark Instance methods
-(instancetype)initWithValue:(id)_value settingFormat:(Format)_format isMandatory:(BOOL)_mandatory;
-(instancetype)initWithValue:(id)_value settingFormat:(Format)_format isMandatory:(BOOL)_mandatory andOperation:(Operation)_operation;

-(instancetype)initWithValue:(id)_value endValue:(id)_endValue settingFormat:(Format)_format isMandatory:(BOOL)_mandatory;
-(instancetype)initWithValue:(id)_value endValue:(id)_endValue settingFormat:(Format)_format isMandatory:(BOOL)_mandatory andOperation:(Operation)_operation;

-(instancetype)initWithValue:(id)_value endValue:(id)_endValue settingFormat:(Format)_format isMandatory:(BOOL)_mandatory operation:(Operation)_operation andFixedValues:(NSArray *)_fixedValues;

- (BOOL) checkValue:(OYMUserValue *)userValue;
@end
#endif
