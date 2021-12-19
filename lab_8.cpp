#include <iostream>
#include <time.h>
#include <random>

using std::cout;
using std::cin;


int** get_NxN_matrix(const int N);
void delete_NxN_matrix(int** matrix,const int N);

void init_NxN_matrix_with_random_numbers(int** matrix,const int N,int limit_max_val = 10);
void display_NxN_matrix(int** matrix,const int N);

int* get_address_of_min_element_of_array(int* arr, const int size);
void swap_elements_by_address(int* p_f, int* p_s);
void prosses_NxN_matrix(int** matrix,const int N);

int max_el(int a, int b);
void prosses_special_NxN_matrix_by_two_others(int** matrix, int** first_matrix, int** second_matrix, const int N);


int main(int argc, char **argv)
{
    srand(time(NULL));
    int n;
    cout << "Enter the size of matrixes: "; cin >> n;
    int **A = get_NxN_matrix(n);
    int **B = get_NxN_matrix(n);
    int **Q = get_NxN_matrix(n);
    
    init_NxN_matrix_with_random_numbers(A,n);
    init_NxN_matrix_with_random_numbers(B,n);
    
    cout << "matrix A:\n";
    display_NxN_matrix(A,n);
    prosses_NxN_matrix(A,n);
    cout << "prossesed matrix A:\n";
    display_NxN_matrix(A,n);
    
    cout << "matrix B:\n";
    display_NxN_matrix(B,n);
    prosses_NxN_matrix(B,n);
    cout << "prossesed matrix B:\n";
    display_NxN_matrix(B,n);
    
    prosses_special_NxN_matrix_by_two_others(Q,A,B, n);
    cout << "prossesed special matrix Q:\n";
    display_NxN_matrix(Q,n);
    
    delete_NxN_matrix(A,n);
    delete_NxN_matrix(B,n);
    delete_NxN_matrix(Q,n);
    return 0;
}

int** get_NxN_matrix(const int N)
{
    int **matrix = new int*[N];
    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new int[N];
    }
    return matrix;
}

void delete_NxN_matrix(int** matrix, const int N)
{
    for(int i = 0; i < N; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void init_NxN_matrix_with_random_numbers(int** matrix,const int N, int limit_max_val)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            matrix[i][j] = rand() % limit_max_val;
        }
    }
}

void display_NxN_matrix(int** matrix,const int N)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

int* get_address_of_min_element_of_array(int* arr, const int size)
{
    int index = 0;
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] < arr[index])
        {
            index = i;
        }
    }
    return arr + index;
}

void swap_elements_by_address(int* p_f, int* p_s)
{
    int temp = *p_f;
    *p_f = *p_s;
    *p_s = temp;
}

void prosses_NxN_matrix(int** matrix,const int N)
{
    int *p_diag_elem, *p_min_elem;
    for(int i = 0; i < N; ++i)
    {
        p_diag_elem = matrix[i] + i;
        p_min_elem = get_address_of_min_element_of_array(matrix[i],N);
        swap_elements_by_address(p_diag_elem, p_min_elem );
    }
}

int max_el(int a, int b)
{
    return (a > b) ? a : b;
}

void prosses_special_NxN_matrix_by_two_others(int** matrix, int** first_matrix, int** second_matrix, const int N)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            matrix[i][j] = max_el(first_matrix[i][j], second_matrix[i][j]);
        }
    } 
}