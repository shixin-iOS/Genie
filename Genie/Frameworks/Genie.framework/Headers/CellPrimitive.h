/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"
#include "CellStuff.h"

@interface CellPrimitive : NSObject

/*! 语素清单。 */
@property (nonatomic, strong, readonly) NSMutableArray *stuffList;

/*! 创建时的时间戳。 */
@property (nonatomic, assign, readonly) int64_t timestamp;

- (id)initWithPrimitive:(CellPrimitive *)primtive;

/*!
 @brief 使用指定序号初始化。
 
 @param sn 指定原语序号。
 */
- (id)initWithSN:(char *)sn;

/*!
 @brief 获得原语的 SN 。
 
 @return 返回4字节的 SN 。
 */
- (char *)getSN;

/*!
 @brief 提交语素。
 
 @param stuff 指定需提交的语素。
 */
- (void)commit:(CellStuff *)stuff;

/*!
 @brief 获取指定索引位置处的语素。
 
 @param index 指定索引。
 @return 返回语素。
 */
- (CellStuff *)getStuff:(NSUInteger)index;

/*!
 @brief 删除指定索引位置的语素。
 
 @param index 指定索引。
 @return 返回被删除的语素。
 */
- (CellStuff *)removeStuff:(NSUInteger)index;

/*!
 @brief 获取当前原语包含的语素数量。
 
 @return 返回当前原语包含的语素数量。
 */
- (NSUInteger)numStuff;

@end
