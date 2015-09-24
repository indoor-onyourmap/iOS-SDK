//
//  Header.h
//  links-ios
//
//  Created by onyourmap on 20/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_Header_h
#define links_ios_Header_h

#import <Foundation/Foundation.h>
#import "LiveXY.h"
#import "LiveValue.h"

/**
 * Type of event trigger
 */
typedef enum {
    LINKS_EVENT_ENTER_GEOFENCE = 1,
    LINKS_EVENT_EXIT_GEOFENCE = 2,
    LINKS_EVENT_NOT_EQUAL_TO_VALUE = 3,
    LINKS_EVENT_EQUAL_TO_VALUE = 4,
    LINKS_EVENT_LOWER_THAN_VALUE = 5,
    LINKS_EVENT_HIGHER_THAN_VALUE = 6,
    LINKS_EVENT_MOVE = 7,
    LINKS_EVENT_CHANGE = 8,
    LINKS_EVENT_EXIST = 9
}OYMLinksEventType;

#define LINKS_EVENT_ON_ITEM 1
#define LINKS_EVENT_ON_USER 2
#define LINKS_EVENT_ON_SHAPE 3
#define LINKS_EVENT_ON_ALERT 4
#define LINKS_EVENT_ON_EVENT 5
#define LINKS_EVENT_ON_SUPER_ITEM 6

/**
 *
 * An EventTrigger allows to define a triggering rule on an Item.
 * @param type
 * @param objectId
 * @param propertyName
 * @param compareValue
 */
@interface OYMLinksEventTrigger : NSObject

@property OYMLinksEventType type;
@property (nonatomic,strong) NSString* objectId;
@property (nonatomic,strong) NSString* propertyName;
@property (nonatomic,strong) NSString* compareValue;

+(OYMLinksEventTrigger*)OYMLinksEventTriggerWithType:(OYMLinksEventType)type forObject:(NSString*)objectId onProperty:(NSString*)propertyName withCompareValue:(NSString*)compareValue;

+(NSArray*)triggersListToDicoArray:(NSArray*)triggers;
+(NSArray*)toObjectArray:(NSArray*)triggers;

@end


/**
 *
 * An EventValidity defines when an {@links Event} is valid.
 * @param {Number} endDate optional end date of validity. if specified, it defines a period of validity, else it applies on an unlimited period
 * @param {Number} startDate optional start date of validity. if specified, it defines a period of validity, else it applies on an unlimited period
 * @constructor
 */
@interface OYMLinksEventValidity : NSObject

@property (nonatomic,strong) NSString* startDate;
@property (nonatomic,strong) NSString* endDate;
/**
 * list of time ranges following this syntax: HH:MM-HH:MM
 * Example: 09:00-12:30
 */
@property (nonatomic,strong) NSArray* mondayValidHours;
@property (nonatomic,strong) NSArray* tuesdayValidHours;
@property (nonatomic,strong) NSArray* wednesdayValidHours;
@property (nonatomic,strong) NSArray* thursdayValidHours;
@property (nonatomic,strong) NSArray* fridayValidHours;
@property (nonatomic,strong) NSArray* saturdayValidHours;
@property (nonatomic,strong) NSArray* sundayValidHours;

+(OYMLinksEventValidity*)initWithStartDate:(NSDate*)startDate andEndDate:(NSDate*)endDate;
-(id)init;
-(NSDictionary*)toDico;
+(OYMLinksEventValidity*)toObject:(NSDictionary*)dico;

@end


/**
 *
 * An Event object defines when a set of rules can trigger an event.
 *
 */
@interface OYMLinksEvent : NSObject
/**
 *  automatically generated UUID
 */
@property (nonatomic, strong) NSString* uuid;
/**
 * set this item to active or inactive
 */
@property (nonatomic, strong) NSNumber* active;
/**
 *  user additional searchable informations, like a firstname or lastname
 */
@property (nonatomic, strong) NSDictionary* properties;
/**
 *  user live additional searchable informations, they all have a date value
 */
@property (nonatomic, strong) NSDictionary* liveDataProperties;
/**
 * a list of Access Control List (ACL) for each user on this item
 */
@property (nonatomic, strong) NSDictionary* acl;
/**
 * a list of a list of OYMLinksEventTrigger objects that trigger this event.
 */
@property (nonatomic, strong) NSArray* triggerRules;
/**
 * an object defining when the event is valid and can occur
 */
@property (nonatomic, strong) OYMLinksEventValidity* validity;

/** 
 create new event, simple method
 @param active boolean defining if item is active or not
 @param properties  list of key/values representing properties
 @param liveDataProperties  list of liveDataProperties
 @param acl List of acl
 @param triggerRules list of list of rules
 @param validity validity of the event
 @return event object
 */
-(id)initNewEvent:(BOOL)_active properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties acl:(NSDictionary*)_acl triggerRules:(NSArray*) _triggerRules validity:(OYMLinksEventValidity*) _validity;

/**
 create new event, full method
 @param active boolean defining if item is active or not
 @param properties  list of key/values representing properties
 @param liveDataProperties  list of liveDataProperties
 @param acl List of acl
 @param triggerRules list of list of rules
 @param validity validity of the event
 @param id uuid of the object
 @return event object
 */
-(id)initNewEvent:(BOOL)_active properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties acl:(NSDictionary*)_acl triggerRules:(NSArray*) _triggerRules validity:(OYMLinksEventValidity*) _validity uuid:(NSString*)_uuid;


-(NSDictionary*)toDictionary;
+(OYMLinksEvent*)toObject:(NSDictionary*)dico;

@end
#endif
