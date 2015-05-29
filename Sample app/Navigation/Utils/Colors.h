//
//  Colors.h
//  indoor
//
//  Created by onyourmap on 15/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef NAV_UTILS_COLORS_H
#define NAV_UTILS_COLORS_H


#import <Foundation/Foundation.h>
@import UIKit;

#pragma mark Colors
// Basic colors
static NSString *const kOYMColorWhiteHint = @"#88FFFFFF";
static NSString *const kOYMColorUserPosition = @"#238796";
// Background
static NSString *const kOYMColorBackgroundStart = @"#F54337";
static NSString *const kOYMColorBackgroundEnd = @"#F45435";
// Primary palette: OYM (Red)
static NSString *const kOYMColorPrimary = @"#F44336";
static NSString *const kOYMColorPrimaryDark = @"#B71C1C";
static NSString *const kOYMColorPrimaryInverse = @"#F2F2F2";
static NSString *const kOYMColorTextPrimaryDark = @"#FFFFFF";
static NSString *const kOYMColorTextPrimary = @"#FFFFFF";
// Secondary Palette: OYM2
static NSString *const kOYMColorAccentLight = @"#74DBDB";
static NSString *const kOYMColorAccent = @"#67C3C3";
static NSString *const kOYMColorAccentDark = @"#439C9C";


@interface Colors : NSObject

//+ (UIColor*) getFromHex:(NSString*)hex;

+ (UIColor*) whiteHint;
+ (UIColor*) userPosition;

+ (UIColor*) backgroundStart;
+ (UIColor*) backgroundEnd;

+ (UIColor*) primary;
+ (UIColor*) primaryDark;
+ (UIColor*) primaryInverse;
+ (UIColor*) textPrimaryDark;
+ (UIColor*) textPrimary;

+ (UIColor*) accentLight;
+ (UIColor*) accent;
+ (UIColor*) accentDark;


@end
#endif