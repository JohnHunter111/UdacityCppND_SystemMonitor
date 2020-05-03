 #include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    //Code idea from  www.programmingnotes.org/?p=2062
    int trackTime = seconds;
    int Hrs=0, Mins=0, Secs = 0;
    Hrs = seconds / 3600;
    trackTime = seconds % 3600;

    Mins = trackTime / 60;
    trackTime = trackTime % 60;

    Secs = trackTime;

    //Adjust for a leading zero on numbers less than 10 to maintain format
     std::string tempHrs = std::to_string(Hrs);
    if (Hrs < 10) {tempHrs = '0' + tempHrs;};   
    
    std::string tempMin = std::to_string(Mins);
    if (Mins < 10) {tempMin = '0' + tempMin;};
    std::string tempSecs = std::to_string(Secs);
    if (Secs < 10) {tempSecs = '0' + tempSecs;};   

    return tempHrs + ":" + tempMin + ":" + tempSecs;
    
    }

string Format::KBtoMB(std::string InputData){
return std::to_string(std::stol(InputData) / 1024);

}