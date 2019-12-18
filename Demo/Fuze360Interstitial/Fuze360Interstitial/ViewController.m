//
//  ViewController.m
//  Fuze360Interstitial
//
//  Created by Diana on 4/27/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import "ViewController.h"
#import <Fuze360SDK/Fuze360SDK.h>

@interface ViewController () <Fuze360InterstitialDelegate>

@property(nonatomic, strong) Fuze360Interstitial *fuze360Interstitial;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.fuze360Interstitial = [[Fuze360Interstitial alloc] init];
    self.fuze360Interstitial.delegate = self;
    [self.fuze360Interstitial loadInterstitial];
}

- (IBAction)presentInterstitialAction:(id)sender {
    if ([self.fuze360Interstitial isReady]) {
        [self.fuze360Interstitial presentFromRootViewController:self];
    }
}

#pragma mark - Fuze360InterstitialDelegate Methods
- (void)interstitialDidReceiveAd:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialDidReceiveAd");
}

- (void)interstitial:(Fuze360Interstitial *)interstitial didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"Interstitial didFailToReceiveAdWithError: %@", error);
}

- (void)interstitialDidFailToPresentScreenWithError:(NSError *)error {
    NSLog(@"Interstitial interstitialDidFailToPresentScreenWithError: %@", error);
}

- (void)interstitialWillPresentScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillPresentScreen");
}

- (void)interstitialWillDismissScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillDismissScreen");
}

- (void)interstitialDidDismissScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialDidDismissScreen");
    [self.fuze360Interstitial loadInterstitial];
}

- (void)interstitialWillLeaveApplication:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillLeaveApplication");
}

@end
