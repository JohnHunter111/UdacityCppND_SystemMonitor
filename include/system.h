#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "linux_parser.h"

class System {
 public:
  //CONSTRUCTOR
  System(): operatingsystem_(LinuxParser::OperatingSystem()), kernel_(LinuxParser::Kernel()) {
    UpdateProcesses();
  } 

  Processor& Cpu();                   // TODO: See src/system.cpp
  std::vector<Process>& Processes();  // TODO: See src/system.cpp
  float MemoryUtilization();          // TODO: See src/system.cpp
  long UpTime();                      // TODO: See src/system.cpp
  int TotalProcesses();               // TODO: See src/system.cpp
  int RunningProcesses();             // TODO: See src/system.cpp
  std::string Kernel();               // TODO: See src/system.cpp
  std::string OperatingSystem();      // TODO: See src/system.cpp

  void UpdateProcesses(){
    std::vector<int> pids = LinuxParser::Pids();
    processes_.clear();
    for (std::size_t i = 0;i < pids.size();i++){
      //std::cout<< i <<"\n";
      processes_.push_back(Process(pids[i]));
    }
    SortProcesses();
  }

// TODO: Define any necessary private members

 
 private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
  std::string operatingsystem_;
  std::string kernel_;
 void SortProcesses() {
     std::sort(processes_.begin(),processes_.end());
  }
  


};

#endif