//
//  QBAnswerAssistHistoryMessage.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Quickblox/Quickblox.h>

NS_ASSUME_NONNULL_BEGIN

@class QBAIRole;

/**
 QBAnswerAssistHistoryMessage class interface.
 This class represents QuickBlox Answer Assist History.
 */
@interface QBAnswerAssistHistoryMessage : QBCEntity <NSCoding, NSCopying>

/**
 The role of the message sender. Can be a user or assistant.
 */
@property (readonly) QBAIRole *role;

/**
 Message text in conversation history.
 */
@property (readonly) NSString *message;

// Unavailable initializers
- (id)init NS_UNAVAILABLE;
+ (id)new NS_UNAVAILABLE;

- (instancetype)initWithRole:(QBAIRole *)role
                     message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
