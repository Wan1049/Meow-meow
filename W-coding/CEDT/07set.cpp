#include <iostream>
#include <set>

using namespace std;

int main(){

    set<int> s;

    int x;

    bool nodup = false;

    while (cin >> x)
    {
        if (s.find(x) != s.end())
        {
            nodup = true;
            break;
        }

        s.insert(x);
    }
    (!nodup) ? cout << "-1" : cout << s.size() + 1;
}