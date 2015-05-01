//
//  OYMEdgeNode.h
//  indoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMEdgeNode_h
#define indoor_OYMEdgeNode_h

@interface OYMEdgeNode : NSObject

@property int edgeId;
@property double cost;
@property int parentEdgeId;
@property bool chosen;

-(id)initEdgeNodeWithEdgeId:(int)_edgeId parent:(int)_parentEdgeId cost:(double)cost andStatus:(bool)chosen;
-(NSComparisonResult)compare:(OYMEdgeNode*)other;

@end

#endif
