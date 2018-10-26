/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellMessageConnector.h"
#import "GCDAsyncUdpSocket.h"

#ifndef CellDatagramConnector_h
#define CellDatagramConnector_h

/*!
 @brief 数据报消息连接器。
 
 @author Ambrose Xu
 */
@interface CellDatagramConnector : CellMessageConnector <GCDAsyncUdpSocketDelegate>

/*!
 @brief 初始化连接器并指定消息委派。
 
 @param delegate 消息事件委派。
 */
- (id)init:(id<CellMessageHandler>)delegate;

@end

#endif /* CellDatagramConnector_h */
