#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::pow;
using std::sin;

int main()
{
    int k;
    double x, curr_value, sum = 0;
    cout << "Enter k: "; cin >> k;
	cout << "Enter x: "; cin >> x;
    for(int i = 1; i <= k; ++i)
    {
    	curr_value = (x*x * sin(pow(x,i)))/(i*i);
    	sum += curr_value;
    }
    cout << "Sum: " << sum << '\n';
	system("pause");
	
    return 0;
}