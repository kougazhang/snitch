#include "set.h"

namespace set {

std::set<std::string> intersection(std::set<std::string> a, std::set<std::string> b)
{
    std::set<std::string> ret;

    for (auto item : a) {
        auto search = b.find(item);
        if (search != b.end()) {
            ret.insert(item);
        }
    }

    return ret;
}

std::set<std::string> operate_set(std::string opt, std::set<std::string> a, std::set<std::string> b)
{
    if (opt == "u") {
        // union
        a.insert(b.begin(), b.end());
        return a;
    } else if (opt == "i") {
        return intersection(a,b);
    } else if (opt == "m") {
        //
    } else {
        std::string err = "unsupported operate: ";
        err = err + opt;
        throw err;
    }
}

} // namespace set