//
//  Fuze360Interstitial.h
//  Fuze360SDK
//
//  Created by Diana on 2/13/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class Fuze360Interstitial;

@protocol Fuze360InterstitialDelegate <NSObject>

@optional

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialDidReceiveAd:(Fuze360Interstitial *)interstitial;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(Fuze360Interstitial *)interstitial didFailToReceiveAdWithError:(NSError *)error;

/// Called when add fails to present.
- (void)interstitialDidFailToPresentScreenWithError:(NSError *)error;

/// Called just before presenting an interstitial. After this method finishes the interstitial will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the interstitial is on screen (e.g. to visit the App
/// Store from a link on the interstitial).
- (void)interstitialWillPresentScreen:(Fuze360Interstitial *)interstitial;

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(Fuze360Interstitial *)interstitial;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(Fuze360Interstitial *)interstitial;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)interstitialWillLeaveApplication:(Fuze360Interstitial *)interstitial;

@end


@interface Fuze360Interstitial : NSObject

@property (nonatomic, weak) id <Fuze360InterstitialDelegate> delegate;

/// Returns true if the interstitial is ready to be displayed. The delegate's
/// interstitialAdDidReceiveAd: will be called after this property switches from false to true.
@property (nonatomic, readonly, assign) BOOL isReady;

/// Returns true if this interstitial has already been presented.
@property(nonatomic, readonly, assign) BOOL hasBeenUsed;

- (void) loadInterstitial;

- (void) presentFromRootViewController:(UIViewController *) viewController;

@end
