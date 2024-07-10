#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
#ifndef APPFLOWSDK_SWIFT_H
#define APPFLOWSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreFoundation;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="AppflowSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)
@class NSString;
@class SKProduct;
@class SKPaymentTransaction;
@class IMSubscriber;
@class NSData;
enum AttributionNetwork : NSUInteger;
@class GetAttributionResponse;

SWIFT_CLASS("_TtC10AppflowSDK7Appflow")
@interface Appflow : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) Appflow * _Nonnull shared;)
+ (Appflow * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (void)configure;
- (void)setPurchasesLogsWithEnabled:(BOOL)enabled;
- (void)setAnalyticsLogsWithEnabled:(BOOL)enabled;
- (void)getPurchaseProductIds:(void (^ _Nonnull)(NSArray<NSString *> * _Nullable, NSError * _Nullable))completion;
- (void)getSkuDetailsWithProductIds:(NSSet<NSString *> * _Nonnull)productIds completion:(void (^ _Nullable)(NSDictionary<NSString *, SKProduct *> * _Nullable, NSError * _Nullable))completion;
- (void)purchaseSKProduct:(SKProduct * _Nonnull)product completion:(void (^ _Nonnull)(SKPaymentTransaction * _Nonnull, IMSubscriber * _Nonnull, NSError * _Nullable, BOOL))completion;
- (void)purchaseFetchReceiptSKProduct:(SKProduct * _Nonnull)product completion:(void (^ _Nonnull)(SKPaymentTransaction * _Nonnull, NSArray<SKPaymentTransaction *> * _Nonnull, NSData * _Nullable, NSError * _Nullable))completion;
- (void)finishTransactions:(NSArray<SKPaymentTransaction *> * _Nonnull)transactions;
- (void)addMonitorTransationCompletionHandlerWithCompletion:(void (^ _Nonnull)(SKPaymentTransaction * _Nonnull, NSArray<SKPaymentTransaction *> * _Nonnull, NSData * _Nullable, NSError * _Nullable))completion;
- (BOOL)canMakePayment SWIFT_WARN_UNUSED_RESULT;
- (void)hasActiveSubscription:(void (^ _Nonnull)(IMSubscriber * _Nonnull, NSError * _Nullable))completion;
- (void)restorePurchases:(void (^ _Nonnull)(IMSubscriber * _Nonnull, NSError * _Nullable))completion;
- (void)uploadUserInfo;
/// uploadUserInfo
/// \param userId App current userID (optional)
///
/// \param extraAttribute userInfo date
/// field : type
/// username : String
/// email    : String
/// phone    : String
/// gender   : number  // FEMALE = 1,  MALE   = 2,  OTHER  = 3,
/// age      : number
/// …
///
/// \param completion uploadUserInfo to back
///
- (void)uploadUserInfoWithUserId:(NSString * _Nullable)userId extraAttribute:(NSDictionary<NSString *, id> * _Nonnull)extraAttribute completion:(void (^ _Nullable)(BOOL, NSError * _Nullable))completion;
- (NSString * _Nonnull)getAppUserId SWIFT_WARN_UNUSED_RESULT;
- (void)uploadDeviceInfoWithDeviceToken:(NSString * _Nonnull)deviceToken completion:(void (^ _Nonnull)(BOOL, NSError * _Nullable))completion;
- (void)updateAttribution:(NSDictionary * _Nonnull)attribution source:(enum AttributionNetwork)source networkUserId:(NSString * _Nullable)networkUserId completion:(void (^ _Nullable)(GetAttributionResponse * _Nullable, NSError * _Nullable))completion;
/// This method is a convenient way to <code>updateAttribution</code> when the value of attribution_source = custom
/// Note: This method is only for custom attribution
/// The parameter can be empty, note: when it is empty, there is no data in the <code>Appflow dashboard</code>, Be careful with empty fields
/// \param channel Corresponding to <code>channel</code> on the Appflow dashboard
///
/// \param campaign Corresponding to <code>campaign</code> on the Appflow dashboard,
///
/// \param adGroup Corresponding to ad <code>ad group</code> on the Appflow dashboard
///
/// \param creative Corresponding to <code>creative</code> on the Appflow dashboard
///
/// \param clickID Currently just saving data
///
/// \param completion Callback after data reporting is complete
///
- (void)updateCustomAttributionWithChannel:(NSString * _Nonnull)channel campaign:(NSString * _Nullable)campaign adGroup:(NSString * _Nullable)adGroup creative:(NSString * _Nullable)creative clickID:(NSString * _Nullable)clickID completion:(void (^ _Nullable)(GetAttributionResponse * _Nullable, NSError * _Nullable))completion;
- (void)loadPaywallToPurachaseWithCompletion:(void (^ _Nonnull)(BOOL, NSString * _Nullable))completion;
- (void)uploadBigDataWithTypeWithEventName:(NSString * _Nonnull)eventName params:(NSDictionary * _Nullable)params;
- (void)setInAppMesssageAutoShowWithIsAuto:(BOOL)isAuto;
- (void)setFromBackgroudPointToDelayTimeWithDelayTime:(NSTimeInterval)delayTime;
- (BOOL)sendUserNotificationCenterMessageWithUserInfo:(NSDictionary * _Nonnull)userInfo SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNumber;

@interface Appflow (SWIFT_EXTENSION(AppflowSDK))
/// This method is used to fetch the exchange rate for a specified currency code. It takes a currency code as input and asynchronously returns the exchange rate relative to a base currency (usually USD or another benchmark currency).
/// \param currencyCode standard(ISO 4217) currency code(e.g., “USD”, “EUR”, “JPY”).
///
/// \param completion A closure that takes two parameters:
/// <ul>
///   <li>
///     Double:  An <code>NSNumber</code> object representing the currency exchange rate. This value will be <code>nil</code> if the retrieval fails.
///   </li>
///   <li>
///     Error?: An error object if the request fails; if the request is successful, this will be nil.
///   </li>
/// </ul>
///
- (void)getCurrencyRateWithCurrencyCode:(NSString * _Nonnull)currencyCode completion:(void (^ _Nonnull)(NSNumber * _Nullable, NSError * _Nullable))completion;
@end

enum IMPromotingInAppPurchaseStatus : int32_t;
@protocol IMPromotingObserverProtocol;

@interface Appflow (SWIFT_EXTENSION(AppflowSDK))
/// This interface is used to configure whether to continue transactions from the App Store when promoting in-app purchases. By default, this is set to <code>IM_CONTINUE</code>.
/// \param status <code>IMPromotingInAppPurchaseStatus</code> types, is used to specify the promotion within the purchasing behavior. You can select <code>IM_CONTINUE</code>, <code>IM_DEFER_PAYMENT</code>, or <code>IM_CANCEL_PAYMENT</code>.
///
/// \param addObserver Follow <code>IMPromotingObserverProtocol</code> observer object of the agreement, the purchase within the time to deal with the promotion of related operations.
///
- (void)setInAppPurchasePromotingStatus:(enum IMPromotingInAppPurchaseStatus)status addObserver:(id <IMPromotingObserverProtocol> _Nonnull)addObserver;
@end

@class IMOfferSignatureDetail;
@class SKPaymentDiscount;

@interface Appflow (SWIFT_EXTENSION(AppflowSDK))
/// A signature is a unique string that your server generates using specified parameters and your private key. You include it in the signature parameter of SKPaymentDiscount, and the App Store uses it to validate the promotional offer.
/// \param productId Product Identifier
///
/// \param offerId Discount identifier
///
/// \param userid App user id
///
/// \param completion IMOfferSignatureDetail And Error
///
- (void)createASignatureWithProductId:(NSString * _Nonnull)productId offerId:(NSString * _Nonnull)offerId userid:(NSString * _Nonnull)userid completion:(void (^ _Nonnull)(IMOfferSignatureDetail * _Nullable, NSError * _Nullable))completion;
/// <code>paymentDiscount</code> was launched after iOS12.2. Only systems after iOS12.2 can use this interface.
- (void)purchaseSKProductWithDiscount:(SKProduct * _Nonnull)product paymentDiscount:(SKPaymentDiscount * _Nonnull)paymentDiscount applicationUsername:(NSString * _Nullable)applicationUsername completion:(void (^ _Nonnull)(SKPaymentTransaction * _Nonnull, IMSubscriber * _Nonnull, NSError * _Nullable, BOOL))completion SWIFT_AVAILABILITY(ios,introduced=12.2);
@end


@interface Appflow (SWIFT_EXTENSION(AppflowSDK))
/// Configure notifications to automatically enable behavior statistics
- (void)setAutoUserNotificationBehaviorDataReporting;
/// After the user connects to the message push process, choose to send statistics manually
- (void)sendNotificationUserInfoToBehaviorDataReportingWithUserInfo:(NSDictionary * _Nonnull)userInfo;
@end

@class NSCoder;

SWIFT_CLASS("_TtC10AppflowSDK18AppflowWelcomePage")
@interface AppflowWelcomePage : UIView
- (void)awakeFromNib;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSUInteger, AttributionNetwork, open) {
  AttributionNetworkAdjust = 0,
  AttributionNetworkAppsflyer = 1,
  AttributionNetworkBranch = 2,
  AttributionNetworkAppleSearchAds = 3,
  AttributionNetworkFacebook = 4,
  AttributionNetworkCustom = 5,
};


