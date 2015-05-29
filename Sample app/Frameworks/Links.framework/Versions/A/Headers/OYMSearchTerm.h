//
//  OYMSearchTerm.h
//  links-ios
//
//  Created by onyourmap on 04/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMSearchTerm_h
#define links_ios_OYMSearchTerm_h

/** Strings containing all the operators for search terms */
static NSString *const kOYMSearchTerm_MATCH_EXACT = @"MATCH_EXACT";
static NSString *const kOYMSearchTerm_MATCH_FUZZY = @"MATCH_FUZZY";
static NSString *const kOYMSearchTerm_MATCH_PREFIX = @"MATCH_PREFIX";
static NSString *const kOYMSearchTerm_LOWER = @"LOWER";
static NSString *const kOYMSearchTerm_HIGHER = @"HIGHER";
static NSString *const kOYMSearchTerm_BEFORE = @"BEFORE";
static NSString *const kOYMSearchTerm_AFTER = @"AFTER";

/** String containing the different term types avilable */
static NSString *const kOYMSearchTermType_STRING = @"STRING";
static NSString *const kOYMSearchTermType_DATETIME = @"DATETIME";
static NSString *const kOYMSearchTermType_NUMERICAL = @"NUMERICAL";

@interface OYMSearchTerm : NSObject

@property (nonatomic,strong) NSString* type;
@property (nonatomic,strong) NSString* propertyName;
@property (nonatomic,strong) NSString* searchOperator;
@property (nonatomic,strong) NSString* value;

+(OYMSearchTerm*) makeTermWithType:(NSString*)type PropertyName:(NSString*)propertyName searchOperator:(NSString*)searchOperator value:(NSString*)value;
-(NSString*)toDictionary;

@end

#endif
