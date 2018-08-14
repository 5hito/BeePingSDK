//
//  BeePingServices.h
//  BeePingSDK
//
//  Created by Bee on 15-3-9.
//  Copyright (c) 2015年 Bee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "SimplePing.h"

typedef NS_ENUM(NSInteger, BeePingStatus) {
    BeePingStatusDidStart,
    BeePingStatusDidReceivePacket,
    BeePingStatusDidTimeout,
    BeePingStatusFinished,
};

@interface BeePingItem : NSObject

@property(nonatomic) NSString *originalAddress;
@property(nonatomic, copy) NSString *IPAddress;

@property(nonatomic) NSUInteger dateBytesLength;
@property(nonatomic) double     timeMilliseconds;
@property(nonatomic) NSInteger  timeToLive;
@property(nonatomic) NSInteger  ICMPSequence;

@property(nonatomic) BeePingStatus status;

+ (NSString *)statisticsWithPingItems:(NSArray *)pingItems;
+ (CGFloat)avgTimeWithPingItems:(NSArray *)pingItems;

@end

@interface BeePingServices : NSObject

/// 超时时间, default 500ms
@property(nonatomic) double timeoutMilliseconds;

+ (BeePingServices *)startPingAddress:(NSString *)address
                      callbackHandler:(void(^)(BeePingItem *pingItem, NSArray *pingItems))handler
                  errorCallBackHandle:(void(^)(NSError* error, NSString* errMsg))errorHandler;

@property(nonatomic) NSInteger  maximumPingTimes;
- (void)cancel;

@end
