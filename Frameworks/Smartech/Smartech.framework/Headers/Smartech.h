//
//  Smartech.h
//  Smartech
//
//  Created by Netcore Solutions on 28/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import <CoreLocation/CoreLocation.h>

//! Project version number for Smartech.
FOUNDATION_EXPORT double SmartechVersionNumber;

//! Project version string for Smartech.
FOUNDATION_EXPORT const unsigned char SmartechVersionString[];

// In this header, you should import all the public headers of your framework using statements like
// #import <Smartech/PublicHeader.h>

#import <Smartech/SMTNotificationServiceExtension.h>
#import <Smartech/SMTAppInboxViewController.h>
#import <Smartech/SMTAppInboxEvent.h>

NS_ASSUME_NONNULL_BEGIN

@class SMTNotifcationContentHandler, SmartechHandler;

typedef NS_ENUM(NSUInteger, SMTLogLevel) {
    SMTLogLevelVerbose = 1,
    SMTLogLevelDebug = 2,
    SMTLogLevelInfo = 3,
    SMTLogLevelWarn = 4,
    SMTLogLevelError = 5,
    SMTLogLevelFatal = 6,
    SMTLogLevelNone = 7,
};

/**
 @brief SMTAppInboxMessageStatus is an enum for APP Inbox notificaiton message status.
 */
typedef NS_ENUM(NSUInteger, SMTAppInboxMessageStatus) {
    VIEWED, READ, DELETED
};

typedef NS_ENUM(NSUInteger, SMTAppInboxMessageType) {
    ALL_MESSAGE, INBOX_MESSAGE, READ_MESSAGE, UNREAD_MESSAGE
};

typedef void (^AppInboxCompletionBlock) (NSArray <SMTAppInboxEvent *> * _Nullable inboxMessages, NSError * _Nullable error);

typedef void (^AppInboxMediaDownloadAndSaveCompletionBlock) (NSString * _Nullable mediaPath, NSError * _Nullable error);


@protocol SmartechDelegate <NSObject>

@optional


/**
 @brief This is Smartech SDK's delegate method for deeplink handling along with custom payload. This delegate method will be triggered when the user clicks the push notification or deeplink
 
 @param deeplinkURLString - Deeplink string that is passed on push nofitication or inapp message click.
 @param customPayload - Contains url parameters in dictionary format.
 */
- (void)handleDeeplinkActionWithURLString:(NSString *)deeplinkURLString andCustomPayload:(NSDictionary *_Nullable)customPayload;


@end


@interface Smartech : NSObject

@property (nonatomic, copy, readonly) NSString *appGroup;
@property (nonatomic, weak, readonly) id <SmartechDelegate> delegate;
@property (nonatomic, strong, readonly) SmartechHandler *smartechHandler;
@property (nonatomic, strong, readonly) SMTNotifcationContentHandler *notifcationContentHandler;


#pragma mark - SDK Init Methods

/**
 @brief This method returns the Smartech instance.
 
 @return The Smartech instance object.
 */
+ (instancetype)sharedInstance;

/**
 @brief This method is for intialiazing the Smartech SDK.
 
 @discussion You need to call this method inside your app delegates didFinishLaunchingWithOptions: method.
 
 You can use the below code.
 
 @code
 [Smartech sharedInstance] initSDKWithDelegate:self];
 @endcode
 
 @param delegate The Smartech delegate.
 */
- (void)initSDKWithDelegate:(id <SmartechDelegate>)delegate;


#pragma mark - Push Notification Methods

/**
 @brief This method is for registering for push notification with APNS using default configuration.
 
 @discussion You need to call this method if you want to show the push notification permission. By default the SDK will support sound, alert & badge.
 
 You can use the below code.
 
 @code
 [Smartech sharedInstance] registerForPushNotificationWithDefaultAuthorizationOptions];
 @endcode
 */
- (void)registerForPushNotificationWithDefaultAuthorizationOptions;

