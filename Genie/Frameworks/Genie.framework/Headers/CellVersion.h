/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>

@interface CellVersion : NSObject
/**
 返回主版本号

 @return 返回主版本号
 */
+ (int)major;

/**
 返回副版本号

 @return 返回副版本号
 */
+ (int)minor;

/**
 返回修订号

 @return 返回修订号
 */
+ (int)revision;


/**
 返回版本名

 @return 返回版本名
 */
+ (NSString *)name;

@end
