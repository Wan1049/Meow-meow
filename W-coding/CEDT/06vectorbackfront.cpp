#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> v;

    bool front = false;

    int temp = 0;

    while (temp != -1)
    {
        cin >> temp;
        if (temp == -1)
        {
            break;
        }
        if (front)
        {
            v.insert(v.begin(), temp);
            front = false;
        }
        else
        {
            v.push_back(temp);
            front = true;
        }
    }
   
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}