#include "./s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return FAILURE;
  int is_equal = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int_fast32_t i = 0, r = A->rows, c = A->columns; i < r; ++i)
      for (int_fast32_t j = 0; j < c; ++j)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
          is_equal = FAILURE, r = 0, c = 0;
  } else
    is_equal = FAILURE;
  return is_equal;
}
