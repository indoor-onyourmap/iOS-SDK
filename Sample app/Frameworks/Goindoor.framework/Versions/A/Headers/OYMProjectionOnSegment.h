//
//  OYMProjectionOnSegment.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMProjectionOnSegment_h
#define indoor_OYMProjectionOnSegment_h
#import "OYMCoordinates.h"

@interface OYMProjectionOnSegment : NSObject

@property double position;
@property double positionPercent;
@property (nonatomic,strong) OYMCoordinates* projectedPoint;
@property double distance;

-(id)initProjectionOfPoint:(OYMCoordinates*)P betweenPointA:(OYMCoordinates*)A andPointB:(OYMCoordinates*)B;
+(double)getDistanceBetweenA:(OYMCoordinates*)A andB:(OYMCoordinates*)B;

@end

#endif
