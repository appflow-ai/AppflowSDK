//
//  IMRequest.h
//  ImplusAnalyticsSDK
//
//  Created by lin on 2019/12/17.
//  Copyright © 2019 lin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, IMRequestReliability){

    //If it is not sent successfully, put it into the scheduling queue and send it again
    IMRequestReliabilityRetry,

    //The request must be successful, if it is unsuccessful, it will be stored in the DB, and then continue to send when the network is good, similar to WeChat sending a message
    //It should be noted that this type of request does not require a callback
    //Similar to the success of sending WeChat
    //It is a request that must be successful. It only needs to be successful when there is a network.
    IMRequestReliabilityStoreToDB,

    //Ordinary request, success or failure does not affect the business, no need to resend
    //Similar to statistics, background pull requests such as local existing configuration
    IMRequestReliabilityNormal
};


static NSString *const kEventCrash NS_SWIFT_NAME(kEventCrash) =
@"falal_crash";
static NSString *const kEventName NS_SWIFT_NAME(kEventName) =
@"eventName";
static NSString *const kEventValue NS_SWIFT_NAME(kEventValue) =
@"eventValue";
static NSString *const kTimestamp NS_SWIFT_NAME(kTimestamp) =
@"timestamp";
static NSString *const kUserId NS_SWIFT_NAME(kUserId) =
@"userId";
@interface IMRequest : NSObject <NSCopying>

//Unique identifier stored in the database
@property (nonatomic, copy) NSString *requestId;

/**request parameter pair*/
@property (nonatomic, copy) NSDictionary *params;

/**
 Request repetition policy, default retransmission
 */
@property (nonatomic, assign) IMRequestReliability reliability;

/**
 The request was not sent successfully, the number of times to resend
 */
@property (nonatomic, assign, readonly) int retryCount;

/**
 params is directly converted to string storage
   This parameter has a corresponding effect only when the request needs to be stored in the database
   IMRequestReliabilityStoreToDB under this type
 */
@property (nonatomic, copy, readonly) NSString *paramStr;

- (void)reduceRetryCount;

@end

//
//  IMRequestMacro.h
//  ImplusAnalyticsSDK
//
//  Created by lin on 2019/12/17.
//  Copyright © 2019 lin. All rights reserved.
//

#ifndef IMRequestMacro_h
#define IMRequestMacro_h

typedef NS_ENUM(NSInteger, IMRequestType) {
    IMRequestTypeGet,
    IMRequestTypePost,
    IMRequestTypeDelete,
    IMRequestTypePut
};
#define SDKVersion @"1.1.1"

/// screen name ID (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kScreenViewName : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kScreenViewName NS_SWIFT_NAME(kScreenViewName) =
@"screeen_name";

/// placement (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kPlacement : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kPlacement NS_SWIFT_NAME(kPlacement) =
@"splacement";

/// ad_source (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kAdSource : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kAdSource NS_SWIFT_NAME(kAdSource) =
@"ad_source";

/// ad_source (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kFatalCrash : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kFatalCrash NS_SWIFT_NAME(kFatalCrash) =
@"kFatalCrash";

/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kFormat : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kFormat NS_SWIFT_NAME(kFormat) =
@"format";

/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kFormat : @"10_matches_won",
///       // ...
///     };
/// </pre>
static NSString *const kEngagementTimeMsec NS_SWIFT_NAME(kEngagementTimeMsec) =
@"engagement_time_msec";
/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kScreenViewName : kHomepage,
///       // ...
///     };
/// </pre>
static NSString *const kHomepage NS_SWIFT_NAME(kHomepage) =
@"homepage";

/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kScreenViewName : kHomepage,
///       // ...
///     };
/// </pre>
static NSString *const kSetting NS_SWIFT_NAME(kSetting) =
@"setting";
/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kScreenViewName : kSetting,
///       // ...
///     };
/// </pre>
static NSString *const kLockscreen NS_SWIFT_NAME(kLockscreen) =
@"lockscreen";
/// format (NSString).
/// <pre>
///     NSDictionary *params = @{
///       kPlacement : kQuickClean,
///       // ...
///     };
/// </pre>
static NSString *const kQuickClean NS_SWIFT_NAME(kQuickClean) =
@"quick_clean";
/// <pre>
///     NSDictionary *params = @{
///       kPlacement : kBoost,
///       // ...
///     };
/// </pre>
static NSString *const kBoost NS_SWIFT_NAME(kBoost) =
@"boost";
/// <pre>
///     NSDictionary *params = @{
///       kPlacement : kQuickClean,
///       // ...
///     };
/// </pre>
static NSString *const kInstall NS_SWIFT_NAME(kQuickClean) =
@"install";
/// <pre>
///     NSDictionary *params = @{
///       kAdSource : kFaceBook,
///       // ...
///     };
/// </pre>
static NSString *const kFaceBook NS_SWIFT_NAME(kFaceBook) =
@"facebook";
/// <pre>
///     NSDictionary *params = @{
///       kAdSource : kAdmob,
///       // ...
///     };
/// </pre>
static NSString *const kAdmob NS_SWIFT_NAME(kAdmob) =
@"admob";
/// <pre>
///     NSDictionary *params = @{
///       kAdSource : kFaceBook,
///       // ...
///     };
/// </pre>
static NSString *const kMobpup NS_SWIFT_NAME(kMobpup) =
@"mobpup";
/// <pre>
///     NSDictionary *params = @{
///       kFormat : kBanner,
///       // ...
///     };
/// </pre>
static NSString *const kBanner NS_SWIFT_NAME(kBanner) =
@"banner";
/// <pre>
///     NSDictionary *params = @{
///       kFormat : kInterstitial,
///       // ...
///     };
/// </pre>
static NSString *const kInterstitial NS_SWIFT_NAME(kInterstitial) =
@"inserstitial";
// Maximum number of concurrent
static const int _maxCurrentNum = 3;
//The timer queries the database every 60s
#define kTimerDuration 60

#endif /* IMRequestMacro_h */
