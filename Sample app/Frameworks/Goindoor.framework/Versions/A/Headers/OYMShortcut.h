//
//  OYMShortcut.h
//  Goindoor
//
//  Created by Joan Comellas on 06/02/17.
//  Copyright © 2017 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OYMConstant.h"
#import "OYMJsonProtocol.h"

/** Key to retrieve the shortcut name */
static NSString *const kOYMShortcutKeyName = @"name";
/** Key to retrieve the shortcut icon */
static NSString *const kOYMShortcutKeyIcon = @"icon";


/**
 *  This class includes all the information regarding shortcuts that can be present.
 */
@interface OYMShortcut : NSObject <OYMJsonProtocol>

/** Shortcut names per language */
@property (readonly) NS_DICTIONARY_OF(NSString*, NSString*) *name;
/** Shortcut icon */
@property (readonly) NSString *icon;

- (instancetype) initWithName: (NS_DICTIONARY_OF(NSString*, NSString*)*)_name andIcon: (NSString*) _icon;


@end
