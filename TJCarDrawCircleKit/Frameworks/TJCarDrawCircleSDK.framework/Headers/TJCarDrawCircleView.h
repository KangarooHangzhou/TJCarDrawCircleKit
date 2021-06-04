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
