#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {

    string x;
    vector<set<int>> v;
    vector<vector<string>> vvs;

    while (getline(cin, x))
    {
        v.push_back(set<int>());
        vvs.push_back(vector<string>());

        int j = 0;
        vvs.back().push_back("");

        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == ' ')
            {
                if (!vvs.back()[j].empty())
                {
                    vvs.back().push_back("");
                    j++;
                }
            } else
            {
                vvs.back()[j] += x[i];
            }
        }

        for (int i = 0; i < vvs.back().size(); i++)
        {
            if (!vvs.back()[i].empty())
            {
                v.back().insert(stoi(vvs.back()[i]));
            }
        }
    }

    set<int> u, in, d;

    for (auto s : v)
    {
        u.insert(s.begin(), s.end());
    }
    cout << "U: ";
    for (auto i = u.begin(); i != u.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    in = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        set<int> temp;
        for (auto elem : v[i])
        {
            if (in.find(elem) != in.end())
            {
                temp.insert(elem);
            }
        }
        in = temp;
    }
    if (in.size() != 0)
    {
        cout << "I: ";
        for (auto i = in.begin(); i != in.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "I: empty set" << endl;
    }
    
    d = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        for (auto elem : v[i])
        {
            d.erase(elem);
        }
    }
    if (d.size() != 0)
    {
        cout << "D: ";
        for (auto i = d.begin(); i != d.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "D: empty set" << endl;
    }

}