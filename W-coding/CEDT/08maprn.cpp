#include <iostream>
#include <map>

using namespace std;

int main(){

    int n, o;
    map<string, string> mreal, mnick;
    string real, nick;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> real >> nick;
        mreal[real] = nick;
        mnick[nick] = real;
    }

    cin >> o;

    for (int i = 0; i < o; i++)
    {
        cin >> real;
        if (mreal.find(real) != mreal.end())
        {
            cout << (mreal.find(real))->second << endl;
        }
        else if (mnick.find(real) != mnick.end())
        {
            cout << (mnick.find(real))->second << endl;
        }
        else
        {   
            cout << "Not found" << endl;
        }
                  
    }
        
}

