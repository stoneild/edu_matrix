# edu_matrix
## This is education project

In this project realised some matrix operations for working with follow matrices:
```
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```
## Realised follow matrix operations
- Creating matrices (create_matrix)
```
int s21_create_matrix(int rows, int columns, matrix_t *result);
```
- Cleaning of matrices (remove_matrix)
```
void s21_remove_matrix(matrix_t *A);
```
- Matrix comparison (eq_matrix)
```
int s21_eq_matrix(matrix_t *A, matrix_t *B);
```
- Adding (sum_matrix) and subtracting matrices (sub_matrix)
```
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
- Matrix multiplication by scalar (mult_number). Multiplication of two matrices (mult_matrix)
```
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
- Matrix transpose (transpose)
```
int s21_transpose(matrix_t *A, matrix_t *result);
```
- Matrix determinant
```
int s21_determinant(matrix_t *A, double *result);
```
- Inverse of the matrix (inverse_matrix)
```
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```
