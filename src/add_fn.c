#include "./s21_matrix.h"

// Дополнительная функция для проверки выделенной памяти.
// Осуществляется после проверки check_matrix
int check_memory(int rows, double **A) {
  int exit_code = FAILURE;
  if (A != NULL) {
    for (int i = 0; i < rows; i++) {
      if (A[i] != NULL)
        exit_code = SUCCESS;
      else {
        exit_code = FAILURE;
        break;
      }
    }
  }
  return exit_code;
}

// Основая функция проверки матриц
int check_matrix(matrix_t *A) {
  return ((A == NULL || A->rows <= 0 || A->columns <= 0 ||
           check_memory(A->rows, A->matrix)))
             ? FAILURE
             : SUCCESS;
}

int row_col_comp(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}

double **mem_alloc(int rows, int columns) {
  double **matrix = NULL;
  matrix = (double **)malloc(rows * sizeof(double *));
  if (matrix) {
    for (int i = 0; i < rows; i++) {
      matrix[i] = (double *)malloc(columns * sizeof(double));
      if (matrix[i]) {
        for (int j = 0; j < columns; j++) matrix[i][j] = 0.0;
      } else {
        matrix[i] = NULL;
      }
    }
  }
  return (matrix) ? matrix : NULL;
}

// void print_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     for (int j = 0; j < A->columns; j++) {
//       printf("%20.15f", A->matrix[i][j]);
//     }
//     putchar('\n');
//   }
// }

void copy_minor(matrix_t *Amin, matrix_t *A, int row, int col) {
  for (int i = 0, imin = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0, jmin = 0; j < A->columns; j++) {
      if (j == col) continue;
      Amin->matrix[imin][jmin] = A->matrix[i][j];
      jmin++;
    }
    imin++;
  }
}
