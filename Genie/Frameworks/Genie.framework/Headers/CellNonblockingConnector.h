/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellMessageConnector.h"
#import "GCDAsyncSocket.h"

/*!
 @brief 非阻塞消息连接器。
 
 @author Ambrose Xu
 */
@interface CellNonblockingConnector : CellMessageConnector <GCDAsyncSocketDelegate>

/*!
 @brief 使用数据记号初始化。
 
 @param delegate 消息事件委派。
 */
- (id)initWithDelegate:(id<CellMessageHandler>)delegate;

@end
