//
// Created by tategotoazarasi on 24-4-25.
//
#include "sqlist.h"
#include <stdlib.h>

/**
 * 王道01. 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
 * @param L 顺序表
 * @return 被删元素的值
 */
int Wangdao_SqList_1(SqList *L) {
	if(L->length == 0) {
		exit(ERROR);
	}
	int min_i = 0;
	for(int i = 0; i < L->length; i++) {
		if(L->elem[i] < L->elem[min_i]) {
			min_i = i;
		}
	}
	int min_v      = L->elem[min_i];
	L->elem[min_i] = L->elem[L->length - 1];
	L->length--;
	return min_v;
}
/**
 * 王道02. 将一个顺序表的所有元素逆置
 * @param L 顺序表
 */
void Wangdao_SqList_2(SqList *L) {
	int i = 0;
	int j = L->length - 1;
	for(; i < j; i++, j--) {
		int temp   = L->elem[i];
		L->elem[i] = L->elem[j];
		L->elem[j] = temp;
	}
}
/**
 * 王道03. 删除顺序表中所有值为x的元素
 * @param L 顺序表
 * @param x 要删除的元素
 */
void Wangdao_SqList_3(SqList *L, int x) {
	int j       = 0;
	int deleted = 0;
	for(int i = 0; i < L->length; i++) {
		if(L->elem[i] != x) {
			L->elem[j++] = L->elem[i];
		} else {
			deleted++;
		}
	}
	L->length -= deleted;
}
/**
 * 王道04. 删除顺序表中所有值在给定范围[s,t]之间的元素
 * @param L 顺序表
 * @param s 范围起始
 * @param t 范围终止
 */
void Wangdao_SqList_4(SqList *L, int s, int t) {
	if(s >= t) {
		exit(ERROR);
	}
	int j       = 0;
	int deleted = 0;
	for(int i = 0; i < L->length; i++) {
		if(L->elem[i] < s || L->elem[i] > t) {
			L->elem[j++] = L->elem[i];
		} else {
			deleted++;
		}
	}
	L->length -= deleted;
}

void Wangdao_SqList_5(SqList *L) {
	int j       = 0;
	int deleted = 0;
	for(int i = 0; i < L->length; i++, j++) {
		while(i + 1 < L->length && L->elem[i] == L->elem[i + 1]) {
			deleted++;
			i++;
			L->elem[j] = L->elem[i];
		}
	}
	L->length -= deleted;
}