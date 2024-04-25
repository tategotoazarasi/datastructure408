//
// Created by tategotoazarasi on 24-4-25.
//

#ifndef DATASTRUCTURE408_SQLIST_H
#define DATASTRUCTURE408_SQLIST_H

#define LIST_INIT_SIZE 100///< 线性表存储空间的初始分配量
#define LISTINCREMENT 10  ///< 线性表存储空间的分配增量

#include "../../global.h"
#include <check.h>
/**
 * 顺序表的抽象数据类型
 */
typedef struct {
	int *elem;   ///< 存储空间基址
	int length;  ///< 当前长度
	int listsize;///< 当前分配的存储容量
} SqList;

/**
 * 构造一个空的顺序表
 * @param L 顺序表
 * @return 构造成功则返回OK，否则返回ERROR
 */
Status InitList(SqList *L);
/**
 * 在顺序表的第i个位置之前插入元素e
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 插入成功则返回OK，否则返回ERROR
 */
Status ListInsert_Sq(SqList *L, int i, int e);
/**
 * 删除顺序表的第i个元素，并用e返回其值
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 删除成功则返回OK，否则返回ERROR
 */
Status ListDelete_Sq(SqList *L, int i, int *e);
/**
 * 在顺序线性表L中查找第一个值与e满足compare()的元素的位序
 * @param L 顺序线性表
 * @param e 元素
 * @param compare 比较函数
 * @return 若找到则返回其位序，否则返回0
 */
int LocateElem_Sq(SqList *L, int e, Status (*compare)(int, int));
/**
 * 归并两个有序顺序线性表
 * @param La 顺序线性表La
 * @param Lb 顺序线性表Lb
 * @param Lc 归并后的顺序线性表Lc
 */
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc);
/**
 * 销毁线性表
 * @param L 线性表
 */
void DestroyList_Sq(SqList *L);
/**
 * 将线性表置为空表
 * @param L 线性表
 */
void ClearList_Sq(SqList *L);
/**
 * 判断线性表是否为空
 * @param L 线性表
 * @return 若线性表为空则返回TRUE，否则返回FALSE
 */
int ListEmpty_Sq(SqList *L);
/**
 * 返回线性表中数据元素的个数
 * @param L 线性表
 * @return 线性表中数据元素的个数
 */
int ListLength_Sq(SqList *L);
/**
 * 用e返回L中第i个数据元素的值
 * @param L 线性表
 * @param i 数据元素的位序
 * @param e 第i个数据元素
 */
void GetElem_Sq(SqList *L, int i, int *e);
/**
 * 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
 * @param L 线性表
 * @param cur_e 当前数据元素
 * @param pre_e 前驱数据元素
 */
void PriorElem_Sq(SqList *L, const int *cur_e, int *pre_e);
/**
 * 若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
 * @param L 线性表
 * @param cur_e 当前数据元素
 * @param next_e 后继数据元素
 */
void NextElem_Sq(SqList *L, const int *cur_e, int *next_e);
/**
 * 依次对L的每个数据元素调用visit()，一旦visit()失败，则操作失败
 * @param L 线性表
 * @param visit 操作函数
 */
void ListTraverse_Sq(SqList *L, void (*visit)(int *));

#endif//DATASTRUCTURE408_SQLIST_H
