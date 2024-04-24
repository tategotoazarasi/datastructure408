//
// Created by tategotoazarasi on 24-4-24.
//

#ifndef DATASTRUCTURE408_LIST_H
#define DATASTRUCTURE408_LIST_H

/**
 * 线性表的抽象数据类型
 */
typedef struct List {
	/**
     * 构造一个空的线性表
     * @param L 线性表
     */
	void (*InitList)(struct List *L);
	/**
     * 销毁线性表
     * @param L 线性表
     */
	void (*DestroyList)(struct List *L);
	/**
     * 将线性表置为空表
     * @param L 线性表
     */
	void (*ClearList)(struct List *L);
	/**
     * 判断线性表是否为空
     * @param L 线性表
     * @return 若线性表为空则返回TRUE，否则返回FALSE
     */
	int (*ListEmpty)(struct List *L);
	/**
     * 返回线性表中数据元素的个数
     * @param L 线性表
     * @return 线性表中数据元素的个数
     */
	int (*ListLength)(struct List *L);
	/**
     * 用e返回L中第i个数据元素的值
     * @param L 线性表
     * @param i 数据元素的位序
     * @param e 第i个数据元素
     */
	void (*GetElem)(struct List *L, int i, void *e);
	/**
     * 返回L中第一个与e满足compare()的数据元素的位序
     * @param L 线性表
     * @param e 数据元素
     * @param compare 比较函数
     * @return 若存在满足条件的数据元素，则返回其位序，否则返回0
     */
	int (*LocateElem)(struct List *L, void *e, int (*compare)(void *, void *));
	/**
     * 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
     * @param L 线性表
     * @param cur_e 当前数据元素
     * @param pre_e 前驱数据元素
     */
	void (*PriorElem)(struct List *L, void *cur_e, void *pre_e);
	/**
     * 若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
     * @param L 线性表
     * @param cur_e 当前数据元素
     * @param next_e 后继数据元素
     */
	void (*NextElem)(struct List *L, void *cur_e, void *next_e);
	/**
     * 在L的第i个位置之前插入新的数据元素e，L的长度加1
     * @param L 线性表
     * @param i 插入位置
     * @param e 新数据元素
     */
	void (*ListInsert)(struct List *L, int i, void *e);
	/**
     * 删除L的第i个数据元素，并用e返回其值，L的长度减1
     * @param L 线性表
     * @param i 删除位置
     * @param e 删除数据元素
     */
	void (*ListDelete)(struct List *L, int i, void *e);
	/**
     * 依次对L的每个数据元素调用visit()，一旦visit()失败，则操作失败
     * @param L 线性表
     * @param visit 操作函数
     */
	void (*ListTraverse)(struct List *L, void (*visit)(void *));
} List;

#endif//DATASTRUCTURE408_LIST_H
