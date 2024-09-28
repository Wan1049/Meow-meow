#include <iostream>
#include <cmath>

using namespace std;

int checkNum(char color);

int main(){

    int n;

    cin >> n;
    cin.ignore();

    int score[n] = {0}, lastR[n] = {-1}, countR[n] = {0}, count[n] = {0}, counttemp = 0;
    string snook[n];
    bool correct[n];
    char Munyin[6] = {'Y', 'G', 'N', 'B', 'P', 'K'};

    for (int i = 0; i < n; i++)
    {
        getline(cin, snook[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = snook[i].length() - 1; j >= 0; j--)
        {   

            if(snook[i][j] == 'R')
            {
                lastR[i] = j;
                break;
            }
        }
        for (int k = 0; k < snook[i].length(); k++)
        {
            if (snook[i][k] == 'R')
            {
                countR[i]++;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {   
        if (snook[i][0] == 'R')
        {
            correct[i] = true;
            for (int j = 0; j < snook[i].length(); j+= 2)
            {

                score[i] += checkNum(snook[i][j]);
                
                if (snook[i][j] == 'R' && snook[i][j + 2] != 'R' && j + 2 < snook[i].length())
                {
                    correct[i] = true;
                    if (snook[i][j + 4] != 'R' && j + 4 < snook[i].length())
                    {
                        correct[i] = false;
                    }
                }
                if (snook[i][j] == 'R' && j == snook[i].length() - 1 && countR[i] == (snook[i].length() - (snook[i].length() / 2)) - ((snook[i].length() - (snook[i].length() / 2)) / 2))
                {
                    correct[i] = true;
                }
                else
                {
                    correct[i] = false;
                }
                if (snook[i].length() == 3 && snook[i][0] == 'R' && snook[i][2] != 'R')
                {
                    correct[i] = true;
                }
                if ((snook[i][j] != 'R' && j == snook[i].length() - 1 ))
                {
                    count[i] = ((snook[i].length() - lastR[i]) / 2) - 1;
                    int m = 0;
                    for (int k = lastR[i] + 4; k < snook[i].length(); k+=2)  
                    {
                        if(snook[i][k] == Munyin[m])
                        {
                        counttemp++;
                        }
                    
                        m++;
                    }
                    if (counttemp == count[i])
                    {
                        correct[i] = true;
                    }
                    else
                    {
                        correct[i] = false;
                    }
                    counttemp = 0;    
                    m = 0;
                }
                
            }
            
        }
        else
        {
            correct[i] = false;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (correct[i])
        {
            cout << score[i] << '\n';
        }
        else
        {
            cout << "WRONG_INPUT\n";
        }
    }
    
}

int checkNum(char color)
{
    switch (color)
    {
    case 'R':
        return 1;
        break;
    case 'Y':
        return 2;
        break;
    case 'G':
        return 3;
        break;
    case 'N':
        return 4;
        break;
    case 'B':
        return 5;
        break;
    case 'P':
        return 6;
        break;
    case 'K':
        return 7;
        break;
    }
    return 0;
}