#include <string_view>
#include <set>
#include "fmt/format.h"

namespace {
    [[nodiscard("")]]
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

    std::set<std::pair<std::size_t, char>> location_and_char;

    void insert_entry(const std::size_t idx, const char c){
        location_and_char.insert({idx, c});
    }

    void remove_entry(const std::size_t idx, const char c) {
        if (location_and_char.contains({idx, c})) {
            location_and_char.erase({idx, c});
        }
    }


    [[nodiscard("")]]
    unsigned int
    waysToIncreaseLCSBy1(std::string_view sv1, std::string_view sv2) {
        if (sv1.empty() || sv2.empty()) {
            return 0;
        }

        const auto sv1_len = sv1.size();
        const auto sv2_len = sv2.size();
        if (sv1.back() == sv2.back()) {
            remove_entry(sv2_len - 1, sv2.back());
            return 1 + waysToIncreaseLCSBy1(sv1.substr(0, sv1_len - 1),
                                            sv2.substr(0, sv2_len - 1));
        }
        insert_entry(sv2_len - 1, sv2.back());
        return std::max(waysToIncreaseLCSBy1(sv1.substr(0), sv2.substr(0, sv2_len - 1)),
                        waysToIncreaseLCSBy1(sv1.substr(0, sv1_len - 1), sv2.substr(0)));
    }

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

    {
        location_and_char.clear();
        const std::string s1 = "AGGTAB";
        const std::string s2 = "GXTXAYB";
        const auto result = waysToIncreaseLCSBy1(s1, s2);
        fmt::print("result is {} total set {}\n", result, location_and_char.size());
        for(const auto [l, c] : location_and_char) {
            fmt::print("location {} char {}\n", l , c);
        }
    }
    {
        location_and_char.clear();
        const std::string s1 = "ABCDGH";
        const std::string s2 = "AEDFHR";
        const auto result = waysToIncreaseLCSBy1(s1, s2);
        fmt::print("result is {} total set {}\n", result, location_and_char.size());
        for(const auto [l, c] : location_and_char) {
            fmt::print("location {} char {}\n", l , c);
        }
    }
    return 0;
}
