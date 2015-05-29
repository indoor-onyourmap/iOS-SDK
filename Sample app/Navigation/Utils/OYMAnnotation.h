//
//  OYMPinAnnotation.h
//  indoor
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <MapKit/MapKit.h>

#import <indoor/OYMIndoorLocation.h>

#import "UIImage+Tint.h"
#import "Colors.h"



@interface OYMAnnotation : NSObject <MKAnnotation> {
    @private
    UIImage* image;
}

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

+ (MKAnnotationView*) getReusableViewForMap:(MKMapView*)map;
- (instancetype) initWithLocation:(CLLocationCoordinate2D)loc andImage:(UIImage*)i;
- (MKAnnotationView*) view; 


@end
