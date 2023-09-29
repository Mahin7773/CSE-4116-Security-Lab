#include <bits/stdc++.h>
using namespace std;
#define llt unsigned long long int

llt gcd(llt a, llt b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

llt modExp(llt x, llt y, llt z)
{
    llt sum = 1;
    while (y--)
    {
        sum = (sum * x) % z;
    }
    return sum;
}

llt modInverse(llt a, llt b)
{
    a = a % b;
    for (llt i = 2; i < b; i++)
    {
        if ((a * i) % b == 1)
            return i;
    }
    return 1;
}

int main()
{
    llt p = 1549;                   // prime
    llt alpha = 10;                 // primitive
    llt a = rand() % (p - 2);       // private key
    llt beta = modExp(alpha, a, p); // public key
    llt m;                          // message
    llt k1, k2;                     // random number
    while (1)
    {
        k1 = rand() % (p - 1);
        if (gcd(k1, (p - 1)) == 1)
            break;
    }
    while (1)
    {
        k2 = rand() % (p - 1);
        if (gcd(k2, (p - 1)) == 1)
            break;
    }

    cout << "Message: ";
    cin >> m;
    llt c1 = modExp(alpha, k1, p);
    llt c2 = m * modExp(beta, k1, p);
    cout << "C1: " << c1 << " C2: " << c2 << endl;

    llt d = c2 / (modExp(c1, a, p));
    cout << "Decrypted: " << d << endl;

    llt c11 = (modExp(alpha, k1, p) * modExp(alpha, k2, p)) % p;
    llt c22 = m * ((modExp(beta, k1, p) * modExp(beta, k2, p)) % p);

    llt d2 = c22 / (modExp(c11, a, p));

    cout << "Decrypted2: " << d2 << endl;
}