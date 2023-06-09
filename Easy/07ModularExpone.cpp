#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    long long ans = 1;
    long long xx = x;

    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans = ((ans % m) * (xx % m)) % m;
        }

        xx = ((xx % m) * (xx % m)) % m;
        n = n >> 1;
    }

    return static_cast<int>(ans % m);
}

int main()
{
    int x = 4;   // Base
    int n = 3;   // Exponent
    int m = 10;   // Modulus

    int result = modularExponentiation(x, n, m);

    cout << "Result: " << result << endl;

    return 0;
}
