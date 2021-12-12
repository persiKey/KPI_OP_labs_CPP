// Варіант 27 
// ІП-13 Пархомчук Ілля

#include <iostream>
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;

#define MAX_COUNT 10
// В умові сказано "деяка кількість", з якої точно є максимальне і мінімальне значення оцінки (отже, точно є мінімум 2 судді) 
// І ще є "решта" (отже, ще мінімум 1 суддя). Всього маємо: суддя - 3 шт(мінімум).
#define MIN_COUNT 3

bool check_and_fix_input();
int get_count_of_referees();
float max_el(float arr[], const int size);
float min_el(float arr[], const int size);
void enter_marks(float arr[], const int size);
void print_marks(float arr[], const int size);
float get_final_mark(float arr[], const int size);


int main(int argc, char **argv)
{
    float marks[MAX_COUNT];
    int actual_size = get_count_of_referees();
    enter_marks(marks, actual_size);
    print_marks(marks, actual_size);
    float final_mark = get_final_mark(marks, actual_size);
    cout << "Final mark: " << final_mark << '\n';
    return 0;
}

inline bool check_and_fix_input()
{
    if(!cin.good())
    {
        cout << "Something went wrong!\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }   
    return true;
}

int get_count_of_referees()
{
    bool is_correct = false;
    int count = 0;
    do
    {
        cout << "Enter the count of referees: "; cin >> count;
        if(check_and_fix_input())
        {
            if(MIN_COUNT <= count && count <= MAX_COUNT)
            {
                is_correct = true;
            }
            else
            {
                cout << "Number of referees should be between 3 and 10\n";
            }
        }
        
    }while(!is_correct);
    
    return count;
}

float max_el(float arr[], const int size)
{
    float max = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

float min_el(float arr[], const int size)
{
    float min = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

void enter_marks(float arr[], const int size)
{
    for(int i = 0; i < size; )
    {
        cout << "Enter mark #" << i+1 <<": "; cin >> arr[i];
        if(check_and_fix_input() )
        { 
            ++i;
        }
    }
}

void print_marks(float arr[], const int size)
{
    cout << "\nMarks: \n|";
    for(int i = 0; i < size; ++i)
    {
        cout << setw(4) << arr[i] << " |";
    } 
    cout << '\n';
}

float get_final_mark(float arr[], const int size)
{
    float sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    float max_mark = max_el(arr, size);    
    float min_mark = min_el(arr, size);
    cout << "Min mark: " << min_mark << '\n';
    cout << "Max mark: " << max_mark << '\n';
    sum -= max_mark;
    sum -= min_mark;
    return sum/(size - 2);  
}
