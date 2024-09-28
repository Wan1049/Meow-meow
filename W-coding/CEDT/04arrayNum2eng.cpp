#include <iostream>
#include <string>

using namespace std;

string convertNum(long long number);

string hundred(int num);

string oneToNineteen[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                          "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                          "seventeen", "eighteen", "nineteen"};

string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string bigNumbers[] = {"", "thousand", "million", "billion", "trillion"};

int main() {

    long long number;

    cin >> number;

    string result = convertNum(number);

    cout << result;

    return 0;
}

string convertNum(long long number)
{
    if (number == 0)
    {
        return "zero";
    }
    
    string result = "";

    int big = 0;

    while (number > 0)
    {
        int lastThree = number % 1000;
        
        if (lastThree > 0)
        {
            string group = hundred(lastThree);
            result = group + bigNumbers[big] + " " + result;
        }

        number /= 1000;

        big++;
    }
    
    return result;
}

string hundred(int num)
{
    string result = "";   

    if (num >= 100)
    {
        result += oneToNineteen[num / 100] + " hundred ";
        num = num % 100;
    }
    if (num >= 20)
    {
        result += tens[num / 10] + " ";
        num = num % 20;
    }
    if (num > 0)
    {
        result += oneToNineteen[num] + " ";
    }
    
    return result;
}
