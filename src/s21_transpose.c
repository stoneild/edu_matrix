#include "./s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) return 1;
  s21_create_matrix(A->columns, A->rows, result);
  for (int_fast32_t i = 0; i < A->rows; ++i)
    for (int_fast32_t j = 0; j < A->columns; ++j)
      result->matrix[j][i] = A->matrix[i][j];
  return 0;
}
