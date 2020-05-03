#include "processor.h"
#include <iostream>

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() { 
  //https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux   
  SetPreviousUtilisation_();
     RefreshCPUUtilisation_();
    float PrevIdle = prev_idle_ + prev_iowait_;
    float Idle = idle_ + iowait_;
    float PrevNonIdle = prev_user_ + prev_nice_ + prev_system_ + prev_irq_ + prev_softirq_ +  prev_steal_;
    float NonIdle = user_ + nice_ + system_ + irq_ + softirq_  + steal_;
    float PrevTotal  = PrevIdle + PrevNonIdle;
    float Total = Idle+ NonIdle;

    float Total_D = (float)Total - (float)PrevTotal;
    float Idle_D = float(Idle) - (float)PrevIdle;

  return  (Total_D - Idle_D) / Total_D; 

    }