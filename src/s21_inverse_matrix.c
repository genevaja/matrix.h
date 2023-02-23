#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = SUCCESS;
  if (!check_matrix(A)) {
    if (A->rows == A->columns) {
      double determ = 0.0;
      s21_determinant(A, &determ);
      if (fabs(determ - 0.0) > 1e-6) {
        matrix_t Amin;
        matrix_t transp_Amin;
        s21_calc_complements(A, &Amin);
        s21_transpose(&Amin, &transp_Amin);
        s21_mult_number(&transp_Amin, 1.0 / determ, result);
        s21_remove_matrix(&Amin);
        s21_remove_matrix(&transp_Amin);
      } else {
        res_code = CALCULATION_ERROR;
      }
    } else {
      res_code = CALCULATION_ERROR;
    }
  } else {
    res_code = INCORRECT_MATRIX;
  }
  return res_code;
}
