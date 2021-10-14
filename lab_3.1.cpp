#include <iostream>
#include <stdio.h>
#include <cmath>

using std::cout;
using std::cin;


int main(int argc, char **argv)
{
    double a, x_Curr, x_Prev;
    double diff, eps = std::pow(10, -4);
    
    cout << "Enter a: "; cin >> a;
    
    if(a <= 1)
        x_Curr = std::min(2*a, 0.95);
    else if( a < 25 )
        x_Curr = a/5;
    else
        x_Curr = a/25;
        
    do
    {
        x_Prev = x_Curr;
        x_Curr = 4.0/5 * x_Prev + a / (5.0 * std::pow(x_Prev, 4));
        diff = x_Curr - x_Prev;
    }while(std::abs(diff) > eps);
  
    cout << "x = " << x_Curr << "\n";
        
    return 0;
}
