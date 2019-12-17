//
//  Fuze360BannerView.h
//  Fuze360SDK
//
//  Created by Diana on 2/13/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Fuze360BannerView;

@protocol Fuze360BannerViewDelegate <NSObject>

@optional

/// Tells the delegate that an ad request successfully received an ad. The delegate may want to add
/// the banner view to the view hierarchy if it hasn't been added yet.
- (void) fuze360AdsBannerViewDidReceiveAd:(Fuze360BannerView *) bannerView;

/// Tells the delegate that an ad request failed. The failure is normally due to network
/// connectivity or ad availablility (i.e., no fill).
- (void) fuze360AdsBannerView:(Fuze360BannerView *) bannerView didFailToReceiveAdWithError:(NSError *)error;

/// Tells the delegate that the user click will open another app, backgrounding the current
/// application. The standard UIApplicationDelegate methods, like applicationDidEnterBackground:,
/// are called immediately before this method is called.
- (void) adViewWillLeaveApplication:(Fuze360BannerView *) bannerView;

@end


@interface Fuze360BannerView : UIView

@property (nonatomic, weak) id <Fuze360BannerViewDelegate> delegate;

- (void) loadBanner;

@end
