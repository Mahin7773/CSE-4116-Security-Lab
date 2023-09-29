#include <bits/stdc++.h>
using namespace std;
#define llt unsigned long long int

llt gcd(llt a, llt b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// x^y mod z
llt modExp(llt x, llt y, llt z)
{
    llt sum = 1;
    while (y--)
    {
        sum = (sum * x) % z;
    }
    return sum;
}
// a^(-1) mod b
llt modInverse(llt a, llt b)
{
    llt i = 2, s;
    a = a % b;
    for (i = 2; i < b; i++)
    {
        s = (a * i) % b;
        if (s == 1)
            return i;
    }
    return 1;
}
int main()
{
    // two random prime numbers
    llt p = 1549;
    llt q = 1229;
    llt n = p * q;
    llt phi = (p - 1) * (q - 1);
    // Generate public key exponent e
    llt e;
    do
    {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);
    // Calculate private key exponent d
    // d*e = 1 + k*phi
    // d*e mod phi = 1
    llt d = modInverse(e, phi);
    cout << "d:\t" << d << endl
         << "e:\t" << e << endl;

    llt message;
    cout << "Enter a message to encrypt: ";
    cin >> message;

    llt signature = modExp(message, d, n);//signs with private key
    cout << "sign:\t" << signature << endl;

    llt verification = modExp(signature, e, n);//verify with public key
    cout << "verify:\t" << verification << endl;//m == v, verify success

    return 0;
}