/*!
 @brief This method is for registering for push notification with APNS.
 
 @discussion When you call this method you will see the push notification permission alert.
 
 You can use the below code.
 
 @code
 UNAuthorizationOptions options = (UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge);
 [Smartech sharedInstance] registerForPushNotificationWithAuthorizationOptions:options];
 @endcode
 
 @remark You don't need to call.
 
 @code
 [[UIApplication sharedApplication] registerForRemoteNotifications];
 @endcode
 
 @param options The notification authorization constant like alert, badge, sound etc.
 */
- (void)registerForPushNotificationWithAuthorizationOptions:(UNAuthorizationOptions)options;

/**
 @brief This method is for capturing the device token that the app will receive from Apple Push Notification Service (APNS). The method will send the device token to Smartech backend.
 
 @discussion This method should be called inside the didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
 @endcode
 
 @param deviceToken The unique device token recieved from APNS.
 */
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 @brief This method is used for capuring the error that may occur if the app was unable to register your device with APNS or if your app is not properly configured for remote notifications.
 
 @discussion This method should be called inside the didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didFailToRegisterForRemoteNotificationsWithError:error];
 @endcode
 
 @param error An NSError object that encapsulates information why registration did not succeed. The app can choose to display this information to the user.
 */
- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/**
 @brief This method to process incoming remote notifications for your app.
 
 @discussion This method should be called inside the didReceiveRemoteNotification:fetchCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didReceiveRemoteNotification:userInfo];
 @endcode
 
 @param userInfo A dictionary that contains information related to the remote notification, potentially including a badge number for the app icon, an alert sound, an alert message to display to the user, a notification identifier, and custom data.
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 @brief The method will be called on the delegate only if the application is in the foreground. The application can choose to have the notification presented as a sound, badge, alert and/or in the notification list.
 
 @discussion This method should be called inside the userNotificationCenter:willPresentNotification:withCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] willPresentForegroundNotification:notification];
 @endcode
 
 @param notification The notification object that is about to be delivered.
 */
- (void)willPresentForegroundNotification:(UNNotification *)notification;

/**
 @brief The method will be called on the delegate when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction.
 
 @discussion This method should be called inside the userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didReceiveNotificationResponse:response];
 @endcode
 
 @param response The user’s response to the notification. This object contains the original notification and the identifier string for the selected action.
 */
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response;

/**
 @brief The method will be called to get the total notiFication badge count.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getNotificationBadgeCount];
 @endcode
 
 @return NSInteger The notificaiton badge count.
 */
- (NSInteger)getNotificationBadgeCount;


#pragma mark - Carousel Push Notifications Methods

/**
 @brief This method used to load the carousel view for the push notification.
 
 @discussion This method needs to called inside the Notification Content Extensions's viewDidLoad method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] loadCustomNotificationContentView:view];
 @endcode
 
 @param view The view object
 */
- (void)loadCustomNotificationContentView:(UIView *)view;

/**
 @brief Method will call when the user made 3D touch on the notification, This method for displaying carousel Notification.
 
 @discussion This method needs to called inside the Notification Content Extensions's didReceiveNotification: method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didReceiveCustomNotification:notification];
 @endcode
 
 @param notification The notification object that arrived.
 */
- (void)didReceiveCustomNotification:(UNNotification *)notification;

/**
 @brief This method used to call when the user taps on one of the notification action buttons. The completion handler can be called after handling the action to dismiss the notification and forward the action to the app if necessary for Carousel Push Notification.
 
 @discussion This method needs to called inside the Notification Content Extensions's didReceiveNotificationResponse:completionHandler: method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] didReceiveCustomNotificationResponse:response completionHandler:^(UNNotificationContentExtensionResponseOption option) {
 completion(option);
 }];
 @endcode
 
 @param response The response object that identifies the user-selected action.
 @param completion The block to execute when you are finished performing the action.
 */
- (void)didReceiveCustomNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption option))completion;


#pragma mark - Debugging Methods

