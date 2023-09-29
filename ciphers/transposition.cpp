#include <bits/stdc++.h>
using namespace std;
typedef map<int, int>::iterator itrr;
map<int, int> keyMap;

string encryptMessage(string msg, string key)
{
    int row, col, j;
    string cipher = "";

    col = key.length();
    row = msg.length() / col;
    if (msg.length() % col)
        row += 1;

    char matrix[row][col];

    // order set
    for (int i = 0; i < key.length(); i++)
    {
        keyMap[key[i]] = i; // for HACK, the map is  A-->1, C-->2, H-->0, K-->3, sorted by key
    }

    // message to matrix
    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < col;)
        {
            if (msg[k] == '\0')
            {
                matrix[i][j] = '_';
                j++;
            }

            if (isalpha(msg[k]) || msg[k] == ' ')
            {
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }

    // matrix to cipher
    for (itrr ii = keyMap.begin(); ii != keyMap.end(); ++ii)
    {
        j = ii->second; // column
        for (int i = 0; i < row; i++)
        {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
                cipher += matrix[i][j];
        }
    }

    return cipher;
}

string decryptMessage(string cipher, string key)
{
    int col = key.length();

    int row = cipher.length() / col;
    char cipherMat[row][col];

    // cipher to matrix, columnwise
    for (int j = 0, k = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipher[k++];

    // new order
    int index = 0;
    for (itrr ii = keyMap.begin(); ii != keyMap.end(); ++ii)
        ii->second = index++; // A-->0, C-->1, H-->2, K-->3

    // re-arrange matrix with new order
    char decCipher[row][col];
    for (int l = 0, j; l < col; l++) // j--> old matrix column, l--> key iterator, new matrix column
    {
        j = keyMap[key[l]];
        for (int i = 0; i < row; i++)
        {
            decCipher[i][l] = cipherMat[i][j];
        }
    }

    // matrix to msg
    string msg = "";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (decCipher[i][j] != '_')
                msg += decCipher[i][j];
        }
    }
    return msg;
}

int main(void)
{
    string msg, key;
    // cout<<"enter message: ";
    // cin>>msg;
    // cout<<"enter key: ";
    // cin>>key;

    msg = "hello world";
    key = "hack";

    string cipher = encryptMessage(msg, key);
    cout << "Encrypted Message: " << cipher << endl;
    cout << "Decrypted Message: " << decryptMessage(cipher, key) << endl;

    return 0;
}
