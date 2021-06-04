//
//  TJNextViewController.m
//  TJMJCarDrawCircleSDKDemo
//
//  Created by 张雄 on 2021/1/15.
//

#import "TJNextViewController.h"
#import <Masonry/Masonry.h>
#import <SDWebImage/SDWebImage.h>

@interface TJNextViewController ()<UITableViewDataSource>
@property (nonatomic,strong)UITableView *tableView;
@property (nonatomic,strong)NSMutableArray<TJCDCH5PartInfo *> *dataSource;
@end

@implementation TJNextViewController

- (NSMutableArray<TJCDCH5PartInfo *> *)dataSource {
    if (!_dataSource) {
        _dataSource = [NSMutableArray array];
    }
    return _dataSource;
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.dataSource = self;
    }
    return _tableView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.bottom.right.equalTo(self.view);
    }];
    // Do any additional setup after loading the view.
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellID = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:cellID];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    NSString *imageURL = [self.dataSource[indexPath.row].stdPartName partImageStringURL];
    cell.textLabel.text = self.dataSource[indexPath.row].stdPartName;
    cell.detailTextLabel.text = self.dataSource[indexPath.row].partCode;
    [cell.imageView sd_setImageWithURL:[NSURL URLWithString:imageURL] placeholderImage:[UIImage imageNamed:@"AppIcon"]];
    return cell;
}

- (void)setPartList:(NSArray<TJCDCH5PartInfo *> *)partList {
    _partList = partList;
    [self.dataSource addObjectsFromArray:_partList];
    [self.tableView reloadData];
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
