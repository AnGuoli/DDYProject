
//
//  DDYTabBar.m
//  DDYProject
//
//  Created by Rain Dou on 15/5/18.
//  Copyright © 2015年 634778311 All rights reserved.
//

#import "DDYTabBar.h"

@interface DDYTabBar ()

@property (nonatomic, weak) UIButton *plusBtn;

@end

@implementation DDYTabBar

@dynamic delegate;

- (instancetype)initWithFrame:(CGRect)frame {
    
    if (self = [super initWithFrame:frame]) {
        // 设置整个tabbar背景
        [self setBackgroundImage:[UIImage imageWithColor:[UIColor blueColor] size:CGSizeMake(DDYSCREENW, 49)]];
        // 去除tabar顶部线条
        [self setShadowImage:[UIImage imageWithColor:[UIColor clearColor] size:CGSizeMake(DDYSCREENW, 1)]];
        
        //为tabbar添加按钮
        UIButton *plusBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        plusBtn.layer.masksToBounds = YES;
        plusBtn.layer.cornerRadius = 66/2.0;
        plusBtn.layer.borderColor = [UIColor blueColor].CGColor;
        plusBtn.layer.borderWidth = 6;
        
        [plusBtn setBackgroundImage:[UIImage imageWithColor:DDYColor(255, 20, 20, 1.0) size:CGSizeMake(66, 66)] forState:UIControlStateNormal];
        [plusBtn setBackgroundImage:[UIImage imageWithColor:DDYColor(135, 27, 21, 1.0) size:CGSizeMake(66, 66)] forState:UIControlStateHighlighted];
        plusBtn.ddy_size = plusBtn.currentBackgroundImage.size;
        [plusBtn addTarget:self action:@selector(plusBtnTouch:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:plusBtn];
        self.plusBtn = plusBtn;
    }
    return self;
}

#pragma mark - 点击事件
- (void)plusBtnTouch:(UIButton *)button
{
    if ([self.delegate respondsToSelector:@selector(tabBarDidPlusBtn:)]) {
        [self.delegate tabBarDidPlusBtn:self];
    }
}

#pragma mark - 重写layoutSubviews
- (void)layoutSubviews {
    [super layoutSubviews];
    
    // 设置加号位置
    self.plusBtn.ddy_centerX = self.ddy_w * 0.5;
    self.plusBtn.ddy_centerY = self.ddy_h * 0.5;
    self.plusBtn.ddy_centerY = self.ddy_h * 0.5 - 10.0;
    
    // 设置其它button的位置
    CGFloat tabBarBtnW = self.ddy_w / 5;
    CGFloat tabBarBtnIndex = 0;
    for (int i = 0; i < self.subviews.count; i++) {
        UIView *child = self.subviews[i];
        // 由于UITabBarButton是私有的，所以不能直接用
        Class class = NSClassFromString(@"UITabBarButton");
        if ([child isKindOfClass:class]) {
            child.ddy_w = tabBarBtnW;
            child.ddy_x = tabBarBtnW * tabBarBtnIndex;
            tabBarBtnIndex ++;
            if (tabBarBtnIndex == 2) {
                tabBarBtnIndex ++;
            }
        }
    }
}

@end