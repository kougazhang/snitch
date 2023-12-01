#include "set.h"
#include "iostream"

int main()
{
    std::set<std::string> a = {
        "a",
        "b",
    };
    std::set<std::string> b = {
        "a",
        "c",
    };

    std::set<std::string> ret = set::operate_set("u", a, b);
    for (auto item : ret) {
        std::cout << item << std::endl;
    }

    ret = set::operate_set("i", a, b);
    for (auto item : ret) {
        std::cout << item << std::endl;
    }
}