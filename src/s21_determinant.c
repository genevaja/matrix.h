#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int exit_code = SUCCESS;
  if (check_matrix(A)) {
    exit_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    exit_code = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0, j = 0, sign = 1; j < A->columns; j++, sign *= -1) {
      matrix_t Amin;
      s21_create_matrix(A->rows - 1, A->columns - 1, &Amin);
      copy_minor(&Amin, A, i, j);
      double det_temp = 0;
      s21_determinant(&Amin, &det_temp);
      *result += sign * A->matrix[i][j] * det_temp;
      s21_remove_matrix(&Amin);
    }
  }
  return exit_code;
}
