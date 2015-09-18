//
//  OYMNodeSort.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMNodeSort_h
#define indoor_OYMNodeSort_h

@interface OYMNodeSort : NSObject

@property int index;
@property (nonatomic,strong) NSString* node;

-(id)initNodeSortWithIndex:(int)_index andNode:(NSString*)_node;
-(NSComparisonResult)compare:(OYMNodeSort*)other;


@end

#endif