//
//  UpperBar.m
//  indoor
//
//  Created by onyourmap on 16/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UpperBar.h"

@implementation UpperBar

-(void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [Colors primaryInverse].CGColor);
    CGContextFillRect(context, rect);
    CGContextSetFillColorWithColor(context, [Colors primary].CGColor);
    CGContextFillRect(context, CGRectMake(0, rect.size.height-2, rect.size.width, 2));
}


@end
