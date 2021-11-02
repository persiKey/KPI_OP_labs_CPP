#include <iostream>
#include <cmath>

using std::cout;
using std::log10;
using std::pow;

int main(int argc, char** argv)
{
    const int FROM = 1000;
    const int TO = 1000000;
    int div_num = 1;
    for (int i = FROM; i <= TO; ++i)
    {
        int num_of_digits = log10(i) + 1;
        for (int num_in_seq = 2; num_in_seq <= num_of_digits / 2; ++num_in_seq)
        {
            if (num_of_digits % num_in_seq == 0)
            {
                div_num = 1;
                for (int power_10 = num_in_seq; power_10 < num_of_digits; power_10 += num_in_seq)
                {
                    div_num += pow(10, power_10);
                }
                if (i % div_num == 0)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}