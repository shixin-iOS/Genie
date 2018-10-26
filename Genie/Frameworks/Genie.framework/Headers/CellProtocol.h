/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*! 握手协议。 */
const static char CellProtocolHandshake[2] = { 'H', 'S' };
/*! 握手协议码。 */
const static char CellProtocolHandshakeCode = 1;

/*! 原语会话协议。 */
const static char CellProtocolSpeak[2] = { 'S', 'P' };
/*! 原语会话协议码。 */
const static char CellProtocolSpeakCode = 2;

/*! 会话应答协议。 */
const static char CellProtocolSpeakAck[2] = { 'S', 'A' };
/*! 会话应答协议码。 */
const static char CellProtocolSpeakAckCode = 3;

/*! 心跳协议。 */
const static char CellProtocolHeartbeat[2] = { 'H', 'B' };
/*! 心跳协议码。 */
const static char CellProtocolHeartbeatCode = 4;

/*! 心跳应答协议。 */
const static char CellProtocolHeartbeatAck[2] = { 'H', 'A' };
/*! 心跳应答协议码。 */
const static char CellProtocolHeartbeatAckCode = 5;

/*! 批量会话协议。 */
const static char CellProtocolBatchSpeak[2] = { 'B', 'S' };
/*! 批量会话协码。 */
const static char CellProtocolBatchSpeakCode = 6;
/*!
 @brief 握手协议。
 */
@interface CellHandshakeProtocol : NSObject
@property (nonatomic, strong) NSData * key;
@property (nonatomic, strong) NSString * tag;
@end


/*!
 @brief 心跳协议。
 */
@interface CellHeartbeatProtocol : NSObject
@property (nonatomic, strong) NSString * tag;
@property (nonatomic, assign) int64_t originateTimestamp;
@property (nonatomic, assign) int64_t receiveTimestamp;
@property (nonatomic, assign) int64_t transmitTimestamp;
@end


/*!
 @brief 会话协议。
 */
@interface CellSpeakProtocol : NSObject
@property (nonatomic, strong) NSString * target;
@property (nonatomic, strong) CellPrimitive * primitive;
@end


/*!
 @brief 会话应答协议。
 */
@interface CellSpeakAckProtocol : NSObject
@property (nonatomic, strong) NSString * target;
@property (nonatomic, strong) NSData * sn;
@end

@interface CellBatchSpeakProtocol: NSObject
@property (nonatomic, strong) CellPrimitive *primitive;
@property (nonatomic, strong)  NSString *target;
@end

/*!
 @brief 协议描述。

 数据包字段，单位 byte：<br>
 <code>
 +--|-00-|-01-|-02-|-03-|-04-|-05-|-06-|-07-+<br>
 |--+---------------------------------------+<br>
 |01| VER| SN |         RES       |    PN   |<br>
 |--+---------------------------------------+<br>
 |02|              DATA BEGIN               |<br>
 |--+---------------------------------------+<br>
 |03|                ... ...                |<br>
 |--+---------------------------------------+<br>
 |04|               DATA END                |<br>
 |--+---------------------------------------+<br>
 </code>
 DATA 段的数据使用 0x1E 作为数据分隔符。
 */
@interface CellProtocol : NSObject

/*!
 @brief 识别协议类型。
 
 @param data 原始数据报文。
 @return 返回协议码。
 */
+ (char)recognize:(char *)data;

/*!
 @brief 序列化握手。
 */
+ (void)serializeHandshake:(CellByteBuffer *)output key:(char *)key keyLength:(int)keyLength tag:(const char *)tag tagLength:(int)tagLength;

/*!
 @brief 反序列化握手。
 */
+ (CellHandshakeProtocol *)deserializeHandshake:(char *)data length:(NSUInteger)length;

/*!
 @brief 序列化心跳。
 */
+ (void)serializeHeartbeat:(CellByteBuffer *)output tag:(NSString *)tag timestamp:(int64_t)timestamp;

/*!
 @brief 反序列化心跳。
 */
+ (CellHeartbeatProtocol *)deserializeHeartbeat:(char *)data length:(NSUInteger)length;

/*!
 @brief 序列化心跳应答。
 */
+ (void)serializeHeartbeatAck:(CellByteBuffer *)output tag:(NSString *)tag originateTimestamp:(int64_t)originateTimestamp
             receiveTimestamp:(int64_t)receiveTimestamp transmitTimestamp:(int64_t)transmitTimestamp;

/*!
 @brief 反序列化心跳应答。
 */
+ (CellHeartbeatProtocol *)deserializeHeartbeatAck:(char *)data length:(NSUInteger)length;

/*!
 @brief 序列化会话。
 */
+ (void)serializeSpeak:(CellByteBuffer *)output target:(NSString *)target primitive:(CellPrimitive *)primitive;

/*!
 @brief 反序列化会话。
 */
+ (CellSpeakProtocol *)deserializeSpeak:(char *)data length:(NSUInteger)length;

/*!
 @brief 序列化会话应答。
 */
+ (void)serializeSpeakAck:(CellByteBuffer *)output target:(NSString *)target sn:(char *)sn;

/*!
 @brief 反序列化会话应答。
 */
+ (CellSpeakAckProtocol *)deserializeSpeakAck:(char *)data length:(NSUInteger)length;

/*!
 @brief 序列化批量会话协议。
 */
+ (void)serializeBatchSpeak:(CellByteBuffer *)output target:(NSString *)target primitive:(CellPrimitive *)primitive;

/*!
 @brief 反序列化批量会话协议。
 */
+ (CellBatchSpeakProtocol *)deserializeBatchSpeakAck:(char *)data length:(NSUInteger)length;

/*!
 @brief 自动生成包序号。
 */
+ (char)consumeSN;

/*!
 @brief 查找并进行数据转义。
 */
+ (NSUInteger)escape:(char *)output input:(char *)input length:(NSUInteger)length;

@end
