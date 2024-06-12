#include "./s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return 1;
  int status = 0;
  if (A->columns == B->rows) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int_fast32_t i = 0; i < A->rows; ++i)
      for (int_fast32_t j = 0; j < B->columns; ++j) {
        int_fast32_t k = 0;
        for (result->matrix[i][j] = 0; k < A->columns; ++k)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
  } else
    status = 2;
  return status;
}
