//
//  OYMLogProtocol.h
//  indoor
//
//  Created by onyourmap on 11/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMLOGPROTOCOL_H
#define INDOOR_OYMLOGPROTOCOL_H

#import <Foundation/Foundation.h>

@protocol OYMLogProtocol <NSObject>

#pragma mark Required
@required
- (NSString*)toLog;
- (instancetype) initWithJson:(NSString*)json;

@end

#endif
