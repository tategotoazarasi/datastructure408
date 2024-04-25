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