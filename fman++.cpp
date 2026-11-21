#include "fman++.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace FMAN_STD {
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::print;
using std::println;
using std::string;
using std::stringstream;
using std::vector;
}; // namespace FMAN_STD
using namespace FMAN_STD;

char help() {
  cout << YELLOW << "\t\t===COMMANDS===\n";
  cout << GREEN << " mk" << resetcolor << "\t-- to make file or folder.\n";
  cout << GREEN << " cp" << resetcolor << "\t-- to copy file or folder.\n";
  cout << GREEN << " mv" << resetcolor << "\t-- to move(cut) file or folder.\n";
  cout << GREEN << " rm" << resetcolor
       << "\t-- to remove(delete) file or folder.\n"
       << resetcolor;
  return 0;
}

int main(int argc, char *argv[]) {
  Fman::banner(GREEN);
  // * a Object from class Operations in fman++.hpp
  Operations ops;
  // std::vector<std::string> args(argv + 1, argv + argc);
  string cmd;

  while (print(" > "), getline(cin, cmd)) {
    stringstream ss(cmd);

    if (cmd == "q" || cmd == "quit")
      println("{} Bye! ", YELLOW);
    break;
    else if (cmd == "mk") ops.create_file();
    else if (cmd == "mkd") ops.create_directory();
    else if (cmd == "cp") ops.copy_file();
    else if (cmd == "mv") ops.move_file();
    else if (cmd == "rm") ops.delete_file();
    else if (cmd == "help" || cmd == "?") help();
    else println(stderr, "{}[!] Error:{} {} {} is unknown command.", RED,
                 YELLOW, cmd, resetcolor);
    println("\tType: {}\"help or ?\"{} to see commands list.", BLUE,
            resetcolor);
  }
  return 0;
}
