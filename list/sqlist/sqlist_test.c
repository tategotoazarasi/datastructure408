//
// Created by tategotoazarasi on 24-4-25.
//
#include "sqlist_test.h"
#include "sqlist_problems.h"
#include <stdlib.h>

// Test insertions under normal conditions
START_TEST(test_ListInsert_Sq_Normal) {
	SqList L;
	InitList(&L);

	// Insert into empty list
	ck_assert_int_eq(ListInsert_Sq(&L, 1, 100), OK);
	ck_assert_int_eq(L.elem[0], 100);
	ck_assert_int_eq(L.length, 1);

	// Insert at beginning
	ck_assert_int_eq(ListInsert_Sq(&L, 1, 200), OK);
	ck_assert_int_eq(L.elem[0], 200);
	ck_assert_int_eq(L.elem[1], 100);
	ck_assert_int_eq(L.length, 2);

	// Insert at end
	ck_assert_int_eq(ListInsert_Sq(&L, 3, 300), OK);
	ck_assert_int_eq(L.elem[2], 300);
	ck_assert_int_eq(L.length, 3);

	// Insert in the middle
	ck_assert_int_eq(ListInsert_Sq(&L, 3, 250), OK);
	ck_assert_int_eq(L.elem[2], 250);
	ck_assert_int_eq(L.elem[3], 300);
	ck_assert_int_eq(L.length, 4);

	free(L.elem);
}
END_TEST

// Test boundary conditions
START_TEST(test_ListInsert_Sq_Boundary) {
	SqList L;
	InitList(&L);

	// Insert into empty list at the beginning
	ck_assert_int_eq(ListInsert_Sq(&L, 1, 500), OK);
	ck_assert_int_eq(L.length, 1);

	// Insert at list's end+1 position in a single element list
	ck_assert_int_eq(ListInsert_Sq(&L, 2, 600), OK);
	ck_assert_int_eq(L.length, 2);

	free(L.elem);
}
END_TEST

// Test invalid insertions
START_TEST(test_ListInsert_Sq_Invalid) {
	SqList L;
	InitList(&L);

	// Insert at zero index
	ck_assert_int_eq(ListInsert_Sq(&L, 0, 700), ERROR);

	// Insert beyond the end+1 position
	ck_assert_int_eq(ListInsert_Sq(&L, 3, 800), ERROR);

	free(L.elem);
}
END_TEST

// Random tests for robustness
START_TEST(test_ListInsert_Sq_Random) {
	SqList L;
	InitList(&L);
	int pos, num;

	for(int i = 0; i < 100; i++) {
		pos = rand() % (L.length + 1) + 1;
		num = rand();
		ck_assert_int_eq(ListInsert_Sq(&L, pos, num), OK);
	}

	free(L.elem);
}
END_TEST

// Add these tests to the suite
void add_list_insert_tests(TCase *tc) {
	tcase_add_test(tc, test_ListInsert_Sq_Normal);
	tcase_add_test(tc, test_ListInsert_Sq_Boundary);
	tcase_add_test(tc, test_ListInsert_Sq_Invalid);
	tcase_add_test(tc, test_ListInsert_Sq_Random);
}

// Helper function to populate list for testing
void populate_list(SqList *L, int size) {
	L->elem = (int *) malloc(size * sizeof(int));
	for(int i = 0; i < size; ++i) {
		L->elem[i] = i + 1;
	}
	L->length   = size;
	L->listsize = size;
}

