#include "string.h"

namespace str {

std::vector<std::string> split(std::string s, char delimiter)
{
    int i = 0, last = 0, len = s.length();
    std::vector<std::string> ret;

    for (i = 0; i < len; i++) {
        if (delimiter == s[i]) {
            ret.push_back(s.substr(last, i - last));
            last = i + 1;
        }
    }
    ret.push_back(s.substr(last, i - last));

    return ret;
}

std::string join(std::vector<std::string> arr, std::string delimiter)
{
    std::string ret;
    int i = 0;

    for (i = 0; i < arr.size(); i++) {
        ret.append(arr[i]);
        if (i == arr.size() - 1) {
            break;
        }
        ret.append(delimiter);
    }

    return ret;
}

} // namespace str
