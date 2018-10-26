/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#ifndef CellTalkListener_h
#define CellTalkListener_h

#import "CellPrerequisites.h"

/*!
 @brief 会话监听器。
 */
@protocol CellTalkListener <NSObject>
@optional
/*!
 @brief 当收到对端发送过来的原语时该方法被调用。
 
 @param speaker 接收到数据的会话者。
 @param cellet 发送原语的 Cellet 名。
 @param primitive 接收到的原语。
 */
- (void)onListened:(CellSpeaker *)speaker cellet:(NSString *)cellet primitive:(CellPrimitive *)primitive;

/*!
 @brief 当原语发送出去后该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param cellet 接收原语的 Cellet 名。
 @param primitive 发送的原语。
 */
- (void)onSpoke:(CellSpeaker *)speaker cellet:(NSString *)cellet primitive:(CellPrimitive *)primitive;

/*!
 @brief 当收到服务器回送的原语应答时该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param cellet 接收原语的 Cellet 名。
 @param primitive 发送的原语。
 */
- (void)onSpeakAck:(CellSpeaker *)speaker cellet:(NSString *)cellet primitive:(CellPrimitive *)primitive;

/*!
 @brief 当发送的原语在指定时间内没有应答时该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param cellet 接收原语的 Cellet 名。
 @param primitive 发送的原语。
 */
- (void)onSpeakTimeout:(CellSpeaker *)speaker cellet:(NSString *)cellet primitive:(CellPrimitive *)primitive;

/*!
 @brief 当会话者连接到服务器完成握手后该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param cellet 握手的 Cellet 。
 */
- (void)onContacted:(CellSpeaker *)speaker cellet:(NSString *)cellet;

/*!
 @brief 当会话者断开与服务器的连接时该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param cellet 握手的 Cellet 。
 */
- (void)onQuitted:(CellSpeaker *)speaker cellet:(NSString *)cellet;

/*!
 @brief 当发生故障时该方法被调用。
 
 @param speaker 发送数据的会话者。
 @param error 错误描述。
 */
- (void)onFailed:(CellSpeaker *)speaker error:(CellTalkError *)error;

@end

#endif /* CellTalkListener_h */
