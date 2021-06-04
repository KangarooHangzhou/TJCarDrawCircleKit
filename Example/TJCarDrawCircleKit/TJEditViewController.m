//
//  TJEditViewController.m
//  TJMJCarDrawCircleSDKDemo
//
//  Created by 张雄 on 2021/1/15.
//

#import "TJEditViewController.h"

@interface TJEditViewController ()
@property (weak, nonatomic) IBOutlet UITextField *runTypeTF;
@property (weak, nonatomic) IBOutlet UITextField *vinCodeTF;
@property (weak, nonatomic) IBOutlet UITextField *optionCodeTF;
@property (weak, nonatomic) IBOutlet UITextField *findVehicleWayTF;
@property (weak, nonatomic) IBOutlet UITextField *bodyTF;
@property (weak, nonatomic) IBOutlet UITextField *containOperationTF;
@property (weak, nonatomic) IBOutlet UITextField *productCodeTF;
@property (weak, nonatomic) IBOutlet UITextField *resultOnlyTF;
@property (weak, nonatomic) IBOutlet UITextField *tokenTF;
@end

@implementation TJEditViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIBarButtonItem *rightBarItem = [[UIBarButtonItem alloc] initWithTitle:@"保存" style:UIBarButtonItemStylePlain target:self action:@selector(save)];
    self.navigationItem.rightBarButtonItem = rightBarItem;
    self.runTypeTF.text = [NSString stringWithFormat:@"%ld",(long)self.h5URLParams.runType];
    self.vinCodeTF.text = self.h5URLParams.vinCode;
    self.optionCodeTF.text = self.h5URLParams.optionCode;
    self.findVehicleWayTF.text = self.h5URLParams.findVehicleWay;
    self.bodyTF.text = self.h5URLParams.body;
    self.containOperationTF.text = self.h5URLParams.containOperation;
    self.productCodeTF.text = self.h5URLParams.productCode;
    self.resultOnlyTF.text = self.h5URLParams.resultOnly;
    self.tokenTF.text = self.h5URLParams.token;
    // Do any additional setup after loading the view from its nib.
}

- (void)save {
    self.h5URLParams.runType = [self.runTypeTF.text integerValue];
    self.h5URLParams.vinCode = self.vinCodeTF.text;
    self.h5URLParams.optionCode = self.optionCodeTF.text;
    self.h5URLParams.findVehicleWay = self.findVehicleWayTF.text;
    self.h5URLParams.body = self.bodyTF.text;
    self.h5URLParams.containOperation = self.containOperationTF.text;
    self.h5URLParams.productCode = self.productCodeTF.text;
    self.h5URLParams.resultOnly = self.resultOnlyTF.text;
    self.h5URLParams.token = self.tokenTF.text;
    [self.navigationController popViewControllerAnimated:YES];
    if (self.saveBlock) {self.saveBlock();}
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end
