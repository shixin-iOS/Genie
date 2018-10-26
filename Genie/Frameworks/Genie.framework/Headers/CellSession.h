/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 消息会话描述。
 */
@interface CellSession : NSObject

//@property (nonatomic, strong) CellByteBuffer *readCache;

/*!
 @brief 指定消息服务实例和地址初始化。
 */
- (id)initWithAddress:(CellInetAddress *)address;

/*!
 @brief 返回会话 ID 。
 */
- (int64_t)getId;

/*!
 @brief 返回会话的网络地址。
 */
- (CellInetAddress *)getAddress;

/*!
 @brief 是否是安全连接。
 */
- (BOOL)isSecure;

/*!
 @brief 使用密钥激活加密模式。
 
 @param key 指定密钥数据。
 @param keyLength 指定密钥长度。
 */
- (BOOL)activeSecretKey:(const char *)key keyLength:(int)keyLength;

/*!
 @brief 吊销密钥，不使用加密模式。
 */
- (void)deactiveSecretKey;

/*!
 @brief 返回安全密钥。
 */
- (const char *)getSecretKey;

/*!
 @brief 返回安全密钥长度。
 */
- (int)getSecretKeyLength;

/*!
 @brief 复制密钥，并返回密钥长度。
 
 @param output 接收复制数据的缓存。
 @return 返回密钥长度。
 */
- (int)copySecretKey:(char *)output;

@end
