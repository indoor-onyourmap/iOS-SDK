//
//  OYMTransparentTextField.m
//  indoor
//
//  Created by onyourmap on 2/2/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "OYMTransparentTextField.h"

@implementation OYMTransparentTextField

@synthesize lineColor;
//@dynamic placeholder;


- (void)drawRect:(CGRect)rect {
    self.textColor = [UIColor whiteColor];
    
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, [UIColor clearColor].CGColor);
    CGContextFillRect(ctx, rect);
    CGContextSetFillColorWithColor(ctx, lineColor.CGColor);
    CGContextFillRect(ctx, CGRectMake(0, rect.size.height-2, rect.size.width, 2));
}


- (UIColor *)lineColor {
    return lineColor;
}

- (void)setLineColor:(UIColor *)lc {
    lineColor = lc;
    [self setNeedsDisplay];
}


//- (NSString *)placeholder {
//    return self.placeholder;
//}
//
//- (void)setPlaceholder:(NSString *)ph {
////    [super setPlaceholder:ph];
//    self.attributedPlaceholder = [[NSAttributedString alloc] initWithString:ph attributes:[NSDictionary dictionaryWithObjectsAndKeys:Colors.whiteHint, NSForegroundColorAttributeName, nil]];
//}


@end
