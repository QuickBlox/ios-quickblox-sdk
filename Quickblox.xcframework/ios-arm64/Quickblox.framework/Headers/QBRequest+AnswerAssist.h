//
//  QBRequest+AnswerAssist.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuickBlox/QBRequest.h>
#import <QuickBlox/QBCompletionTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class QBAnswerAssistMessage;

@interface QBRequest (AnswerAssist)

/**
 Create answer assist request
 
 @param answerAssist answer assist instance
 @param successBlock Block with response and answer from AI String if the request is succeeded
 @param errorBlock Block with response instance if the request is failed.
 
 @return An instance of QBRequest for cancel operation mainly.
 */
+ (QBRequest *)answerAssist:(QBAnswerAssistMessage *)answerAssist
                 successBlock:(nullable qb_response_answerAssist_block_t)successBlock
                   errorBlock:(nullable qb_response_block_t)errorBlock;

/**
 Create answer assist request
 
 @param answerAssist answer assist instance
 
 @return An answer from AI'.
 */
+ (void)answerAssistWithMessage:(QBAnswerAssistMessage *)answerAssist
                 completion:(void (^) (NSString * _Nullable answer, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
