//
//  GlobalState.h
//  indoor
//
//  Created by onyourmap on 14/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef NAV_GLOBALSTATE_H
#define NAV_GLOBALSTATE_H

#import <Foundation/Foundation.h>

#import <Goindoor/Goindoor.h>

@interface GlobalState : NSObject

@property OYMGoIndoor* go;
@property OYMRoute* route;

#pragma mark Class methods
+ (instancetype) get;


@end
#endif