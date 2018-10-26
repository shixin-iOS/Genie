/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"

@interface CellPrimitiveCapsule : NSObject

@property (nonatomic, strong) NSMutableDictionary * data;

@property (nonatomic, strong) CellSession *session;

- (id)initWithSession:(CellSession *)session;

- (void)addPrimitive:(NSString *)cellet primitive:(CellPrimitive *)primitive;

- (CellPrimitive *)removePrimitive:(NSString *)cellet sn:(const char *)sn;

- (void)clean;

@end
