#pragma once

#include <filesystem>
#include <print>
#include <string_view>
#include <vector>
#include <array>

inline constexpr std::string_view resetcolor = "\033[0m";
inline constexpr std::string_view RED = "\033[31m";
inline constexpr std::string_view GREEN = "\033[32m";
inline constexpr std::string_view GREEN_B = "\033[1;32m";
inline constexpr std::string_view YELLOW = "\033[1;33m";
inline constexpr std::string_view BLUE = "\033[34m";

namespace Setting {};
namespace Fman {
char FMAN(const std::string_view color) {
    const std::vector<std::array<std::string, 1>> Banner = {
        {"\t\tFile_Manager_C++"},
        {"| ████████╗+ ██╗    ██╗\\  ███████╗* ██╗   ██║!"},
        {"| ██╔═════╝+ ████ ████║\\ ██╔═══██║* ████╗ ██║!"},
        {"| ██████╗  + ██║███ ██║\\ ██║   ██║* ██║██║██║!"},
        {"| ██╔═══╝  + ██║    ██║\\ ████████║* ██║ ████║!"},
        {"| ██║      + ██║    ██║\\ ██║   ██║* ██║   ██║!"},
        {"| ╚═╝      + ╚═╝    ╚═╝\\ ╚═╝   ╚═╝* ╚═╝   ╚═╝!"},
    };
    std::print("{}", color);
    for(const auto &line : Banner) {
        std::println("{}", line[0]);
    }   
     std::println(resetcolor);
    return 0;
  }
};
namespace Varbs {
    #define UP "^[[A"
    #define DOWN "^[[B"
    #define RIGHT "^[[C"
    #define LEFT "^[[D"
};
