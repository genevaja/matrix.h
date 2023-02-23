#include "../header.h"

START_TEST(calc_complements_1) {
  matrix_t A, result;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A, result;
  int rows = 6, columns = 6;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A, result;
  int rows = 10, columns = 7;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A, result;
  A.matrix = NULL;
  A.rows = -15;
  A.columns = -15;
  result.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t A, result;
  A.matrix = NULL;
  A.rows = 0;
  A.columns = 0;
  result.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_6) {
  matrix_t A, result;
  s21_create_matrix(10, 5, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_7) {
  matrix_t A, result, etalon;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &etalon);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;

  etalon.matrix[0][0] = 0;
  etalon.matrix[0][1] = 10.0;
  etalon.matrix[0][2] = -20.0;
  etalon.matrix[1][0] = 4.0;
  etalon.matrix[1][1] = -14.0;
  etalon.matrix[1][2] = 8.0;
  etalon.matrix[2][0] = -8.0; 
  etalon.matrix[2][1] = -2.0; 
  etalon.matrix[2][2] = 4.0;
  
  ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon.matrix[i][j], 0.000001);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_calc_complements;

  s = suite_create("calc_complements");

  tc_calc_complements = tcase_create("calc_complements");
  tcase_add_test(tc_calc_complements, calc_complements_1);
  tcase_add_test(tc_calc_complements, calc_complements_2);
  tcase_add_test(tc_calc_complements, calc_complements_3);
  tcase_add_test(tc_calc_complements, calc_complements_4);
  tcase_add_test(tc_calc_complements, calc_complements_5);
  tcase_add_test(tc_calc_complements, calc_complements_6);
  tcase_add_test(tc_calc_complements, calc_complements_7);
  suite_add_tcase(s, tc_calc_complements);

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
