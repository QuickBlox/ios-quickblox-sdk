//
//  QBReaction.h
//  Quickblox
//
//  Created by QuickBlox team on 08.06.2026.
//  Copyright © 2026 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QBReaction : NSObject <NSCoding, NSCopying>

/**
 Type of reaction (e.g., "like", "love", "laugh").
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Total number of times this reaction has been used on the message.
 */
@property (nonatomic, assign) NSInteger count;

/**
 List of user IDs who have added this reaction to the message.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *userIDs;

/**
 Create new reaction.
 
 @param name   Reaction type to add (e.g. @c "like", @c "love", @c "haha").
                   Must not be empty.
 @return New QBReaction instance
 */
+ (QBReaction *)reactionWithName:(NSString *)name;

@end

/**
 Provides a stable identifier derived from the reaction's name.
 Use this extension when you need to uniquely identify a `QBReaction` instance,
 for example when storing reactions in Swift collections or conforming to the
 `Identifiable` protocol.
 */
@interface QBReaction (Identifiable)

/**
 A stable identifier derived from the reaction name.
 */
@property (nonatomic, readonly, nullable) NSString *reactionID NS_SWIFT_NAME(id);

@end

NS_ASSUME_NONNULL_END
