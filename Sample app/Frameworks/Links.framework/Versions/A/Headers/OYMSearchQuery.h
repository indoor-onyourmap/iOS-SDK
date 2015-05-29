//
//  OYMSearchQuery.h
//  links-ios
//
//  Created by onyourmap on 04/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMSearchQuery_h
#define links_ios_OYMSearchQuery_h

#import "OYMSearchTerm.h"

/** Strings containing the different searchable objects */
static int const kOYMSearchObjectType_ITEMS = 1;
static int const kOYMSearchObjectType_SUPER_ITEMS = 2;
static int const kOYMSearchObjectType_USERS = 4;
static int const kOYMSearchObjectType_EVENTS = 8;
static int const kOYMSearchObjectType_ALERTS = 16;
static int const kOYMSearchObjectType_SHAPES = 32;

/** Strings containing the type of ordering available */
static NSString *const kOYMSearchOrderBy_ASCENDING = @"asc";
static NSString *const kOYMSearchOrderBy_DESCENDING = @"dsc";

@interface OYMSearchQuery : NSObject

@property (nonatomic) NSMutableArray* terms;
@property (nonatomic) NSMutableArray* sortProperties;
@property (nonatomic) int typeMask;
@property (nonatomic) int offset;
@property (nonatomic) int bucketSize;

-(id)initOYMSearchQuery;
-(void)addTerm:(OYMSearchTerm*)arg1,... NS_REQUIRES_NIL_TERMINATION;
-(void)addSortProperty:(NSString*)property sortedBy:(NSString*)sorting;
-(NSMutableArray*)serializeTerms;
-(NSDictionary*)toDictionnary;


@end
#endif
