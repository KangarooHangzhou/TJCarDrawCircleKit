#
# Be sure to run `pod lib lint TJCarDrawCircleKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TJCarDrawCircleKit'
  s.version          = '0.1.6'
  s.summary          = '同基科技基于"TJCarDrawCircleSDK"开发的车型画圈Kit.'
  s.description      = <<-DESC
  由同基科技基于"TJCarDrawCircleSDK"开发的车型画圈Kit.
                       DESC
  s.homepage         = 'https://github.com/KangarooHangzhou/TJCarDrawCircleKit.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'xtzPioneer' => 'xtz_pioneer@icloud.com' }
  s.source           = { :git => 'https://github.com/KangarooHangzhou/TJCarDrawCircleKit.git', :tag => s.version.to_s }
  s.ios.deployment_target = '10.0'
  s.ios.source_files = 'TJCarDrawCircleKit/Classes/**/*.{h,m}'
  s.ios.public_header_files = 'TJCarDrawCircleKit/Classes/TJCarDrawCircleKit.h'
  s.ios.dependency 'YYModel'
  s.ios.dependency 'Masonry'
  s.static_framework = true
  s.ios.frameworks = "Foundation", "UIKit"
  s.ios.vendored_frameworks = 'TJCarDrawCircleKit/Frameworks/TJCarDrawCircleSDK.framework'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
