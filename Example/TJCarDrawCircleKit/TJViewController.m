//
//  TJViewController.m
//  TJCarDrawCircleKit
//
//  Created by xtzPioneer on 01/20/2021.
//  Copyright (c) 2021 xtzPioneer. All rights reserved.
//

#import "TJViewController.h"
#import <TJCarDrawCircleKit/TJCarDrawCircleKit.h>
#import <Masonry/Masonry.h>
#import "TJNextViewController.h"
#import "TJEditViewController.h"

@interface TJViewController ()
@property (nonatomic,strong)TJCarDrawCircleView *carDrawCircleView;
@property (nonatomic,strong)TJCDCH5URLParams *h5URLParams;
@end

@implementation TJViewController

- (TJCarDrawCircleView *)carDrawCircleView {
    if (!_carDrawCircleView) {
        _carDrawCircleView = [TJCarDrawCircleView carDrawCircleView];
    }
    return _carDrawCircleView;
}

- (TJCDCH5URLParams *)h5URLParams {
    if (!_h5URLParams) {
        _h5URLParams = [TJCDCH5URLParams new];
        _h5URLParams.runType = TJCDCSUMRunTypeDeBug;
        _h5URLParams.bigCase = @"0";
        _h5URLParams.vinCode = @"MBJBA3FS0J0811457";
        _h5URLParams.optionCode = @"000";
        _h5URLParams.findVehicleWay = @"A";
        _h5URLParams.body = @"SUV";
        _h5URLParams.containOperation = @"1";
        _h5URLParams.productCode = @"I0601";
        _h5URLParams.resultOnly = @"1";
        _h5URLParams.token = @"eyJhbGciOiJIUzUxMiJ9.eyJsb2dpbnVzZXIiOiJOT1JNQUw65oGS55Sf5ZCM5Z-6X-aYjuiniUIyQuacjeWKoToxNjExNzM3NzkzNTU0OjM2MDAifQ.C8SI7Ol-gIeUHPz-7rUqlHD5ZPDk5l2iclPTR1KgL9H0zwuf-LKB-jXJnb52Q0NQ1Dkc8gYrXSgTu1cAMpysLQ";
    }
    return _h5URLParams;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    UIBarButtonItem *leftBarItem = [[UIBarButtonItem alloc] initWithTitle:@"编辑配置" style:UIBarButtonItemStylePlain target:self action:@selector(edit)];
    self.navigationItem.leftBarButtonItem = leftBarItem;
    UIBarButtonItem *rightBarItem = [[UIBarButtonItem alloc] initWithTitle:@"重新加载" style:UIBarButtonItemStylePlain target:self action:@selector(reload)];
    self.navigationItem.rightBarButtonItem = rightBarItem;
    __weak __typeof(self) weakSelf = self;
    [self.view addSubview:self.carDrawCircleView];
    [self.carDrawCircleView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.bottom.right.equalTo(self.view);
    }];
    self.carDrawCircleView.h5StartLoadHandler = ^{
        NSLog(@"页面开始加载时调用!");
    };
    self.carDrawCircleView.h5LoadCompleteHandler = ^{
        NSLog(@"页面加载完成之后调用!");
    };
    self.carDrawCircleView.h5LoadFailureHandler = ^(NSError * _Nonnull error) {
        NSLog(@"页面加载失败时调用!");
    };
    self.carDrawCircleView.circleFailureHandler = ^(NSError * _Nonnull error) {
        NSLog(@"画圈失败Error:%@",error);
    };
    self.carDrawCircleView.circleHandler = ^(TJCDCH5OCContent * _Nonnull content) {
        NSMutableArray *partList = [NSMutableArray array];
        [content.partList enumerateObjectsUsingBlock:^(id<TJCDCH5PartInfoProtocol>  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [partList addObject:obj];
        }];
        TJNextViewController *nextViewController = [TJNextViewController new];
        nextViewController.partList = partList;
        nextViewController.title = @"配件列表";
        nextViewController.view.backgroundColor = [UIColor whiteColor];
        [weakSelf.navigationController pushViewController:nextViewController animated:YES];
    };
    [self reload];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)reload {
    self.carDrawCircleView.h5URLParams = self.h5URLParams;;
    [self.carDrawCircleView loadRequest];
    [self.carDrawCircleView reload];
}

- (void)edit {
    __weak __typeof(self) weakSelf = self;
    TJEditViewController *editViewController = [TJEditViewController new];
    editViewController.h5URLParams = self.h5URLParams;
    editViewController.title = @"编辑配置";
    editViewController.view.backgroundColor = [UIColor whiteColor];
    editViewController.saveBlock = ^{
        [weakSelf reload];
    };
    [self.navigationController pushViewController:editViewController animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
