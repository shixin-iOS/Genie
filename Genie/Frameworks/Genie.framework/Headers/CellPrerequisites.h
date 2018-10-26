/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#ifndef CellPrerequisites_h
#define CellPrerequisites_h

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

#ifndef NULL
#define NULL 0
#endif

#pragma mark Servie Protocol

/*!
 @brief 标准服务接口。

 @author Ambrose Xu
 */
@protocol CellService <NSObject>

/*!
 @brief 启动服务。
 
 @return 如果启动成功返回 <code>YES</code> 。
 */
- (BOOL)startup;

/*!
 @brief 关闭服务。
 */
- (void)shutdown;

@end



/*!
 @brief 对话者状态。
 */
typedef enum _CellSpeakState
{
    /// 连接已断开
    Disconnected = 0,

    /// 正在建立连接
    Connecting,

    /// 连接已建立
    Connected,

    /// 正在断开连接
    Disconnecting

} CellSpeakState;



// Util Group

@class CellLogger;
@class CellLoggerManager;
@class CellCryptology;
@class CellInetAddress;
@class CellMessage;
@class CellMessageConnector;
@class CellMessageService;
@class CellNonblockingConnector;
@class CellSession;
@class CellByteBuffer;


// API Group

@class CellNucleus;
@class CellNucleusConfig;
@class CellNucleusTag;
@class CellVersion;


// Talk Group

@class CellDialect;
@class CellDialectFactory;
@class CellActionDialect;
@class CellPrimitive;
@class CellStuff;
@class CellTalkService;
@class CellSpeaker;
@class CellTalkError;
@class CellPrimitiveCapsule;
@class CellHeartbeatContext;
@class CellHeartbeatMachine;
@class CellAcknowledgement;
#endif // CellPrerequisites_h
