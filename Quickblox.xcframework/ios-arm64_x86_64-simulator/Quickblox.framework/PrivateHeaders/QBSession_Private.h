//
//  QBSession_Private.h
//  Quickblox
//
//  Created by QuickBlox team on 16/01/2014.
//  Copyright (c) 2016 QuickBlox. All rights reserved.
//

#import "QBSession.h"

@class QBTask;
@class QBResponse;
@class QBSessionParameters;
@class QBUpdateUserParameters;

typedef NS_ENUM(NSUInteger, QBSessionAuthType) {
    QBSessionAuthTypeNotSet = 0,
    QBSessionAuthTypeUsingLogin = 1,
    QBSessionAuthTypeUsingEmail = 2,
    QBSessionAuthTypeUsingSocialProvider = 3,
    QBSessionAuthTypeUsingFirebase = 5
};

@interface QBSession ()

/// User can start session with startSessionWithDetails:
/// Then we disable auto create session
@property (nonatomic, assign) BOOL manuallyCreated;

@property (nonatomic, copy) dispatch_block_t updateSessionBlock;

@property (nonatomic, readwrite) NSDate *sessionExpirationDate;
@property (nonatomic, strong) QBSessionParameters* sessionParameters;
@property (nonatomic, assign) QBSessionAuthType authType;

/// Auto create session initiated
- (void)startAutoSessionWithDetails:(QBASession *)session expirationDate:(NSDate *)sessionDate;

/// User initiated
- (void)startSessionWithDetails:(QBASession *)session expirationDate:(NSDate *)sessionDate;

- (void)startUpdateSessionUsingLogin:(NSString *)login password:(NSString *)password;
- (void)finishUpdateSessionUsingLogin:(QBUUser *)user password:(NSString *)password;

- (void)startUpdateSessionUsingEmail:(NSString *)email password:(NSString *)password;

- (void)finishUpdateSessionUsingEmail:(QBUUser *)user password:(NSString *)password;

- (void)startUpdateSessionUsingSocialProvider:(NSString *)socialProvider
                                  accessToken:(NSString *)accessToken
                                 accessSecret:(NSString *)accessSecret;

- (void)finishUpdateSessionUsingSocialProvider:(NSString *)socialProvider
                                   accessToken:(NSString *)accessToken
                                  accessSecret:(NSString *)accessSecret
                                          user:(QBUUser *)user;

- (void)startUpdateSessionUsingFirebase:(NSString *)socialProvider
                              projectID:(NSString *)projectID
                            accessToken:(NSString *)accessToken;

- (void)finishUpdateSessionUsingFirebase:(NSString *)socialProvider
                               projectID:(NSString *)projectID
                             accessToken:(NSString *)accessToken
                                    user:(QBUUser *)user;
//MARK: - Update User

- (void)updateSessionUser:(QBUUser *)user
                 password:(NSString *)password
                   params:(QBUpdateUserParameters *)params;
//MARK: - Restore / Reset
+ (QBSession *)restoreQBSession;
- (void)postLogoutNotification;
- (void)postLoginNotification;

//MARK: - Validate

- (void)updateExpirationDate:(NSDate *)newExpirationDate;
- (void)validateWithResponse:(QBResponse *)response;

@end
