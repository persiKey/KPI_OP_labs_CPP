#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 24

void enter_string(char *const str, int lenght);
int* get_digits_array_from_string(char *const str, int lenght, int* count);
void delete_arr(int *arr);
void print_digits(int* arr, const int size);
int sum_of_elements(int* arr, const int size);

int main(int argc, char **argv)
{
    char buffer[BUFFER_SIZE];
    int digit_count = 0;
    int* digits = NULL;
    int result = 0;
    
    puts("Enter your string: ");
    enter_string(buffer, BUFFER_SIZE);
    
    digits = get_digits_array_from_string(buffer, BUFFER_SIZE, &digit_count);
    printf("found %d digits: ", digit_count);
    print_digits(digits, digit_count);
    
    result = sum_of_elements(digits, digit_count);
    printf("sum of all digits: %d\n", result);
    
    delete_arr(digits);

    getchar();
    return 0;
}


void enter_string(char *const str, int lenght)
{
    fgets(str, lenght, stdin);
    int pre_end_pos = strlen(str)-1;
    if(str[pre_end_pos] == '\n') 
    {
        str[pre_end_pos] = '\0';
    }
        
}

int* get_digits_array_from_string(char *const str, int lenght, int* count)
{
    int i = 0;
    while(str[i] != '\0' && i < lenght)
    {
        if( '0' <= str[i] && str[i] <= '9')
        {
            ++(*count);
        }  
        ++i;
    }
    
    int *temp = malloc(*count * sizeof(int));
    if(temp == NULL) 
    {
        exit( EXIT_FAILURE );
    }
    
    i = 0;
    int dig_pos = 0;
    while(str[i] != '\0' && i < lenght)
    {
        if( '0' <= str[i] && str[i] <= '9')
        {
            temp[dig_pos] = (int)str[i] - (int)'0';
            ++dig_pos;
        }  
        ++i;
    }
    return temp;
}

void delete_arr(int *arr)
{
    if(arr)
    {
        free(arr);
    }
}

void print_digits(int* arr, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int sum_of_elements(int* arr, const int size)
{
    int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}
