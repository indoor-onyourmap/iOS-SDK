//
//  OYMJsonProtocol.h
//  Goindoor
//
//  Created by onyourmap on 11/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMJsonProtocol_H
#define INDOOR_OYMJsonProtocol_H

#import <Foundation/Foundation.h>

@protocol OYMJsonProtocol <NSObject>

#pragma mark Required
@required
- (NSString*)toJson;
- (instancetype) initWithJson:(NSString*)json;

@optional
- (NSDictionary*) toDictionary;

@end

#endif
