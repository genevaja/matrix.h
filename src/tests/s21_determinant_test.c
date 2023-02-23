#include "../header.h"

START_TEST(determinant_1) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  int rows = 6, columns = 6;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
}
END_TEST

// Проблема с этим тестом
START_TEST(determinant_3) {
  matrix_t A;
  int rows = 10, columns = 7;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A;
  A.matrix = NULL;
  A.rows = -7;
  A.columns = -7;
  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t *A = NULL;
  double result;
  int status = s21_determinant(A, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 2, &A);
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t A;
  double result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, 2.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_10) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[1][0] = 2.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_11) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, -2.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_12) {
  matrix_t A;
  double result = 0.0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_13) {
  matrix_t A;
  double result = 0.0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, -8.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_14) {
  matrix_t A;
  double result = 0.0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[0][2] = 5.0;
  A.matrix[0][3] = 11.0;
  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 9.0;
  A.matrix[1][3] = 8.0;
  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 5.0;
  A.matrix[2][3] = 4.0;
  A.matrix[3][0] = 3.0;
  A.matrix[3][1] = 2.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 0.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, 593.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_15) {
  matrix_t A;
  double result = 0.0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = -3.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -7.0;
  A.matrix[1][2] = 11.0;
  A.matrix[1][3] = 5.0;
  A.matrix[2][0] = -9.0;
  A.matrix[2][1] = 4.0;
  A.matrix[2][2] = 25.0;
  A.matrix[2][3] = 84.0;
  A.matrix[3][0] = 3.0;
  A.matrix[3][1] = 12.0;
  A.matrix[3][2] = -5.0;
  A.matrix[3][3] = 58.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq(result, 36086.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_16) {
  matrix_t A;
  double result = 0.0;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = -3.0;
  A.matrix[0][3] = 9.0;
  A.matrix[0][4] = 9.123;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -7.0;
  A.matrix[1][2] = 11.0;
  A.matrix[1][3] = 5.0;
  A.matrix[1][4] = 5.4;
  A.matrix[2][0] = -9.0;
  A.matrix[2][1] = 4.0;
  A.matrix[2][2] = 25.0;
  A.matrix[2][3] = 8.0;
  A.matrix[2][4] = 4.33;
  A.matrix[3][0] = 3.0;
  A.matrix[3][1] = 12.0;
  A.matrix[3][2] = -5.0;
  A.matrix[3][3] = 1.23;
  A.matrix[3][4] = 8.93;
  A.matrix[4][0] = 31.0;
  A.matrix[4][1] = 2.0;
  A.matrix[4][2] = 5.0;
  A.matrix[4][3] = -2.001;
  A.matrix[4][4] = 1.93;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, SUCCESS);
  ck_assert_double_eq_tol(result, -637197.54237, 0.000001);
  s21_remove_matrix(&A);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_determinant;

  s = suite_create("determinant");

  tc_determinant = tcase_create("determinant");
  tcase_add_test(tc_determinant, determinant_1);
  tcase_add_test(tc_determinant, determinant_2);
  tcase_add_test(tc_determinant, determinant_3);
  tcase_add_test(tc_determinant, determinant_4);
  tcase_add_test(tc_determinant, determinant_5);
  tcase_add_test(tc_determinant, determinant_8);
  tcase_add_test(tc_determinant, determinant_9);
  tcase_add_test(tc_determinant, determinant_10);
  tcase_add_test(tc_determinant, determinant_11);
  tcase_add_test(tc_determinant, determinant_12);
  tcase_add_test(tc_determinant, determinant_13);
  tcase_add_test(tc_determinant, determinant_14);
  tcase_add_test(tc_determinant, determinant_15);
  tcase_add_test(tc_determinant, determinant_16);
  suite_add_tcase(s, tc_determinant);

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
