#include "./s21_matrix.h"

int s21_is_correct(matrix_t *A) {
  return A && A->matrix && A->rows > 0 && A->columns > 0;
}

int s21_copy_matrix(matrix_t *A, matrix_t *result) {
  for (int_fast32_t i = 0; i < A->rows; ++i)
    for (int_fast32_t j = 0; j < A->rows; ++j)
      result->matrix[i][j] = A->matrix[i][j];
  return 0;
}

double s21_get_minor(matrix_t *matrix, int im, int jm, matrix_t *minor) {
  double result = 1;
  if (matrix->rows) {
    for (int_fast32_t i = 0; i < minor->rows; ++i)
      for (int_fast32_t j = 0; j < minor->rows; ++j)
        minor->matrix[i][j] =
            matrix->matrix[i < im ? i : i + 1][j < jm ? j : j + 1];
    s21_determinant(minor, &result);
  }
  return result;
}
