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
/**
 * 王道10. 将顺序表循环左移p个位置
 * @param L 顺序表
 * @param p 左移位数
 */
void Wangdao_SqList_10(SqList *L, int p) {
	int n     = L->length / p;
	int first = 1;
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < n + 1; j++) {
			int current = (i + j * p) % L->length;
			int tmp;
			if(first) {
				tmp   = L->elem[current];
				first = 0;
			} else {
				int tmp2         = L->elem[current];
				L->elem[current] = tmp;
				tmp              = tmp2;
			}
		}
	}
}
/**
 * 王道11. 找出两个有序顺序表的中位数
 * @param L1 顺序表1
 * @param L2 顺序表2
 * @return 中位数
 */
int Wangdao_SqList_11(SqList *L1, SqList *L2) {
	int i = 0, j = 0;
	for(int k = 1; k < (L1->length + L2->length + 1) / 2; k++) {
		if(L1->elem[i] < L2->elem[j]) {
			i++;
		} else {
			j++;
		}
	}
	if(i == L1->length) {
		return L2->elem[j];
	} else if(j == L2->length) {
		return L1->elem[i];
	} else if(L1->elem[i] < L2->elem[j]) {
		return L1->elem[i];
	} else {
		return L2->elem[j];
	}
}