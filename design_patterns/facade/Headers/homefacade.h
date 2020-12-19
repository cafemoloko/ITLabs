#ifndef HOMEFACADE_H
#define HOMEFACADE_H
#include "aircondition.h"
#include "alarm.h"
#include "homedoors.h"
#include "homewindows.h"
#include "lights.h"
/*
- Zaimplementuj fasadę do sterowania inteligentnego domu:
- leaveHome() – wyłączenie świateł, klimatyzacji, zamykanie okien, drzwi
- enterHome – otwarcie drzwi, włączenie świateł,
- dowolną swoją komendę
- Zaimplementuj alarm dla domu i użyj go przy wyjściu i wejściu.
*/


class HomeFacade
{
    AirCondition h_airCondition;
    Alarm h_alarm;
    HomeDoors h_doors;
    HomeWindows h_homewindows;
    Lights h_lights;

public:
    HomeFacade();
    void leaveHome();
    void enterHome();
};

#endif // HOMEFACADE_H
