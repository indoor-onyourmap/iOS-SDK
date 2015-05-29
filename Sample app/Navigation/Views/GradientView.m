//
//  GradientView.m
//  indoor
//
//  Created by onyourmap on 2/2/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "GradientView.h"

@implementation GradientView




- (void)drawRect:(CGRect)rect {
    // Drawing code
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    NSArray* cols = [NSArray arrayWithObjects:(id)Colors.backgroundStart.CGColor, (id)Colors.backgroundEnd.CGColor, nil];
    CGFloat loc[2] = {1.0, 0.0};
    CGGradientRef gradient = CGGradientCreateWithColors(CGColorSpaceCreateDeviceRGB(), (CFArrayRef)cols, loc);
    CGPoint start = CGPointMake(0, rect.size.height);
    CGPoint end = CGPointMake(0, 0);
    CGContextDrawLinearGradient(ctx, gradient, start, end, 3);
    
    
//    let ctx = UIGraphicsGetCurrentContext()
//    let colors = [Colors.backgroundStart.CGColor, Colors.backgroundEnd.CGColor]
//    let loc: [CGFloat] = [0.0, 1.0]
//    let gradient = CGGradientCreateWithColors(CGColorSpaceCreateDeviceRGB(), colors, loc)
//    let startPoint = CGPointMake(0, rect.height)
//    let endPoint = CGPointMake(0, 0)
//    CGContextDrawLinearGradient(ctx, gradient, startPoint, endPoint, 3)
}



@end
