/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#import "CellPrerequisites.h"
#import "CellTalkService.h"
@interface CellNucleus : NSObject

@property (nonatomic, strong, readonly) CellNucleusTag * tag;

@property (nonatomic, strong, readonly) CellTalkService * talkService;

- (void)resetTag;

- (id)initWithConfig:(CellNucleusConfig *)config;

- (void)destroy;

@end
