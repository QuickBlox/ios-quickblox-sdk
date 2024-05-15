//
//  QBAnswerAssistCompletionTypes.h
//
//  Created by QuickBlox team
//  Copyright (c) 2017 QuickBlox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class QBResponse;

/**Block with response instance and answerAssist*/
typedef void(^qb_response_answerAssist_block_t) (QBResponse *response, NSString *answerAssist);

NS_ASSUME_NONNULL_END
