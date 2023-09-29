#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int s)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}

int main()
{
    string text = "HelloWorld"; //no space, as space not in
    int s = 4;                  //a-z, A-Z

    cout << "Text :" << text << endl;
    cout << "Shift:" << s << endl;
    s = s % 26; // ensuring that s lies between 0-25
    cout << "Cipher:" << encrypt(text, s) << endl;
    cout << "deCipher:" << encrypt(encrypt(text, s), 26 - s) << endl;
    return 0;
}
