//
//  Fuze360NativeAdView.h
//  Fuze360SDK
//
//  Created by Mac Mini on 2/17/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Fuze360NativeAdView;

@protocol Fuze360NativeAdViewDelegate <NSObject>

@optional

/// Tells the delegate that an ad request successfully received an ad. The delegate may want to add
/// the native ad view to the view hierarchy if it hasn't been added yet.
- (void) fuze360NativeAdViewDidReceiveAd:(Fuze360NativeAdView *) nativeAd;

/// Tells the delegate that an ad request failed. The failure is normally due to network
/// connectivity or ad availablility (i.e., no fill).
- (void) fuze360NativeAdView:(Fuze360NativeAdView *) nativeAdView didFailToReceiveAdWithError:(NSError *)error;

/// Tells the delegate that the user click will open another app, backgrounding the current
/// application. The standard UIApplicationDelegate methods, like applicationDidEnterBackground:,
/// are called immediately before this method is called.
- (void) nativeAdViewWillLeaveApplication:(Fuze360NativeAdView *) nativeAd;

@end

@interface Fuze360NativeAdView : UIView

@property (nonatomic, weak) id <Fuze360NativeAdViewDelegate> delegate;

- (void) loadNativeAd;

@end
