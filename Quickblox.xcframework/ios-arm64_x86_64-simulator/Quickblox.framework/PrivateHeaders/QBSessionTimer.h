//
//  QBSessionTimer.h
//  Quickblox
//
//  Created by Injoit on 12.09.2022.
//  Copyright © 2022 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, QBSessionTimerState) {
    QBSessionTimerStateActive,
    QBSessionTimerStatePause
};

NS_ASSUME_NONNULL_BEGIN

@interface QBSessionTimer : NSObject

@property (nonatomic, copy, readonly, nullable) dispatch_block_t expireSessionBlock;
@property (nonatomic, strong, readonly, nullable) NSDate *sessionExpirationDate;
@property (nonatomic, strong, readonly, nullable) NSTimer *timer;

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)queue;

- (void)startWithSessionExpirationDate:(NSDate *)date
state:(QBSessionTimerState)state
block:(dispatch_block_t)block;

- (void)stop;
- (void)resume;
- (void)invalidate;

// Unavailable initializers
+ (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
