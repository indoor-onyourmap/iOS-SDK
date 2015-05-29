//
//  OYMEdgeBucketNode.h
//  indoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMEdgeBucketNode_h
#define indoor_OYMEdgeBucketNode_h

@interface OYMEdgeBucketNode : NSObject

@property int edgeId;
@property double cost;

-(id)initEdgeBucketNodeWithEdgeId:(int)_edgeId andCost:(double)_cost;
-(NSComparisonResult)compare:(OYMEdgeBucketNode*)other;

@end

#endif
