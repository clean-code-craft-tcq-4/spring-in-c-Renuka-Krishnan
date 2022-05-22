#include "stats.h"
#include "math.h"
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


/*
Function name : check_and_alert
Formal parameters : [in]maxThreshold
                    [in]alerters
                    [in]computedStats
Function Description : This function checks if the max value in computedStats is greater than maxThreshold. If yes, call the  alerter functions.
*/
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) 
{
     
 if(computedStats.max > maxThreshold)
 {
     alerters[0]();
     alerters[1]();
 }
}

/*
Function name : compute_statistics
Formal parameters : [in]numberset
                    [in]setlength
Function Description : This function calculates the maximum, minimum and average of the given numberset.
*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i=0;
    float Total = 0;
    if(setlength == 0)
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
    }
    else
    {
        s.min= numberset[0];
        s.max = numberset[0];
     for(i=0;i<setlength;i++)
         {
          if(numberset[i] < s.min)
          s.min= numberset[i];

          if(numberset[i] > s.max )
          s.max = numberset[i];  
         
         Total = Total + numberset[i];
         }
       s.average =  Total/setlength;
    }
    return s;
}


