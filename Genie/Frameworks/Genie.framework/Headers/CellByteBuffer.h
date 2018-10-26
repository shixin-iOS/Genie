/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"

@interface CellByteBuffer : NSObject

- (id)initWithCapacity:(NSUInteger)capacity;

- (NSUInteger)capacity;

- (NSUInteger)position;

- (CellByteBuffer *)position:(NSUInteger)newPosition;

- (NSUInteger)limit;

- (CellByteBuffer *)limit:(NSUInteger)newLimit;

- (void)clear;

- (CellByteBuffer *)flip;

- (NSUInteger)remaining;

- (BOOL)hasRemaining;

- (CellByteBuffer *)put:(char)data;

- (CellByteBuffer *)put:(const char *)data offset:(NSUInteger)offset length:(NSUInteger)length;

- (char)get;

- (CellByteBuffer *)get:(char *)buf offset:(NSUInteger)offset length:(NSUInteger)length;

- (char *)bytes;

@end
