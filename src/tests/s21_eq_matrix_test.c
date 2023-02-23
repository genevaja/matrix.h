#include "../header.h"

START_TEST(eq_test_1) {
  matrix_t A, B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_2) {
  matrix_t A, B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_3) {
  matrix_t A, B;
  s21_create_matrix(10, 5, &A);
  s21_create_matrix(10, 5, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_4) {
  matrix_t A, B;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 50; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_5) {
  matrix_t A, B;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 50; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_6) {
  matrix_t A, B;
  s21_create_matrix(100, 500, &A);
  s21_create_matrix(100, 500, &B);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 500; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_7) {
  matrix_t A, B;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_8) {
  matrix_t A, B;
  s21_create_matrix(1, 2, &A);
  B.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A), s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_9) {
  matrix_t A, B;
  s21_create_matrix(1, 2, &A);
  B.matrix = NULL;
  B.rows = 0;
  B.columns = 5;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_test_10) {
  matrix_t A, B;
  A.matrix = NULL;
  A.rows = 0;
  A.columns = 0;
  B.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}
END_TEST

START_TEST(eq_test_11) {
  matrix_t A, B;
  int A_rows = 3, A_columns = 4, B_rows = 2, B_columns = 4;
  s21_create_matrix(A_rows, A_columns, &A);
  s21_create_matrix(B_rows, B_columns, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_12) {
  matrix_t A, B;
  A.rows = -3;
  A.columns = -3;
  B.rows = -3;
  B.columns = -3;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_eq_test;

  s = suite_create("equality tests");

  tc_eq_test = tcase_create("equality tests");
  tcase_add_test(tc_eq_test, eq_test_1);
  tcase_add_test(tc_eq_test, eq_test_2);
  tcase_add_test(tc_eq_test, eq_test_3);
  tcase_add_test(tc_eq_test, eq_test_4);
  tcase_add_test(tc_eq_test, eq_test_5);
  tcase_add_test(tc_eq_test, eq_test_6);
  tcase_add_test(tc_eq_test, eq_test_7);
  tcase_add_test(tc_eq_test, eq_test_8);
  tcase_add_test(tc_eq_test, eq_test_9);
  tcase_add_test(tc_eq_test, eq_test_10);
  tcase_add_test(tc_eq_test, eq_test_11);
  tcase_add_test(tc_eq_test, eq_test_12);
  suite_add_tcase(s, tc_eq_test);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
