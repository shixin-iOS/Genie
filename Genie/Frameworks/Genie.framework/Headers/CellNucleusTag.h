/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"

/*!
 @brief 内核标签。
 */
@interface CellNucleusTag : NSObject

/*!
 @brief 使用随机 UUID 初始化标签。
 */
- (id)initWithRandom;

/*!
 @brief 根据 UUID 格式的字符串初始化标签。
 */
- (id)initWithString:(NSString *)uuid;

/*!
 @brief 返回 UUID 的字符串形式。
 */
- (NSString *)getAsString;

- (const char *)bytesAsString;

- (NSUInteger)bytesLength;

@end
