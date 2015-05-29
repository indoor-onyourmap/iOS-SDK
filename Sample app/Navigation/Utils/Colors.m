//
//  Colors.m
//  indoor
//
//  Created by onyourmap on 15/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "Colors.h"

static UIColor* whiteHint = nil;
static UIColor* userPosition = nil;

static UIColor* backgroundStart = nil;
static UIColor* backgroundEnd = nil;

static UIColor* primary = nil;
static UIColor* primaryDark = nil;
static UIColor* primaryInverse = nil;
static UIColor* textPrimaryDark = nil;
static UIColor* textPrimary = nil;

static UIColor* accentLight = nil;
static UIColor* accent = nil;
static UIColor* accentDark = nil;


@implementation Colors

+ (UIColor*) getFromHex:(NSString*)hex {
    NSScanner* sc = [NSScanner scannerWithString:[hex substringFromIndex:1]];
    unsigned int b;
    [sc scanHexInt:&b];
    if ([hex length] == 7) {
        return [UIColor colorWithRed:(((b & 0xFF0000) >> 16) / 255.0f) green:(((b & 0x00FF00) >> 8) / 255.0f) blue:((b & 0x000000FF) / 255.0f) alpha:1];
    } else {
        return [UIColor colorWithRed:(((b & 0x00FF0000) >> 16) / 255.0f) green:(((b & 0x0000FF00) >> 8) / 255.0f) blue:((b & 0x000000FF) / 255.0f) alpha:(((b & 0xFF000000) >> 24) / 255.0f)];;
    }
}


+ (UIColor*) whiteHint {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        whiteHint = [self getFromHex:kOYMColorWhiteHint];
    });
    
    return whiteHint;
}

+ (UIColor*) userPosition {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        userPosition = [self getFromHex:kOYMColorUserPosition];
    });
    
    return userPosition;
}


+ (UIColor *) backgroundStart {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        backgroundStart = [self getFromHex:kOYMColorBackgroundStart];
    });
    
    return backgroundStart;
}

+ (UIColor *) backgroundEnd {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        backgroundEnd = [self getFromHex:kOYMColorBackgroundEnd];
    });
    
    return backgroundEnd;
}


+ (UIColor*) primary {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        primary = [self getFromHex:kOYMColorPrimary];
    });
    
    return primary;
}

+ (UIColor*) primaryDark {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        primaryDark = [self getFromHex:kOYMColorPrimaryDark];
    });
    
    return primaryDark;
}

+ (UIColor*) primaryInverse {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        primaryInverse = [self getFromHex:kOYMColorPrimaryInverse];
    });
    
    return primaryInverse;
}

+ (UIColor*) textPrimaryDark {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        textPrimaryDark = [self getFromHex:kOYMColorTextPrimaryDark];
    });
    
    return textPrimaryDark;
}

+ (UIColor*) textPrimary {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        textPrimary = [self getFromHex:kOYMColorTextPrimary];
    });
    
    return textPrimary;
}


+ (UIColor*) accentLight {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        accentLight = [self getFromHex:kOYMColorAccentLight];
    });
    
    return accentLight;
}

+ (UIColor*) accent {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        accent = [self getFromHex:kOYMColorAccent];
    });
    
    return accent;
}

+ (UIColor*) accentDark {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        accentDark = [self getFromHex:kOYMColorAccentDark];
    });
    
    return accentDark;
}


@end
