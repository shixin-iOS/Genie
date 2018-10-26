/*
 -----------------------------------------------------------------------------
 This source file is part of Genie.
 
 Copyright (c) 2017 Genie Team.
 -----------------------------------------------------------------------------
 */

#ifndef CellLiteralBase_h
#define CellLiteralBase_h

/*!
 @brief 原语语素字面义定义。
 */
typedef enum _CellLiteralBase
{
    /*! 字符串类型。 */
    CCLiteralBaseString = 'S',

    /*! 整数型。 */
    CCLiteralBaseInt = 'I',

    /*! 长整型。 */
    CCLiteralBaseLong = 'L',

    /*! 浮点型。 */
    CCLiteralBaseFloat = 'F',

    /*! 双精浮点型。 */
    CCLiteralBaseDouble = 'D',

    /*! 布尔型。 */
    CCLiteralBaseBool = 'B',

    /*! JSON 类型。 */
    CCLiteralBaseJSON = 'J',

    /*! 二进制类型。 */
    CCLiteralBaseBin = 'N'

} CellLiteralBase;

/*!
 @brief 解析字面义。
 */
CellLiteralBase parseLiteralBase(char code);

#endif /* CellLiteralBase_h */
