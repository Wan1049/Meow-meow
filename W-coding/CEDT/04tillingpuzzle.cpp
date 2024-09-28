#include <iostream>

using namespace std;

int main(){

    int n, zero, count = 0;

    cin >> n;

    int puzzletemp[n * n], puzzle[n * n - 1], set[((n * n) - 1) * ((n * n) - 2) / 2][2];

    //input in puzzle
    int j = 0;
    for (int i = 0; i < n * n; i++)
    {
        cin >> puzzletemp[i];
        if (puzzletemp[i] == 0)
        {
            zero = i;
            j--;
        }
        else
        {
            puzzle[j] = puzzletemp[i];
        }
    j++;
    }
    
    zero = zero / n; // find 0 line
    //make array to set
    int k = 0, i = 0;
    for (int j = k + 1; j < (n * n) - 1; j++)
    {
        set[i][0] = puzzle[k];
        set[i][1] = puzzle[j];
        i++;
        if (j == (n * n) - 2 ) // set ว่า ถ้ามันไล่ไปหมดให้ขึ้นตัวใหม่
        {
            k++;
            j = k;
        }
    }
    for (int i = 0; i < ((n * n) - 1) * ((n * n) - 2) / 2; i++) // นับ inversion
    {
        if (set[i][0] > set[i][1])
        {
            count++;
        }
    }
    if (n % 2 == 1 && count % 2 == 0)
    {
        cout << "YES";
    }
    else if (n % 2 == 0)
    {
        if (count % 2 == 0 && zero % 2 == 1)
        {
            cout << "YES";
        }
        else if (count % 2 == 1 && zero % 2 == 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }      
}