//
//  OYMPinAnnotation.m
//  indoor
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "OYMAnnotation.h"

static NSString *const kOYMAnnotationIdentifier = @"OYMAnnotation";


@implementation OYMAnnotation

@synthesize coordinate;

+ (MKAnnotationView*) getReusableViewForMap:(MKMapView*)map {
    return [map dequeueReusableAnnotationViewWithIdentifier:kOYMAnnotationIdentifier];
}

- (instancetype) initWithLocation:(CLLocationCoordinate2D)loc andImage:(UIImage*)i {
    if (self = [super init]) {
        coordinate = loc;
        image = i;
    }
    return self;
}

- (MKAnnotationView*) view {
    MKAnnotationView* av = [[MKAnnotationView alloc] initWithAnnotation:self reuseIdentifier:kOYMAnnotationIdentifier];
//    av.image = [[UIImage imageNamed:@"Logo"] imageTintedWithColor:[Colors getFromHex:kOYMColorUserPosition]];
    av.image = image;
    
    return av;
}


- (void) setCoordinate:(CLLocationCoordinate2D)pos {
    // KVO
    [self willChangeValueForKey:@"coordinate"];
    coordinate = pos;
    [self didChangeValueForKey:@"coordinate"];    
}



@end
