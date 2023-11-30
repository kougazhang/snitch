#include "string.h"
#include "bash.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "split needs two args" << std::endl;
        return -1;
    }

    std::vector<std::string> ret = str::split(argv[1], argv[2][0]);
    if (ret.size() == 0) {
        std::cout << "split faild" << std::endl;
        return -1;
    }

    std::string s = bash::array(ret);

    std::cout << s;
    return 0;
}