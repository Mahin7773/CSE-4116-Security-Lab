// capital letters only
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    string input;
    string key;
    cout << "Input:";
    cin >> input;
    cout << "key:";
    cin >> key;
    string output;
    for (int i = 0; i < input.length(); i++)
    {
        int first = input[i] - 'A';
        int second = key[i] - 'A';
        int xxor = first ^ second;
        if (xxor > 26)
        {
            xxor = xxor - 26;
        }
        output.push_back('A' + xxor);
    }
    cout << output << endl;
}