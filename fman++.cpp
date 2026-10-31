#include "fman++.hpp"

#include <iostream>

namespace FMAN_STD {
   using std::cin;
   using std::cout;
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

string Fname;

class Operations {
private:
   void file_status(const fs::path& path, fs::file_status status) {
      cout << path << endl;
      file_status("~/", fs::status("~/"));
   }
   void file_ownership () {   // Change file ownership
      try {
         fs::path file_path("example_file.txt");
         fs::perms perms(file_perm_mask::read | file_perm_mask::write | file_perm_mask::user);
         fs::chown(file_path, perms);
      } 
      catch (const std::fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
      }
   }
   inline int current_dir{
      return fs::current_path();
   }

public:
   char make_f() {   
      cout << " > ";
      w_file.open(Fname);
      if(!w_file.is_open()) {
         cerr << RED<<"[!] error: " 
              << reset<<"Can`t create the file!\n";
         return 1;
      }
      cout << GREEN<<"[+] fileCreate... Finished\n" << reset;
      w_file.close();
      return 0;
   }
   char make_F() {
      fs::create_directories(Fname);
      return 0;
   }
   char copy_fF(const fs::path& path) { 
      cout << " > ";
      if(in_file) {
         cerr << RED<<"[!] error: "
      }
      const auto copyOptions = fs::copy_options::update_existing
               | fs::copy_options::recursive
               | fs::copy_options::directories_only;
      cout << GREEN<<"[+] fileCopy... Finished\n" << reset;
      return 0;
   }
   char move_fF(const fs::path& path) {
      cout << " > ";
      return 0;
   }
   char remove_fF() {
      cout << " > ";
      return 0;
   }  
};

class CLI {
public:
   char help() {
      cout << YELLOW << "\t\t===COMMANDS===\n" << reset;
      cout << GREEN<< " mk" << reset<<"\t- to make file or folder.";
      cout << GREEN<< " cp" << reset<<"\t- to copy file or folder.\n";
      cout << GREEN<< " mv" << reset<<"\t- to move(cut) file or folder.\n";
      cout << GREEN<< " rm" << reset<<"\t- to remove(delete) file or folder.\n";
      return 0;  
   }
   char cmd_input(string cmd) {
         if(cmd == "mk") {
            cout << " enter_"; cin >> Fname;
            make_file();
         }
         else if(cmd == "cp") {
            cout << " enter_";
            copy_f();
         }
         else if(cmd == "mv") {      
            cout << " enter_";      
            move_f();
         }
         else if(cmd == "rm") {
            remove_f();
         }
         else if(cmd == "help" || cmd == "?") {
            help();
         }
         else {
           cerr << RED<<"[!] error: " << reset<<"unknown command?\n";
           cout << "\t+ type " << BLUE<<"\"help / ?\""
                << reset<<" to see commands list\n";
         }
      return 0;
   }
};

int main(){
   Fman::FMAN(GREEN);
   CLI term1;

   for(int i = 0; i <= 10; ++i) {
      cout << " cmd> \n"; 
      term1.cmd_input("mk");

   return 0;
}
