#include "ncurses_display.h"
#include "system.h"
#include <iostream>
#include "Test_LParser.h"

int main() {
  
  string CheckParserOutput = "N";  //allow the user to switch to a debug mode to check the LinuxParser output
  std::cout <<"Do you want to check the LinuxParser output? (Y/N) \n";
  std::cin >> CheckParserOutput ;
  
  if (CheckParserOutput != "Y"){
  System system;
  NCursesDisplay::Display(system);
  }
  else
  {
    LPTestScript();
  }
  
}