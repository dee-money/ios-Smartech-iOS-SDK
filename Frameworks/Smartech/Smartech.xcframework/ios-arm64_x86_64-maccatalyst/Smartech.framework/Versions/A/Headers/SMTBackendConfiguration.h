//
//  SMTBackendConfiguration.h
//  Smartech
//
//  Created by Netcore Solutions on 29/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SMTBaseURL;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SMTBackendEnvironment) {
    BackendEnvironmentProduction = 0,
    BackendEnvironmentPod = 1,
    BackendEnvironmentStaging = 2,
    BackendEnvironmentIndependent = 3,
};

typedef NS_ENUM(NSUInteger, BackendBaseURLType) {
    BackendBaseURLTypeAppInit = 0,
    BackendBaseURLTypeEvents = 1,
    BackendBaseURLTypePushAmp = 2,
    BackendBaseURLTypeInApp = 3,
    BackendBaseURLTypeInbox = 4,
    BackendBaseURLTypeCategory = 5,
    BackendBaseURLTypeListSegment = 6,
    BackendBaseURLTypeGetGeofences = 7
};


/**
 @brief  This class configures the backend.
 */
@interface SMTBackendConfiguration : NSObject

@property (nonatomic, readonly, copy) NSURL *baseAppInitURL;
@property (nonatomic, readonly, copy) NSURL *baseTrackAppActUrl;
@property (nonatomic, readonly, copy) NSURL *basePushAmpUrl;
@property (nonatomic, readonly, copy) NSURL *baseInAppUrl;
@property (nonatomic, readonly, copy) NSURL *baseInboxUrl;
@property (nonatomic, readonly, copy) NSURL *listSegmentUrl;
@property (nonatomic, readonly, copy) NSURL *geofencesUrl;
@property (nonatomic, readonly, copy) NSURL *getMessageCountUrl;

/**
 @brief Returns the global SMTBackendConfiguration instance.
 
 @return SMTBackendConfiguration instance.
 */
+ (instancetype)sharedInstance;

/**
 @brief Sets the Smartech environment.
 
 @param environment BackendEnvironment instance.
 */
- (void)setEnvironment:(SMTBackendEnvironment)environment;

/**
 @brief Sets the Smartech base URL for backend communication.
 
 @param URLString Backend base URL String.
 */
- (void)setBaseAppInitURLString:(NSString *)URLString;

/**
 @brief Sets the Smartech base URL for backend communication.
 
 @param baseURL Backend base URL object that contains all the base urls.
 */
- (void)setAllBaseURL:(SMTBaseURL *)baseURL;

@end

NS_ASSUME_NONNULL_END
