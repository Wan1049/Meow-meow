#include <iostream>
#include <algorithm>

using namespace std;

bool equal(int pancake[], int sortarray[], int n);

int main() {
    int n;
    cin >> n;
    int pancake[n], sortarray[n];

    for (int i = 0; i < n; i++)
    {
        cin >> pancake[i];
        sortarray[i] = pancake[i];
    }
    cout << '\n';
    for (auto X : pancake) 
    {
        cout << X << " ";
    }
    cout << '\n';

    sort(sortarray, sortarray + n);

    int i = 1, temp = 0;
    while (!equal(pancake, sortarray, n))
    {
        for (int j = 0; j < n; j++) {
            if (sortarray[n - i] == pancake[j])
            {
                if (n - i == j)
                {
                    temp = 0;
                    i++;
                    break;
                }
                temp = j;
                break;
            }
        }

        if (temp != 0) 
        {
            for (int k = 0; temp - k - k > 0; k++)
            {
                swap(pancake[temp - k], pancake[k]);
            }

            for (auto X : pancake) 
            {
                cout << X << " ";
            }
            cout << '\n';
        }

        for (int k = 0; n - i - k - k > 0; k++)
        {
            swap(pancake[n - i - k], pancake[k]);
        }
        for (auto X : pancake)
        {
            cout << X << " ";
        }
        cout << '\n';

        i++;
    }
}

bool equal(int pancake[], int sortarray[], int n)
{   
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pancake[i] == sortarray[i])
        {
            count++;
        }
    }
    return count == n;
}