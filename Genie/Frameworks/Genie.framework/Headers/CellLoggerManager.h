/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 日志等级。
 */
typedef enum _CellLogLevel
{
    /*! Debug 等级。 */
    LL_DEBUG = 1,

    /*! Info 等级。 */
    LL_INFO = 3,

    /*! Warning 等级。 */
    LL_WARN = 5,

    /*! Error 等级。 */
    LL_ERROR = 7

} CellLogLevel;


/*!
 @brief 日志事件委派。
 */
@protocol CellLogDelegate <NSObject>

/*!
 @brief 以 Debug 等级记录日志。
 @param text 日志文本内容。
 */
- (void)logDebug:(NSString *)text;

/*!
 @brief 以 Info 等级记录日志。
 @param text 日志文本内容。
 */
- (void)logInfo:(NSString *)text;

/*!
 @brief 以 Warning 等级记录日志。
 @param text 日志文本内容。
 */
- (void)logWarn:(NSString *)text;

/*!
 @brief 以 Error 等级记录日志。
 @param text 日志文本内容。
 */
- (void)logError:(NSString *)text;

@end // CellLogDelegate


/*!
 @brief 日志管理器。
 
 @author Ambrose Xu
 */
@interface CellLoggerManager : NSObject

/*! 日志事件委派。 */
@property (nonatomic, strong) id<CellLogDelegate> delegate;

/*! 当前日志级别。 */
@property (nonatomic, assign) CellLogLevel level;

/*!
 @brief 返回日志管理器的单例。
 */
+ (CellLoggerManager *)sharedSingleton;

/*!
 @brief 记录日志。

 @param text 日志文本内容。
 @param level 日志等级。
 */
- (void)log:(NSString *)text level:(CellLogLevel)level;

/*!
 @brief 记录日志。

 @param level 日志等级。
 @param format 日志格式化文本内容。
 */
- (void)log:(CellLogLevel)level textFormat:(NSString *)format, ...;

@end
