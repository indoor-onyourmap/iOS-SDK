//
//  RoundedButton.m
//  indoor
//
//  Created by Joan Comellas on 31/03/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "RoundedButton.h"

@implementation RoundedButton


- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetStrokeColorWithColor(context, [UIColor whiteColor].CGColor);
    CGContextSetLineWidth(context, 12.0f);
    CGContextSetFillColorWithColor(context, [UIColor clearColor].CGColor);
    CGContextFillRect(context, rect);
    
    UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:12.0f];
    [[UIColor whiteColor] setStroke];
    [path stroke];
    
    if (self.state == UIControlStateHighlighted) {
        [[Colors whiteHint] setFill];
        [path fill];
    }
    
    if (!isInit) {
        [self addTarget:self action:@selector(setNeedsDisplay) forControlEvents:UIControlEventAllEvents];
        self.showsTouchWhenHighlighted = NO;
        isInit = YES;
    }
}

@end
