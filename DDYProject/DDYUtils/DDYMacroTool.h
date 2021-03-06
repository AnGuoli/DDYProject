//
//  DDYMacroTool.h
//  DDYProject
//
//  Created by starain on 15/8/8.
//  Copyright © 2015年 Starain. All rights reserved.
//

////////////////////////// 宏定义 ////////////////////////////

/** 需要横屏或者竖屏，获取屏幕宽度与高度 */
#define DDYSCREENW [UIScreen mainScreen].bounds.size.width
#define DDYSCREENH [UIScreen mainScreen].bounds.size.height
#define DDYNAVBARH self.navigationController.navigationBar.ddy_h
#define DDYSCREENBOUNDS [UIScreen mainScreen].bounds
#define DDYSCREENSIZE [UIScreen mainScreen].bounds.size

/** 根据比例改变不同尺寸上数值 */
#define DDYKW(R) R*(DDYSCREENW)/375
#define DDYKH(R) R*(DDYSCREENH)/667

/** 自定义颜色和随机颜色 */
#define DDYColor(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
#define DDYRGBA(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
#define DDYRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0] 
#define DDYBackColor [UIColor colorWithRed:245/255.0 green:245/255.0 blue:245/255.0 alpha:1.0]
#define APP_MAIN_COLOR DDYColor(63, 183, 198, 1)

/** 字体 */
#define DDYFont(f) [UIFont systemFontOfSize:(f)]
#define DDYBDFont(f) [UIFont boldSystemFontOfSize:(f)]

/** 本地存储和通知中心 */
#define DDYUserDefaults [NSUserDefaults standardUserDefaults]
#define DDYNotificationCenter [NSNotificationCenter defaultCenter]

/** 圆角和边框 */
#define DDYBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

/** 沙盒路径:temp,Document,Cache */
#define DDYPathTemp NSTemporaryDirectory()
#define DDYPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define DDYPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]


/** 获取系统版本 */
#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)? (YES):(NO))
#define IOS_VERSION_9_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)? (YES):(NO))
#define IOS_VERSION_10_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)? (YES):(NO))

/** 获取当前语言 */
#define LRCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

/**  常数 */
#define DDYPI 3.14159265358979323846


// 定义这个常量,就可以在使用Masonry不必总带着前缀 `mas_`:
#define MAS_SHORTHAND
// 定义这个常量,以支持在 Masonry 语法中自动将基本类型转换为 object 类型:
#define MAS_SHORTHAND_GLOBALS


// 处于开发阶段
#ifdef DEBUG
#define DDYLog(...) NSLog(__VA_ARGS__)
#define DDYInfoLog(fmt, ...) NSLog((@"\n[fileName:%s]\n[methodName:%s]\n[lineNumber:%d]\n" fmt),__FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
// 处于发布阶段
#else
#define DDYLog(...)
#define DDYInfoLog(...)
#endif




