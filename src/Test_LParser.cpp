#include "linux_parser.h"
#include <string>
#include <iostream>
#include "processor.h"
#include "system.h"

using std::string;
//using std:
// test the linuxparser modules to see what they produce
void LPTestScript(){

std::size_t i = 0;
std::vector<std::string> CPUUsage = LinuxParser::CpuUtilization();
for (i =0; i < CPUUsage.size();i++){
    std::cout << "CPU Usage element " << i << ": " << CPUUsage[i] << "\n";
};

Processor cpu;
std::cout << cpu.Utilization() << "\n" ;

float MemUsage  = LinuxParser::MemoryUtilization(); 
std::cout << "Memory used: " << MemUsage << "\n";  
  
  
long SystemUp = LinuxParser::UpTime(); 
std::cout << "System uptime: " << SystemUp << "\n";
  
string OS = LinuxParser::OperatingSystem();
std::cout << "Operating System: " << OS << "\n";
  
string kernel = LinuxParser::Kernel();
std::cout << "OS Kernel: " << kernel << "\n";  

std::vector<int> pids = LinuxParser::Pids();
for (std::size_t i =0; i < pids.size();i++){
	std::cout << "ProcessID " << i << ": " << pids[i] << "\n"; 
}

std::string uid = LinuxParser::Uid(pids[0]);
std::cout << "Uid for PID "<< pids[0] <<": " << uid << "\n"; 

std::string user = LinuxParser::User(pids[0]);
std::cout << "User for PID "<< pids[0] <<": " << user << "\n"; 

std::string ram = LinuxParser::Ram(pids[0]);
std::cout << "RAM used for PID "<< pids[0] <<": " << ram << "KB \n"; 

std::string command = LinuxParser::Command(pids[0]);
std::cout << "Command line for PID "<< pids[0] <<": " << command << "\n"; 

System sys;
std::vector<Process> proc = sys.Processes();

for (std::size_t i =0;i<proc.size();i++){
	std::cout << proc[i].Pid() << ":  " << proc[i].UpTime() << '\n';
}


//std::vector<std::string> Test = LinuxParser::StringToVector("root:x:0:0:root:/root:/bin/bash",":");
//for (int i =0; i < Test.size();i++){
	//std::cout << "" << i << ": " << Test[i] << "\n"; 
//}

//long jiffies = LinuxParser::Jiffies();
//std::cout << "No. of Jiffies: " << jiffies << "\n";     
    
};