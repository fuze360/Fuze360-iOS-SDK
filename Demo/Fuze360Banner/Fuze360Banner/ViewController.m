//
//  ViewController.m
//  Fuze360Banner
//
//  Created by Diana on 4/27/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <Fuze360BannerViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.bannerView.delegate = self;
    [self.bannerView loadBanner];
}

#pragma mark - Fuze360BannerViewDelegate methods
- (void) fuze360AdsBannerViewDidReceiveAd:(Fuze360BannerView *) bannerView {
    NSLog(@"fuze360AdsBannerViewDidReceiveAd");
}

- (void) fuze360AdsBannerView:(Fuze360BannerView *) bannerView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"Banner didFailToReceiveAdWithError: %@", error);
}

- (void) adViewWillLeaveApplication:(Fuze360BannerView *) bannerView {
    NSLog(@"adViewWillLeaveApplication");
}


@end
