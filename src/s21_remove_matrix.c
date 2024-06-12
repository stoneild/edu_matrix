#include "./s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!A->matrix) return;
  free(A->matrix);
  A->matrix = NULL;
  return;
}