SWIFT_CLASS("_TtC10AppflowSDK11IMAnalytics")
@interface IMAnalytics : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10AppflowSDK19IMDeviceInfoManager")
@interface IMDeviceInfoManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC10AppflowSDK13IMEntitlement")
@interface IMEntitlement : NSObject
/// product group id
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
/// Expiration time of the subscription (millisecond)
@property (nonatomic, readonly) int64_t expireAt;
/// product subscription\purchase status,
/// true: subscribed\purchased; false: unsubscribed\unpurchased
@property (nonatomic, readonly) BOOL isActive;
/// product Id
@property (nonatomic, readonly, copy) NSString * _Nonnull productId;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC10AppflowSDK18IMInAppMessagePage")
@interface IMInAppMessagePage : UIView
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC10AppflowSDK22IMOfferSignatureDetail")
@interface IMOfferSignatureDetail : NSObject
/// keyIdentifier in SKPaymentDiscount
@property (nonatomic, readonly, copy) NSString * _Nonnull keyIdentifier;
/// signature in SKPaymentDiscount
@property (nonatomic, readonly, copy) NSString * _Nonnull signature;
/// nonce in SKPaymentDiscount
@property (nonatomic, readonly, copy) NSString * _Nonnull nonce;
/// timestamp in SKPaymentDiscount
@property (nonatomic, readonly) int64_t timestamp;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC10AppflowSDK9IMProduct")
@interface IMProduct : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
@property (nonatomic, readonly, strong) SKProduct * _Nonnull product;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

