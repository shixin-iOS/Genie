/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 辅助函数库。
 
 @author Ambrose Xu
 */
@interface CellUtil : NSObject

/*!
 @brief 返回当前系统绝对时间值。单位：秒。
 */
+ (NSTimeInterval)currentTimeInterval;

/*!
 @brief 返回当前系统绝对时间值。单位：毫秒。
 */
+ (int64_t)currentTimeMillis;

/*!
 @brief 生成随机数。
 */
+ (long)randomLong;

/*!
 @brief 生成指定长度的随机字符串。
 
 @param length 指定字符串长度。
 @return 返回生成的字符串。
 */
+ (NSString *)randomString:(int)length;

/*!
 @brief 生成指定长度的随机字符串。
 
 @param string 指定生成的字符串指针。
 @param length 指定字符串长度。
 */
+ (void)randomString:(char *)string length:(int)length;

/*!
 @brief 生成指定长度的随机字节数组。
 
 @param output 指定接收数据的字节数组。
 @param length 指定需生成数组的长度。
 */
+ (void)randomBytes:(char *)output length:(int)length;

/*!
 @brief 转换 NSData 为 NSTimeInterval，即绝对时间。
 */
+ (NSTimeInterval)convertDataToTimeInterval:(NSData *)data;

/*!
 @brief short 型转字节流。
 */
+ (unsigned int)shortToBytes:(char *)output input:(short)input;

/*!
 @brief int 型转字节流。
 */
+ (unsigned int)intToBytes:(char *)output input:(int)input;

/*!
 @brief long long 型转字节流。
 */
+ (unsigned int)longToBytes:(char *)output input:(long long)input;

/*!
 @brief float 型转字节流。
 */
+ (unsigned int)floatToBytes:(char *)output input:(float)input;

/*!
 @brief double 型转字节流。
 */
+ (unsigned int)doubleToBytes:(char *)output input:(double)input;

/*!
 @brief BOOL 型转字节流。
 */
+ (unsigned int)boolToBytes:(char *)output input:(BOOL)input;

/*!
 @brief 字节流转 short 型。
 */
+ (short)bytesToShort:(char *)input;

/*!
 @brief 字节流转 int 型。
 */
+ (int)bytesToInt:(char *)input;

/*!
 @brief 字节流转 long long 型。
 */
+ (long long)bytesToLong:(char *)input;

/*!
 @brief 字节流转 float 型。
 */
+ (float)bytesToFloat:(char *)input;

/*!
 @brief 字节流转 double 型。
 */
+ (double)bytesToDouble:(char *)input;

/*!
 @brief 字节流转 BOOL 型。
 */
+ (BOOL)bytesToBool:(char *)input;

/*!
 @brief ZIP 算法压缩数据。
 */
+ (NSUInteger)compress:(CellByteBuffer *)output input:(char *)input length:(int)length;

/*!
 @brief ZIP 算法解压数据。
 */
+ (NSUInteger)uncompress:(CellByteBuffer *)output input:(char *)input length:(int)length;

@end
