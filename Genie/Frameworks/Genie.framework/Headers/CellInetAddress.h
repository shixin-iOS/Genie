/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"

/*!
 @brief 网络地址描述。
 
 @author Ambrose Xu
 */
@interface CellInetAddress : NSObject

/*! 网络主机名或主机地址。 */
@property (nonatomic, strong, readonly) NSString *host;
/*! 网络端口号。 */
@property (nonatomic, assign, readonly) NSUInteger port;

/*!
 @brief 按指定地址和端口号初始化。

 @param host 网络主机名或地址。
 @param port 网络主机端口号。
 */
- (id)initWithAddress:(NSString *)host port:(NSUInteger)port;

/*!
 @brief 返回主机地址字符串。
 */
- (NSString *)getHost;

/*!
 @brief 返回通信服务端口。
 */
- (NSUInteger)getPort;

@end
