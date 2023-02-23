#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = SUCCESS;
  if (check_matrix(A)) {
    res_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        matrix_t Amin;
        s21_create_matrix(result->rows - 1, result->columns - 1, &Amin);
        copy_minor(&Amin, A, i, j);
        s21_determinant(&Amin, &result->matrix[i][j]);
        if ((i + j) % 2) result->matrix[i][j] *= -1;
        s21_remove_matrix(&Amin);
      }
    }
  }
  return res_code;
}
