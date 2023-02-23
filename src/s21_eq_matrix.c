#include "./s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int exit_code = EQ_SUCCESS;
  if (check_matrix(A) || check_matrix(B) || row_col_comp(A, B))
    exit_code = EQ_FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-8) {
          exit_code = EQ_FAILURE;
          break;
        }
      }
    }
  }
  return exit_code;
}
