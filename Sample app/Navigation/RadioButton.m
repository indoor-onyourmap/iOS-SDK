//
//  RadioButton.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "RadioButton.h"

@implementation RadioButton
@synthesize btnColor;

- (void)drawRect:(CGRect)rect {
    
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGFloat borderWidth = 2.0f;
    CGPoint center = CGPointMake(rect.size.width / 2, rect.size.height / 2);
    CGFloat borderRadius = rect.size.width / 2 - borderWidth/2;
    CGFloat startAngle = 0;
    CGFloat endAngle = M_PI * 2;
    CGFloat innerDotWidth = rect.size.width / 4;
    CGFloat innerRadius = innerDotWidth/2;
    
    // Border
    CGContextSetLineWidth(context, borderWidth);
    CGContextSetStrokeColorWithColor(context, self.btnColor.CGColor);
    CGContextAddArc(context, center.x, center.y, borderRadius, startAngle, endAngle, 0);
    CGContextStrokePath(context);
    if (self.selected) {
        // Inner Dot
        CGContextSetLineWidth(context, innerDotWidth);
        CGContextSetStrokeColorWithColor(context, self.btnColor.CGColor);
        CGContextAddArc(context, center.x, center.y, innerRadius, startAngle, endAngle, 0);
        CGContextStrokePath(context);
    }
}

-(UIColor *)btnColor {
    if (btnColor == nil) {
        return [UIColor darkGrayColor];
    }
    return btnColor;
}

-(void)setSelected:(BOOL)selected {
    [super setSelected:selected];
    if (selected) {
        self.tintColor = [UIColor clearColor];
        btnColor = Colors.accent;
    } else {
        btnColor = [UIColor darkGrayColor];
    }
    [self setNeedsDisplay];
}


@end
