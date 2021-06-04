//
//  TJCDCH5ORSelectPartProtocol.h
//  AFNetworking
//
//  Created by 张雄 on 2020/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 同基画圈H5OR选中Part协议
@protocol TJCDCH5ORSelectPartProtocol <NSObject>

/// 配件标准编码(是否必须:是)
@property (nonatomic,copy)NSString *partCode;

/// 配件名称(是否必须:是)
@property (nonatomic,copy)NSString *partName;

/// 与中台交互的实际工项(例如: replace、panel、fit、accessoryFit、 paint, material、externalRepair、electrical)【更换、钣金/维修、拆 装、附件拆装、喷漆、辅料、外修、机电】(是否必须:是)
@property (nonatomic,copy)NSString *operation;

@end

NS_ASSUME_NONNULL_END
