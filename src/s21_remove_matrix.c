#include "./s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!check_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) free(A->matrix[i]);
    }
    free(A->matrix);
  }
}
