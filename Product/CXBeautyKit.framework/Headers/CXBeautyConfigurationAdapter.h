//
//  CXBeautyConfigurationAdapter.h
//  CXBeautyKit
//
//  Created by 杨乃川 on 2018/4/10.
//

#import <Foundation/Foundation.h>
//#import "CXBackgroundBlurFilter.h"
#import <MetalPetal/MetalPetal.h>
#import "CXFilterInputType.h"
@class CXBeautyConfiguration,CXMakeupLayerConfiguration, CXBeautyFilterFaceAdditionalInfo, CXBeautyMasks, MMFaceFeature, MMImageSegmentationResult, CXAutoLevelInfo;
NS_ASSUME_NONNULL_BEGIN

typedef NSString *const CXFaceAdjustmentsKey NS_STRING_ENUM;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsChinLengthKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsJawWidthKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsForeheadKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsNoseLiftKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsNoseWidthKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsMouthSizeKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsEyeTiltKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsEyeSizeKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsNoseSizeKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsJawShapeKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsNoseRidgeWidthKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsNoseTipSizeKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsThinFaceKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsLipThicknessKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsFaceWidthKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsEyeDistanceKey;
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsEyeHeightKey;// [-1, 1]
FOUNDATION_EXTERN CXFaceAdjustmentsKey CXFaceAdjustmentsFaceShortenKey;

// !! CXMakeupType not available for lite version
typedef NSString *const CXMakeupType NS_STRING_ENUM;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypeEyeShadow;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypeFaceShadow;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypeBlush;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypeLip;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypePupil;
FOUNDATION_EXTERN CXMakeupType  CXMakeupTypeHairColor;



typedef NS_OPTIONS(NSUInteger, CXBeautyOption){
    CXBeautyOptionNone = 0,
    CXBeautyOptionFaceAdjust = 1 << 0,
    CXBeautyOptionSkinSmooth = 1 << 1,
    CXBeautyOptionSkinWhiten = 1 << 2,
    CXBeautyOptionMakeup = 1 << 3,   // not available for lite version
    CXBeautyOptionBackgroundBlur = 1 << 4, // not available for lite version
    CXBeautyOptionColorEnhance = 1 << 5,
    CXBeautyOptionAll = NSUIntegerMax,
};

@interface CXDetectionResults : NSObject

@property (nonatomic, copy, nullable) NSArray <MMFaceFeature *> *faceFeatures;
@property (nonatomic, strong, nullable) MMImageSegmentationResult *imageSegmentationResult;
@property (nonatomic, strong, nullable) MMImageSegmentationResult *hairSegmentationResult;
@property (nonatomic, strong, nullable) CXAutoLevelInfo *whintenLevelInfo;

@end


@interface CXBeautyConfigurationAdapter : NSObject

@property (nonatomic, readonly) CXBeautyConfiguration *configuration;

@property (nonatomic, assign) CXBeautyOption beautyOption; // default on: faceAdjust , skinWhiten, skinSmooth

- (nullable MTIImage *)processedImageWithInputImage:(nullable MTIImage *)intpuImage detectionResult:(nullable CXDetectionResults *)result;

- (instancetype)initWithConfiguration:(nullable CXBeautyConfiguration *)configuration;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, assign) CXFilterInputType inputType;
@end


@interface CXBeautyConfigurationAdapter (FaceAdjust)

- (void)adjustFaceWithKey:(CXFaceAdjustmentsKey)key amount:(float)amount;

@end


@interface CXBeautyConfigurationAdapter (Skin)
- (void)smoothSkin:(float)amount;

- (void)smoothSkinCorrection:(BOOL)correctionEnbale;

- (void)whitenSkin:(float)amount;

- (void)whitenTeeth:(float)amount;

- (void)faceIllumination:(float)amount;

- (void)adjustNasolabialFoldsArea:(float)amount;

- (void)adjustEyesArea:(float)amount;
@end

@interface CXBeautyConfigurationAdapter (ColorEnhance)
- (void)saturation:(float)saturation;

- (void)sharpening:(float)sharpening;

- (void)contrast:(float)contrast;
@end


NS_ASSUME_NONNULL_END
