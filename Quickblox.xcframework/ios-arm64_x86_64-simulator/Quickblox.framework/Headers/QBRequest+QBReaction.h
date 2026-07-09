//
//  QBRequest+QBReaction.h
//  Quickblox
//
//  Created by QuickBlox on 08.06.2026.
//  Copyright © 2026 QuickBlox. All rights reserved.
//

#import <QuickBlox/QBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class QBReaction;

@interface QBRequest (QBReaction)

/// Add a reaction to a message.
///
/// Adds the specified reaction to the identified message. The operation fails if
/// the message has reached the maximum number of allowed reaction types, if you have
/// reached the maximum number of reactions allowed per message, if the message ID is
/// invalid or does not exist, or if the reaction value is invalid or missing.
///
/// @param reaction The reaction to add to the message.
/// @param messageId The identifier of the target message.
/// @param completion Block invoked when the operation finishes. The `error` argument is `nil` on success; otherwise it describes why the operation failed.
///
/// @note Calling this method again with the same reaction has no additional effect and completes successfully.
+ (void)addReaction:(QBReaction *)reaction
    toMessageWithId:(NSString *)messageId
         completion:(void (^)(NSError * _Nullable error))completion;

/// Remove a reaction from a message.
///
/// Fails if the reaction does not exist on the message, if the message is not found or not accessible, or if parameters are invalid.
///
/// @param reaction The reaction to remove from the message.
/// @param messageId The identifier of the message from which to remove the reaction.
/// @param completion Block invoked when the operation finishes. The `error` argument is `nil` on success; otherwise it describes why the operation failed.
+ (void)deleteReaction:(QBReaction *)reaction
     fromMessageWithId:(NSString *)messageId
            completion:(void (^)(NSError * _Nullable error))completion;

/// Fetches all reactions for the specified message.
///
/// @param messageId The unique identifier of the message whose reactions are being fetched. Must not be empty.
/// @param completion Block invoked on the main queue when the request finishes. On success, @c reactions is a non-nil array of @c QBReaction objects (possibly empty); @c error is @c nil. On failure, @c reactions is @c nil and @c error describes the reason.
///
/// @note The operation may fail if the message ID is invalid, the message does not exist, or you do not have access to the message.
+ (void)fetchReactionsWithMessageId:(NSString *)messageId
                         completion:(void (^)(NSArray<QBReaction *> * _Nullable reactions, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
