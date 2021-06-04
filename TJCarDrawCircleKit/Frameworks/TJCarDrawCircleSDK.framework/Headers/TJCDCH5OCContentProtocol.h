//
//  TJCDCH5OCContentProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>
#import "TJCDCH5CollisionInfoProtocol.h"
#import "TJCDCH5PartInfoProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5OnCircle内容协议
@protocol TJCDCH5OCContentProtocol <NSObject>

/// 圈选推荐所需要的上下文context
@property (nonatomic,copy)NSString *context;

/// 是否存在加载更多
@property (nonatomic,assign)BOOL hasMore;

/// 最大碰撞模式列表，只有大案定损时才会返回碰撞模式
@property (nonatomic,strong)NSArray<id<TJCDCH5CollisionInfoProtocol>> *maxCollisionInfo;

/// 最小碰撞模式列表，只有大案定损时才会返回碰撞模式
@property (nonatomic,strong)NSArray<id<TJCDCH5CollisionInfoProtocol>> *minCollisionInfo;

/// 配件列表
@property (nonatomic,strong)NSArray<id<TJCDCH5PartInfoProtocol>> *partList;

@end

NS_ASSUME_NONNULL_END
