#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string text;
    map<string ,vector<string>> species; // <species, <animal1, 2, 3>>
    vector<string> order;

    while (getline(cin, text))
    {
        string name = text.substr(0, text.find(' ')), spe = text.substr(text.find(' ') + 1, text.length() - text.find(' ') - 1);
        if (find(order.begin(), order.end(), spe) == order.end())
        {
            order.push_back(spe);
        }
        species[spe].push_back(name);
    }
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ": ";
        for (auto animal : species[order[i]])
        {
            cout << animal << " ";
        }
        cout << endl;
    }
    
    
}