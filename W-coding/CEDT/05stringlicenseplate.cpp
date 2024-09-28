#include <iostream>

using namespace std;

int main(){

    string plate, result = "", te = "";
    char x, y;
    int number, first, three;
    bool xy = false;

    cin >> plate;
    cin >> number;

    x = plate[1];
    y = plate[2];

    first = plate[0] - '0';

    three = stoi(plate.substr(4, 3));

    three = three + (number % 1000);
    
    if(three >= 1000)
    {
        xy = true;
        three = three % 1000;
    }
    if (xy)
        {
            y++;
            xy = false;
            if (y > 'Z')
            {
            y = 'A';
            x++;
            }
            if (x > 'Z')
            {
            x = 'A';
            first++;
            }
        }

    for (int i = 0; i < number / 1000; i++)
    {
        y++;

        if (y > 'Z')
        {
            y = 'A';
            x++;
        }
        if (x > 'Z')
        {
            x = 'A';
            first++;
        }
    }
    if (three < 10)
    {
        te = "00" + to_string(three);
    }
    else if (three < 100)
    {
        te = "0" + to_string(three);
    }
    else
    {
        te = to_string(three);
    }
    
    result = to_string(first) + x + y + "-" + te;

    cout << result;
}