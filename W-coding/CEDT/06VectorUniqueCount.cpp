#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v, result;

    int temp;

    while(cin >> temp)
    {
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());

    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != v[i + 1])
        {
            count++;
            result.push_back(v[i]);
        }
    }

    cout << count << endl;

    int end = result.size();
    if (result.size() > 10)
    {
        end = 10;
    }
    
    for(int i = 0; i < end; i++)
    {
        cout << result[i] << " ";
    }
}