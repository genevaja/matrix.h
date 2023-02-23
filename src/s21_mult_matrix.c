#include "./s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = SUCCESS;
  if (check_matrix(A) || check_matrix(B))
    exit_code = INCORRECT_MATRIX;
  else if (A->columns != B->rows)
    exit_code = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return exit_code;
}
