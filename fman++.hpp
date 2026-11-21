#pragma once

#include <array>
#include <filesystem>
#include <print>
#include <string_view>
#include <system_error>
#include <vector>
namespace fs = std::filesystem;

inline constexpr std::string_view resetcolor = "\033[0m";
inline constexpr std::string_view RED = "\033[31m";
inline constexpr std::string_view GREEN = "\033[32m";
inline constexpr std::string_view GREEN_B = "\033[1;32m";
inline constexpr std::string_view YELLOW = "\033[1;33m";
inline constexpr std::string_view BLUE = "\033[34m";

struct FileError : public std::runtime_error {
  FileError(const std::string &message) : std::runtime_error(message) {}
};

struct DirectoryError : public std::runtime_error {
  DirectoryError(const std::string &message) : std::runtime_error(message) {}
};

namespace Fman {
inline void banner(const std::string_view color) {
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
  for (const auto &line : Banner) {
    std::println("{}", line[0]);
  }
  std::println(resetcolor);
}
};

class Operations {
private:
  fs::path create_file(const fs::path &path) {
    try {
      fs::create_file(path);
      return path;
    } catch (const std::filesystem_error &err) {
      throw FileError("Error creating file: " + e.what());
    }
  }
  fs::path create_directory(const fs::path &path) {
    try {
      fs::create_directories(path);
      return path;
    } catch (const std::filesystem_error &err) {
      throw DirectoryError("Error creating directory: " + e.what());
    }
  }
  fs::path get_parent_directory(const fs::path &path) {
    if (path.empty()) {
      throw std::invalid_argument("Path cannot be empty");
    }
    return fs::parent_path(path);
  }
  fs::path get_file_name(const fs::path &path) {
    if (path.empty()) {
      throw std::invalid_argument("Path cannot be empty");
    }
    return fs::path(path.filename());
  }

public:
  void create_directory(const fs::path &path) { create_directory(path); }
  void create_file(const fs::path &path) { create_file(path); }
  void copy_file(const fs::path &source, const fs::path &destination) {}
  void move_file(const fs::path &source, const fs::path &destination) {}
  void delete_file(const fs::path &path) {}
  bool file_exists(const fs::path &path) { return 0; }
  bool directory_exists(const fs::path &path) { return 0; }
  bool rename_file() {
    fs::path("/foo").replace_filename("bar");
    return true;
  }
  std::vector<fs::path> list_files(const fs::path &path) {}
  std::vector<fs::path> list_directories(const fs::path &path) {}
  fs::path get_current_directory() {}
};
