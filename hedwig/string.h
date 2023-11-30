#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <iostream>

namespace str {
std::vector<std::string> split(std::string s, char delimiter);
std::string join(std::vector<std::string> arr, std::string delimiter);
template <typename... Args>
std::string string_format(const std::string &format, Args... args);
} // namespace string
