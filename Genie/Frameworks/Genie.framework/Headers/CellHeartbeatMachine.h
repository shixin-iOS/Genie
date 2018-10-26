/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"

@protocol CellHeartbeatMachineDelegate <NSObject>

@optional

- (void)onSessionTimeout:(CellSession *)session time:(int64_t)time;

@end

@interface CellHeartbeatMachine : NSObject

@property (nonatomic, strong) id<CellHeartbeatMachineDelegate>heartbeatDelegate;

/**
 初始化方法

 @param connector connector
 @param delegate delegate
 @return 实体对象
 */
- (id)initWithConnector:(CellNonblockingConnector *)connector withDelegate:(id<CellHeartbeatMachineDelegate>)delegate;

/**
 启动心跳控制器
 */
- (void)startup;


/**
 关闭心跳控制器
 */
- (void)shutdown;


/**
 添加被管理的心跳会话

 @param session CellSession
 */
- (void)addSession:(CellSession *)session withTag:(NSString *)tag;

/**
 删除被管理的心跳会话

 @param session CellSession
 */
- (void)removeSession:(CellSession *)session;


/**
 处理来自对端的心跳数据

 @param session CellSession
 @param data data
 @param length 长度
 @param time 接收到数据包时的时间
 */
- (void)processHeartbeat:(CellSession *)session data:(char *)data length:(NSUInteger)length
                    time:(int64_t)time;


/**
 处理来自对端的返回的心跳应答

 @param session CellSession
 @param data data
 @param length 长度
 */
- (void)processHeartbeatAck:(CellSession *)session data:(char *)data length:(NSUInteger)length;

@end