/**
 @brief Set the debug logging level
 
 @discussion Set using SMTLogLevel enum values or the corresponding int values.
 
 SMTLogLevelVerbose     - enables all logging.
 SMTLogLevelDebug       - enables verbose debug logging.
 SMTLogLevelInfo        - enables minimal information related to SDK integration.
 SMTLogLevelWarn        - enables warning information related to SDK integration.
 SMTLogLevelError       - enables errorn information related to SDK integration.
 SMTLogLevelFatal       - enables crash information related to SDK integration.
 SMTLogLevelNone        - turns off all SDK logging.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setDebugLevel:SMTLogLevelNone];
 @endcode
 
 @param level The debug level to set.
 */
- (void)setDebugLevel:(SMTLogLevel)level;


#pragma mark - Event Tracking Methods

/**
 @brief This method is used to track app install event.
 
 @discussion This method should be called by the developer to track the app install event to Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppInstall];
 @endcode
 */
- (void)trackAppInstall;

/**
 @brief This method is used to track app update event.
 
 @discussion This method should be called by the developer to track the app updates event to Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppUpdate];
 @endcode
 */
- (void)trackAppUpdate;

/**
 @brief This method is used to track app install or update event by Smartech SDK itself.
 
 @discussion This method should be called by the developer to track the app install or update event by Smartech SDK itself. If you are calling this method then you should not call trackAppInstall or trackAppUpdate method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppInstallUpdateBySmartech];
 @endcode
 */
- (void)trackAppInstallUpdateBySmartech;

/**
 @brief This method is used to track custom event done by the user.
 
 @discussion This method should be called by the developer to track any custom activites that is performed by the user in the app to Smartech backend.
 
 You can use the below code.
 
 @code
 NSDictionary *payloadDictionary = @{};
 [[Smartech sharedInstance] trackEvent:@"Event Name" andPayload:payloadDictionary];
 @endcode
 
 @param eventName The event name to be tracked.
 @param payloadDictionary The payload as dictionary which has event related parameters
 */
- (void)trackEvent:(NSString *)eventName andPayload:(NSDictionary * _Nullable)payloadDictionary;

/**
 @brief This method is used to send login event to Smartech backend.
 
 @discussion This method should be called only when the app gets the user's identity or when the user does a login activity in the application.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] login:@"Your Primary Key Configured In Smartech Panel"];
 @endcode
 
 @param userIdentity The user's primary key as configured in the Smartech Panel.
 */
- (void)login:(NSString *)userIdentity;

/**
 @brief This method would logout the user and clear identity on Smartech backend.
 
 @discussion This method should be called only when the user log out of the application.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] logoutAndClearUserIdentity:YES];
 @endcode
 
 @param clearUserIdentity Yes or No.
 */
- (void)logoutAndClearUserIdentity:(BOOL)clearUserIdentity;

/**
 @brief This method would set the user identity locally and with all subsequent events this identity will be send.
 
 @discussion This method should be called only when the user gets the identity.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setUserIdentity:@"Your Primary Key Configured In Smartech Panel"];
 @endcode
 
 @param userIdentity The user identity.
 */
- (void)setUserIdentity:(NSString *)userIdentity;

/**
 @brief This method would get the user identity that is stored in the SDK.
 
 @discussion This method should be called to get the user's identity.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getUserIdentity];
 @endcode
 
 @return NSString The user identity saved in the SDK.
 */
- (NSString *)getUserIdentity;

/**
 @brief This method would clear the identity that is stored in the SDK.
 
 @discussion This method will clear the user's identity by removing it from.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] clearUserIdentity];
 @endcode
 */
- (void)clearUserIdentity;

/**
 @brief This method is used to update the user profile.
 
 @discussion This method should be called by the developer to update all the user related attributes to Smartech.
 
 You can use the below code.
 
 @code
 NSDictionary *payloadDictionary = @{};
 [[Smartech sharedInstance] updateUserProfile:payloadDictionary];
 @endcode
 
 @param payloadDictionary The payload as dictionary which has event related parameters
 */
- (void)updateUserProfile:(NSDictionary *)payloadDictionary;


#pragma mark - GDPR Methods

/**
 @brief This method is used to opt tracking.
 
 @discussion If you call this method then we will opt in or opt out the user of tracking.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] optTracking:NO];
 @endcode
 
 @param isOpted Boolean variable to set tracking.
 */
