#include <iostream>

using namespace std;

int main(){

    string text, line[100] = {}, lin, result[100] = {};

    int count = 0;

    bool open = false;

    char temp;

    while (getline(cin, lin))
    {
        if (lin.empty())
        {
            break;
        }
        line[count] = lin;
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < line[i].length(); j++)
        {
            temp = line[i][line[i].length() - 1];

            if (line[i][j] == temp && !open)
            {
                open = true;
            }
            else if (open && line[i][j] != temp)
            {
                result[i] += line[i][j];
            }
            else if (line[i][j] == temp && open)
            {
                open = false;
            }
        }
        open = false;
        
    }

    for (int i = 0; i < count; i++)
    {
        cout << result[i] << '\n';
    }
    
        
}