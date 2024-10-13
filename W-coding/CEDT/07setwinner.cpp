#include <iostream>
#include <set>

using namespace std;

int main() {

    string x, y;
    set<string> win, loss;

    while(cin >> x >> y)
    {
        win.insert(x);
        loss.insert(y);
    }

    for (auto itt = win.begin(); itt != win.end();)
    {
        if (loss.find(*itt) != loss.end())
        {
            itt = win.erase(itt);
        } else
        {
            ++itt;
        }
    }

    if (!win.empty())
    {
        for (const auto& winner : win)
        {
            cout << winner << " ";
        }
    } else {
        cout << "None";
    }
}
