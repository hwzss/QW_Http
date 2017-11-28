//
//  MBProgressHUD+QW.m
//  QW_Http
//
//  Created by qwkj on 2017/11/28.
//  Copyright © 2017年 qwkj. All rights reserved.
//

#import "MBProgressHUD+QW.h"

#define delayTime 1.6

@implementation MBProgressHUD (QW)
#pragma -mark 显示信息，不带加载
+(MBProgressHUD *)showSingleMessage:(NSString *)message toView:(UIView *)view{
    if (view==nil)view=[[UIApplication sharedApplication].windows lastObject];
    MBProgressHUD *hud=[MBProgressHUD showHUDAddedTo:view animated:YES];
    hud.labelText=message;
    
    hud.removeFromSuperViewOnHide=YES;
    hud.mode=MBProgressHUDModeText;
    [hud hide:YES afterDelay:delayTime];
    return hud;
}
+(MBProgressHUD *)QW_showSingleMessage:(NSString *)message{
    return [self showSingleMessage:message toView:nil];
}

+ (void)hideHUDForView:(UIView *)view
{
    if (view == nil) view = [[UIApplication sharedApplication].windows lastObject];
    //    [self hideHUDForView:view animated:YES];
    //修改:由于有时lastobject并不是hud显示的view，所以这里修改一下，不是的话就遍历一下
    if (![self hideHUDForView:view animated:YES]) {
        [[UIApplication sharedApplication].windows enumerateObjectsUsingBlock:^(__kindof UIWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if (obj!=view){
                if([self hideHUDForView:obj animated:YES]){
                    *stop = YES;
                }
            }
        }];
        
    }
}

+ (void)QW_hideHUD
{
    [self hideHUDForView:nil];
}
@end
