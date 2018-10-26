/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 加解密工具。
 
 @author Ambrose Xu
 */
@interface CellCryptology : NSObject

/*!
 @brief 返回 CellCryptology 的单例。
 */
+ (CellCryptology *)sharedSingleton;

/*!
 @brief 简单数据异或加密。密钥长度必须为 8 位。

 @param out 加密后的密文。
 @param text 待加密的明文数据。
 @param length 待加密明文数据的长度。
 @param key 加密数据使用的密钥，长度必须为 8 位。
 @return 返回加密后的密文长度。
 */
- (int)simpleEncrypt:(char *)out text:(const char *)text length:(int)length key:(const char *)key;

/*!
 @brief 简单数据异或解密。密钥长度必须为 8 位。

 @param out 解密后的明文。
 @param text 待解密的密文数据。
 @param length 待解密密文数据的长度。
 @param key 解密数据使用的密钥，长度必须为 8 位。
 @return 返回解密后的明文长度。
 */
- (int)simpleDecrypt:(char *)out text:(const char *)text length:(int)length key:(const char *)key;

@end
