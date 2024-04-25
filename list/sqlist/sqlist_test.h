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

void add_wangdao_tests(TCase *tc);

Suite *add_suite_sqlist(void);


#endif//DATASTRUCTURE408_SQLIST_TEST_H
