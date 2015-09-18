//
//  OYMUserValue.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 03/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//


#ifndef INDOOR_USERVALUE_H
#define INDOOR_USERVALUE_H

#import <Foundation/Foundation.h>

#pragma mark Enumerations
/** Enumeration containing all the Format Type */
typedef enum{
    BOOLEAN,
    DATE,
    FIXED,
    NUMBER,
    STRING
}Format;

/** Enumeration containing all the Operation Type */
typedef enum{
    BETWEEN,
    CONTAINS,
    EQUALS,
    GREATER,
    LESSER,
    NONE
}Operation;
/**
 *  This class defines a value stored for user settings.
 */
@interface OYMUserValue : NSObject

@property (readonly) id value;
@property (readonly) Format format;
@property (readonly) NSArray *fixedValues;

#pragma mark Instance methods
-(instancetype)initWithValue:(id)_value settingFormat:(Format)_format;
-(instancetype)initWithValue:(id)_value settingFormat:(Format)_format andFixedValues:(NSArray *)_fixedValues;

@end
#endif