#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;

    int num;

    cin >> num;

    v.push_back(num);

    while(num != 1)
    {
        if (num % 2 == 0)
        {
            v.push_back(num / 2);
            num /= 2;
        }
        else
        {
            v.push_back((num * 3) + 1);
            num = num * 3 + 1;
        }
        
    }
    
    int beg = 0;
    if (v.size() > 15)
    {
        beg = v.size() - 15;
    }
    
    for(int i = beg; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << "->";
        }
        
    }
}