// Test normal deletions
START_TEST(test_ListDelete_Sq_Normal) {
	SqList L;
	InitList(&L);
	populate_list(&L, 5);// Populate list with elements 1, 2, 3, 4, 5

	int e;
	// Delete middle element (3)
	ck_assert_int_eq(ListDelete_Sq(&L, 3, &e), OK);
	ck_assert_int_eq(e, 3);
	ck_assert_int_eq(L.length, 4);
	ck_assert_int_eq(L.elem[2], 4);

	// Delete first element
	ck_assert_int_eq(ListDelete_Sq(&L, 1, &e), OK);
	ck_assert_int_eq(e, 1);
	ck_assert_int_eq(L.length, 3);
	ck_assert_int_eq(L.elem[0], 2);

	// Delete last element
	ck_assert_int_eq(ListDelete_Sq(&L, 3, &e), OK);
	ck_assert_int_eq(e, 5);
	ck_assert_int_eq(L.length, 2);

	free(L.elem);
}
END_TEST

// Test boundary conditions
START_TEST(test_ListDelete_Sq_Boundary) {
	SqList L;
	InitList(&L);
	populate_list(&L, 1);// List with one element

	int e;
	// Delete only element
	ck_assert_int_eq(ListDelete_Sq(&L, 1, &e), OK);
	ck_assert_int_eq(e, 1);
	ck_assert_int_eq(L.length, 0);

	free(L.elem);
}
END_TEST

// Test invalid deletions
START_TEST(test_ListDelete_Sq_Invalid) {
	SqList L;
	InitList(&L);
	populate_list(&L, 3);// List with elements 1, 2, 3

	int e;
	// Attempt to delete at index 0
	ck_assert_int_eq(ListDelete_Sq(&L, 0, &e), ERROR);

	// Attempt to delete beyond length
	ck_assert_int_eq(ListDelete_Sq(&L, 4, &e), ERROR);

	free(L.elem);
}
END_TEST

// Random tests for robustness
START_TEST(test_ListDelete_Sq_Random) {
	SqList L;
	InitList(&L);
	populate_list(&L, 100);// Populate list with 100 elements

	int e, index;
	for(int i = 0; i < 50; ++i) {
		index = rand() % L.length + 1;
		ck_assert_int_eq(ListDelete_Sq(&L, index, &e), OK);
	}

	free(L.elem);
}
END_TEST

// Add these tests to the suite
void add_list_delete_tests(TCase *tc) {
	tcase_add_test(tc, test_ListDelete_Sq_Normal);
	tcase_add_test(tc, test_ListDelete_Sq_Boundary);
	tcase_add_test(tc, test_ListDelete_Sq_Invalid);
	tcase_add_test(tc, test_ListDelete_Sq_Random);
}

// Helper function to populate list for testing
void populate_list_for_locate(SqList *L, int size) {
	L->elem = (int *) malloc(size * sizeof(int));
	for(int i = 0; i < size; ++i) {
		L->elem[i] = i * 10;// Fill list with 0, 10, 20, ..., 10*(size-1)
	}
	L->length   = size;
	L->listsize = size;
}

// Comparison function for tests
Status compare_ints(int a, int b) {
	return a == b ? TRUE : FALSE;
}

// Test locating existing elements
START_TEST(test_LocateElem_Sq_Existing) {
	SqList L;
	InitList(&L);
	populate_list_for_locate(&L, 10);// List with elements 0, 10, 20, ..., 90

	// Locate middle element
	ck_assert_int_eq(LocateElem_Sq(&L, 50, compare_ints), 6);

	// Locate first element
	ck_assert_int_eq(LocateElem_Sq(&L, 0, compare_ints), 1);

	// Locate last element
	ck_assert_int_eq(LocateElem_Sq(&L, 90, compare_ints), 10);

	free(L.elem);
}
END_TEST

// Test locating non-existing elements
START_TEST(test_LocateElem_Sq_NonExisting) {
	SqList L;
	InitList(&L);
	populate_list_for_locate(&L, 5);// List with elements 0, 10, 20, 30, 40

	// Try to locate an element that does not exist
	ck_assert_int_eq(LocateElem_Sq(&L, 35, compare_ints), 0);

	free(L.elem);
}
END_TEST

// Test empty list
START_TEST(test_LocateElem_Sq_Empty) {
	SqList L;
	InitList(&L);

	// Attempt to locate any element in an empty list
	ck_assert_int_eq(LocateElem_Sq(&L, 10, compare_ints), 0);
}
END_TEST

