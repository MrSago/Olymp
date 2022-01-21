#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m, cab, mil, rez, temp, rc = 0, rm = 0, cc = 0, cm = 0;
    // cin >> m >> mil >> cab;
    m = 19;
    mil = 7;
    cab = 5;
    rez = m % cab;
    rc = m / cab;
    for (int i = 1; i < m / cab; i++)
    {
        temp = m - i * cab;
        if (temp % mil < rez)
        {
            rez = temp % mil;
            rm = temp / mil;
            rc = i;
        }

    }
    cout << rm << " " << rc;

}