//
//  MBProgressHUD+QW.h
//  QW_Http
//
//  Created by qwkj on 2017/11/28.
//  Copyright © 2017年 qwkj. All rights reserved.
//

#import <MBProgressHUD/MBProgressHUD.h>

@interface MBProgressHUD (QW)
+ (void)QW_hideHUD;

/**
 *  显示提示框，不带加载
 *
 *  @param message 提示信息
 *
 *  @return 提示框
 */
+(MBProgressHUD *)QW_showSingleMessage:(NSString *)message;
@end