// Random tests for robustness
START_TEST(test_LocateElem_Sq_Random) {
	SqList L;
	InitList(&L);
	populate_list_for_locate(&L, 100);// Populate list with 100 elements

	// Random tests
	for(int i = 0; i < 20; ++i) {
		int num      = rand() % 1000;
		int expected = num / 10 + 1;
		if(num >= 0 && num < 1000 && num % 10 == 0) {
			ck_assert_int_eq(LocateElem_Sq(&L, num, compare_ints), expected);
		} else {
			ck_assert_int_eq(LocateElem_Sq(&L, num, compare_ints), 0);
		}
	}

	free(L.elem);
}
END_TEST

// Add these tests to the suite
void add_locate_elem_tests(TCase *tc) {
	tcase_add_test(tc, test_LocateElem_Sq_Existing);
	tcase_add_test(tc, test_LocateElem_Sq_NonExisting);
	tcase_add_test(tc, test_LocateElem_Sq_Empty);
	tcase_add_test(tc, test_LocateElem_Sq_Random);
}

// Helper function to populate list for merging
void populate_list_for_merge(SqList *L, int start, int end, int step) {
	int size = (end - start) / step + 1;
	L->elem  = (int *) malloc(size * sizeof(int));
	for(int i = 0; i < size; ++i) {
		L->elem[i] = start + i * step;
	}
	L->length   = size;
	L->listsize = size;
}

// Test normal merge conditions
START_TEST(test_MergeList_Sq_Normal) {
	SqList La, Lb, Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	// Prepare lists
	populate_list_for_merge(&La, 1, 10, 2);// La = {1, 3, 5, 7, 9}
	populate_list_for_merge(&Lb, 2, 10, 2);// Lb = {2, 4, 6, 8, 10}

	// Merge lists
	MergeList_Sq(&La, &Lb, &Lc);
	ck_assert_int_eq(Lc.length, 10);
	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 0; i < 10; ++i) {
		ck_assert_int_eq(Lc.elem[i], expected[i]);
	}

	free(La.elem);
	free(Lb.elem);
	free(Lc.elem);
}
END_TEST

// Test merging with empty lists
START_TEST(test_MergeList_Sq_Empty) {
	SqList La, Lb, Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	// La is empty
	populate_list_for_merge(&Lb, 1, 5, 1);// Lb = {1, 2, 3, 4, 5}

	// Merge lists
	MergeList_Sq(&La, &Lb, &Lc);
	ck_assert_int_eq(Lc.length, 5);
	for(int i = 0; i < 5; ++i) {
		ck_assert_int_eq(Lc.elem[i], i + 1);
	}

	free(Lb.elem);
	free(Lc.elem);
}
END_TEST

// Add these tests to the suite
void add_merge_list_tests(TCase *tc) {
	tcase_add_test(tc, test_MergeList_Sq_Normal);
	tcase_add_test(tc, test_MergeList_Sq_Empty);
}

// Test for DestroyList_Sq
START_TEST(test_DestroyList_Sq) {
	SqList L;
	InitList(&L);
	populate_list(&L, 10);// Create a list with 10 elements

	DestroyList_Sq(&L);
	ck_assert_ptr_null(L.elem);
	ck_assert_int_eq(L.length, 0);
	ck_assert_int_eq(L.listsize, 0);
}
END_TEST

// Test for ClearList_Sq
START_TEST(test_ClearList_Sq) {
	SqList L;
	InitList(&L);
	populate_list(&L, 10);// Create a list with 10 elements

	ClearList_Sq(&L);
	ck_assert_int_eq(L.length, 0);
	ck_assert_int_ne(L.listsize, 0);// List size should not change

	// Clearing already empty list
	ClearList_Sq(&L);
	ck_assert_int_eq(L.length, 0);
}
END_TEST

