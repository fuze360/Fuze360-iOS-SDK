# Fuze360SDK 1.0.0

![Platform](https://img.shields.io/badge/PLATFORM-iOS-ff69b4.svg)

## Installation with CocoaPods

To add Fuze360SDK to your app, add the following line to your Podfile:

```ruby
pod 'Fuze360SDK', :git => 'https://github.com/fuze360/Fuze360-iOS-SDK.git', :tag => '1.0.0'
```
and run
```
pod install
```

## Initialize Fuze360SDK

Before loading ads, app should initialize Fuze360SDK. This should be done once, at app launch:
```objective-c
#import <Fuze360SDK/Fuze360SDK.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
	// Initialize Fuze360SDK    
    [Fuze360Manager configureWithApiKey:@“API_KEY” authId:@“AUTH_ID” andMode:Fuze360SDKModeSandbox];
    
    return YES;
}
```

```API_KEY``` and ```AUTH_ID``` are generated when app is registered for Fuze360SDK.
While coding, testing and debugging, make sure to use ```Fuze360SDKModeSandbox``` mode. Failure to do so can lead to suspension of your account.
Make sure to replace it with ```Fuze360SDKModeLive``` before publishing your app.

## Interstitial Ads

Interstitial ads are full-screen ads that cover the interface of an app until closed by the user. When an app shows an interstitial ad, the user has the choice to either tap on the ad and continue to its destination or close it and return to the app.
Interstitial ads are requested and shown by ```Fuze360Interstitial``` objects.
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.fuze360Interstitial = [[Fuze360Interstitial alloc] init];
    self.fuze360Interstitial.delegate = self;
    [self.fuze360Interstitial loadInterstitial];
}
```

To show an interstitial, check the ```isReady``` property to verify that it's done loading, then call ```presentFromRootViewController```:
```objective-c
if (self.fuze360Interstitial.isReady) {
	[self.fuze360Interstitial presentFromRootViewController:self];
} else {
	NSLog(@"Interstitial is not ready“);
}
```

Once an interstitial is shown, ```hasBeenUsed``` returns ```true``` and the interstitial can't be used to present another ad. If you try to present an interstitial ad again, you'll get the error ```"Interstitial has been used"```.
By preloading another interstitial immediately after the previous one is dismissed, your app is prepared to show an interstitial again at the next logical break point.
The best place to load another interstitial is in the ```interstitialDidDismissScreen``` method on ```Fuze360InterstitialDelegate``` so that the next interstitial starts loading as soon as the previous one is dismissed. 
```objective-c
- (void)interstitialDidDismissScreen:(Fuze360Interstitial *)interstitial {
    [self.fuze360Interstitial loadInterstitial];
}
```

Each of the methods in ```Fuze360InterstitialDelegate``` are marked as optional, so you only need to implement the methods you want.
```objective-c
// Tells the delegate an ad request succeeded.
- (void)interstitialDidReceiveAd:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialDidReceiveAd");
    [interstitial presentFromRootViewController:self];
}

// Tells the delegate an ad request failed.
- (void)interstitial:(Fuze360Interstitial *)interstitial didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"Interstitial didFailToReceiveAdWithError: %@", error);
}

// Tells the delegate that an interstitial failed to be presented
- (void)interstitialDidFailToPresentScreenWithError:(NSError *)error {
    NSLog(@"Interstitial interstitialDidFailToPresentScreenWithError: %@", error);
}

// Tells the delegate that an interstitial will be presented.
- (void)interstitialWillPresentScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillPresentScreen");
}

// Tells the delegate the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillDismissScreen");
}

// Tells the delegate the interstitial had been animated off the screen.
- (void)interstitialDidDismissScreen:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialDidDismissScreen");
}

// Tells the delegate that a user click will open another app (such as Safari or App Store), backgrounding the current app.
- (void)interstitialWillLeaveApplication:(Fuze360Interstitial *)interstitial {
    NSLog(@"interstitialWillLeaveApplication");
}
```

## Banner Ads
Banner ads are displayed in ```Fuze360BannerView```, so the first step is to include a ```Fuze360BannerView``` in view hierarchy. This is typically done in Interface Builder or programmatically.
To load banner ad, call:
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.bannerView.delegate = self;
    [self.bannerView loadBanner];
}
```

To register for banner ad events, set the ```delegate``` property on ```Fuze360BannerView``` to an object that implements the ```Fuze360BannerViewDelegate``` protocol.
Each of the methods in ```Fuze360BannerViewDelegate``` is marked as optional, so you only need to implement the methods you want.
```objective-c
// Tells the delegate an ad request succeeded.
- (void) fuze360AdsBannerViewDidReceiveAd:(Fuze360BannerView *) bannerView {
    NSLog(@"fuze360AdsBannerViewDidReceiveAd");
}

// Tells the delegate an ad request failed.
- (void) fuze360AdsBannerView:(Fuze360BannerView *) bannerView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"Banner didFailToReceiveAdWithError: %@", error);
}

// Tells the delegate that a user click will open another app (such as Safari or App Store), backgrounding the current app.
- (void) adViewWillLeaveApplication:(Fuze360BannerView *) bannerView {
    NSLog(@"adViewWillLeaveApplication");
}
```

## Native Ads
Native ads are displayed in ```Fuze360NativeAdView```, so the first step is to include a ```Fuze360NativeAdView``` in view hierarchy. This is typically done in Interface Builder or programmatically.
To load native ad, call:
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.nativeAdView.delegate = self;
    [self.nativeAdView loadNativeAd];
}
```

To register for native ad events, set the ```delegate``` property on ```Fuze360NativeAdView``` to an object that implements the ```Fuze360NativeAdViewDelegate``` protocol.
Each of the methods in ```Fuze360NativeAdViewDelegate``` is marked as optional, so you only need to implement the methods you want.
```objective-c
// Tells the delegate an ad request succeeded.
- (void) fuze360NativeAdViewDidReceiveAd:(Fuze360NativeAdView *) nativeAd {
    NSLog(@"fuze360NativeAdViewDidReceiveAd");
}

// Tells the delegate an ad request failed.
- (void) fuze360NativeAdView:(Fuze360NativeAdView *) nativeAdView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"NativeAd didFailToReceiveAdWithError: %@", error);
}

// Tells the delegate that a user click will open another app (such as Safari or App Store), backgrounding the current app.
- (void) nativeAdViewWillLeaveApplication:(Fuze360NativeAdView *) nativeAd {
    NSLog(@"nativeAdViewWillLeaveApplication");
}
```

## License

Fuze360SDK is available under the MIT license. See the LICENSE file for more info.
