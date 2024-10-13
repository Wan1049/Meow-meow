#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    vector<tuple<double, string, double>> v;
    vector<string> vs;

    string x;
    double y;

    while (true)
    {
        cin >> x;
        if (x == "END")
        {
            break;
        }
        cin >> y;
        v.push_back(make_tuple(0, x, y));
    }
    
    while(cin >> x)
    {
        vs.push_back(x);  
    }

    for (int i = 0; i < vs.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if(vs[i] == get<1>(v[j]))
            {
                get<0>(v[j]) += -get<2>(v[j]);
                break;
            }
        }
    }

    sort(v.begin(), v.end());
    
    
    bool print = false;
    for (int i = 0; i < 3; i++)
    {
        if (get<0>(v[i]) < 0)
        {
            print = true;
            cout << get<1>(v[i]) << " " << -1 * get<0>(v[i]) << endl;
        }
    }
    if (!print)
    {
        cout << "No Sales";
    }
}