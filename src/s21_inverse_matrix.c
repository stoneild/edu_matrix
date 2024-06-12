#include "./s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) return 1;
  if (A->rows != A->columns) return 2;
  double determinant;
  s21_determinant(A, &determinant);
  if (determinant) {
    matrix_t tmp;
    s21_calc_complements(A, result);
    s21_transpose(result, &tmp);
    s21_remove_matrix(result);
    s21_mult_number(&tmp, 1 / determinant, result);
    s21_remove_matrix(&tmp);
  }
  return determinant ? 0 : 2;
}
