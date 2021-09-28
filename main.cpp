#include <string_view>
#include "fmt/format.h"

[[nodiscard]]
unsigned int count_lcs(std::string_view sv1, std::string_view sv2) {
    if (sv1.empty() || sv2.empty()) {
        return 0;
    }
    const auto sv1_len = sv1.size();
    const auto sv2_len = sv2.size();
    if (sv1.back() == sv2.back()) {
        return 1 + count_lcs(sv1.substr(0, sv1_len - 1),
                             sv2.substr(0, sv2_len - 1));
    }
    return std::max(count_lcs(sv1.substr(0), sv2.substr(0, sv2_len - 1)),
                    count_lcs(sv1.substr(0, sv1_len - 1), sv2.substr(0)));
}

int main() {
    fmt::print("Hello, World!\n");
    {
        const std::string s1 = "AGGTAB";
        const std::string s2 = "GXTXAYB";
        const auto result = count_lcs(s1, s2);
        fmt::print("result is {}\n", result);
    }
    {
        const std::string s1 = "ABCDGH";
        const std::string s2 = "AEDFHR";
        const auto result = count_lcs(s1, s2);
        fmt::print("result is {}\n", result);
    }
    return 0;
}
