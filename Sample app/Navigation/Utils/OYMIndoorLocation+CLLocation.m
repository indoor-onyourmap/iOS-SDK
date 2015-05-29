//
//  OYMIndoorLoc.m
//  indoor
//
//  Created by onyourmap on 21/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "OYMIndoorLocation+CLLocation.h"

@implementation OYMIndoorLocation (CLLocation)

- (CLLocationCoordinate2D) getCoords {
    return CLLocationCoordinate2DMake(self.latitude, self.longitude);
}

@end
