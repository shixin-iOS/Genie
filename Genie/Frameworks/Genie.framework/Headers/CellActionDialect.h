//
//  CellActionDialect.h
//  Genie
//
//  Created by 曾長歡 on 2018/3/6.
//  Copyright © 2018年 曾長歡. All rights reserved.
//

#import "CellPrimitive.h"

@interface CellActionDialect : CellPrimitive

/**
 动作名
 */
@property (nonatomic, strong) NSString *name;


/**
 用于从原语构造

 @param primitive 原语
 @return ActionDialect
 */
- (id)initWithPrimitive:(CellPrimitive *)primitive;

/**
 构造函数

 @param name 动作名
 @return ActionDialect
 */
- (id)initWithName:(NSString *)name;

/**
 是否包含指定键的参数

 @param key key
 @return YES/NO
 */
- (BOOL)containsParam:(NSString *)key;


/**
 添加值为字符串类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key stringValue:(NSString *)value;


/**
 添加值为int类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key intValue:(int)value;

/**
 添加值为long long类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key longlongValue:(long long)value;


/**
 添加值为BOOL类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key boolValue:(BOOL)value;


/**
 添加值为float类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key floatValue:(float)value;


/**
 添加值为double类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key doubleValue:(double)value;


/**
 添加值为NSDictionary类型的键值对参数

 @param key key
 @param value value
 */
- (void)appendParam:(NSString *)key json:(NSDictionary *)value;


/**
 获取指定键的字符串形式的参数值

 @param key key
 @return NSString
 */
- (NSString *)getParamAsString:(NSString *)key;


/**
 获取指定键的整数形式的参数值

 @param key key
 @return int
 */
- (int)getParamAsInt:(NSString *)key;


/**
 取指定键的长整型形式的参数值

 @param key key
 @return long
 */
- (long)getParamAsLong:(NSString *)key;


/**
 取指定键的长整型形式的参数值

 @param key key
 @return long long
 */
- (long long)getParamAsLongLong:(NSString *)key;


/**
 获取指定键的布尔型形式的参数值

 @param key key
 @return BOOL
 */
- (BOOL)getParamAsBool:(NSString *)key;


/**
 获取指定键的 NSDictionary 形式的参数值

 @param key key
 @return  NSDictionary
 */
- (NSDictionary *)getParamAsJson:(NSString *)key;

@end










