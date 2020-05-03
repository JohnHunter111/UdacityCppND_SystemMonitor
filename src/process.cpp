#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "format.h"
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() {
  //https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  
  std::vector<std::string> CPUdata = LinuxParser::CpuUtilization(Pid());
  float uTime = 0.0, sTime =0.0, cuTime = 0.0, csTime =0.0;
  long int startTime  =uptime_;
  //int Hz = systemHz_;
  uTime = stof(CPUdata[13]); sTime = stof(CPUdata[14]); cuTime = stof(CPUdata[15]); csTime = stof(CPUdata[16]);
  
    
  float total_time = uTime + sTime +cuTime + csTime;
  float uptime  = LinuxParser::UpTime();
  float seconds = uptime - (startTime / systemHz_)  ;
  float cpu_usage = ((total_time / systemHz_)/seconds);

  return cpu_usage; }

// DONE: Return the command that generated this process
string Process::Command() { return command_; }

// DONE: Return this process's memory utilization
string Process::Ram() { 
  UpdateRAM();
  return Format::KBtoMB(to_string(ram_)); 
}
//function to expose the private varibale contents for debugging
float Process::Ram_(){
  return ram_;
}
// DONE: Return the user (name) that generated this process
string Process::User() { return user_; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { 
  return LinuxParser::UpTime() - (uptime_/systemHz_) ;
   
   }

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    //Sort on memory
    //return ram_ < a.ram_; 
    return this->ram_ > a.ram_;
    //return this->cpuUtil_ > a.cpuUtil_;
    //return this->uptime_ < a.uptime_;
   }