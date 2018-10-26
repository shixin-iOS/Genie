/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

#ifndef CELL_HEAD_LENGTH
#define CELL_HEAD_LENGTH 4
#endif

#ifndef CELL_TAIL_LENGTH
#define CELL_TAIL_LENGTH 4
#endif

/// 默认消息头。
static char MessageDefaultHead[] = { 0x20, 0x13, 0x09, 0x08 };

/// 默认消息尾。
static char MessageDefaultTail[] = { 0x19, 0x78, 0x10, 0x04 };

/*!
 @brief 消息描述类。
 */
@interface CellMessage : NSObject

/*! 消息序号。 */
@property (nonatomic, strong, readonly) NSNumber *sn;

/*! 自定义上下文。 */
@property (nonatomic, strong) NSObject * context;

/*!
 @brief 指定数据对象初始化。

 @param data 指定消息数据。
 */
- (id)initWithData:(NSData *)data;

/*!
 @brief 指定字节数组初始化。

 @param bytes 指定字节数组形式的消息数据。
 @param length 指定数据长度。
 */
- (id)initWithBytes:(const char *)bytes length:(NSUInteger)length;

/*!
 @brief 获取消息的数据。
 
 @return 返回消息数据。
 */
- (NSData *)data;

/*!
 @brief 获得消息的数据指针。
 
 @return 返回消息的数据指针。
 */
- (char *)getPayload;

/*!
 @brief 获得消息数据的长度。
 
 @return 返回消息数据的长度。
 */
- (NSUInteger)getPayloadLength;

/*!
 @brief 设置消息负载数据。

 @param bytes 指定字节数组形式的消息数据。
 @param length 指定数据长度。
 */
- (void)setPayload:(const char *)bytes length:(NSUInteger)length;

/*!
 @brief 是否启用压缩。
 */
- (BOOL)isCompressible;

/*!
 @brief 校验负载是否是压缩格式。
 */
- (BOOL)verifyCompression;

/*!
 @brief 是否需要压缩。
 */
- (BOOL)needCompressible;

/*!
 @brief 校验负载是否是压缩格式。
 */
+ (BOOL)verifyCompression:(NSData *)data;

/*!
 @brief 从指定的数据源提取符合格式的 CellMessage 数据对象列表。
 */
+ (void)extract:(NSMutableArray *)result source:(CellByteBuffer *)source remains:(CellByteBuffer *)remains;

@end
