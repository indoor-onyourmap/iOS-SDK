//
//  OYMFloor+GoogleMaps.m
//  Goindoor
//
//  Created by Joan Comellas on 15/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#import "OYMFloor+GoogleMaps.h"
#import "objc/runtime.h"

static void * OYMFloorTileProviderGooglePropertyKey = &OYMFloorTileProviderGooglePropertyKey;
static NSString* kOYMTileOverlayBundleName = @"goindoorTiles";
static NSBundle* tilesBundle;


/**
   This category will provided an initialized GMSURLTileLayer to be used in Google Maps.
 */
@implementation OYMFloor (GoogleMaps)

- (GMSURLTileLayer*) tileProviderGoogle {
    GMSURLTileLayer *tiles = [GMSURLTileLayer tileLayerWithURLConstructor:^NSURL *(NSUInteger x, NSUInteger y, NSUInteger zoom) {
        int y2 = (int) (pow(2, zoom)-y-1);
        
        NSBundle *bundle = [OYMFloor getBundle];
        if (bundle != nil && [bundle pathsForResourcesOfType:nil inDirectory:self.uuid].count > 0) {
            return [bundle URLForResource:[NSString stringWithFormat:@"%ld",(long)y2] withExtension:@"png" subdirectory:[NSString stringWithFormat:@"%@/%ld/%ld", self.uuid, (long)zoom, (long)x]];
        } else {
            NSString *str = [NSString stringWithFormat:@"https://indoor.onyourmap.com/indoor/getTiles.php?l=%@&x=%ld&y=%ld&z=%ld", self.uuid, (long)x, (long)y2, (long)zoom];
            return [NSURL URLWithString:str];
        }
    }];
    objc_setAssociatedObject(self, OYMFloorTileProviderGooglePropertyKey, tiles, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    return tiles;
}

- (void) setTileProviderGoogle:(GMSURLTileLayer *)_tileProviderGoogle {
    objc_setAssociatedObject(self, OYMFloorTileProviderGooglePropertyKey, _tileProviderGoogle, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (NSBundle*) getBundle {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        tilesBundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:kOYMTileOverlayBundleName ofType:@"bundle"]];
    });
    
    return tilesBundle;
}


@end
