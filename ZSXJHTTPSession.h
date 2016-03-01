//
//  ZSXJHTTPSession.h
//  AFTestDemo
//
//  Created by lynulzy on 8/21/15.
//  Copyright (c) 2015 ZSXJ. All rights reserved.
//

#import "AFHTTPSessionManager.h"

typedef void (^SuccessBlock) (NSURLSessionDataTask *task,id responseObject);
typedef void (^FailedBlcok) (NSURLSessionDataTask *task,NSError*theError);
typedef void (^NetworkChangeBlock) (AFNetworkReachabilityStatus status);
typedef void (^MonitorProgressBlock) (NSURLSession *session, NSURLSessionTask *task, int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);
@interface ZSXJHTTPSession : AFHTTPSessionManager
@property (nonatomic, readwrite, strong) UIActivityIndicatorView *actIndicator;
@property (nonatomic, readwrite, copy) NetworkChangeBlock networkChangeBlock;
@property (nonatomic, readonly, strong) NSString *userDefineServerURL;

+ (ZSXJHTTPSession *)sharedSession;

- (void)POST: (NSString *)actStr ReqParams: (NSDictionary *) params
     success: (SuccessBlock) succBlc
     failure: (FailedBlcok) failBlc;
/**
 *  @author lzy, 15-09-07 17:09:50
 *
 *  @brief  上传带图片的post请求
 *
 *  @param imgDict <#imgDict description#>
 *  @param theAct  <#theAct description#>
 *  @param params  <#params description#>
 *  @param succBlc <#succBlc description#>
 *  @param failBlc <#failBlc description#>
 */
- (void)uploadImage:(NSDictionary *) imgDict
              byAct:(NSString *) theAct
          ReqParams:(NSDictionary *) params
            success:(SuccessBlock) succBlc
            failure:(FailedBlcok) failBlc;
- (void)monitorUploadImage:(NSDictionary *)imgDict
              byAct:(NSString *)theAct
          ReqParams:(NSDictionary *)params
           monitorProgress:(MonitorProgressBlock) monitorBlock
                  progress: (NSProgress *) theProgress
            success:(SuccessBlock)succBlc
            failure:(FailedBlcok)failBlc;
@end
