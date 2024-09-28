#include <iostream>

using namespace std;

int main(){

    int n, sum = 0, max = -1;

    cin >> n;

    int power[n], powernew[n - 1];

    bool first = true;
    
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(power[i] <= power[i + 1])
        {
            sum += power[i];
        }
        if (power[i] > power[i + 1])
        {
            sum += power[i];
            if (sum > max)
            {
                max = sum;
            }
            sum = 0;
        }
        if (i == n - 1 && first)
        {
            first = false;
            i = 0;
            if (power[n - 1] <= power[i])
            {
                sum += power[i];
            }
            if (power[i] > power[i + 1])
            {
                sum += power[i];
            if (sum > max)
            {
                max = sum;
            }
                sum = 0;
            }
        }
        if (sum > max)
        {
           max = sum;
        }
    }
    for (int j = 0; j < n; j++)
    {   
        bool second = true;
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (i == j)
            {
                k++;
            }
            powernew[i] = power[k];
            k++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if(powernew[i] <= powernew[i + 1])
            {
                sum += powernew[i];
            }
            if (powernew[i] > powernew[i + 1])
            {
                sum += powernew[i];
                if (sum > max)
                {
                    max = sum;
                }
                sum = 0;
            }
            if (i == n - 2 && second)
            {
                second = false;
                i = 0;
                if (powernew[n - 2] <= powernew[i])
                {
                    sum += powernew[i];
                }
                if (powernew[i] > powernew[i + 1])
                {
                    sum += powernew[i];
                if (sum > max)
                {
                    max = sum;
                }
                    sum = 0;
                }
            }
            if (sum > max)
            {
            max = sum;
            }
        }

        
    }
    
    cout << max;
}