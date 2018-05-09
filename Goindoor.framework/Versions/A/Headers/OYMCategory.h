//
//  OYMCategory.h
//  Goindoor
//
//  Created by Joan Comellas on 06/02/17.
//  Copyright © 2017 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OYMConstant.h"
#import "OYMJsonProtocol.h"

/** Key to retrieve the category name */
static NSString *const kOYMCategoryKeyName = @"name";
/** Key to retrieve the category icon */
static NSString *const kOYMCategoryKeyIcon = @"icon";


/**
 *  This class includes all the information regarding categories that can be present.
 */
@interface OYMCategory : NSObject <OYMJsonProtocol>

/** Category names per language */
@property (readonly) NS_DICTIONARY_OF(NSString*, NSString*) *name;
/** Category icon */
@property (readonly) NSString *icon;

- (instancetype) initWithName: (NS_DICTIONARY_OF(NSString*, NSString*)*)_name andIcon: (NSString*) _icon;


@end
