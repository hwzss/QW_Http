//
//  CIM_HTTPTool.h
//  CloudIM
//
//  Created by qwkj on 16/3/2.
//  Copyright © 2016年 qwkj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"

typedef void(^successBlock) (id responseDict);
typedef void (^failureBlock)(NSError *error);

typedef void(^SetParametersBlock)(NSMutableDictionary *params);
typedef void(^RequestSuccess)(id jsonData);
typedef void (^RequestError)(NSString *errorStr);
typedef void (^RequestConnectfailure)(BOOL *isShowErrorAlert);
@interface CIM_HTTPTool : NSObject


/**
 *  GET请求
 *
 *  @param URLString 用于创建请求url的urlstring
 *  @param params    请求参数
 *  @param success   请求成功时的回调
 *  @param failure   请求失败时的回调
 */
+(void)Cim_GET:(NSString *)URLString Parameters:(id)params Success:(successBlock)success Failure:(failureBlock)failur;

#pragma -mark 新版 请求带安全机制

#pragma -mark 发送请求3.0
/**
 *  调用接口
 *
 *  @param URLString      接口地址
 *  @param setParameters  设置接口参数，如params[@"token"]=token;
 *  @param success        接口请求成功回调，对于数据部分的json
 *  @param failure        接口请求成功，但返回失败时回调
 *  @param connectfailure 接口调用失败，连接错误时回调，isShowErrorAlert是
 */
+(void)CIM_POST_3:(NSString *)URLString
       parameters: (SetParametersBlock)setParameters
          success:(RequestSuccess)success
          failure:(RequestError)failure
   connectfailure:(RequestConnectfailure)connectfailure;
/**
 *  调用接口,需要自己指定超时时间
 *
 *  @param URLString      接口地址
 *  @param timeout       超时时间
 *  @param setParameters  设置接口参数，如params[@"token"]=token;
 *  @param success        接口请求成功回调，对于数据部分的json
 *  @param failure        接口请求成功，但返回失败时回调
 *  @param connectfailure 接口调用失败，连接错误时回调，isShowErrorAlert是
 */
+(void)CIM_POST_31:(NSString *)URLString
           Timeout:(NSTimeInterval)timeout
        parameters: (void(^)(NSMutableDictionary *params))setParameters
           success:(void (^)(id jsonData))success
           failure:(void (^)(NSString *errorStr))failure
    connectfailure:(void (^)(BOOL *isShowErrorAlert))connectfailure;

/**
 *  发送post请求，带安全机制，需要自己指定超时时间
 *
 *  @param URLString     url
 *  @param timeout       超时时间
 *  @param setParameters 设置请求参数回调
 *  @param success       成功回调
 *  @param failure       失败回调
 */
+(void)CIM_POST_21:(NSString *)URLString
           Timeout:(NSTimeInterval )timeout
       parameters: (void (^)(NSMutableDictionary *params))setParameters
          success:(void (^)(NSURLSessionDataTask * task, id responseObject))success
          failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;

/**
 *  发送post请求，带安全机制,超时时间为默认时间
 *
 *  @param URLString     url
 *  @param setParameters 设置请求参数回调
 *  @param success       成功回调
 *  @param failure       失败回调
 */
+(void)CIM_POST_2:(NSString *)URLString
 parameters: (void(^)(NSMutableDictionary *params))setParameters
    success:(void (^)(NSURLSessionDataTask * task, id responseObject))success
    failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;
/**
 *  发送post请求，带安全机制，可自定义请求体参数如超时时间等
 *
 *  @param URLString         url
 *  @param requestSerializer 请求体管理对象
 *  @param setParameters     设置请求参数回调
 *  @param success            成功回调
 *  @param failure           失败回调
 */
+(void)CIM_POST_22:(NSString *)URLString
RequestSerializer:(void(^)(AFHTTPRequestSerializer *aRequestSerializer,AFHTTPSessionManager *magr))requestSerializer
        parameters: (void(^)(NSMutableDictionary *params))setParameters
           success:(void (^)(NSURLSessionDataTask * task, id responseObject))success
           failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;
/**
 *  发送post请求，带安全机制，可自定义请求体参数如超时时间等
 *
 *  @param URLString         url
 *  @param requestSerializer 请求体管理对象
 *  @param setParameters     设置请求参数回调
 *  @param success           成功回调
 *  @param failure           失败回调
 *  @param connectfailure    链接失败回调
 */
+(void)CIM_POST_32:(NSString *)URLString
          RequestSerializer:(void(^)(AFHTTPRequestSerializer *aRequestSerializer,AFHTTPSessionManager *magr))requestSerializer
        parameters: (void(^)(NSMutableDictionary *params))setParameters
           success:(void (^)(id jsonData))success
           failure:(void (^)(NSString *errorStr))failure
    connectfailure:(void (^)(BOOL *isShowErrorAlert))connectfailure;


/**
 上传图片接口
 
 
 @param URLString urlStr
 @param setParameters 设置参数
 @param block 设置data
 @param success 成功
 @param failure 失败
 @param connectfailure 链接失败
 */
+(void)CIM_UploadImagesFile:(NSString *)URLString
                 parameters: (void(^)(NSMutableDictionary *params))setParameters
  constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                    success:(void (^)(id jsonData))success
                    failure:(void (^)(NSString *errorStr))failure
             connectfailure:(void (^)(BOOL *isShowErrorAlert))connectfailure;

/**
 带图片上传的请求
 
 @param URLString 接口地址
 @param setParameters 参数
 @param images 图片数组
 @param success 成功
 @param failure 失败
 @param connectfailure 链接失败
 */
+(void)CIM_UploadImagesFileV2:(NSString *)URLString
                   parameters: (void(^)(NSMutableDictionary *params))setParameters
                       ImageS:(NSMutableArray *)images
                      success:(void (^)(id jsonData))success
                      failure:(void (^)(NSString *errorStr))failure
               connectfailure:(void (^)(BOOL *isShowErrorAlert))connectfailure;

@end



