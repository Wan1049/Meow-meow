#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string y;

    vector<string> vs;

    cin >> y;

    y += "$";

    vs.push_back(y);

    string result = "";

    for (int i = 0; i < y.length() - 1; i++)
    {
        for (int j = 1; j < y.length(); j++)
        { 
            result += y[j];
        }

        result += y[0];
        y = result;
        vs.push_back(result);
        result = "";
    }
    sort(vs.begin(), vs.end());

    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i][y.length() - 1];
    }
}