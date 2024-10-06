#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &line, char delimiter)
{
    vector<string> vs;
    string temp;

    for (char ch : line)
    {
        if (ch != delimiter)
        {
            temp += ch;
        }
        else
        {
            if (!temp.empty())
            {
                vs.push_back(temp);
                temp.clear();
            }
        }
    }

    if (!temp.empty())
    {
        vs.push_back(temp);
    }
    return vs;
}

int main()
{
    string line;
    getline(cin, line);

    string delim;
    getline(cin, delim);

    vector<string> result = split(line, delim[0]);

    for (const string &e : result)
    {
        cout << '(' << e << ')';
    }

    return 0;
}