#include <iostream>

using namespace std;

string addString(string num, string result);

int main(){

    string result = "", num;

    while (true)
    {
        cin >> num;

        if (num == "END")
        {
            break;
        }
        result = addString(num, result);

    }
    cout << result;
}

string addString(string num, string re)
{
    string result;

    int length = max(num.length(), re.length());

    num = string(length - num.length(), '0') + num;
    re = string(length - re.length(), '0') + re;

    int count = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = (num[i] - '0') + (re[i] - '0') + count;
        result = to_string(digit % 10) + result;
        count = digit / 10;
    }
    if (count > 0) result = to_string(count % 10) + result;
    return result;
    
}