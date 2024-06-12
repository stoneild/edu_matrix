#include "./s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_correct(A)) return 1;
  if (A->rows != A->columns) return 2;
  matrix_t tmp;
  s21_create_matrix(A->rows, A->rows, &tmp);
  s21_copy_matrix(A, &tmp);
  *result = s21_calc_determinant(&tmp);
  s21_remove_matrix(&tmp);
  return 0;
}

double s21_calc_determinant(matrix_t *A) {
  int_fast32_t sh;
  double result = 1;
  for (sh = 0; sh < A->rows && fabs(A->matrix[sh][0]) < EPS; ++sh)
    ;
  for (int_fast32_t j_base = 0; result && j_base < A->rows; ++j_base) {
    if (A->matrix[(j_base + sh) % A->rows][j_base]) {
      result *= A->matrix[(j_base + sh) % A->rows][j_base];
      for (int_fast32_t i_base = j_base + 1; result && i_base < A->rows;
           ++i_base) {
        double k = A->matrix[(i_base + sh) % A->rows][j_base] /
                   A->matrix[(j_base + sh) % A->rows][j_base];
        A->matrix[(i_base + sh) % A->rows][j_base] = 0;
        for (int_fast32_t j = j_base + 1; j < A->rows; ++j)
          A->matrix[(i_base + sh) % A->rows][j] -=
              A->matrix[(j_base + sh) % A->rows][j] * k;
      }
    } else if (j_base + 1 < A->rows) {
      matrix_t sub_matrix;
      s21_create_matrix(A->rows - j_base, A->rows - j_base, &sub_matrix);
      for (int_fast32_t n = j_base; n < A->rows; ++n) {
        for (int_fast32_t m = j_base; m < A->rows; ++m)
          sub_matrix.matrix[n - j_base][m - j_base] =
              A->matrix[(n + sh) % A->rows][m];
      }
      result *= s21_calc_determinant(&sub_matrix);
      s21_remove_matrix(&sub_matrix);
      j_base = A->rows;
    } else
      result = 0;
  }
  return (sh % 2 && !(A->rows % 2)) ? result * -1 : result;
}
