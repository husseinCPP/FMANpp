#include "fman++.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace FMAN_STD {
   using std::cin;
   using std::cout;
   using std::cerr;
   using std::endl;
   using std::println;
   using std::print;
   using std::string;
   using std::vector;
   using std::array; 
   using std::ofstream;
   using std::ifstream;
   using std::stringstream;
};
namespace fs = std::filesystem;
using namespace FMAN_STD;

char help() {
   cout << YELLOW << "\t\t===COMMANDS===\n";
   cout << GREEN<< " mk" << resetcolor<<"\t-- to make file or folder.\n";
   cout << GREEN<< " cp" << resetcolor<<"\t-- to copy file or folder.\n";
   cout << GREEN<< " mv" << resetcolor<<"\t-- to move(cut) file or folder.\n";
   cout << GREEN<< " rm" << resetcolor<<"\t-- to remove(delete) file or folder.\n"  << resetcolor;
   return 0;  
}

int main(){
   Fman::banner(GREEN);
   Operations ops;
   string cmd;
   
   while(print(" > "), getline(cin, cmd)) {
      stringstream ss(cmd);
      vector<string> argv;

      if(cmd == "q" || cmd == "quit") {
         println("{} Bye! ", YELLOW);
         break;
      }  else if(cmd == "mk") ops.create_file();
         else if(cmd == "mk") ops.create_directory();
         else if(cmd == "cp") ops.copy_file();
         else if(cmd == "mv") ops.move_file();
         else if(cmd == "rm") ops.delete_file();
         else if(cmd == "help" || cmd == "?") help();
      else {
         println(stderr, "{}[!] Error:{} {} {} is unknown command.", RED, YELLOW, cmd, resetcolor);
         println("\tType: {}\"help or ?\"{} to see commands list.", BLUE, resetcolor);
      }
   }
   return 0;
}
