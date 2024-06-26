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
/**
 * 王道03. 删除顺序表中所有值为x的元素
 * @param L 顺序表
 * @param x 要删除的元素
 */
void Wangdao_SqList_3(SqList *L, int x);
/**
 * 王道04. 删除顺序表中所有值在给定范围[s,t]之间的元素
 * @param L 顺序表
 * @param s 范围起始
 * @param t 范围终止
 */
void Wangdao_SqList_4(SqList *L, int s, int t);
/**
 * 王道05. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
 * @param L 顺序表
 */
void Wangdao_SqList_5(SqList *L);
/**
 * 王道10. 将顺序表循环左移p个位置
 * @param L 顺序表
 * @param p 左移位数
 */
void Wangdao_SqList_10(SqList *L, int p);
/**
 * 王道11. 找出两个有序顺序表的中位数
 * @param L1 顺序表1
 * @param L2 顺序表2
 * @return 中位数
 */
int Wangdao_SqList_11(SqList *L1, SqList *L2);
/**
 * 王道14. 计算并返回三个有序顺序表的元素之间的最小距离
 * @param L1 顺序表1
 * @param L2 顺序表2
 * @param L3 顺序表3
 * @return 最小距离
 */
int Wangdao_SqList_14(SqList *L1, SqList *L2, SqList *L3);

#endif//DATASTRUCTURE408_SQLIST_PROBLEMS_H
