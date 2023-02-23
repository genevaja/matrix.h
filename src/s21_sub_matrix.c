#include "./s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = SUCCESS;
  if (check_matrix(A) || check_matrix(B))
    exit_code = INCORRECT_MATRIX;
  else if (row_col_comp(A, B))
    exit_code = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return exit_code;
}
