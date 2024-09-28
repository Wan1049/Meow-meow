#include <iostream>

using namespace std;

int main(){

    int n, watertemp = 0, leftegde, water = 0, rightedge, max = -1;

    cin >> n;

    int drainwater[n];

    for (int i = 0; i < n; i++)
    {
        cin >> drainwater[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (drainwater[i] > drainwater[i + 1])
        {
            leftegde = i;

            for (int j = i + 1; j < n; j++)
            {
                if (drainwater[j] > max)
                {
                    max = drainwater[j];
                    rightedge = j;
                    if (max > drainwater[leftegde])
                    {
                        break;
                    }
                    
                }
            }
            
            if (drainwater[leftegde] <= drainwater[rightedge])
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (rightedge == j)
                    {
                        break;
                    }
                    watertemp += drainwater[leftegde] - drainwater[j];
                    water += watertemp;
                    watertemp = 0;
                }
            }
            else if (drainwater[leftegde] > drainwater[rightedge])
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (rightedge == j)
                    {
                        break;
                    }
                    watertemp += drainwater[rightedge] - drainwater[j];
                    water += watertemp;
                    watertemp = 0;
                }
            }
            max = -1;
            i = rightedge - 1;
        }
        
    }
    cout << water;
}