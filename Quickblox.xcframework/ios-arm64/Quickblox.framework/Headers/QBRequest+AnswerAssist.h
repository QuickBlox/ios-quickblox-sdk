//
//  QBRequest+AnswerAssist.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickBlox/QBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class QBAnswerAssistMessage;

@interface QBRequest (AnswerAssist)
/**
 Create answer assist request
 
 @param answerAssist answer assist instance
 
 @return An answer from AI'.
 */
+ (void)answerAssistWithMessage:(QBAnswerAssistMessage *)answerAssist
                 completion:(void (^) (NSString * _Nullable answer, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
