# edu_matrix
## Обзор
edu_matrix — это проект, созданный в образовательных целях.

Проект реализует несколько операций с матрицами в статической библиотеке s21_matrix.a на языке программирования Си для работы с матрицами, определёнными следующей структурой:
```
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Зависимости
Для сборки и запуска проекта потребуются следующие зависимости:
- gcc (для компиляции объектных файлов);
- ar из пакета binutils (для создания статической библиотеки);
- ranlib из пакета binutils (для генерации индекса архива);
- make (для сборки проекта из Makefile);
- checkmk из пакета check (для генерации C unit-тестов);
- lcov (для отчёта по покрытию).

## Цели Makefile
Makefile определяет следующие цели:
- **all**, **s21_matrix.a**: сборка библиотеки s21_matrix.a из исходных файлов;
- **test**: пересборка проекта, компиляция тестового исполнимого файла и запуск тестов;
- **gcov_report**: запуск тестов с покрытием и генерация HTML-отчёта для визуализации покрытия;
- **clean**: удаление объектных файлов, данных покрытия и промежуточных файлов;
- **rebuild**: очистка проекта и пересборка с нуля;
- **remove**: удаление библиотеки и всех промежуточных файлов, очистка проекта.

Для выполнения целей в каталоге src используйте команду:

```
make [goal]
```

## Реализованные операции с матрицами
- Создание матриц (create_matrix):
```
int s21_create_matrix(int rows, int columns, matrix_t *result);
```
- Очистка матриц (remove_matrix):
```
void s21_remove_matrix(matrix_t *A);
```
- Сравнение матриц (eq_matrix):
```
int s21_eq_matrix(matrix_t *A, matrix_t *B);
```
- Сложение (sum_matrix) и вычитание матриц (sub_matrix):
```
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
- Умножение матрицы на скаляр (mult_number), умножение двух матриц (mult_matrix):
```
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
- Транспонирование матрицы (transpose):
```
int s21_transpose(matrix_t *A, matrix_t *result);
```
- Вычисление определителя матрицы:
```
int s21_determinant(matrix_t *A, double *result);
```
- Вычисление обратной матрицы (inverse_matrix):
```
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

## Лицензия
Этот проект распространяется по лицензии GNU General Public License, как указано в файле [LICENSE.txt](./LICENSE.txt). Для подробной информации, пожалуйста, ознакомьтесь с файлом [LICENSE.txt](./LICENSE.txt).
