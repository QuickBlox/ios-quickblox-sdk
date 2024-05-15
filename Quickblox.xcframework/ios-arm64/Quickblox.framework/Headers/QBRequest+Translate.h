//
//  QBRequest+Translate.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickBlox/QBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class QBTranslateMessage;

@interface QBRequest (Translate)

/**
 Create translate request
 
 @param translate translate message instance
 
 @return An answer from AI'.
 */
+ (void)translateWithMessage:(QBTranslateMessage *)translate
                 completion:(void (^) (NSString * _Nullable answer, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
