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


@implementation OYMFloor (GoogleMaps)

- (GMSURLTileLayer*) tileProviderGoogle {
    GMSURLTileLayer *tiles = [GMSURLTileLayer tileLayerWithURLConstructor:^NSURL *(NSUInteger x, NSUInteger y, NSUInteger zoom) {
        int y2 = (int) (pow(2, zoom)-y-1);
        NSString *url = [NSString stringWithFormat:@"https://indoor.onyourmap.com/indoor/getTiles.php?l=%@&x=%d&y=%d&z=%d",self.uuid,(int) x, y2, (int) zoom];
        return [NSURL URLWithString:url];
    }];
    objc_setAssociatedObject(self, OYMFloorTileProviderGooglePropertyKey, tiles, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    return tiles;
}

- (void) setTileProviderGoogle:(GMSURLTileLayer *)_tileProviderGoogle {
    objc_setAssociatedObject(self, OYMFloorTileProviderGooglePropertyKey, _tileProviderGoogle, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}


@end
