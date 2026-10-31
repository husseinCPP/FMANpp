#pragma optimize("O2")

#include <filesystem>
#include <fstream>
#include <print>
#include <vector>
#include <string>
#include <array>

#define reset "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define GREEN_B "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[34m"

namespace Setting {};
namespace Fman {
char FMAN(const std::string color) {
    const std::vector<std::array<std::string, 1>> Banner = {
        {"\t\tFile_MANager_c++"},
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
     std::println(reset);
    return 0;
  }
};
namespace Vars {
    #define UP "^[[A"
    #define DOWN "^[[B"
    #define RIGHT "^[[C"
    #define LEFT "^[[D"
};
