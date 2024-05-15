//
//  QBSessionManager+Private.h
//  Quickblox
//
//  Created by Injoit on 21.09.2022.
//  Copyright © 2022 QuickBlox. All rights reserved.
//

#import "QBSessionManager.h"

@class QBTask;
@class QBSessionTimer;

NS_ASSUME_NONNULL_BEGIN

@interface QBSessionManager ()

@property (nonatomic, strong, readonly, nullable) QBSessionTimer *timer;

- (QBTask *)createSessionTaskForPath:(NSString *)path method:(NSString *)method;

- (void)updateSessionExperationDate:(NSDate *)date;
- (void)postSessionExpire;

@end

NS_ASSUME_NONNULL_END
