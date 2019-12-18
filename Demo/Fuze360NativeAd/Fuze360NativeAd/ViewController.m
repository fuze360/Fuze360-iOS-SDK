//
//  ViewController.m
//  Fuze360NativeAd
//
//  Created by Diana on 4/27/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <Fuze360NativeAdViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.nativeAdView.delegate = self;
    [self.nativeAdView loadNativeAd];
}

#pragma mark - Fuze360NativeAdDelegate Methods
- (void) fuze360NativeAdViewDidReceiveAd:(Fuze360NativeAdView *) nativeAd {
    NSLog(@"fuze360NativeAdViewDidReceiveAd");
}

- (void) fuze360NativeAdView:(Fuze360NativeAdView *)nativeAdView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"NativeAd didFailToReceiveAdWithError: %@", error);
}

- (void) nativeAdViewWillLeaveApplication:(Fuze360NativeAdView *) nativeAd {
    NSLog(@"nativeAdViewWillLeaveApplication");
}


@end
