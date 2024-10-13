#include <iostream>
#include <set>

using namespace std;

int main(){

    multiset<char> a, b;

    string x, y;

    getline(cin, x);
    getline(cin, y);

    for (int i = 0; i < x.length(); i++)
    {
        a.insert(tolower(x[i]));
    }
    for (int i = 0; i < y.length(); i++)
    {
        b.insert(tolower(y[i]));
    }
    a.erase(' ');
    b.erase(' ');

    (a == b) ? cout << "YES" : cout << "NO";

}