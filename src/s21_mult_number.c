#include "./s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_is_correct(A)) return 1;
  int status = 0;
  s21_create_matrix(A->rows, A->columns, result);
  for (int_fast32_t i = 0; i < A->rows; i++)
    for (int_fast32_t j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;
  return status;
}
