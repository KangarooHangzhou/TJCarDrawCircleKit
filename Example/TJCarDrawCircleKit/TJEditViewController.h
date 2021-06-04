//
//  TJEditViewController.h
//  TJMJCarDrawCircleSDKDemo
//
//  Created by 张雄 on 2021/1/15.
//

#import <UIKit/UIKit.h>
#import <TJCarDrawCircleKit/TJCarDrawCircleKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TJEditViewController : UIViewController
@property (nonatomic,strong)TJCDCH5URLParams *h5URLParams;
@property (nonatomic,copy)void(^saveBlock) (void);
@end

NS_ASSUME_NONNULL_END
