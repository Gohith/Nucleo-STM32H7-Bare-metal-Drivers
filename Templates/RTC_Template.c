/**
 *  This file shows how to use the RTC peripheral driver library
 *  to Initialize, SET, GET the DAY, TIME
 */


#include<RTC.h>

RTC_date_t dateGet, dateSet = {
    .day = 23,
    .month = 2,
    .year = 26,
    .weekday = 3
};

RTC_time_t timeGet, timeSet = {
    .hours = 15,
    .minutes = 25,
    .seconds = 00
};

int main(){
    // Init the LSE clock to RTC
    RTC_Init_LSE();
    // Set the time
    RTC_Set_Time(&timeSet);
    // Get the current time
    RTC_Get_Time(&timeGet );
    // Set the date
    RTC_Set_Date(&dateSet);
    // Get the current date
    RTC_Get_Date(&dateGet);
    return 0;
}