// Test for ListEmpty_Sq
START_TEST(test_ListEmpty_Sq) {
	SqList L;
	InitList(&L);
	ck_assert_int_eq(ListEmpty_Sq(&L), TRUE);

	populate_list(&L, 10);
	ck_assert_int_eq(ListEmpty_Sq(&L), FALSE);
}
END_TEST

// Test for ListLength_Sq
START_TEST(test_ListLength_Sq) {
	SqList L;
	InitList(&L);
	ck_assert_int_eq(ListLength_Sq(&L), 0);

	populate_list(&L, 10);
	ck_assert_int_eq(ListLength_Sq(&L), 10);

	ClearList_Sq(&L);
	ck_assert_int_eq(ListLength_Sq(&L), 0);
}
END_TEST

// Add these tests to the test case in the test suite
void add_list_management_tests(TCase *tc) {
	tcase_add_test(tc, test_DestroyList_Sq);
	tcase_add_test(tc, test_ClearList_Sq);
	tcase_add_test(tc, test_ListEmpty_Sq);
	tcase_add_test(tc, test_ListLength_Sq);
}

// Test for normal element retrieval
START_TEST(test_GetElem_Sq_Normal) {
	SqList L;
	InitList(&L);
	for(int i = 1; i <= 10; i++) {
		ListInsert_Sq(&L, i, i * 10);// List will contain 10, 20, ..., 100
	}

	int e;
	// Access first element
	GetElem_Sq(&L, 1, &e);
	ck_assert_int_eq(e, 10);

	// Access middle element
	GetElem_Sq(&L, 5, &e);
	ck_assert_int_eq(e, 50);

	// Access last element
	GetElem_Sq(&L, 10, &e);
	ck_assert_int_eq(e, 100);
}
END_TEST

// Test boundary conditions
START_TEST(test_GetElem_Sq_Boundary) {
	SqList L;
	InitList(&L);
	for(int i = 1; i <= 5; i++) {
		ListInsert_Sq(&L, i, i * 10);// List will contain 10, 20, 30, 40, 50
	}

	int e;
	// Attempt to access zero index
	GetElem_Sq(&L, 0, &e);
	ck_assert_int_eq(e, ERROR);

	// Attempt to access beyond the list length
	GetElem_Sq(&L, 6, &e);
	ck_assert_int_eq(e, ERROR);
}
END_TEST

// Test empty list access
START_TEST(test_GetElem_Sq_Empty) {
	SqList L;
	InitList(&L);

	int e;
	// Attempt to access any element in an empty list
	GetElem_Sq(&L, 1, &e);
	ck_assert_int_eq(e, ERROR);
}
END_TEST

// Add these tests to the test case in the test suite
void add_get_elem_tests(TCase *tc) {
	tcase_add_test(tc, test_GetElem_Sq_Normal);
	tcase_add_test(tc, test_GetElem_Sq_Boundary);
	tcase_add_test(tc, test_GetElem_Sq_Empty);
}

// Helper function to initialize a list with multiple elements
void init_and_populate_list(SqList *L, int num) {
	InitList(L);
	for(int i = 1; i <= num; i++) {
		ListInsert_Sq(L, i, i * 10);// Insert elements 10, 20, ..., num*10
	}
}

// Test for PriorElem_Sq
START_TEST(test_PriorElem_Sq) {
	SqList L;
	init_and_populate_list(&L, 5);// Create a list with elements 10, 20, 30, 40, 50

	int e, pre_e;
	e = 20;
	PriorElem_Sq(&L, &e, &pre_e);
	ck_assert_int_eq(pre_e, 10);
}
END_TEST

// Test for NextElem_Sq
START_TEST(test_NextElem_Sq) {
	SqList L;
	init_and_populate_list(&L, 5);// Create a list with elements 10, 20, 30, 40, 50

	int e, next_e;
	e = 40;
	NextElem_Sq(&L, &e, &next_e);
	ck_assert_int_eq(next_e, 50);
}
END_TEST

