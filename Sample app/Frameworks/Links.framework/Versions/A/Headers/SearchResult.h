//
//  SearchResult.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 19/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksSearchResult_h
#define links_ios_OYMLinksSearchResult_h

#import <Foundation/Foundation.h>

typedef enum {
    OYM_LINKS_ITEM,
    OYM_LINKS_EVENT,
    OYM_LINKS_ALERT,
    OYM_LINKS_USER,
    OYM_LINKS_SHAPE,
    OYM_LINKS_PLACEMARK,
    OYM_LINKS_ERROR
}ObjectType;

@interface OYMLinksSearchResult : NSObject

@property (nonatomic,strong) NSDictionary* highlightedProperties;
@property (nonatomic,strong) id object;
@property (nonatomic) ObjectType type;
@property (nonatomic) float score;

/**
 A SearchResult represents a matched result from a search searchObjects(NSString*).
 @param type type of the found object ( ITEM,EVENT,ALERT,USER,SHAPE,PLACEMARK
 @param object object found
 @param score score fo the search
 @param matchedPropertyName matching property
 @param matchedValue value of the matching property
 */
-(id)initSearchResultWithType:(ObjectType)_type object:(id)object score:(float)score highlightedProperties:(NSDictionary*)highlightedProperties;

+(ObjectType)getObjectTypeFromString:(NSString*)string;

@end
#endif