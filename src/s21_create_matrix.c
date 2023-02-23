#include "./s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *A) {
  int check_res;
  if (rows > 0 && columns > 0) {
    A->matrix = mem_alloc(rows, columns);
    A->rows = rows;
    A->columns = columns;
    check_res = check_memory(rows, A->matrix);
  } else {
    check_res = INCORRECT_MATRIX;
  }
  return check_res;
}
