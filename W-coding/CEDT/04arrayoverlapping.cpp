#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findArea (int a, int b, int c, int d)
{
    int array[4] = {a, b, c, d};
    sort(array, array + 4);
    return array[2] - array[1];
}

int main(){
    
    int n;

    cin >> n;

    int rec[n][4], overlap[n*n], position[n*n][2], k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((max(rec[i][0], rec[j][0]) < min(rec[i][2], rec[j][2])) && (max(rec[i][1], rec[j][1]) < min(rec[i][3], rec[j][3])))
            {
                overlap[k] = findArea(rec[i][0], rec[i][2], rec[j][0], rec[j][2]) * findArea(rec[i][1], rec[i][3], rec[j][1], rec[j][3]);
                position[k][0] = i;
                position[k][1] = j;
                k++;
            }
        }
    }
    int max = *max_element (overlap, overlap + k);
    if (k == 0)
    {
        cout << "No overlaps";
    }
    else
    {
        cout << "Max overlapping area = " << max << '\n';
        for (int i = 0; i < k ; i++)
        {
            if (overlap[i] == max)
            {
                cout << "rectangles " << position[i][0] << " and " << position[i][1] << '\n';
            }         
        }
    }


}