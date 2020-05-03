#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <unistd.h>
#include "linux_parser.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
public:
  Process(int pid):pid_(pid){UpdateProcessInfo();}
  int Pid();                              // TODO: See src/process.cpp
  std::string User();                     // TODO: See src/process.cpp
  std::string Command();                  // TODO: See src/process.cpp
  float CpuUtilization();                 // TODO: See src/process.cpp
  std::string Ram();                      // TODO: See src/process.cpp
  long int UpTime();                      // TODO: See src/process.cpp
  bool operator<(Process const &a) const; // TODO: See src/process.cpp
  float Ram_();
  //Updates the information that will usually be static during the life of the process
  void UpdateProcessInfo(){
      user_ = LinuxParser::User(pid_);
      command_ = LinuxParser::Command(pid_);
      systemHz_ = sysconf(_SC_CLK_TCK);
      uptime_ = LinuxParser::UpTime(pid_);  //assuming Uptime of th eprocess doesn't change
      UpdateRAM();
      UpdateCPUUtilisation();
  }
  // TODO: Declare any necessary private members
private:
  int pid_;
  std::string user_;
  std::string command_;
  int systemHz_;
  float cpuUtil_;
  float ram_; 
  long int uptime_;
  void UpdateRAM(){
    ram_ = std::stof(LinuxParser::Ram(Pid()));
  } 
  void UpdateCPUUtilisation(){
    cpuUtil_ = Process::CpuUtilization();
  }
};

#endif