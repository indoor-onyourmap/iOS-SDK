//
//  OYMConstant.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 19/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef OYMConstant_h
#define OYMConstant_h

#if __has_feature(nullability)
#   define __ASSUME_NONNULL_BEGIN      NS_ASSUME_NONNULL_BEGIN
#   define __ASSUME_NONNULL_END        NS_ASSUME_NONNULL_END
#   define __NULLABLE                  _Nullable
#   define __NONNULL                   _Nonnull
#else
#   define __ASSUME_NONNULL_BEGIN
#   define __ASSUME_NONNULL_END
#   define __NULLABLE
#   define __NONNULL
#endif

#if __has_feature(objc_generics)
#define NS_ARRAY_OF(ObjectClass...)                                 NSArray <ObjectClass>
#define NS_MUTABLE_ARRAY_OF(ObjectClass...)         NSMutableArray <ObjectClass>
#define NS_SET_OF(ObjectClass...)                   NSSet <ObjectClass>
#define NS_MUTABLE_SET_OF(ObjectClass...)           NSMutableSet <ObjectClass>
#define NS_DICTIONARY_OF(ObjectClass...)            NSDictionary <ObjectClass>
#define NS_MUTABLE_DICTIONARY_OF(ObjectClass...)    NSMutableDictionary <ObjectClass>
#else
#define NS_ARRAY_OF(ObjectClass...)                 NSArray
#define NS_MUTABLE_ARRAY_OF(ObjectClass...)         NSMutableArray
#define NS_SET_OF(ObjectClass...)                   NSSet
#define NS_MUTABLE_SET_OF(ObjectClass...)           NSMutableSet
#define NS_DICTIONARY_OF(ObjectClass...)            NSDictionary
#define NS_MUTABLE_DICTIONARY_OF(ObjectClass...)    NSMutableDictionary
#endif

#define ReturnEmptyStringIfNil(str) (str == (id)[NSNull null] || str.length == 0 ) ? @"" : str
#define ReturnNumberZeroIfNil(number) (number == (id)[NSNull null] || number == nil ) ? @0 : number
#define ReturnNSNullIfNilOtherwiseJson(obj) obj? obj.toJson: [NSNull null]

#define JsonObjectToJsonString(jo) ([NSJSONSerialization isValidJSONObject:jo])?[[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:jo options:0 error:nil] encoding:NSUTF8StringEncoding]:(([jo isKindOfClass:[NSString class]])?(NSString*)jo:@"")
#define JsonStringToJsonObject(jsonStr) (jsonStr == nil)?nil:[NSJSONSerialization JSONObjectWithData:[jsonStr dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingAllowFragments error:nil]

#endif
