//
//  OYMTransparentTextField.m
//  indoor
//
//  Created by onyourmap on 2/2/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "OYMTransparentTextField.h"

@interface OYMTransparentTextField ()

@property (nonatomic)  UIColor *lineColor;

@end

@implementation OYMTransparentTextField

@synthesize lineHighlightedColor, lineNormalColor, lineColor;
//@dynamic placeholder;


- (void)drawRect:(CGRect)rect {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, [UIColor clearColor].CGColor);
    CGContextFillRect(ctx, rect);
    CGContextSetFillColorWithColor(ctx, self.lineColor.CGColor);
    CGContextFillRect(ctx, CGRectMake(0, rect.size.height-2, rect.size.width, 2));
}
//Line Color
-(UIColor *)lineColor{
    if (lineColor == nil) {
        return self.lineNormalColor;
    }
    return lineColor;
}

-(void)setLineColor:(UIColor *)lc {
    lineColor = lc;
    [self setNeedsDisplay];
}

//Line HeighLighted Color
- (UIColor *)lineHighlightedColor {
    if (lineHighlightedColor == nil) {
        return Colors.accent;
    }
    return lineHighlightedColor;
}

- (void)setLineHighlightedColor:(UIColor *)lhc{
    lineHighlightedColor = lhc;
}

//Line Normal Color
-(UIColor *)lineNormalColor {
    if (lineNormalColor == nil) {
        return [UIColor whiteColor];
    }
    return lineNormalColor;
}

-(void)setLineNormalColor:(UIColor *)lnc {
    lineNormalColor = lnc;
}

//Responder Methods
- (BOOL)becomeFirstResponder {
    BOOL returnValue = [super becomeFirstResponder];
    [self setLineColor:self.lineHighlightedColor];
    return returnValue;
}

-(BOOL)resignFirstResponder {
    BOOL returnValue = [super resignFirstResponder];
    [self setLineColor:self.lineNormalColor];
    return returnValue;
}

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender {
    return NO;
}

@end
