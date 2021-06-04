//
//  TJCDCH5ORParamsProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>
#import "TJCDCH5OROptionProtocol.h"
#import "TJCDCH5ORSelectPartProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5二次推荐/加载更多参数协议
@protocol TJCDCH5ORParamsProtocol <NSObject>

/// vin码，当⻋型点选时传空字符串""(是否必须:是)
@property (nonatomic,copy)NSString *vinCode;

/// ⻋型配置(是否必须:否)
@property (nonatomic,copy)NSString *optionCode;

/// 明觉SID,当optionType=mjsid时必传(是否必须:否)
@property (nonatomic,copy)NSString *mjsid;

/// 定型方式optionCode:精解析,mjsid:sid解析(包括vin- sid),默认值optionCode(是否必须:否)
@property (nonatomic,copy)NSString *optionType;

/// 圈选二次推荐所需要的上下文，第一次圈选可传空字符 串。之后需要传上一次圈选、二次推荐返回的context(是否必须:是)
@property (nonatomic,copy)NSString *context;

/// 是否查询局部总成关系(是否必须:否)
@property (nonatomic,copy)NSString *parentChild;

/// 是否包含工项(是否必须:否)
@property (nonatomic,copy)NSString *containOperation;

/// 当前⻚面的已选配件(是否必须:是)
@property (nonatomic,strong)NSArray<id<TJCDCH5ORSelectPartProtocol>> *selections;

/// 推荐类型(normal:普通推荐、bigcase大案推荐)(是否必须:是)
@property (nonatomic,copy)NSString *recommendType;

/// 透传给定损核心的配置项目(是否必须:是)
@property (nonatomic,strong)id<TJCDCH5OROptionProtocol> option;

@end

NS_ASSUME_NONNULL_END
