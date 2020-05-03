#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>
#include <iostream>
#include "linux_parser.h"

using std::string;
using std::vector;

class Processor {
public:
  Processor(){RefreshCPUUtilisation_();}
  float Utilization();

   // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
private:
  long user_ , prev_user_=0; 
  long nice_ , prev_nice_=0;
  long system_, prev_system_=0;
  long idle_, prev_idle_=0;
  long iowait_, prev_iowait_=0;
  long irq_, prev_irq_=0;
  long softirq_, prev_softirq_=0;
  long steal_,prev_steal_ = 0;
  long guest_, prev_guest_=0;
  long guest_nice_, prev_guest_nice_=0;

  void SetPreviousUtilisation_(){
    prev_user_ = user_; prev_nice_ = nice_; prev_system_ = system_; prev_idle_ = idle_ ; prev_iowait_ = iowait_;
    prev_irq_ = irq_; prev_softirq_ = softirq_ ;prev_guest_ = guest_; prev_guest_nice_= guest_nice_;
    prev_steal_ = steal_;
      
  }

  void RefreshCPUUtilisation_(){
      vector<string> CPUData;
      int i = 0;
      CPUData = LinuxParser::CpuUtilization();
      //Copy current values to 'prev'values
      //Get current values for CPU usage
      user_ = std::stol(CPUData[i++]);// std::cout << "user_" << user_ << "\n";
      nice_= std::stol(CPUData[i++]);//std::cout << "nice_" << nice_ << "\n";
      system_ =std::stol(CPUData[i++]);//std::cout << "system_" << system_ << "\n";
      idle_ =std::stol(CPUData[i++]);//std::cout << "idle_" << idle_ << "\n";
      iowait_ =std::stol(CPUData[i++]);//std::cout << "iowait_" << iowait_ << "\n";
      irq_ = std::stol(CPUData[i++]);//std::cout << "irq_" << irq_ << "\n";
      softirq_ = std::stol(CPUData[i++]);//std::cout << "softirq_" << softirq_ << "\n";
      guest_= std::stol(CPUData[i++]);//std::cout << "guest_" << guest_ << "\n";
      guest_nice_= std::stol(CPUData[i++]);//std::cout << "guest_nice_" << guest_nice_ << "\n";
      
      //prev_user_ = user_; prev_nice_ = nice_; prev_system_ = system_; prev_idle_ = idle_ ; prev_iowait_ = iowait_;
      //prev_irq_ = irq_; prev_softirq_ = softirq_ ;prev_guest_ = guest_; prev_guest_nice_= guest_nice_;

  };

};

#endif