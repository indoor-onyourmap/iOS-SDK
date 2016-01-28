//
//  OYMDataWebservice.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 20/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMDATAWEBSERVICE_H
#define INDOOR_OYMDATAWEBSERVICE_H

#import <Foundation/Foundation.h>

#import "OYMConstant.h"

#import "OYMDataHandler.h"
#import "OYMWebservice.h"

@interface OYMDataWebservice : NSObject <OYMDataServer>

- (instancetype __NONNULL) initWithUser:(NSString *__NONNULL)_user andPassword:(NSString *__NONNULL)_password ;

@end

#endif