// Add these tests to the test case in the test suite
void add_prior_next_elem_tests(TCase *tc) {
	tcase_add_test(tc, test_PriorElem_Sq);
	tcase_add_test(tc, test_NextElem_Sq);
}

// 操作函数：总是成功
void always_success_visit(int *e) {
	// 可以对元素进行操作，如打印或修改
}

// 操作函数：在元素值为50时失败
void fail_on_fifty_visit(int *e) {
	if(*e == 50) {
		exit(ERROR);// 模拟操作失败
	}
}

// 测试遍历正常情况
START_TEST(test_ListTraverse_Sq_Success) {
	SqList L;
	InitList(&L);
	for(int i = 1; i <= 5; i++) {
		ListInsert_Sq(&L, i, i * 10);// Insert elements 10, 20, 30, 40, 50
	}

	// 期望没有错误发生，所有元素都被处理
	ListTraverse_Sq(&L, always_success_visit);
	ck_assert_msg(L.length == 5, "All elements should have been visited successfully.");
}
END_TEST

// 测试空表的遍历
START_TEST(test_ListTraverse_Sq_Empty) {
	SqList L;
	InitList(&L);

	// 空表，期望无事发生
	ListTraverse_Sq(&L, always_success_visit);
	ck_assert_msg(L.length == 0, "Traversal on empty list should handle gracefully.");
}
END_TEST

// 添加测试用例到套件
void add_list_traverse_tests(TCase *tc) {
	tcase_add_test(tc, test_ListTraverse_Sq_Success);
	tcase_add_test(tc, test_ListTraverse_Sq_Empty);
}

// 测试正常初始化
START_TEST(test_InitList_Normal) {
	SqList L;
	Status result = InitList(&L);

	// 验证初始化结果是否成功
	ck_assert_int_eq(result, OK);
	ck_assert_ptr_nonnull(L.elem);
	ck_assert_int_eq(L.length, 0);
	ck_assert_int_eq(L.listsize, LIST_INIT_SIZE);
	// 清理资源
	free(L.elem);
}
END_TEST

// 添加测试用例到测试套件
void add_init_tests(TCase *tc) {
	tcase_add_test(tc, test_InitList_Normal);
}

// 测试初始化后插入多个元素
START_TEST(test_Init_Insert) {
	SqList L;
	Status result = InitList(&L);
	ck_assert_int_eq(result, OK);

	// 插入多个元素
	for(int i = 1; i <= 5; i++) {
		ck_assert_int_eq(ListInsert_Sq(&L, i, i * 10), OK);
	}

	// 检查插入后的顺序和数量
	ck_assert_int_eq(L.length, 5);
	for(int i = 0; i < 5; i++) {
		ck_assert_int_eq(L.elem[i], (i + 1) * 10);
	}

	// 清理资源
	free(L.elem);
}
END_TEST

// 测试插入和删除功能
START_TEST(test_Insert_Delete) {
	SqList L;
	InitList(&L);

	// 插入元素
	for(int i = 1; i <= 5; i++) {
		ListInsert_Sq(&L, i, i);
	}

	// 删除第三个元素
	int e;
	ListDelete_Sq(&L, 3, &e);
	ck_assert_int_eq(e, 3);

	// 验证剩余元素和顺序
	int expected[] = {1, 2, 4, 5};
	for(int i = 0; i < L.length; i++) {
		ck_assert_int_eq(L.elem[i], expected[i]);
	}

	// 清理资源
	free(L.elem);
}
END_TEST

