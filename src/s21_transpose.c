#include "./s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int exit_code = SUCCESS;
  if (check_matrix(A))
    exit_code = INCORRECT_MATRIX;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return exit_code;
}
