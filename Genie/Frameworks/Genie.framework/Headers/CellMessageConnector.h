/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellMessageService.h"

/*!
 @brief 消息连接器。

 @author Ambrose Xu
 */
@interface CellMessageConnector : CellMessageService

/*! 连接地址。 */
@property (nonatomic, strong, readonly) NSString *address;
/*! 连接端口。 */
@property (nonatomic, assign, readonly) NSUInteger port;

/*!
 @brief 连接指定地址的消息接收器。

 @param address 指定连接地址。
 @param port 指定连接端口。
 @return 如果连接启动成功返回<code>YES</code>，否则返回 <code>NO</code> 。
 */
- (BOOL)connect:(NSString *)address port:(NSUInteger)port;

/*!
 @brief 关闭已建立的连接。
 */
- (void)disconnect;

/*!
 @brief 设置连接超时。

 @param timeout 指定以毫秒为单位的超时时长。
 */
- (void)setConnectTimeout:(NSTimeInterval)timeout;

/*!
 @brief 获得对应的会话实例。

 @return 返回对应的会话实例。
 */
- (CellSession *)getSession;

/*!
 @brief 是否已经连接。
 
 @return 如果已经连接返回 <code>YES</code> 。
 */
- (BOOL)isConnected;

/*!
 @brief 将指定的消息写入连接通道，发送给已连接的接收器。
 
 @param message 指定待发送的消息。
 */
- (void)write:(CellMessage *)message;

@end
