//
//  TJCDCH5OperableProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5可选拆装项目协议
@protocol TJCDCH5OperableProtocol <NSObject>

/// 与中台交互的实际工项(例如: replace、 panel、fit、accessoryFit、paint, material、 externalRepair、electrical【更换、钣金/维修、 拆装、附件拆装、喷漆、辅料、外修、机电】
@property (nonatomic,copy)NSString *operation;

/// 损伤程度
@property (nonatomic,strong)NSArray<NSString *> *severity;

/// 喷漆类型
@property (nonatomic,strong)NSArray<NSString *> *condition;

/// 喷漆等级
@property (nonatomic,strong)NSArray<NSString *> *paintLevel;

/// 附件拆装名称
@property (nonatomic,copy)NSString *accessoryStdPartName;

/// 附件拆装标准码
@property (nonatomic,copy)NSString *accessoryPartCode;

/// 附件拆装标志(一言为定)
@property (nonatomic,copy)NSString *accessoryFlag;

/// 选中状态,true代表选中(一言为定)
@property (nonatomic,assign)BOOL chooseFlag;

/// 计数限制
@property (nonatomic,assign)int countLimit;

@end

NS_ASSUME_NONNULL_END
