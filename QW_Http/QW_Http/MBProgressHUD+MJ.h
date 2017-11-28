//
//  MBProgressHUD+MJ.h
//
//  Created by mj on 13-4-18.
//  Copyright (c) 2013年 itcast. All rights reserved.
//

#import "MBProgressHUD.h"

@interface MBProgressHUD (MJ)
+ (void)showSuccess:(NSString *)success toView:(UIView *)view;
+ (void)showError:(NSString *)error toView:(UIView *)view;

+ (MBProgressHUD *)showMessage:(NSString *)message toView:(UIView *)view;


+ (void)showSuccess:(NSString *)success;
+ (void)showError:(NSString *)error;
/**
 *  发送加载提示
 *
 *  @param message 没有网络的时候不会显示加载框
 *
 *  @return 有网返回加载框，无网返回nil
 */
+ (MBProgressHUD *)showMessage:(NSString *)message;

+ (void)hideHUDForView:(UIView *)view;
+ (void)hideHUD;
/**
 *  显示提示框，不带加载
 *
 *  @param message 提示信息
 *  @param view    显示的view
 *
 *  @return 提示框
 */
+(MBProgressHUD *)showSingleMessage:(NSString *)message toView:(UIView *)view;
/**
 *  显示提示框，不带加载
 *
 *  @param message 提示信息
 *
 *  @return 提示框
 */
+(MBProgressHUD *)showSingleMessage:(NSString *)message;
@end
