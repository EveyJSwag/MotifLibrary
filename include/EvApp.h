#ifndef EV_APP
#define EV_APP

#include <Xm/Xm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class EvApp
{
public:
   EvApp();
   static void MainLoop();

protected:
   // *************************************
   // * There will only ever be 'one' app
   // *************************************
   static XtAppContext w_base_app_p;
private:
   const char* name;
};


#endif /*EV_APP*/