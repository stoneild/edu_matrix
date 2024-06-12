#include "./s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    result->matrix = NULL;
    return 1;
  }
  int status = 0;
  result->rows = rows;
  result->columns = columns;
  result->matrix =
      malloc(sizeof(double *) * rows + rows * columns * sizeof(double));
  if (result->matrix)
    for (int_fast32_t i = 0; i < rows; ++i)
      result->matrix[i] = (double *)(result->matrix + rows) + columns * i;
  else
    status = 2;  // Very big matrix is 1 or 2 status?
  return status;
}
