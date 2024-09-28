#include <iostream>

using namespace std;

int main(){

    string text, result = "";

    bool open = false;

    cin >> text;

    for (int i = 0; i < text.length(); i++)
    {
        result += text[i];

        if (isdigit(text[i + 1]) && !open && !isdigit(text[i]))
        {
            result += ", ";
            open = true;
        }
        else if ((text[i + 1] >= 'A' && text[i + 1] <= 'Z') && !open)
        {
            result += ", ";
        }
        else if (open && isalpha(text[i + 1]))
        {
            result += ", ";
            open = false;
        }
        
    }
    cout << result;

}