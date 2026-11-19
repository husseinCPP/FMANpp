// fman++.cpp
#include "fman++.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace fs = std::filesystem;

class Operations {
public:
    bool make_file(const fs::path& p) {
        std::ofstream f(p);
        if (!f) { 
            std::println(stderr, "{}[!] Can't create file{}", RED, resetcolor); 
            return false; 
        }
        std::println("{}[+] File created{}", GREEN, resetcolor);
        return true;
    }
    bool make_dir(const fs::path& p) {
        std::error_code ec;
        if (!fs::create_directories(p, ec) && ec) {
            std::println(stderr, "{}[!] {}{}", RED, ec.message(), resetcolor);
            return false;
        }
        std::println("{}[+] Directory created{}", GREEN, resetcolor);
        return true;
    }
    bool copy(const fs::path& from, const fs::path& to) {
        std::error_code ec;
        fs::copy(from, to, fs::copy_options::recursive | fs::copy_options::overwrite_existing, ec);
        if (ec) { std::println(stderr, "{}[!] {}{}", RED, ec.message(), resetcolor); return false; }
        std::println("{}[+] Copied{}", GREEN, resetcolor);
        return true;
    }
    bool move(const fs::path& from, const fs::path& to) {
        std::error_code ec;
        fs::rename(from, to, ec);
        if (ec) { std::println(stderr, "{}[!] {}{}", RED, ec.message(), resetcolor); return false; }
        std::println("{}[+] Moved{}", GREEN, resetcolor);
        return true;
    }
    bool remove(const fs::path& p) {
        std::error_code ec;
        auto n = fs::remove_all(p, ec);
        if (ec) { std::println(stderr, "{}[!] {}{}", RED, ec.message(), resetcolor); return false; }
        std::println("{}[+] Removed {} item(s){}", GREEN, n, resetcolor);
        return true;
    }
};

int main() {
    Fman::banner(GREEN);
    Operations ops;
    std::string line;
    while (std::print(" > "), std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector<std::string> args;
        for (std::string a; iss >> a;) args.push_back(a);
        if (args.empty()) continue;

        const auto& c = args[0];
        if (c == "exit" || c == "q") break;
        else if (c == "mk"  && args.size() >= 2) ops.make_file(args[1]);
        else if (c == "mkd" && args.size() >= 2) ops.make_dir(args[1]);
        else if (c == "cp"  && args.size() >= 3) ops.copy(args[1], args[2]);
        else if (c == "mv"  && args.size() >= 3) ops.move(args[1], args[2]);
        else if (c == "rm"  && args.size() >= 2) ops.remove(args[1]);
        else std::println(stderr, "{}[!] Unknown command or missing args{}", RED, resetcolor);
    }
}


/* fman++.hpp
#pragma once
#include <filesystem>
#include <print>
#include <string_view>

inline constexpr std::string_view resetcolor = "\033[0m";
inline constexpr std::string_view RED   = "\033[31m";
inline constexpr std::string_view GREEN = "\033[32m";
inline constexpr std::string_view YELLOW= "\033[1;33m";
inline constexpr std::string_view BLUE  = "\033[34m";

namespace Fman {
inline void banner(std::string_view color) {
    std::println("{}File_Manager_C++{}", color, resetcolor);
}
}
*/