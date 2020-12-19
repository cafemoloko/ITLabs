#include "homefacade.h"
#include "aircondition.h"
#include "alarm.h"
#include "homedoors.h"
#include "homewindows.h"
#include "lights.h"
#include <iostream>

HomeFacade::HomeFacade()
{
    AirCondition h_airCondition;
    Alarm h_alarm;
    HomeDoors h_doors;
    HomeWindows h_homewindows;
    Lights h_lights;
}

void HomeFacade::leaveHome()
{
    std::cout<< "Leaving home:" << std::endl;
    h_lights.turnOffLights();
    h_airCondition.turnAirConditionOFF();
    h_homewindows.closeWindows();
    h_doors.closeDoors();
    h_alarm.turnAlarmON();
    std::cout << "\n";
}

void HomeFacade::enterHome()
{
    std::cout<< "Entering home:" <<std::endl;
    h_alarm.turnAlarmOFF();
    h_doors.openDoors();
    h_airCondition.turnAirConditionON();
    h_airCondition.setAirTemp(22);
}


