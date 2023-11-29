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

string join(vector<string> arr, string delimiter)
{
    string ret;
    int i = 0;

    for (i = 0; i < arr.size(); i++) {
        ret.append(arr[i]);
        if (i == arr.size()-1) {
            break;
        } 
        ret.append(delimiter);
    }

    return ret;
}

int main()
{
    string s = "abc";
    string delimiter = ",";
    vector<string> res;
    res.push_back(s);
    res.push_back(s);
    res.push_back(s);
    string ret = join(res, delimiter); 
    cout << ret << endl;
}
