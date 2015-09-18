//
//  OYMGraph.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMGraph_h
#define indoor_OYMGraph_h

#import <Foundation/Foundation.h>

@interface OYMGraph : NSObject

@property NSArray*  graphTable;

-(id)initGraphWithEdges:(NSArray*)edges;
-(NSArray*)getNextEdges:(int)edgeId;

@end



#endif
