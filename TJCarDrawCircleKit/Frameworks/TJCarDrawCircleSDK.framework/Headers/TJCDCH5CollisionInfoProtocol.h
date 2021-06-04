//
//  TJCDCH5CollisionInfoProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5碰撞模式协议
@protocol TJCDCH5CollisionInfoProtocol <NSObject>

/// 碰撞模式代码
@property (nonatomic,copy)NSString *collisionCode;

/// 碰撞模式说明
@property (nonatomic,copy)NSString *aDescription;

@end

NS_ASSUME_NONNULL_END
