//
// Created by tategotoazarasi on 24-4-25.
//

#ifndef DATASTRUCTURE408_SQLIST_PROBLEMS_H
#define DATASTRUCTURE408_SQLIST_PROBLEMS_H

#include "sqlist.h"

/**
 * 王道01. 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
 * @param L 顺序表
 * @return 被删元素的值
 */
int Wangdao_SqList_1(SqList *L);
/**
 * 王道02. 将一个顺序表的所有元素逆置
 * @param L 顺序表
 */
void Wangdao_SqList_2(SqList *L);

#endif//DATASTRUCTURE408_SQLIST_PROBLEMS_H
