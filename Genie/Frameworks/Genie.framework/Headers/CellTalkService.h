/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#ifndef CellTalkService_h
#define CellTalkService_h

#import "CellPrerequisites.h"
#import "CellTalkService.h"
#import "CellTalkListener.h"
#import "CellSession.h"
@interface CellTalkService : NSObject

@property (nonatomic, strong) CellNucleusTag *tag;

@property (nonatomic, weak) id<CellTalkListener>delegate;
/**
 构造函数。

 @param tag tag
 @return TalkService对象
 */
- (id)initWithTag:(CellNucleusTag *)tag;


/**
 与指定地址和端口上的 Cellet 建立连接。

 @param host 地址
 @param port 端口
 @param cellet cellet
 @return 如果返回 <code>NO</code> 则劫持事件，阻止事件回调发生。
 */
- (BOOL)call:(NSString *)host withPort:(int)port withCellet:(NSString *)cellet;


/**
  与指定地址和端口上的 Cellet 建立连接。

 @param host 地址
 @param port 端口
 @param cellets cellet
 @return 如果返回 <code>NO</code> 则劫持事件，阻止事件回调发生。
 */
- (BOOL)call:(NSString *)host withPort:(int)port withCellets:(NSArray <NSString *>*)cellets;


/**
 关闭与指定地址和端口的服务器的连接。

 @param host 地址
 @param port 端口
 @param now 是否立即挂断
 */
- (void)hangup:(NSString *)host withPort:(int)port withNow:(BOOL)now;

/**
 向指定的Cellet发送原语。

 @param cellet cellet
 @param primitive 原语
 @return 如果返回 <code>NO</code> 则劫持事件，阻止事件回调发生。
 */
- (BOOL)speak:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;


/**
 向指定终端发送批量原语数据

 @param session 会话
 @param primitives 原主
 @return 如果返回 <code>NO</code> 则劫持事件，阻止事件回调发生。
 */
- (BOOL)speakWithBatch:(CellSession *)session withCellet:(NSString *)cellet withPrimitives:(NSArray <CellPrimitive *> *)primitives;

/**
 设置原语应答超时时间。

 @param timeout timeout
 */
- (void)setAckTimeout:(int64_t)timeout;


/**
 返回原语应答超时时间。

 @return timeout
 */
- (int64_t)getAckTimeout;


/**
 是否已经连接到指定的 Cellet 。

 @param cellet cellet
 @return 如果返回 <code>NO</code> 则劫持事件，阻止事件回调发生。
 */
- (BOOL)isCalled:(NSString *)cellet;

@end

#endif
