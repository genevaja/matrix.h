#include "../header.h"

START_TEST(inverse_matrix_1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  matrix_t etalon;
  s21_create_matrix(3, 3, &etalon);
  etalon.matrix[0][0] = 1.0;
  etalon.matrix[0][1] = -1.0;
  etalon.matrix[0][2] = 1.0;
  etalon.matrix[1][0] = -38.0;
  etalon.matrix[1][1] = 41.0;
  etalon.matrix[1][2] = -34.0;
  etalon.matrix[2][0] = 27.0;
  etalon.matrix[2][1] = -29.0;
  etalon.matrix[2][2] = 24.0;

  matrix_t B;

  ck_assert_int_eq(s21_inverse_matrix(&A, &B), SUCCESS);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(etalon.matrix[i][j], B.matrix[i][j], 0.000001);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&etalon);

}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  matrix_t B;

  ck_assert_int_eq(s21_inverse_matrix(&A, &B), SUCCESS);

  matrix_t E;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &E), SUCCESS);

  for (int i = 0; i < E.rows; i++) {
      ck_assert_double_eq(E.matrix[i][i], 1.0);
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&E);

}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  A.matrix[2][3] = -3.0;
  A.matrix[3][0] = 5.0;
  A.matrix[3][1] = -1.0;
  A.matrix[3][2] = -3.0;
  A.matrix[3][3] = -1.0;

  matrix_t B;

  ck_assert_int_eq(s21_inverse_matrix(&A, &B), SUCCESS);

  matrix_t E;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &E), SUCCESS);

  for (int i = 0; i < E.rows; i++) {
      ck_assert_double_eq(E.matrix[i][i], 1.0);
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&E);

}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 2.192;
  A.matrix[0][1] = 5.42;
  A.matrix[0][2] = 7.12;
  A.matrix[0][3] = 7.01;
  A.matrix[1][0] = 6.01;
  A.matrix[1][1] = 3.111;
  A.matrix[1][2] = 4.084;
  A.matrix[1][3] = 4.432;
  A.matrix[2][0] = 5.11;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  A.matrix[2][3] = -3.0;
  A.matrix[3][0] = 5.102;
  A.matrix[3][1] = -1.8;
  A.matrix[3][2] = -3.94;
  A.matrix[3][3] = -1.0001;

  matrix_t B;

  ck_assert_int_eq(s21_inverse_matrix(&A, &B), SUCCESS);

  matrix_t E;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &E), SUCCESS);


  for (int i = 0; i < E.rows; i++) {
    for (int j = 0; j < E.columns; j++) {
      if (j == i)
        ck_assert_double_eq_tol(E.matrix[i][j], 1.0, 0.00000000001);
      else
        ck_assert_double_eq_tol(E.matrix[i][j], 0.0, 0.00000000001);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&E);

}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A;
  s21_create_matrix(10, 4, &A);
  matrix_t B;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), CALCULATION_ERROR);
  s21_remove_matrix(&A);

}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t *A = NULL;
  matrix_t B;
  ck_assert_int_eq(s21_inverse_matrix(A, &B), INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 1.0;
  A.matrix[0][2] = 1.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 1.0;
  A.matrix[2][1] = 1.0;
  A.matrix[2][2] = 1.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST


Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_inverse_matrix;

  s = suite_create("inverse_matrix");

  tc_inverse_matrix = tcase_create("inverse_matrix");
  tcase_add_test(tc_inverse_matrix, inverse_matrix_1);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_2);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_3);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_4);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_5);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_6);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_7);
  suite_add_tcase(s, tc_inverse_matrix);

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
