#
# Be sure to run `pod lib lint MDRecordAndEdit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MMBeautyMedia'
  s.version          = '2.0.0'
  s.summary          = 'MMBeautyMedia'

  s.description      = <<-DESC
    beauty media
                       DESC

  s.homepage         = 'https://cosmos.wemomo.com/beauty/wiki/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'cosmos' => 'cosmossaas@gmail.com' }
  s.source           = { :git => 'https://github.com/cosmos33/MMBeautyMedia-iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'

  s.subspec 'Beauty' do |sp|
    sp.vendored_frameworks = 'Product/CXBeautyKit.framework'
    sp.resources = 'Resources/Beauty/*'
  end

  s.subspec 'Filter' do |sp|
    sp.vendored_frameworks = 'Product/MLFilterKit.framework', 'Product/MLFilterKitMetalPetal.framework'
    sp.resources = 'Resources/Filter/*'
  end

  s.subspec 'Sticker' do |sp|
    sp.vendored_frameworks = 'Product/FaceDecorationKit.framework', 'Product/FaceDecorationKitMetalPetal.framework', 'Product/FaceDecorationKitX3D.framework'
    sp.resources = 'Resources/Sticker/*'
    sp.dependency 'MMXEngine'
  end

  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => '$(inherited) NO', 'OTHER_LDFLAGS' => '$(inherited) -ObjC', 'MTL_LANGUAGE_REVISION' => 'Metal12', 'CLANG_WARN_DOCUMENTATION_COMMENTS' => '$(inherited) NO'}

  s.dependency 'Mantle'
  s.dependency 'MetalPetal/Static'

end
