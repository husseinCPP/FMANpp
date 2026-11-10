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

};
namespace fs = std::filesystem;
using namespace FMAN_STD;

   ifstream r_file; // read 
   ofstream out_file; //output file


class Operations {
private:
   char file_status(const fs::path& path, fs::file_status status) {
      cout << path << endl;
      file_status("~/", fs::status("~/"));
      return 0;
   } 
   inline string current_dir() {
      return fs::current_path();
   }

/*****************************************************/
public:
   string Fname;
   bool make_file(const fs::path& path) {
      ofstream w_file(path);
      if(!w_file) {
         println(stderr,"{}[!] Error: Can`t create the file{}", RED, resetcolor);
         return false;
      }
      println("{}[+] fileCreation... Completed.{}", GREEN, resetcolor);
      return true;
   }
    bool make_dir(const fs::path& path) {
        std::error_code ec;
        if (!fs::create_directories(path, ec) && ec) {
            println(stderr, "{}[!] Error: Can`t create the folder{}", RED, ec.message(), resetcolor);
            return false;
        }
        println("{}[+] Directory created{}", GREEN, resetcolor);
        return true;
    }
   bool copy_fF(const fs::path& from, const fs::path& to) { 
      if(1 == 1) {
         cerr << RED<<"[!] Error: ";
      }
      else {
         cout << GREEN<<"[+] fileCopy... Finished\n" << resetcolor;
      }
      return 0;
   }
   bool move_fF(const fs::path& from, const fs::path& to) {
      return 0;
   }
   bool remove_fF() {
      return 0;
   }  
};
/*class Cli {
public:
};*/
char help() {
   cout << YELLOW << "\t\t===COMMANDS===\n";
   cout << GREEN<< " mk" << resetcolor<<"\t-- to make file or folder.\n";
   cout << GREEN<< " cp" << resetcolor<<"\t-- to copy file or folder.\n";
   cout << GREEN<< " mv" << resetcolor<<"\t-- to move(cut) file or folder.\n";
   cout << GREEN<< " rm" << resetcolor<<"\t-- to remove(delete) file or folder.\n"  << resetcolor;
   return 0;  
}

int main(){
   Fman::FMAN(GREEN);
   
   Operations ops;

   string cmd;
   
   while(print(" > "), getline(cin, cmd)) {

      if(cmd == "q" || cmd == "quit") break;
      if(cmd == "mk") ops.make_file("/tmp");
      else if(cmd == "cp") ops.copy_fF("/tmp","/mnt");
      else if(cmd == "mv") ops.move_fF("/tmp","/mnt");
      else if(cmd == "rm") ops.remove_fF();
      else if(cmd == "help" || cmd == "?") help();
      else {
         println(stderr, "{}[!] Error:{} {} {} is unknown command.", RED, YELLOW, cmd, resetcolor);
         println("\tType: {}\"help or ?\"{} to see commands list.", BLUE, resetcolor);
      }
   }
   return 0;
}
