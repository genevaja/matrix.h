#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define EQ_SUCCESS 1
#define EQ_FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Create matrix
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Remove_matrix
void s21_remove_matrix(matrix_t *A);

// Compare matrix
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Summ and subtraction matrix
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Mult matrix
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Transpose matrix
int s21_transpose(matrix_t *A, matrix_t *result);

// Minor matrix and calc_complements
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Matrix determinant
int s21_determinant(matrix_t *A, double *result);

// Inverse matrix
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Создание матрицы
double **mem_alloc(int rows, int columns);

// Проверка на корректное выделение памяти
int check_memory(int rows, double **matrix);

// Проверка на корректность матрицы
int check_matrix(matrix_t *A);

// Сравнение строк и столбцов у матриц. Если они равны,
// функция возвращает 0
int row_col_comp(matrix_t *A, matrix_t *B);

// Вывод содержимого матрицы
void print_matrix(matrix_t *A);

void copy_minor(matrix_t *Amin, matrix_t *A, int i, int j);
