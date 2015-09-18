//
//  SaveButton.m
//  Navigation
//
//  Created by Brijendra Tiwari on 27/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "SaveButton.h"

@implementation SaveButton


 //Only override drawRect: if you perform custom drawing.
- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGFloat radius = rect.size.width / 4;
    CGFloat width = rect.size.width / 2;
    CGPoint center = CGPointMake(rect.size.width / 2, rect.size.height / 2);
    CGContextSetLineWidth(context, width);
    CGContextSetStrokeColorWithColor(context, [Colors accent].CGColor);
    CGContextAddArc(context, center.x, center.y, radius, 0, M_PI * 2, YES);
    CGContextStrokePath(context);
}


@end
