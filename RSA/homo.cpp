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

    llt message1, message2;
    cout << "m1:\t"; //works for 3*3 or 3*4 digit messages
    cin >> message1;
    cout << "m2:\t";
    cin >> message2;
    llt message = message1 * message2;

    llt cipherText1 = modExp(message1, e, n);
    cout << "c1:\t" << cipherText1 << endl;
    llt cipherText2 = modExp(message2, e, n);
    cout << "c2:\t" << cipherText2 << endl;

    llt cipherText = cipherText1 * cipherText2;
    cout << "c=c1*c2:\t" << cipherText << endl;
    llt deCipher = modExp(cipherText, d, n);
    cout << "Decrypted:\t" << deCipher << endl;
    cout << "m=m1*m2:\t" << message << endl;

    return 0;
}