- (void)optTracking:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt tracking.
 
 @discussion If you call this method you will get the current status of the tracking which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] hasOptedTracking];
 @endcode
 
 @return BOOL The current status of opt tracking
 */
- (BOOL)hasOptedTracking;

/**
 @brief This method is used to opt push notifications.
 
 @discussion If you call this method then we will opt in or opt out the user of recieving push notifications.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] optPushNotification:NO];
 @endcode
 
 @param isOpted Boolean variable to set tracking.
 */
- (void)optPushNotification:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt push notification.
 
 @discussion If you call this method you will get the current status of the tracking which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] hasOptedPushNotification];
 @endcode
 
 @return BOOL The current status of opt push notifications.
 */
- (BOOL)hasOptedPushNotification;

/**
 @brief This method is used to opt in-app messages.
 
 @discussion If you call this method then we will opt in or opt out the user of in-app messages.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] optInAppMessage:YES];
 @endcode
 
 @param isOpted Boolean variable to set in-app messages.
 */
- (void)optInAppMessage:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt in-app messages.
 
 @discussion If you call this method you will get the current status of the opt in-app messages which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] hasOptedInAppMessage];
 @endcode
 
 @return BOOL The current status of opt push notifications.
 */
- (BOOL)hasOptedInAppMessage;


#pragma mark - Location Methods

/**
 @brief This method is used to set the user's location to the SDK.
 
 @discussion You need to call this method to set location which will be passed on the Smartech SDK.
 
 You can use the below code.
 
 @code
 CLLocationCoordinate2D c2D = CLLocationCoordinate2DMake(lat, lon);
 [[Smartech sharedInstance] setUserLocation:c2D];
 @endcode
 
 @param location The user's locations to be passed with the events.
 */
- (void)setUserLocation:(CLLocationCoordinate2D)location;


#pragma mark - Helper Methods

/**
 @brief This method is used to get the device push token used by Smartech SDK.
 
 @discussion If you call this method you will get the device push token which is used for sending push notification.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getDevicePushToken];
 @endcode
 
 @return NSString The device push token.
 */
- (NSString *)getDevicePushToken;

/**
 @brief This method is used to get the device unique id used by Smartech SDK.
 
 @discussion If you call this method you will get the device unique id which is used to identify a device on Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getDeviceGuid];
 @endcode
 
 @return NSString The unique device id.
 */
- (NSString *)getDeviceGuid;

/**
 @brief This method is used to manually process events.
 
 @discussion If you call this method the Smartech SDK will start the processing immediately.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] processEventsManually];
 @endcode
 */
- (void)processEventsManually;

/**
 @brief This method is used to print all the Smartech related values stored in NSUserDefault.
 
 @discussion If you call this method you will be able to get all the Smartech related values stored in NSUserDefault.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getSmartechStoredPreference];
 @endcode
 */
- (NSDictionary *)getSmartechStoredPreference;

/**
 @brief This method is used to get the a URL after adding Smartech attribution parameters.
 
 @discussion This method should be called by the developer if you want to track attribution from your app to your website. Your website should be integrated with Smartech JavaScript Library. When you call the method we will add the query parameters to the provided NSURL.
 
 You can use the below code.
 
 @code
 NSURL *deeplinkURL = [NSURL URLWithString:@"https://netcoresmartech.com/"];
 NSURL *smartechAttributedURL = [[Smartech sharedInstance] getSmartechAttributedURL:deeplinkURL];
 @endcode
 
 @param deeplinkURL The url to which the attribution is to be added.
 @return NSURL The complete URL with the Smartech attribution parameter.
 */
- (NSURL *)getSmartechAttributedURL:(NSURL *)deeplinkURL;

/**
 @brief This method is used to check is the notification is from Smartech or not.
 
 @param userInfo The notification payload.
 
 @return BOOL If YES then notification is from Smartech.
 */
- (BOOL)isNotificationFromSmartech:(NSDictionary *)userInfo;


@end

NS_ASSUME_NONNULL_END
