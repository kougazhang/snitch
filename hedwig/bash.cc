#include "bash.h"
#include "string.h"
#include <string.h>

namespace bash {

std::string array(std::vector<std::string> vector)
{
    std::string ret = "declare -A ret;";
    int i=0;
    char line[1024]={0,};
    for (auto s : vector) {
        sprintf(line, "ret[%d]=\"%s\";", i, s.c_str());
        ret.append(line);
        i++;
    }
    return ret;
}

} // namespace bash