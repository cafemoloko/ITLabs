#include <iostream>
#include "homefacade.h"

using namespace std;

int main()
{

    HomeFacade *homeFacade = new HomeFacade();

    homeFacade->leaveHome();
    homeFacade->enterHome();


    return 0;
}
