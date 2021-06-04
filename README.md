# TJCarDrawCircleKit

[![CI Status](https://img.shields.io/travis/xtzPioneer/TJCarDrawCircleKit.svg?style=flat)](https://travis-ci.org/xtzPioneer/TJCarDrawCircleKit)
[![Version](https://img.shields.io/cocoapods/v/TJCarDrawCircleKit.svg?style=flat)](https://cocoapods.org/pods/TJCarDrawCircleKit)
[![License](https://img.shields.io/cocoapods/l/TJCarDrawCircleKit.svg?style=flat)](https://cocoapods.org/pods/TJCarDrawCircleKit)
[![Platform](https://img.shields.io/cocoapods/p/TJCarDrawCircleKit.svg?style=flat)](https://cocoapods.org/pods/TJCarDrawCircleKit)

### 简介
同基科技基于"TJCarDrawCircleSDK"开发的车型画圈Kit.
### 功能
* 画圈获取配件信息列表
* 配件信息包含标准名称、配件OE、配件图片、配件价格、等基本信息
* 加载请求/重载请求
* 加载更多配件
* 清除缓存
### 运行示例项目
要运行示例项目，请克隆存储库，然后首先从Example目录运行`pod install`。
### 安装
```ruby
pod 'TJCarDrawCircleKit'
```
### 导入文件
```objc
#import <TJCarDrawCircleKit/TJCarDrawCircleKit.h>
```
### 创建画圈视图
```objc
TJCarDrawCircleView *carDrawCircleView = [TJCarDrawCircleView carDrawCircleView];
```
### 创建画圈参数
```objc
TJCDCH5URLParams * h5URLParams = [TJCDCH5URLParams new];
h5URLParams.resultOnly = @"1";
h5URLParams.containOperation = @"1";
h5URLParams.productCode = @"I0601";
h5URLParams.bigCase = @"0";
```
### 运行环境参数
```objc
// 测试环境
h5URLParams.runType = TJCDCSUMRunTypeDeBug;
h5URLParams.token = @"测试环境Token"
// 发布环境
h5URLParams.runType = TJCDCSUMRunTypeRelease;
h5URLParams.token = @"发布环境Token"
```
### 精准定型参数
```objc
h5URLParams.findVehicleWay = @"A";
h5URLParams.optionCode = @"optionCode";
h5URLParams.vinCode = @"vinCode";
```
### 销售车型参数
```objc
h5URLParams.findVehicleWay = @"B";
h5URLParams.optionCode = @"mjsid"
```
### 手选车型参数
```objc
h5URLParams.findVehicleWay = @"C";
h5URLParams.optionCode = @"mjsid"
```
### 清除缓存
```objc
[carDrawCircleView clearCache:^{
	NSLog(@"画圈页面缓存已经清理！");
}];
```
### 加载请求
```objc
carDrawCircleView.h5URLParams = h5URLParams;;
[carDrawCircleView loadRequest];
```
### 方法回调
```objc
carDrawCircleView.h5StartLoadHandler = ^{
	NSLog(@"页面开始加载时调用!");
};
carDrawCircleView.h5LoadCompleteHandler = ^{
	NSLog(@"页面加载完成之后调用!");
};
carDrawCircleView.h5LoadFailureHandler = ^(NSError * _Nonnull error) {
	NSLog(@"页面加载失败时调用!");
};
carDrawCircleView.circleFailureHandler = ^(NSError * _Nonnull error) {
	NSLog(@"画圈失败Error:%@",error);
};
carDrawCircleView.circleHandler = ^(TJCDCH5OCContent * _Nonnull content) {
	NSLog(@"画圈成功后回调！")
};
```
### 画圈视图
```objc
//
//  TJCarDrawCircleView.h
//  Expecta
//
//  Created by 张雄 on 2020/11/18.
//

#import <UIKit/UIKit.h>
#import "TJCDCH5URLParams.h"
#import "TJCDCH5OCContent.h"
#import "TJCDCH5PartInfo.h"
#import "TJCDCH5CollisionInfo.h"
#import "TJCDCH5Operable.h"
#import "TJCDCH5OROption.h"
#import "TJCDCH5ORParams.h"
#import "TJCDCH5ORSelectPart.h"
#import "NSString+TJCDCCategory.h"

NS_ASSUME_NONNULL_BEGIN

/// 内容回调
typedef void (^TJCDCCTContentHandler) (TJCDCH5OCContent *content);

/// 完成回调
typedef void (^TJCDCCTLDCompleteHandler) (void);

/// 失败回调
typedef void (^TJCDCCTLDFailureHandler) (NSError *error);

/// 同基画圈视图
@interface TJCarDrawCircleView : UIView

/// H5URL参数
@property (nonatomic,strong)TJCDCH5URLParams *h5URLParams;

/// H5开始加载回调
@property (nonatomic,copy)TJCDCCTLDCompleteHandler h5StartLoadHandler;

/// H5加载完成回调
@property (nonatomic,copy)TJCDCCTLDCompleteHandler h5LoadCompleteHandler;

/// H5加载失败回调
@property (nonatomic,copy)TJCDCCTLDFailureHandler h5LoadFailureHandler;

/// 画圈回调
@property (nonatomic,copy)TJCDCCTContentHandler circleHandler;

/// 画圈失败回调
@property (nonatomic,copy)TJCDCCTLDFailureHandler circleFailureHandler;

/// 加载更多回调
@property (nonatomic,copy)TJCDCCTContentHandler loadMoreHandler;

/// 加载更多失败回调
@property (nonatomic,copy)TJCDCCTLDFailureHandler loadMoreFailureHandler;

/// 加载请求
- (void)loadRequest;

/// 重载
- (void)reload;

/// 加载更多
/// @param inputHandler 输入参数回调
- (void)loadMore:(nullable void(^)(TJCDCH5ORParams *input))inputHandler;

/// 清除缓存
/// @param completionHandler 完成回调
- (void)clearCache:(TJCDCCTLDCompleteHandler)completionHandler;

/// 快速构建画圈视图
+ (instancetype)carDrawCircleView;

// 禁止使用下列方法
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)copy NS_UNAVAILABLE;
- (instancetype)mutableCopy NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

```
### 配件信息
```objc
//
//  TJCDCH5PartInfoProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>
#import "TJCDCH5OperableProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5配件协议
@protocol TJCDCH5PartInfoProtocol <NSObject>

/// 请求配件名
@property (nonatomic,copy)NSString *reqPartName;

/// 江湖名函数解析之后的名称
@property (nonatomic,copy)NSString *jhmPartName;

/// 备注
@property (nonatomic,copy)NSString *comment;

/// epc配件号
@property (nonatomic,copy)NSString *srcPartNumber;

/// 图片名
@property (nonatomic,copy)NSString *image;

/// 替换链标记
@property (nonatomic,copy)NSString *subChainFlag;

/// 单⻋用量
@property (nonatomic,copy)NSString *qty;

/// 替换件
@property (nonatomic,copy)NSString *substitute;

/// 配件价格
@property (nonatomic,copy)NSString *partPrice;

/// 小红点位置
@property (nonatomic,copy)NSString *position;

/// 标准配件号
@property (nonatomic,copy)NSString *partNumber;

/// 图中编号
@property (nonatomic,copy)NSString *partRefOnImage;

/// 标准配件名
@property (nonatomic,copy)NSString *stdPartName;

/// 标准配件ID
@property (nonatomic,copy)NSString *partCode;

/// 总成件OE号list,当且仅当入参parentChild为true时才 可能会返回
@property (nonatomic,strong)NSArray<NSString *> *parent;

/// 局部件OE号list,当且仅当入参parentChild为true时才 可能会返回
@property (nonatomic,strong)NSArray<NSString *> *child;

/// 可选拆装项目,当且金蛋入参containOperation为true 时才返回
@property (nonatomic,strong)NSArray<id<TJCDCH5OperableProtocol>> *operables;

@end

NS_ASSUME_NONNULL_END
```
### 获取配件图片URL
```objc
// “partInfo”遵循“TJCDCH5PartInfoProtocol”协议
NSString *imageURL = [partInfo.stdPartName partImageStringURL];
```
### 版本&更新
> 更新时间：2021.6.4  版本：0.1.6 更新内容：新增加载更多配件 <br>
> 更新时间：2021.2.6  版本：0.1.5 更新内容：优化代码 <br>
> 更新时间：2021.1.27 版本：0.1.4 更新内容：新增获取图片URL <br>
> 更新时间：2021.1.22 版本：0.1.3 更新内容：新增清除缓存功能 <br>
> 更新时间：2021.1.20 版本：0.1.2 更新内容：新增错误提示 <br>
> 更新时间：2021.1.20 版本：0.1.1 更新内容：修复参数格式 <br>
> 更新时间：2021.1.20 版本：0.1.0 更新内容：新增画圈功能 <br>
## License

TJCarDrawCircleKit is available under the MIT license. See the LICENSE file for more info.
