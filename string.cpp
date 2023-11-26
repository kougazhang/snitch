#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> *split(string s, char delimiter)
{
    int i = 0, last = 0;
    vector<string> *res = new vector<string>;

    for (i = 0; i < s.length(); i++) {
        if (delimiter == s[i]) {
            res->push_back(s.substr(last, i - last));
            last = i + 1;
        }
    }

    res->push_back(s.substr(last, i - last));

    return res;
}

int main()
{
    string s = "a,b,c";
    char delimiter = ',';
    vector<string> *res = split(s, delimiter);
    for (auto it : *res) {
        cout << it << endl;
    }
    delete(res);
}