//
//  QBAnswerAssistMessage.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickBlox/QBCEntity.h>

NS_ASSUME_NONNULL_BEGIN

@class QBAnswerAssistHistoryMessage;

/**
 QBAnswerAssist class interface.
 This class represents QuickBlox Answer Assist Message.
 */
@interface QBAnswerAssistMessage : QBCEntity <NSCoding, NSCopying>

/**
 ID of Smart Chat Assistan of Your Application in QuickBlox Dashboard.
 */
@property (readonly) NSString *smartChatAssistantId;

/**
 Message you want to get answer for.
 */
@property (readonly) NSString *message;

/**
 Conversation history. Used to add context.
 */
@property (readonly) NSArray<QBAnswerAssistHistoryMessage *> *history;

// Unavailable initializers
- (id)init NS_UNAVAILABLE;
+ (id)new NS_UNAVAILABLE;

- (instancetype)initWithMessage:(NSString *)message
           smartChatAssistantId:(NSString *)smartChatAssistantId
                                     history:(NSArray<QBAnswerAssistHistoryMessage *> *)history;

- (instancetype)initWithMessage:(NSString *)message
           smartChatAssistantId:(NSString *)smartChatAssistantId;

@end

NS_ASSUME_NONNULL_END
