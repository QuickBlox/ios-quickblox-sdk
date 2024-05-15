//
//  QBAIRole.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickBlox/QBCEntity.h>


NS_ASSUME_NONNULL_BEGIN

// AI Role types
typedef NS_ENUM(NSUInteger, QBAIRoleType) {
    
    QBAIRoleTypeUser = 1,
    QBAIRoleTypeAssistant = 2,
};

@interface QBAIRole : QBCEntity <NSCoding, NSCopying>

/**
Type of role.
 */
@property (readonly) QBAIRoleType type;

/**
Name of role.
 */
@property (readonly) NSString *name;

// Unavailable initializers
- (id)init NS_UNAVAILABLE;
+ (id)new NS_UNAVAILABLE;

- (instancetype)initWithType:(QBAIRoleType)type;

@end

NS_ASSUME_NONNULL_END
