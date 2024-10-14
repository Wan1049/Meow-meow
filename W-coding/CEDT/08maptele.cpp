#include <iostream>
#include <map>

using namespace std;

int main(){

    int n, m;
    string text;
    map<string, string> name, tele;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, text);
        name[text.substr(0, text.rfind(' '))] = text.substr(text.rfind(' ') + 1, text.length() - text.rfind(' ') - 1);
        tele[text.substr(text.rfind(' ') + 1, text.length() - text.rfind(' ') - 1)] = text.substr(0, text.rfind(' '));
    }
    
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        getline(cin, text);
        if (name.find(text) != name.end())
        {
            cout << text << " --> " << (name.find(text))->second << endl;
        }
        else if (tele.find(text) != tele.end())
        {
            cout << text << " --> " << (tele.find(text))->second << endl;
        }
        else
        {
            cout << text << " --> " << "Not found" << endl;
        }
        
    }
    
}