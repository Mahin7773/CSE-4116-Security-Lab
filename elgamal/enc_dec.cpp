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
    llt k;                          // random number
    while (1)
    {
        k = rand() % (p - 1);
        if (gcd(k, (p - 1)) == 1)
            break;
    }
    cout << "Message: ";
    cin >> m;

    llt y1 = modExp(alpha, k, p);    // 1st part
    llt y2 = m * modExp(beta, k, p); // 2nd part
    //encryption
    cout << "y1:\t" << y1 << endl;
    cout << "y2:\t" << y2 << endl;

    llt dec = y2 / modExp(y1, a, p); // decryption

    cout << "decrypted: " << dec << endl;

    return 0;
}