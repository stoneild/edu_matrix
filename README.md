# edu_matrix
## Overview
edu_matrix is a project created for educational purpose.

This project implements some matrix operations in the static library s21_matrix.a to work with matrices of the following struct:
```
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Dependencies
To build and run this project, you will need the following dependencies:
- gcc (to compile object files);
- ar from binutils (to create a static library);
- ranlib from binutils (to generate an index to an archive);
- make (to building the project from the Makefile);
- checkmk from package check (to generating C unit tests);
- lcov (for the coverage report);

## Makefile Targets
The Makefile defines the following goals:
- **all**, **s21_matrix.a**: Builds the s21_matrix.a library from the source files.
- **test**: Rebuilds the project, compiles the test executable, and runs the tests.
- **gcov_report**: Runs tests with code coverage and generates an HTML report for coverage visualization.
- **clean**: Removes object files, coverage data, and intermediate files.
- **rebuild**: Cleans the project and rebuilds it from scratch.
- **remove**: Deletes the library and all intermediate files, cleaning the project.

Use the following command to execute the targets in the src directory:
```make [goal]```

## The following matrix operations have been implemented
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

##License
This project is licensed under the GNU General Public License, as specified in the LICENSE.txt file. Please refer to the LICENSE.txt for further details.
