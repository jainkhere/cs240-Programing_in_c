/**
 * @file pointer-operations_arrays.c
 * @author kunal jain (kunal.jain001@umb.edu)
 * @brief This programs shows how to represent array using
 *        pointers
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

void test_illegal_pointer_assignment() {
    int* p;
    // Without initializing pointer with a null value,
    // below assignment - *p = 100, could be dangerous 
    // as we are trying access and alter the value present
    // at an address that we know nothing about.
    
    // A pointer should always be set to null before we assign
    // value to that pointer.
    // That prevents any dangerous alterations we might perform
    // on the memory space.
    // p = NULL;


    printf("Address of p -> %d\n", &p);
    printf("Value of p -> %d\n", p);
    printf("Value at p -> %d\n", *p);

    printf("Before assignment\n");

    // On some compilers your code may crash here if you
    // don't assign a NULL value to pointer.
    *p = 5;
    
    printf("After assignment\n");

    printf("Address of p -> %d\n", &p);
    printf("Value of p -> %d\n", p);
    printf("Value at p -> %d\n", *p);
}

// print 2D array using the array variable.
void printArray2D(char arr[][3], int rows, int columns) {
    int i, j;
    // Nested loop to print all values of 2D array.
    // Use first loop to iterate over rows
    // Use second loop to iterate over columns
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void printArray2DUsingPointer(char* arr, int rows, int columns) {
    // arr = {
    //     { '1', '2', '3' },
    //     { 'a', 'b', 'c' }
    // }
    //
    // arr[i][j] = We have to find this to print array
    // arr[0][0] = arr + 0
    // arr[0][1] = arr + 1
    // arr[0][j] = arr + j
    // arr[1][j] = arr + j + (1 * (no of elements in a row))
    // arr[i][j] = arr + j + (i * columns)
    //
    // We will use above expression to print the 2D array
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c ", *(arr + j + (i * columns)));
        }
        printf("\n");
    }
}

// print 3D array using the array variable.
void printArray3D(char arr[][2][3], int table, int rows, int columns) {
    int i, j, k;
    // Nested loop to print all values of 3D array.
    // Use first loop to iterate over table
    // Use second loop to iterate over rows
    // Use third loop to iterate over columns
    for (i = 0; i < table; i++) {
        for (j = 0; j < rows; j++) {
            for (k = 0; k < columns; k++) {
                printf("%c ", arr[i][j][k]);
            }
        }
        printf("\n");
    }
}

void printArray3DUsingPointer(char* arr, int table, int rows, int columns) {
    // arr = {
    //     {{ '1', '2', '3' }, { 'a', 'b', 'c' }}
    //     {{ '4', '5', '6' }, { ' x', 'y', 'z'}}
    // }
    //
    // arr[i][j][k] = We have to find this to print array
    // arr[0][0][0] = arr + 0
    // arr[0][0][1] = arr + 1
    // arr[0][0][k] = arr + k
    // arr[0][1][k] = arr + k + (1 * (no of elements in a row))
    // arr[0][j][k] = arr + k + (j * columns)
    // arr[1][j][k] = arr + k + (j * columns) + (1 * (no of elements in a table))
    // arr[i][j][k] = arr + k + (j * columns) + (i * (rows * columns))
    //
    // We will use above expression to print the 2D array
    int i, j, k;
    for (i = 0; i < table; i++) {
        for (j = 0; j < rows; j++) {
            for (k = 0; k < columns; k++) {
                printf("%c ", *(arr + k + (j * columns) + (i * (rows*columns))));
            }
        }
        printf("\n");
    }
}

// Function to print N dimensional array
// char* arr -> Pointer to N dimensional array
// int N     -> Dimension of array to print
// int* size -> Pointer to array of size of each N dimensions
void printArrayNDUsingPointer(char* arr, int N, int* size) {
    // *arr is pointer to first element of N dimensional array.
    // 
    // N is the dimensionality of array.
    // Dimensionality of 2D array -> 2
    // Dimensionality of 3D array -> 3
    // Dimensionality of ND array -> N
    //
    // *size is array of size of each N dimensions.
    // For example, if array is of size [2][4][6] then
    // size array -> { 2, 4, 6 }
    // size[0] -> size of 1st dimension of array
    // size[1] -> size of 2nd dimension of array
    // size[2] -> size of 3rd dimension of array
    // .
    // .
    // .
    // size[N-1] -> size of Nth dimension of array
    //
    // Total elements in this array = size[0] * size[1] * ... size[N-1]
    int n_elements = 1;
    int i;
    for (i = 0; i < N; i++) {
        n_elements = n_elements * size[i];
    }

    for (i = 0; i < n_elements; i++) {
        printf("%c ", *(arr + i));
    }
}

int main(void) {

    // Uncomment below line to run the function
    // test_illegal_pointer_assignment();

    char a[] = "HelloWorld";
    char b[] = "HelloCS240";

    // print a[6] and b[5]
    printf("Value of a[6] -> %c\n", a[6]);
    printf("Value of b[5] -> %c\n", b[5]);

    // Print values without using array name
    // TYPE* pointer-name = array-name
    // TYPE -> type of element of array
    char* pa = a;
    // pa + k -> a[k]
    char* pb = b;

    // *pa -> a[0], *(pa + 0) -> a[0]
    // *(pa + i) -> a[i]
    printf("Value of a[6] -> %c\n", *(pa + 6));
    printf("Value of b[5] -> %c\n", *(pb + 5));

    char* c[2];
    c[0] = pa;
    c[1] = pb;

    // print values without pa and pb

    // *(pa + i) -> a[i]
    // *(c[0] + i) -> a[i]
    // *c[0] -> *(pa) -> *(&a[0]) -> Value at address of a[0] -> a[0]
    printf("Value of a[6] -> %c\n", *(c[0] + 6));
    printf("Value of b[5] -> %c\n", *(c[1] + 5));

    // one dimensional array
    // char c[] = { '1', '2', '3' };
    // c[0] = '1' c[1] = '2' c[2] = '3'

    // two dimensional array - Collection of one dimensional array
    char arr_2d[][3] = {
        { '1', '2', '3' },
        { 'a', 'b', 'c' }
    };
    // arr_2d[0][0] = '1' arr_2d[0][1] = '2' arr_2d[0][2] = '3'
    // arr_2d[1][0] = 'a' arr_2d[1][1] = 'b' arr_2d[1][2] = 'c'
    // printArray2D(arr_2d, 2, 3);
    printArray2DUsingPointer(&(arr_2d[0][0]), 2, 3);

    // Three dimensional array - Collection of two dimensional array
    // arr_3d[][][] = {
    //     {...a 2d array here...},
    //     {...another 2d array here...}
    //     ...
    // }
    // In a 3d array, for instance arr_3d[2][2][3], 
    // arr_3d[0] is a table(2D array) of 2 rows and 3 colums 
    // and so is arr_3d[1].
    char arr_3d[][2][3] = {
        {{ '1', '2', '3' }, { 'a', 'b', 'c' }}, // <- e[0]
        {{ '4', '5', '6' }, { 'x', 'y', 'z' }}  // <- e[1]
    };
    // arr_3d[0][0][0] = '1' arr_3d[0][0][1] = '2' arr_3d[0][0][2] = '3'
    // arr_3d[0][1][0] = 'a' arr_3d[0][1][1] = 'b' arr_3d[0][1][2] = 'c'
    // arr_3d[1][0][0] = '4' arr_3d[1][0][1] = '5' arr_3d[1][0][2] = '6'
    // arr_3d[1][1][0] = 'x' arr_3d[1][1][1] = 'y' arr_3d[1][1][2] = 'z'

    printArray3D(arr_3d, 2, 2, 3);
    printArray3DUsingPointer(arr_3d[0][0], 2, 2, 3);

    int size[] = {2, 2, 3};
    
    printArrayNDUsingPointer(&(arr_3d[0][0][0]), 3, size);


    // Represent c using pointer
    // TYPE* pointer-name = array-name
    // TYPE -> type of element of array
    char**pc = c;


    return 0;
}