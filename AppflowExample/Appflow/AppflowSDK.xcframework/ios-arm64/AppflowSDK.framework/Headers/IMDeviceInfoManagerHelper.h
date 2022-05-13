//
//  IMDeviceInfoManagerHelper.h
//  ImplusAnalyticsSDK
//
//  Created by MAximiloan Boiko on 24.12.2021.
//  Copyright © 2021 lin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IMDeviceInfoManagerHelper : NSObject

+ (IMDeviceInfoManagerHelper *)sharedManager;
//Appkey
@property (nonatomic, strong) NSString *appKey;
//init with tage
@property (nonatomic, strong) NSString *tag;


/**
 Get mac address

 @return returns the mac address
 */

- (NSString *)getMacAddress;

- (BOOL)isReachable;
- (void)setNewAppKey:(NSString *) mewAppKey;

/**
 Get device memory size

 @return return memory size
 */
- (int32_t)getTotalMemorySize;

/**
 Get the available memory of the current device

 @return return available memory
 */
- (int32_t)getAvailableMemory;

/**
 Get accurate device power

 @return return battery
 */
- (CGFloat)getCurrentBatteryLevel;

- (NSNumber *)getDataNetworkItemView;

- (NSString *)getIPAddress:(BOOL)preferIPv4;

@end

