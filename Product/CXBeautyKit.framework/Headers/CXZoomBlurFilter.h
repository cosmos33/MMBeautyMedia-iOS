//
//  CXZoomBlurFilter.h
//  CXBeautyKit
//
//  Created by 杨乃川 on 2019/1/4.
//

#import <Foundation/Foundation.h>
@import MetalPetal;
NS_ASSUME_NONNULL_BEGIN

@interface CXZoomBlurFilter : NSObject<MTIUnaryFilter>
@property (nonatomic, assign) float radius;

@property (nonatomic, strong) MTIMask *mask;


@end

NS_ASSUME_NONNULL_END