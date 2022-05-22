#include "stats.h"
#include "math.h"
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter()
{
     emailAlertCallCount++;
}
void ledAlerter()
{
    ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) 
{
     
 if(computedStats > maxThreshold)
 {
     alerters[0]();
     alerters[1]();
 }
}
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


