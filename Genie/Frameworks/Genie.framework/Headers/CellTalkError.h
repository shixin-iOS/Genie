//
//  CellTalkError.h
//  Genie
//
//  Created by 曾長歡 on 2018/3/21.
//  Copyright © 2018年 曾長歡. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CellMessageService.h"

typedef enum _TalkError
{
    /** 网络一般错误。 */
    CellTalkErrorNetworkError = 1000,
    /** 网络链路错误。 */
    CellTalkErrorNetworkLinkError = 1010,
    /** 网络 Socket 错误。 */
    CellTalkErrorNetworkSocketError = 1020,
    /** 网络 I/O 错误。 */
    CellTalkErrorNetworkIOError = 1030,
    /** 心跳超时。 */
    CellTalkErrorHeartbeatTimeout = 1040,
    /** 握手错误。 */
    CellTalkErrorHandshakeError = 2000,
    /** 握手超时。 */
    CellTalkErrorHandshakeTimeout = 2001
}TalkError;

@interface CellTalkError : NSObject

@property (nonatomic, assign) NSInteger errorCode;

@property (nonatomic, copy) NSString *desc;

+ (CellTalkError *)transformError:(CellMessageErrorCode)messageError;

-(instancetype)initWithCode:(NSInteger)code andDesc:(NSString *)desc;


@end
