//
//  SMTDeeplinkHelper.h
//  Smartech
//
//  Created by Netcore Solutions on 19/03/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^DeeplinkCompletion) (NSString * _Nullable deeplinkURLString, BOOL shouldBeControlledByDev, NSDictionary * _Nullable customPayload);


@interface SMTDeeplinkHelper : NSObject

/**
 @brief This method is used to handle deeplink through url scheme.
 
 @param deeplinkURL - parameters to be associated.
 @param completionBlock - the completion handler.
 */
+ (void)handleOpenURLScheme:(NSURL *)deeplinkURL
             withCompletion:(DeeplinkCompletion)completionBlock;

/**
 @brief This method is used to handle universal deeplink .
 
 @param userActivity - object provides a lightweight way to capture the state of your app.
 @param completionBlock - the completion handler.
 */
+ (void)handleUniversalLinkWithUserActivity:(NSUserActivity *)userActivity
                              andCompletion:(DeeplinkCompletion)completionBlock;

/**
 @brief This method is to know handle URL String.
 
 @param deeplinkURLString - Deeplink URL String.
 @param customPayload - Notification custom payload.
 @param completionBlock - the completion handler.
 */
+ (void)handleDeeplinkURLString:(NSString * _Nullable)deeplinkURLString
                  customPayload:(NSDictionary * _Nullable)customPayload
                 withCompletion:(DeeplinkCompletion)completionBlock;

@end

NS_ASSUME_NONNULL_END
