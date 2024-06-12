#include "./s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return 1;
  int status = 0;
  if (A->rows == B->rows && A->columns == B->columns) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int_fast32_t i = 0; i < A->rows; i++)
      for (int_fast32_t j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  } else
    status = 2;
  return status;
}
