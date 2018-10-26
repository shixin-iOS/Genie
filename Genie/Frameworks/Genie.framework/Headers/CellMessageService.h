/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 消息错误码定义。
 
 @author Ambrose Xu
 */
typedef enum _CellMessageErrorCode
{
    /*! 未知的错误类型。 */
    CellMessageErrorUnknown = 100,
    /*! 无效的网络地址。 */
    CellMessageErrorAddressInvalid = 101,
    /*! 错误的状态。 */
    CellMessageErrorStateError = 102,
    
    /*! Socket 函数发生错误。 */
    CellMessageErrorSocketFailed = 200,
    /*! 绑定服务时发生错误。 */
    CellMessageErrorBindFailed = 201,
    /*! 监听连接时发生错误。 */
    CellMessageErrorListenFailed = 202,
    /*! Accept 发生错误。 */
    CellMessageErrorAcceptFailed = 203,

    /*! 连接失败。 */
    CellMessageErrorConnectFailed = 300,
    /*! 连接超时。 */
    CellMessageErrorConnectTimeout = 301,
    /*! 连接正常结束 */
    CellMessageErrorConnectEnd = 305,

    /*! 写数据超时。 */
    CellMessageErrorWriteTimeout = 401,
    /*! 读数据超时。 */
    CellMessageErrorReadTiemout = 402,
    /*! 写入数据时发生错误。 */
    CellMessageErrorWriteFailed = 403,
    /*! 读取数据时发生错误。 */
    CellMessageErrorReadFailed = 404,
    /** 写数据越界。 */
    CellMessageErrorWriteOutOfBounds = 405

} CellMessageErrorCode;


/*!
 @brief 消息服务处理监听器。
 */
@protocol CellMessageHandler <NSObject>
@optional

/*!
 @brief 创建连接会话。
 
 @param session 发生此事件的会话。
 */
- (void)sessionCreated:(CellSession *)session;

/*!
 @brief 销毁连接会话。
 
 @param session 发生此事件的会话。
 */
- (void)sessionDestroyed:(CellSession *)session;

/*!
 @brief 开启连接会话。
 
 @param session 发生此事件的会话。
 */
- (void)sessionOpened:(CellSession *)session;

/*!
 @brief 关闭连接会话。
 
 @param session 发生此事件的会话。
 */
- (void)sessionClosed:(CellSession *)session;

/*!
 @brief 接收到消息。
 
 @param session 发生此事件的会话。
 @param message 接收到的消息。
 */
- (void)messageReceived:(CellSession *)session message:(CellMessage *)message;

/*!
 @brief 消息已发送。
 
 @param session 发生此事件的会话。
 @param message 已发送的消息。
 */
- (void)messageSent:(CellSession *)session message:(CellMessage *)message;

/*!
 @brief 发生错误。
 
 @param errorCode 发生错误的错误码。
 @param session 发生此事件的会话。
 @see CCMessageErrorCode
 */
- (void)errorOccurred:(CellMessageErrorCode)errorCode session:(CellSession *)session;

@end


/*!
 @brief 消息服务。
 
 @author Ambrose Xu
 */
@interface CellMessageService : NSObject

/*! 消息事件委派。 */
@property (strong, nonatomic) id<CellMessageHandler> delegate;

/*!
 @brief 指定消息操作委派初始化。
 
 @param delegate 指定委派。
 */
- (id)initWithDelegate:(id<CellMessageHandler>)delegate;

/*!
 @brief 设置消息操作委派。
 
 @param delegate 指定委派。
 */
- (void)setDelegate:(id<CellMessageHandler>)delegate;

@end
