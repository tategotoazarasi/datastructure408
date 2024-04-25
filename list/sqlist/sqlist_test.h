//
// Created by tategotoazarasi on 24-4-25.
//

#ifndef DATASTRUCTURE408_SQLIST_TEST_H
#define DATASTRUCTURE408_SQLIST_TEST_H

#include "sqlist.h"
#include <check.h>
#include <stdlib.h>

// 前置声明各测试用例函数
void add_init_tests(TCase *tc);
void add_list_insert_tests(TCase *tc);
void add_list_delete_tests(TCase *tc);
void add_locate_elem_tests(TCase *tc);
void add_merge_list_tests(TCase *tc);
void add_list_management_tests(TCase *tc);
void add_get_elem_tests(TCase *tc);
void add_prior_next_elem_tests(TCase *tc);
void add_list_traverse_tests(TCase *tc);
void add_combination_tests(TCase *tc);

Suite *add_suite(void) {
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
	suite_add_tcase(s, tc_core);// 将测试用例组加入到套件

	return s;
}


#endif//DATASTRUCTURE408_SQLIST_TEST_H
