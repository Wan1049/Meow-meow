#include <iostream>

using namespace std;

int main(){

    string text;

    getline(cin, text);

    int textlength = text.length();
    char alphabet[26];
    int count[26] = {};

    for (int i = 0; i < textlength; i++) // set all to lower case
    {
        text[i] = tolower(text[i]);
    }


    for (int i = 0; i < 26; i++) // array a-z
    {
        alphabet[i] = 'a' + i;
    }

    for (int i = 0; i < textlength; i++) // check
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == alphabet[j])
            {
                count[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            cout << alphabet[i] << " -> " << count[i] << '\n';
        }
    }
    
}
