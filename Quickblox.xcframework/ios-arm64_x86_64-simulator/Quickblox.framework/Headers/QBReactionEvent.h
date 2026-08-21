//
//  QBReactionEvent.h
//  Quickblox
//
//  Created by QuickBlox team on 25.06.2026.
//  Copyright © 2026 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Describes whether a reaction was added to or removed from a message.
typedef NS_ENUM(NSUInteger, QBReactionEventAction) {
    /// The reaction was added to the message.
    QBReactionEventActionAdd,
    /// The reaction was removed from the message.
    QBReactionEventActionRemove,
};

/// Represents a single reaction change event received over XMPP.
///
/// Each event describes one reaction mutation (add or remove) for a specific message.
/// Clients apply these events incrementally to maintain the current reaction state.
@interface QBReactionEvent : NSObject <NSCoding, NSCopying>

/// The ID of the dialog containing the message.
@property (nonatomic, copy, nullable) NSString *dialogID;

/// The ID of the message that was reacted to.
@property (nonatomic, copy, nullable) NSString *messageID;

/// The name of the reaction (e.g., emoji or custom text).
@property (nonatomic, copy, nullable) NSString *reactionName;

/// The ID of the user who performed the action.
@property (nonatomic, assign) NSUInteger userID;

/// Whether the reaction was added or removed.
@property (nonatomic, assign) QBReactionEventAction action;

/// The timestamp when the action occurred.
@property (nonatomic, strong, nullable) NSDate *dateSent;

@end

NS_ASSUME_NONNULL_END
