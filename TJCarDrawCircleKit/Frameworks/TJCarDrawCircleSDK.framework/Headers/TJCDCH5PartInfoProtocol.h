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
