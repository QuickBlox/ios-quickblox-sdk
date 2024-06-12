//
//  AI.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class QBAnswerAssistMessage;
@class QBTranslateMessage;

@interface AI : NSObject
/**
 Create answer assist request
 
 @param answerAssist answer assist instance
 
 @return An answer from AI'.
 */
- (void)answerAssistWithMessage:(QBAnswerAssistMessage *)answerAssist
                 completion:(void (^) (NSString * _Nullable answer, NSError * _Nullable error))completion;
/**
 Create translate request
 
 @param translate translate message instance
 
 @return An answer from AI'.
 */
- (void)translateWithMessage:(QBTranslateMessage *)translate
                 completion:(void (^) (NSString * _Nullable answer, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
