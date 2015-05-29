//
//  GlobalState.m
//  indoor
//
//  Created by onyourmap on 14/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "GlobalState.h"

static GlobalState* gs = nil;

@implementation GlobalState

+ (instancetype) get {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (!gs) {
            gs = [GlobalState new];
        }
    });
    return gs;
}




@end
