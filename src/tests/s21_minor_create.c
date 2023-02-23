#include "../header.h"

START_TEST(minor_matrix_1) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  int number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, number++)
      A.matrix[i][j] = number;
  }
  int current_cell[2] = {1, 3};
  matrix_t Amin;
  s21_create_matrix(rows - 1, columns - 1, &Amin);
  copy_minor(&Amin, &A, current_cell[0], current_cell[1]);

  matrix_t B;
  s21_create_matrix(rows - 1, columns - 1, &B);
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 2;
  B.matrix[0][3] = 4;

  B.matrix[1][0] = 10;
  B.matrix[1][1] = 11;
  B.matrix[1][2] = 12;
  B.matrix[1][3] = 14;

  B.matrix[2][0] = 15;
  B.matrix[2][1] = 16;
  B.matrix[2][2] = 17;
  B.matrix[2][3] = 19;

  B.matrix[3][0] = 20;
  B.matrix[3][1] = 21;
  B.matrix[3][2] = 22;
  B.matrix[3][3] = 24;

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      ck_assert_int_eq(B.matrix[i][j], Amin.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&Amin);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(minor_matrix_2) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  int number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, number++)
      A.matrix[i][j] = number;
  }
  int current_cell[2] = {0, 0};
  matrix_t Amin;
  s21_create_matrix(rows - 1, columns - 1, &Amin);
  copy_minor(&Amin, &A, current_cell[0], current_cell[1]);

  matrix_t B;
  s21_create_matrix(rows - 1, columns - 1, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 7;
  B.matrix[0][2] = 8;
  B.matrix[0][3] = 9;

  B.matrix[1][0] = 11;
  B.matrix[1][1] = 12;
  B.matrix[1][2] = 13;
  B.matrix[1][3] = 14;

  B.matrix[2][0] = 16;
  B.matrix[2][1] = 17;
  B.matrix[2][2] = 18;
  B.matrix[2][3] = 19;

  B.matrix[3][0] = 21;
  B.matrix[3][1] = 22;
  B.matrix[3][2] = 23;
  B.matrix[3][3] = 24;

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      ck_assert_int_eq(B.matrix[i][j], Amin.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&Amin);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(minor_matrix_3) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  int number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, number++)
      A.matrix[i][j] = number;
  }
  int current_cell[2] = {0, 1};
  matrix_t Amin;
  s21_create_matrix(rows - 1, columns - 1, &Amin);
  copy_minor(&Amin, &A, current_cell[0], current_cell[1]);

  matrix_t B;
  s21_create_matrix(rows - 1, columns - 1, &B);
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 7;
  B.matrix[0][2] = 8;
  B.matrix[0][3] = 9;

  B.matrix[1][0] = 10;
  B.matrix[1][1] = 12;
  B.matrix[1][2] = 13;
  B.matrix[1][3] = 14;

  B.matrix[2][0] = 15;
  B.matrix[2][1] = 17;
  B.matrix[2][2] = 18;
  B.matrix[2][3] = 19;

  B.matrix[3][0] = 20;
  B.matrix[3][1] = 22;
  B.matrix[3][2] = 23;
  B.matrix[3][3] = 24;

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      ck_assert_int_eq(B.matrix[i][j], Amin.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&Amin);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(minor_matrix_4) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  int number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, number++)
      A.matrix[i][j] = number;
  }
  int current_cell[2] = {2, 2};
  matrix_t Amin;
  s21_create_matrix(rows - 1, columns - 1, &Amin);
  copy_minor(&Amin, &A, current_cell[0], current_cell[1]);

  matrix_t B;
  s21_create_matrix(rows - 1, columns - 1, &B);
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 4;

  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  B.matrix[1][2] = 8;
  B.matrix[1][3] = 9;

  B.matrix[2][0] = 15;
  B.matrix[2][1] = 16;
  B.matrix[2][2] = 18;
  B.matrix[2][3] = 19;

  B.matrix[3][0] = 20;
  B.matrix[3][1] = 21;
  B.matrix[3][2] = 23;
  B.matrix[3][3] = 24;

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      ck_assert_int_eq(B.matrix[i][j], Amin.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&Amin);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(minor_matrix_5) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  int number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, number++)
      A.matrix[i][j] = number;
  }
  int current_cell[2] = {4, 4};
  matrix_t Amin;
  s21_create_matrix(rows - 1, columns - 1, &Amin);
  copy_minor(&Amin, &A, current_cell[0], current_cell[1]);

  matrix_t B;
  s21_create_matrix(rows - 1, columns - 1, &B);
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 2;
  B.matrix[0][3] = 3;

  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  B.matrix[1][2] = 7;
  B.matrix[1][3] = 8;

  B.matrix[2][0] = 10;
  B.matrix[2][1] = 11;
  B.matrix[2][2] = 12;
  B.matrix[2][3] = 13;

  B.matrix[3][0] = 15;
  B.matrix[3][1] = 16;
  B.matrix[3][2] = 17;
  B.matrix[3][3] = 18;

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      ck_assert_int_eq(B.matrix[i][j], Amin.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&Amin);
  s21_remove_matrix(&B);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_minor_matrix;

  s = suite_create("s21_minor_matrix");

  tc_minor_matrix = tcase_create("s21_minor_matrix");
  tcase_add_test(tc_minor_matrix, minor_matrix_1);
  tcase_add_test(tc_minor_matrix, minor_matrix_2);
  tcase_add_test(tc_minor_matrix, minor_matrix_3);
  tcase_add_test(tc_minor_matrix, minor_matrix_4);
  tcase_add_test(tc_minor_matrix, minor_matrix_5);
  suite_add_tcase(s, tc_minor_matrix);

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
