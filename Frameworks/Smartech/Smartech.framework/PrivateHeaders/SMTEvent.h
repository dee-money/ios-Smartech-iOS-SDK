//
//  SMTEvent.h
//  Smartech
//
//  Created by Netcore Solutions on 20/02/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - Push Notification Gateway Source

/**
 @brief SMTPushNotificationGatewaySource is an enum for request Smartech push notifciation gateway source type.
 */
typedef NS_ENUM(NSUInteger, SMTPushNotificationGatewaySource) {
    APNS = 2,
    PUSH_AMPLIFICATION = 3
};

/**
 @brief This defines the type of Smartech push notification source.
 
 @param source This is one of the SMTPushNotificationGatewaySource.
 
 @return NSString The push notification gateway source string.
 */
extern NSString *PushNotificationGatewaySourceString(SMTPushNotificationGatewaySource source);

/**
 @brief This defines the type of Smartech push notification gateway source.
 
 @param gatewaySource This is one of the SMTPushNotificationGatewaySource.
 
 @return SMTPushNotificationGatewaySource The push notification gateway source int value.
 */
extern SMTPushNotificationGatewaySource PushNotificationGatewaySourceFromString(NSString *gatewaySource);


#pragma mark - Push Notification Campaign Type

/**
 @brief SMTPushNotificationCampaignType is an enum for push notification campaign type.
 */
typedef NS_ENUM(NSUInteger, SMTPushNotificationCampaignType) {
    SMTPushNotificationCampaignTypeNormal = 0,
    SMTPushNotificationCampaignTypeScheduled = 1
};

/**
 @brief This defines the type of push notification campaign type.
 
 @param campaignType This is one of the SMTPushNotificationCampaignType.
 
 @return NSString The push notification campaign type string.
 */
extern NSString *PushNotificationCampaignTypeString(SMTPushNotificationCampaignType campaignType);

/**
 @brief This defines the type of Smartech push notification campaign type.
 
 @param campaignTypeString This is one of the SMTPushNotificationCampaignType in string format.
 
 @return SMTPushNotificationCampaignType The push notification campaign type int value.
 */
extern SMTPushNotificationCampaignType PushNotificationCampaignFromString(NSString *campaignTypeString);


#pragma mark - Push Notification Current Status

/**
 @brief SMTCurrentStatus is an enum for push notification status.
 */
typedef NS_ENUM(NSUInteger, SMTPushNotificationCurrentStatus) {
    SMTPushNotificationCurrentStatusScheduled = 1,
    SMTPushNotificationCurrentStatusCancelled = 2,
    SMTPushNotificationCurrentStatusRendered = 3,
    SMTPushNotificationCurrentStatusDelivered = 4
};

/**
 @brief This defines the push notification current status in string value.
 
 @discussion This method accepts a SMTPushNotificationCurrentStatus value representing the current push notification status and it converts it to the corresponding string value.
 
 @param currentStatuss This is one of the push notification's current status.
 
 @return NSString The push notifications current status in string format.
 */
extern NSString *PushNotificationCurrentStatus(SMTPushNotificationCurrentStatus currentStatuss);

/**
 @brief This defines the type of Smartech push notification's current status.
 
 @param currentStatusString This is one of the SMTPushNotificationCurrentStatus in string format.
 
 @return SMTPushNotificationCurrentStatus The push notification's current status int value.
 */
SMTPushNotificationCurrentStatus PushNotificationCurrentStatusFromString(NSString *currentStatusString);


#pragma mark - Event Type

/**
 @brief SMTEventType is an enum for request Smartech event type.
 */
typedef NS_ENUM(NSUInteger, SMTEventType) {
    SYSTEM, CUSTOM, LIFE_CYCLE, PUSH, INAPP, APPINBOX
};

/**
 @brief This defines the type of Smartech events.
 
 @param eventType This is one of the SMTEventType.
 
 @return NSString The event type string.
 */
extern NSString *EventTypeString(SMTEventType eventType);


#pragma mark - Event Status

/**
 @brief SMTEventStatus is an enum to know events status.
 */
typedef NS_ENUM(NSUInteger, SMTEventStatus) {
    SMTEventStatusPending = 1,
    SMTEventStatusInProgress = 2,
    SMTEventStatusSuccess = 3,
    SMTEventStatusFailed = 4
};


#pragma mark - Event Name
/**
 @brief SMTEvent is an enum for request Smartech Events.
 */
typedef NS_ENUM(NSUInteger, SMTEvent) {
    
    USER_CUSTOM_EVENT = 0,
    
    DEVICE_DATA_DUMP_EVENT = 99,
    
    APP_INSTALLED = 20,
    APP_UPDATED = 81,
    APP_CRASHED = 82,
    APP_REINSTALLED = 83,

    FIRST_APP_LAUNCHED = 80,
    APP_LAUNCHED = 21,
    
    PUSH_NOTIFICATION_TOKEN_GENERATED = 86,
    PUSH_NOTIFICATION_TOKEN_FAILED = 87,
    PUSH_NOTIFICATION_TOKEN_REFRESHED = 88,
    
    DEVICE_DETAILS_UPDATED = 26,
    
    APP_LOCATION_ENABLED = 89,
    APP_LOCATION_DISABLED = 90,

    PUSH_NOTIFICATION_DELIVERED = 12,
    PUSH_NOTIFICATION_CLICKED = 13,
    PUSH_NOTIFICATION_DISMISSED = 14,
    PUSH_NOTIFICATION_REPLIED = 19,
    
    INAPP_MESSAGE_VIEWED = 41,
    INAPP_MESSAGE_CLICKED = 42,
    INAPP_MESSAGE_CLOSED = 43,
    
    INBOX_MESSAGE_DELIVERED = 44,
    INBOX_MESSAGE_VIEWED = 45,
    INBOX_MESSAGE_CLICKED = 46,
    INBOX_MESSAGE_DISMISSED = 47,
    
    USER_LOGGED_IN = 22,
    USER_LOGGED_OUT = 23,
    
    USER_ENABLED_PUSH_NOTIFICATION = 84,
    USER_DISABLED_PUSH_NOTIFICATION = 85,

    USER_OPT_IN_TRACKING = 70,
    USER_OPT_OUT_TRACKING = 71,
    
    USER_OPT_IN_PUSH_NOTIFICATION = 72,
    USER_OPT_OUT_PUSH_NOTIFICATION = 73,

    USER_OPT_IN_INAPP_MESSAGES = 74,
    USER_OPT_OUT_INAPP_MESSAGES = 75,
    
    USER_PROFILE_PUSH = 40,
    
    GEOFENCE_ENTER = 91,
    GEOFENCE_EXIT = 93,

    HANSEL_PROMPT_SHOW = 63,
    HANSEL_PROMPT_DISMISS = 64,
    HANSEL_BRANCH_TRACKER = 65
};

/**
 @brief This defines the type of Smartech event used to track event.
 
 @discussion This method accepts a SMTEvent value representing the Smartech event and it converts it to the corresponding string value.
 
 @param event This is one of the SMTEvent.
 
 @return NSString The SMTEvent name.
 */
extern NSString *EventNameString(SMTEvent event);

NS_ASSUME_NONNULL_END
