//
//  CellHeartbeatContext.h
//  Genie
//
//  Created by 曾長歡 on 2017/12/18.
//  Copyright © 2017年 曾長歡. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CellPrerequisites.h"

@interface CellHeartbeatContext : NSObject

/**
 心跳包离开发送端的时间
 */
@property (nonatomic, assign) int64_t originateTimestamp;


/**
 对端接收到心跳包的时间
 */
@property (nonatomic, assign) int64_t receiveTimestamp;


/**
 对方返回心跳应答的时间
 */
@property (nonatomic, assign) int64_t transmitTimestamp;


/**
 本地收到心跳应答的时间
 */
@property (nonatomic, assign) int64_t localTimestamp;


/**
 内核标签
 */
@property (nonatomic, copy) NSString *tag;


/**
 关联的会话
 */
@property (nonatomic, strong) CellSession *session;

- (id)initWithSession:(CellSession *)session withTag:(NSString *)tag;

@end
