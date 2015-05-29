//
//  BottomBar.m
//  indoor
//
//  Created by onyourmap on 16/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "PrimaryBarView.h"

@implementation PrimaryBarView


-(void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [Colors primary].CGColor);
    CGContextFillRect(context, rect);
}


@end
