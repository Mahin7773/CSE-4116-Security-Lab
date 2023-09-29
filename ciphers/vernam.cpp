//binary stream
#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int XOR(int a, int b)
{
    if (a == b)
        return 0;
    else
        return 1;
}

string vernam(string msg, string key)
{
    if(msg.size()!=key.size())
        return "size error";
    string cipher = "";
    for (int i = 0; i < msg.size(); i++)
    {
        int a = (msg[i] == '0') ? 0 : 1;
        // cout<<a<<" ";
        int b = (key[i] == '0') ? 0 : 1;
        // cout<<b<<" ";
        int c = XOR(a, b);
        // cout<<c<<endl;
        cipher += (c == 0) ? '0' : '1';
    }
    return cipher;
}

int main()
{
    string msg = "11001100"; // msg, key same size
    string key = "00110011";
    cout << "cipher: " << vernam(msg, key) << endl;
    cout << "decipher: " << vernam(vernam(msg, key), key) << endl;
}