// 测试归并
START_TEST(test_MergeLists) {
	SqList La, Lb, Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	// 分别插入元素到La和Lb
	int elementsA[] = {1, 3, 5};
	int elementsB[] = {2, 4, 6};
	for(int i = 0; i < 3; i++) {
		ListInsert_Sq(&La, i + 1, elementsA[i]);
		ListInsert_Sq(&Lb, i + 1, elementsB[i]);
	}

	// 归并La和Lb到Lc
	MergeList_Sq(&La, &Lb, &Lc);
	int expected[] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < Lc.length; i++) {
		ck_assert_int_eq(Lc.elem[i], expected[i]);
	}

	// 清理资源
	free(La.elem);
	free(Lb.elem);
	free(Lc.elem);
}
END_TEST

// 添加测试用例到套件
void add_combination_tests(TCase *tc) {
	tcase_add_test(tc, test_Init_Insert);
	tcase_add_test(tc, test_Insert_Delete);
	tcase_add_test(tc, test_MergeLists);
}

START_TEST(wangdao_sqList_Test_1) {
	SqList L;
	InitList(&L);
	int elements[] = {1, 0, 3, 4, 6};
	for(int i = 0; i < 5; i++) {
		ListInsert_Sq(&L, i + 1, elements[i]);
	}
	int ans = Wangdao_SqList_1(&L);
	ck_assert_int_eq(ans, 0);
	ck_assert_int_eq(L.length, 4);
	int expected[] = {1, 6, 3, 4};
	for(int i = 0; i < L.length; i++) {
		ck_assert_int_eq(L.elem[i], expected[i]);
	}
}
END_TEST

START_TEST(wangdao_sqList_Test_2) {
	SqList L;
	InitList(&L);
	int elements[] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++) {
		ListInsert_Sq(&L, i + 1, elements[i]);
	}
	Wangdao_SqList_2(&L);
	int expected[] = {5, 4, 3, 2, 1};
	for(int i = 0; i < L.length; i++) {
		ck_assert_int_eq(L.elem[i], expected[i]);
	}
}
END_TEST

START_TEST(wangdao_sqList_Test_3) {
	SqList L;
	InitList(&L);
	int elements[] = {1, 2, 3, 4, 5, 3, 2, 1};
	for(int i = 0; i < 8; i++) {
		ListInsert_Sq(&L, i + 1, elements[i]);
	}
	Wangdao_SqList_3(&L, 3);
	int expected[] = {1, 2, 4, 5, 2, 1};
	for(int i = 0; i < L.length; i++) {
		ck_assert_int_eq(L.elem[i], expected[i]);
	}
}
END_TEST

START_TEST(wangdao_sqList_Test_4) {
	SqList L;
	InitList(&L);
	int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i = 0; i < 9; i++) {
		ListInsert_Sq(&L, i + 1, elements[i]);
	}
	Wangdao_SqList_4(&L, 3, 7);
	int expected[] = {1, 2, 8, 9};
	for(int i = 0; i < L.length; i++) {
		ck_assert_int_eq(L.elem[i], expected[i]);
	}
}
END_TEST

void add_wangdao_tests(TCase *tc) {
	tcase_add_test(tc, wangdao_sqList_Test_1);
	tcase_add_test(tc, wangdao_sqList_Test_2);
	tcase_add_test(tc, wangdao_sqList_Test_3);
	tcase_add_test(tc, wangdao_sqList_Test_4);
}

Suite *add_suite_sqlist(void) {
	Suite *s;
	TCase *tc_core;

	s       = suite_create("TestSuite_SqList");// 创建测试套件
	tc_core = tcase_create("Core");            // 创建核心测试用例组

	// 添加测试用例到测试组
	add_init_tests(tc_core);
	add_list_insert_tests(tc_core);
	add_list_delete_tests(tc_core);
	add_locate_elem_tests(tc_core);
	add_merge_list_tests(tc_core);
	add_list_management_tests(tc_core);
	add_get_elem_tests(tc_core);
	add_prior_next_elem_tests(tc_core);
	add_list_traverse_tests(tc_core);
	add_combination_tests(tc_core);

	add_wangdao_tests(tc_core);

	suite_add_tcase(s, tc_core);// 将测试用例组加入到套件

	return s;
}