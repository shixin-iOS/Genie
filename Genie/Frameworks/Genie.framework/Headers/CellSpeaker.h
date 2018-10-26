/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"
#import "CellMessageService.h"
#import "CellTalkError.h"
@protocol CellTalkDelegate <NSObject>
@optional
/**
 当收到对端发送过来的原语时该方法被调用。

 @param speaker 接收到数据的会话者
 @param cellet 发送原语的Cellet名
 @param primitive 接收到的原语
 */
- (void)onListened:(CellSpeaker *)speaker withCellet:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;

/**
 当原语发送出去后该方法被调用。

 @param speaker 发送数据的会话者
 @param cellet 接收原语的Cellet名
 @param primitive 发送的原语
 */
- (void)onSpoke:(CellSpeaker *)speaker withCellet:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;

/**
 当收到服务器回送的原语应答时该方法被调用。

 @param speaker 发送数据的会话者
 @param cellet 接收原语的Cellet名
 @param primitive 发送的原语
 */
- (void)onSpeakAck:(CellSpeaker *)speaker withCellet:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;

/**
 当发送的原语在指定时间内没有应答时该方法被调用。

 @param speaker 发送数据的会话者
 @param cellet 接收原语的Cellet
 @param primitive 发送的原语
 */
- (void)onSpeakTimeout:(CellSpeaker *)speaker withCellet:(NSString *)cellet withPrimitive:(CellPrimitive *)primitive;

/**
 当会话者连接到服务器完成握手后该方法被调用。

 @param speaker 发送数据的会话者
 @param cellet 握手的Cellet
 */
- (void)onContacted:(CellSpeaker *)speaker withCellet:(NSString *)cellet;

/**
 当会话者连接到服务器完成握手后该方法被调用。

 @param speaker 发送数据的会话者
 @param cellet 握手的Cellet
 */
- (void)onQuitted:(CellSpeaker *)speaker withCellet:(NSString *)cellet;

/**
 当发生故障时该方法被调用。

 @param speaker 发送数据的会话者
 @param code 错误码
 */
- (void)onFailed:(CellSpeaker *)speaker andCode:(CellTalkError *)code;

@end


@interface CellSpeaker : NSObject <CellMessageHandler>

@property (nonatomic, strong) NSString * host;

@property (nonatomic, assign) NSUInteger port;

@property (atomic, assign, readonly) CellSpeakState state;

@property (nonatomic, strong, readonly) CellSession * session;

/**
 会话代理
 */
@property (strong, nonatomic) id<CellTalkDelegate> delegate;

- (id)initWithTag:(CellNucleusTag *)tag andHost:(NSString *)host andPort:(NSUInteger)port;

- (NSString *)getRemoteHost;

- (NSUInteger)getRemotePort;

- (BOOL)speak:(NSString *)cellet primitive:(CellPrimitive *)primitive;

- (BOOL)start;

- (void)stop:(BOOL)now;

- (void)setAckTimeout:(NSTimeInterval)timeout;
@end
