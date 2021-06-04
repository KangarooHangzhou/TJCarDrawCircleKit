//
//  TJCDCH5URLParamsProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 运行类型
typedef NS_ENUM(NSInteger,TJCDCSUMRunType) {
    /// 测试环境
    TJCDCSUMRunTypeDeBug   = 0,
    /// 生产环境
    TJCDCSUMRunTypeRelease = 1,
};

/// 同基画圈H5URL参数协议
@protocol TJCDCH5URLParamsProtocol <NSObject>

/// 运行类型
@property (nonatomic,assign)TJCDCSUMRunType runType;

/// 产品码(是否必须:是)
@property (nonatomic,copy)NSString *productCode;

/// vin码(是否必须:是)
@property (nonatomic,copy)NSString *vinCode;

/// 定型方式,可选值A:代表需要设置optionCode或者不设代表MJ_SID(是否必须:是)
@property (nonatomic,copy)NSString *findVehicleWay;

/// 根据findVehicleWay参数确定
@property (nonatomic,copy)NSString *optionCode;

/// ⻋辆信息, 例如:两厢3⻔(是否必须:是)
@property (nonatomic,copy)NSString *body;

/// 查询结果是否包含工项,可选值为:1代表展示或者不设(是否必须:是)
@property (nonatomic,copy)NSString *containOperation;

/// 是否展示结果⻚面,可选值为1代表展示,并回调给应用或者不设(是否必须:是)
@property (nonatomic,copy)NSString *resultOnly;

/// 是否是大案,可选值为:1代表大案或者不设(是否必须:是)
@property (nonatomic,copy)NSString *bigCase;

/// 可访问的Token(是否必须:是)
@property (nonatomic,copy)NSString *token;

@end

NS_ASSUME_NONNULL_END
