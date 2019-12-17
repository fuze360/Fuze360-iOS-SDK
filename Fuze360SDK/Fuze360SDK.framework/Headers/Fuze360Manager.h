//
//  Fuze360Manager.h
//  Fuze360SDK
//
//  Created by Diana on 3/6/18.
//  Copyright © 2018 Diana. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Fuze360Manager : NSObject

typedef NS_ENUM(NSInteger, Fuze360SDKMode) {
    Fuze360SDKModeSandbox,
    Fuze360SDKModeLive
};

// Configure Fuze360SDK authentication keys and mode
+ (void) configureWithApiKey:(NSString *)api_key authId:(NSString *)auth_id andMode:(Fuze360SDKMode)mode;

@end