/// When promoting in-app purchases, configure whether to continue transactions from the App Store. The default setting is <code>IM_CONTINUE</code>
typedef SWIFT_ENUM(int32_t, IMPromotingInAppPurchaseStatus, open) {
  IMPromotingInAppPurchaseStatusIM_CONTINUE = 0,
  IMPromotingInAppPurchaseStatusIM_DEFER_PAYMENT = 1,
  IMPromotingInAppPurchaseStatusIM_CANCEL_PAYMENT = 2,
};

@class SKPayment;

SWIFT_PROTOCOL("_TtP10AppflowSDK27IMPromotingObserverProtocol_")
@protocol IMPromotingObserverProtocol <NSObject>
- (void)imPromotingAddStorePaymentWithStatus:(enum IMPromotingInAppPurchaseStatus)status payment:(SKPayment * _Nonnull)payment product:(SKProduct * _Nonnull)product;
@end


SWIFT_CLASS("_TtC10AppflowSDK10IMPurchase")
@interface IMPurchase : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) IMPurchase * _Nonnull shared;)
+ (IMPurchase * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (void)configureInitSDKWithAppFlowPlist;
- (void)getSkuDetailsWithProductIds:(NSSet<NSString *> * _Nonnull)productIds completion:(void (^ _Nullable)(NSDictionary<NSString *, SKProduct *> * _Nullable, NSError * _Nullable))completion;
- (void)hasActiveSubscription:(void (^ _Nonnull)(IMSubscriber * _Nonnull, NSError * _Nullable))completion;
- (void)restorePurchases:(void (^ _Nonnull)(IMSubscriber * _Nonnull, NSError * _Nullable))completion;
- (void)enableLog:(BOOL)isEnable;
- (BOOL)isSandbox SWIFT_WARN_UNUSED_RESULT;
- (void)invalidateCache;
- (void)getPurchaseProductIds:(void (^ _Nonnull)(NSArray<NSString *> * _Nullable, NSError * _Nullable))completion;
- (BOOL)getUserIsActive SWIFT_WARN_UNUSED_RESULT;
/// uploadUserInfo
/// \param userId App current userID (optional)
///
/// \param extraAttribute userInfo date
/// field : type
/// username : String
/// email    : String
/// phone    : String
/// gender   : number  // FEMALE = 1,  MALE   = 2,  OTHER  = 3,
/// age      : number
/// …
///
/// \param completion uploadUserInfo to back
///
- (void)uploadUserInfoWithUserId:(NSString * _Nullable)userId extraAttribute:(NSDictionary<NSString *, id> * _Nonnull)extraAttribute completion:(void (^ _Nullable)(BOOL, NSError * _Nullable))completion;
- (NSString * _Nonnull)getAppUserId SWIFT_WARN_UNUSED_RESULT;
- (void)uploadDeviceInfoWithDeviceToken:(NSString * _Nonnull)deviceToken completion:(void (^ _Nonnull)(BOOL, NSError * _Nullable))completion;
- (void)updateAttribution:(NSDictionary * _Nonnull)attribution source:(enum AttributionNetwork)source networkUserId:(NSString * _Nullable)networkUserId completion:(void (^ _Nullable)(GetAttributionResponse * _Nullable, NSError * _Nullable))completion;
- (void)updateCustomAttributionWithChannel:(NSString * _Nonnull)channel campaign:(NSString * _Nullable)campaign adGroup:(NSString * _Nullable)adGroup creative:(NSString * _Nullable)creative clickID:(NSString * _Nullable)clickID completion:(void (^ _Nullable)(GetAttributionResponse * _Nullable, NSError * _Nullable))completion;
@end








SWIFT_CLASS("_TtC10AppflowSDK16IMRequestManager")
@interface IMRequestManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class IMSubscription;

SWIFT_CLASS("_TtC10AppflowSDK12IMSubscriber")
@interface IMSubscriber : NSObject
/// product id
@property (nonatomic, readonly, copy) NSString * _Nonnull productId;
/// Expiration time of the subscription (millisecond)
@property (nonatomic, readonly) int64_t expireAt;
/// product subscription\purchase status,
/// true: subscribed\purchased; false: unsubscribed\unpurchased
@property (nonatomic, readonly) BOOL isActive;
/// check entitlement for current status
@property (nonatomic, copy) NSArray<IMEntitlement *> * _Nonnull imEntitlements;
/// subscription details by product_id
@property (nonatomic, copy) NSArray<IMSubscription *> * _Nonnull imSubscriptions;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(int32_t, IMSubscriberStatus, open) {
/// Not currently used
/// The receipt is out of date or there is another purchase issue.
/// *
  IMSubscriberStatusIM_MISSING_PURCH_INFO = 0,
/// The receipt is expired but the subscription is still in a billing-retry state.
/// If grace period is enabled, this state excludes subscriptions in grace period.
/// *
  IMSubscriberStatusIM_EXPIRED_IN_RETRY = -1,
/// The receipt is fully expired due to a billing issue.
  IMSubscriberStatusIM_EXPIRED_FROM_BILLING = -2,
/// The customer did not accept the price increase.
  IMSubscriberStatusIM_FAIL_TO_ACCEPT_INCREASE = -3,
/// The product is no longer available.
  IMSubscriberStatusIM_PROD_NOT_AVAILABLE = -4,
/// The customer intentionally cancelled the subscription.
  IMSubscriberStatusIM_EXP_VOLUNTARILY = -5,
/// The system canceled the subscription because the customer upgraded.
  IMSubscriberStatusIM_Upgraded = -6,
/// The customer received a refund due to a perceived issue with the app.
  IMSubscriberStatusIM_ISSUE_REFUND = -7,
/// The customer received a refund for the subscription.
  IMSubscriberStatusIM_OTHER_REFUND = -8,
/// The receipt is expired and have been paused
  IMSubscriberStatusIM_EXPIRED_WITH_PAUSE = -9,
/// The subscription is active and have been paused
  IMSubscriberStatusIM_ACTIVE_BUT_PAUSE = 6,
/// The subscription is active and auto-renew is on.
  IMSubscriberStatusIM_ACTIVE_AUTO_REN_ON = 5,
/// The subscription is active and auto-renew is off.
  IMSubscriberStatusIM_ACTIVE_AUTO_REN_OFF = 4,
/// The subscription is a non-renewing subscription.
  IMSubscriberStatusIM_NON_REN_SUB = 3,
/// The subscription is an off-platform subscription.
  IMSubscriberStatusIM_OFF_PLATFORM_SUB = 2,
/// The subscription expired, but is in grace period.
  IMSubscriberStatusIM_EXPIRED_IN_GRACE = 1,
};

@class IMSubscriptionOriginalTransaction;

SWIFT_CLASS("_TtC10AppflowSDK14IMSubscription")
@interface IMSubscription : NSObject
/// product Id
@property (nonatomic, readonly, copy) NSString * _Nonnull productId;
/// SubscriptionState_State
@property (nonatomic, readonly) enum IMSubscriberStatus status;
/// Expiration time of the subscription (millisecond)
@property (nonatomic, readonly) int64_t expireAt;
/// Time to unsubscribe (millisecond)
@property (nonatomic, readonly) int64_t cancelAt;
/// The next subscription ID to switch: Product ID
@property (nonatomic, readonly, copy) NSString * _Nonnull willRenewTo;
/// Original transactions
@property (nonatomic, copy) NSArray<IMSubscriptionOriginalTransaction *> * _Nonnull originalTransactions;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC10AppflowSDK33IMSubscriptionOriginalTransaction")
@interface IMSubscriptionOriginalTransaction : NSObject
/// Original order note
@property (nonatomic, readonly, copy) NSString * _Nonnull originalTxid;
/// Time to start the subscription (millisecond)
@property (nonatomic, readonly) int64_t startAt;
/// Expiration time of the subscription (millisecond)
@property (nonatomic, readonly) int64_t expireAt;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC10AppflowSDK10ParamModel")
@interface ParamModel : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
