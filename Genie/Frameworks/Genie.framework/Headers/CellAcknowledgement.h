//
//  CellAcknowledgement.h
//  Genie
//
//  Created by 曾長歡 on 2017/12/14.
//  Copyright © 2017年 曾長歡. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CellPrerequisites.h"

@protocol CellAcknowledgementDelegate <NSObject>

@optional

- (void)onAckTimeout:(CellSession *)session withCellet:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;

@end

@interface CellAcknowledgement : NSObject

@property (nonatomic, weak) id<CellAcknowledgementDelegate> acknowledgementDelegate;

- (id)initWithDic:(NSMutableDictionary<NSNumber *,CellPrimitiveCapsule *> *)dic withDelegate:(id<CellAcknowledgementDelegate>)delegate;

- (void)resetTimeout:(NSTimeInterval)timeout;

- (void)start;

- (void)stop;

- (NSTimeInterval)getTimeout;
@end
