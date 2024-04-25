//
// Created by tategotoazarasi on 24-4-25.
//
#include "sqlist.h"
#include <stdlib.h>

/**
 * 构造一个空的线性表
 * @param L 线性表
 * @return 构造成功则返回OK，否则返回ERROR
 */
Status InitList(SqList *L) {
	L->elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
	if(!L->elem)
		return OVERFLOW;         // 存储分配失败
	L->length   = 0;             // 空表长度为0
	L->listsize = LIST_INIT_SIZE;// 初始存储容量
	return OK;
}

/**
 * 在顺序表的第i个位置之前插入元素e
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 插入成功则返回OK，否则返回ERROR
 */
Status ListInsert_Sq(SqList *L, int i, int e) {
	// i的合法值为1<=i<=L->length+1
	if(i < 1 || i > L->length + 1)
		return ERROR;// i值不合法
	if(L->length >= L->listsize) {
		// 当前存储空间已满，增加分配
		int *newbase = (int *) realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		if(!newbase)
			return OVERFLOW;         // 存储分配失败
		L->elem = newbase;           // 新基址
		L->listsize += LISTINCREMENT;// 增加存储容量
	}
	int *q = &(L->elem[i - 1]);// q为插入位置
	for(int *p = &(L->elem[L->length - 1]); p >= q; --p) {
		*(p + 1) = *p;// 插入位置及之后的元素右移
	}
	*q = e;     // 插入e
	++L->length;// 表长增1
	return OK;
}

/**
 * 删除顺序表的第i个元素，并用e返回其值
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 删除成功则返回OK，否则返回ERROR
 */
Status ListDelete_Sq(SqList *L, int i, int *e) {
	// i的合法值为1<=i<=L->length
	if(i < 1 || i > L->length)
		return ERROR;                // i值不合法
	int *p = &(L->elem[i - 1]);      // p为被删除元素的位置
	*e     = *p;                     // 被删除元素的值赋给e
	int *q = L->elem + L->length - 1;// 表尾元素的位置
	for(++p; p <= q; ++p) {
		*(p - 1) = *p;// 被删除元素之后的元素左移
	}
	--L->length;// 表长减1
	return OK;
}

/**
 * 在顺序线性表L中查找第一个值与e满足compare()的元素的位序
 * @param L 顺序线性表
 * @param e 元素
 * @param compare 比较函数
 * @return 若找到则返回其位序，否则返回0
 */
int LocateElem_Sq(SqList *L, int e, Status (*compare)(int, int)) {
	int i  = 1;      // i的初值为第一个元素的位序
	int *p = L->elem;// p的初值为第一个元素的存储位置
	while(i <= L->length && !(*compare)(*p++, e))
		++i;
	if(i <= L->length)
		return i;
	return 0;
}

/**
 * 归并两个有序顺序线性表
 * @param La 顺序线性表La
 * @param Lb 顺序线性表Lb
 * @param Lc 归并后的顺序线性表Lc
 */
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc) {
	int *pa = La->elem, *pb = Lb->elem;
	Lc->listsize = Lc->length = La->length + Lb->length;
	int *pc = Lc->elem = (int *) malloc(Lc->listsize * sizeof(int));
	if(!Lc->elem)
		exit(OVERFLOW);// 存储分配失败
	int *pa_last = La->elem + La->length - 1;
	int *pb_last = Lb->elem + Lb->length - 1;
	while(pa <= pa_last && pb <= pb_last) {// 归并
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa <= pa_last)
		*pc++ = *pa++;// 插入La的剩余元素
	while(pb <= pb_last)
		*pc++ = *pb++;// 插入Lb的剩余元素
}
/**
 * 销毁线性表
 * @param L 线性表
 */
void DestroyList_Sq(SqList *L) {
	free(L->elem);
	L->elem     = NULL;
	L->length   = 0;
	L->listsize = 0;
}
/**
 * 将线性表置为空表
 * @param L 线性表
 */
void ClearList_Sq(SqList *L) {
	L->length = 0;
}
/**
 * 判断线性表是否为空
 * @param L 线性表
 * @return 若线性表为空则返回TRUE，否则返回FALSE
 */
int ListEmpty_Sq(SqList *L) {
	return L->length == 0;
}
/**
 * 返回线性表中数据元素的个数
 * @param L 线性表
 * @return 线性表中数据元素的个数
 */
int ListLength_Sq(SqList *L) {
	return L->length;
}
/**
 * 用e返回L中第i个数据元素的值
 * @param L 线性表
 * @param i 数据元素的位序
 * @param e 第i个数据元素
 */
void GetElem_Sq(SqList *L, int i, int *e) {
	if(i < 1 || i > L->length)
		exit(ERROR);// i值不合法
	*e = L->elem[i - 1];
}
/**
 * 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
 * @param L 线性表
 * @param cur_e 当前数据元素
 * @param pre_e 前驱数据元素
 */
void PriorElem_Sq(SqList *L, const int *cur_e, int *pre_e) {
	for(int i = 1; i < L->length; i++) {
		if(L->elem[i] == *cur_e) {
			*pre_e = L->elem[i - 1];
			return;
		}
	}
	exit(ERROR);// 没有找到元素或cur_e是第一个元素
}
/**
 * 若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
 * @param L 线性表
 * @param cur_e 当前数据元素
 * @param next_e 后继数据元素
 */
void NextElem_Sq(SqList *L, const int *cur_e, int *next_e) {
	for(int i = 0; i < L->length - 1; i++) {
		if(L->elem[i] == *cur_e) {
			*next_e = L->elem[i + 1];
			return;
		}
	}
	exit(ERROR);// 没有找到元素或cur_e是最后一个元素
}
/**
 * 依次对L的每个数据元素调用visit()，一旦visit()失败，则操作失败
 * @param L 线性表
 * @param visit 操作函数
 */
void ListTraverse_Sq(SqList *L, void (*visit)(int *)) {
	for(int i = 0; i < L->length; i++) {
		visit(&L->elem[i]);
	}
}