#include "fman++.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace FMAN_STD {
   using std::cin;
   using std::cout;
   using std::cerr;
   using std::endl;
   using std::string;
   using std::vector;
   using std::array; 
   using std::ofstream;
   using std::ifstream;
};
namespace fs = std::filesystem;
using namespace FMAN_STD;

   ofstream w_file; // write
   ifstream r_file; // read 
   ofstream out_file; //output file
   ifstream in_file; //input file

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
   char make_f() {
      w_file.open(Fname);
      if(!w_file.is_open()) {
         cerr << RED<<"[!] Error: " << resetcolor<<"Can`t create the file!\n";
      } else {
         cout << GREEN<<"[+] fileCreate... Finished\n" << resetcolor;
         w_file.close();
      }
      return 0;
   }
   char make_F() {
      
      return 0;
   }
   char copy_fF(const fs::path& from, const fs::path& to) { 
      if(1 == 1) {
         cerr << RED<<"[!] Error: ";
      }
      else {
         cout << GREEN<<"[+] fileCopy... Finished\n" << resetcolor;
      }
      return 0;
   }
   char move_fF(const fs::path& from, const fs::path& to) {
      return 0;
   }
   char remove_fF() {
      return 0;
   }  
};
/*
class Cli {
public:
};
*/
char help() {
   cout << YELLOW << "\t\t===COMMANDS===\n";
   cout << GREEN<< " mk" << resetcolor<<"\t-- to make file or folder.\n";
   cout << GREEN<< " cp" << resetcolor<<"\t-- to copy file or folder.\n";
   cout << GREEN<< " mv" << resetcolor<<"\t-- to move(cut) file or folder.\n";
   cout << GREEN<< " rm" << resetcolor<<"\t-- to remove(delete) file or folder.\n"  << resetcolor;
   return 0;  
}

int main(){
   Fman::FMAN(YELLOW);
   
   Operations term;

   string cmd;
   for(int i = 0; i <= 10; i++) {
      cout << " > ";
      cin >> cmd;
      if(cmd == "mk") {
         term.make_f();
      }
      else if(cmd == "cp") {
         term.copy_fF("/tmp","/mnt");
      }
      else if(cmd == "mv") {      
         term.move_fF("/tmp","/mnt");
      }
      else if(cmd == "rm") {
         term.remove_fF();
      }
      else if(cmd == "help" || cmd == "?"|| cmd == "^[[A") {
         help();
      }
      else {
        cerr << RED<<"[!] Error: " << resetcolor<<"unknown command.\n";
        cout << "\ttype " << BLUE<<"\"help / ?\""
             << resetcolor<<" to see commands list.\n";
      }
   }
   return 0;
}
