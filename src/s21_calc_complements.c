#include "./s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) return 1;
  if (A->rows != A->columns) return 2;
  matrix_t minor;
  minor.rows = A->rows - 1;
  s21_create_matrix(minor.rows, minor.rows, &minor);
  s21_create_matrix(A->rows, A->rows, result);
  for (int_fast32_t i = 0; i < A->rows; ++i)
    for (int_fast32_t j = 0; j < A->rows; ++j) {
      result->matrix[i][j] = pow(-1, i + j) * s21_get_minor(A, i, j, &minor);
    }
  s21_remove_matrix(&minor);
  return 0;
}
