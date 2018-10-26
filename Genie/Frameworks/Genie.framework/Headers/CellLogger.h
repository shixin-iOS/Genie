/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 日志记录器。
 
 @author Ambrose Xu
 */
@interface CellLogger : NSObject

/*!
 @brief 记录 DEBUG 等级日志。
 */
+ (void)d:(NSString *)format, ...;

/*!
 @brief 记录 INFO 等级日志。
 */
+ (void)i:(NSString *)format, ...;

/*!
 @brief 记录 WARNING 等级日志。
 */
+ (void)w:(NSString *)format, ...;

/*!
 @brief 记录 ERROR 等级日志。
 */
+ (void)e:(NSString *)format, ...;

/*!
 @brief 当前日志等级是否是 DEBUG 级别。
 */
+ (BOOL)isDebugLevel;

@end
