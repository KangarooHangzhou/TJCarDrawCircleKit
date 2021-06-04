//
//  TJCDCH5OROptionProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5OR操作协议
@protocol TJCDCH5OROptionProtocol <NSObject>

/// 气囊是否爆炸(大案定损配置参数)(是否必须:否)
@property (nonatomic,assign)BOOL airbag;

/// 底盘是否受损(大案定损配置参数)(是否必须:否)
@property (nonatomic,assign)BOOL chassis;

/// 发动机是否受损(大案定损配置参数)(是否必须:否)
@property (nonatomic,assign)BOOL engine;

@end

NS_ASSUME_NONNULL_END
