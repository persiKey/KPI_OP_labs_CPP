/*/////////////////////////////////////////////////////////////////////

    ��-13 ��������� ���� (³��������)
    ������ 26

***********************************************************************
    ��������� ������� ���������� ���� ���� � ������� ��������� ����.
    ������ ������� ����������.

*//////////////////////////////////////////////////////////////////////

#include <iostream> //���������� �������� ��� �������
#include <conio.h>
#include <math.h>

using std::cin; //�� ��� ����� �������,
using std::cout;//�� ��������������� "using namespace std" - �������

#define PI 3.14159265358979323846 //����� ����� ������ � ������� ))

int main()
{
    setlocale(LC_ALL, ".1251"); // �� ��� ����� �������, 
    system("chcp 1251 > null"); // ��� ��������� ������������ ��������� ����� "�"

    float side_a, side_b, side_c; //���������� ������ ����� 

    float alpha, beta, gamma;// ���������� ������ ����
    float radius;   // ���������� ����� ������ 

    cout << "������ ����: ";
    cin >> alpha >> beta >> gamma; //��� 3-� ���� �� ����

    cout << "������ ����� ��������� ����: ";
    cin >> radius; //��������� ����� ��������-г���������

    /******************************

          a       b       c
        ----- = ----- = ----- = 2 R
        sin(a)  sin(b)  sin(c)

        a = 2 R * sin(a);

    ******************************/

    side_a = 2 * radius * sin(alpha / 180 * PI); //��������� ����� ������� �� �������� ����
    side_b = 2 * radius * sin(beta / 180 * PI); //��������� ����� ������� �� �������� ����
    side_c = 2 * radius * sin(gamma / 180 * PI); //��������� ������ ������� �� �������� ����

    printf("\n�������:\n\ta = %.2f\n\tb = %.2f\n\tc = %.2f\n", //�������� ���� 3-� �����
                                side_a, side_b, side_c);

    // printf() ������ ����������� �����-������ �� �����, �� ������ �������� �� ����� ��������
    // ������ '\n' - ������� �� ����� �����
    // ������ '\t' - ���������
    // "%f" - ������, �� �� ���� ����� � ����� ���� ���������� ��������� ��� �������� ���� float
    // "%.2f" - ������, �� ���������� �������� ���� float ���� ������������ ���� �� 2-�� ����� ��� ������
    _getch(); // ��� �������� �������. ��� - ������ �� �� ���� � ��������� ��������� �� ������� ������
    return 0;
}