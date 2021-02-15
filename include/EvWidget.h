#ifndef EV_WIDGET
#define EV_WIDGET

#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include "EvApp.h"

class EvWidget : EvApp
{
public: 
   EvWidget();
   void RealizeWidget();
   Widget w_widget;
   void AppInitialize();
   virtual void SetPos(unsigned int, unsigned int);
   virtual void SetSize(unsigned int, unsigned int);
private:
   const char* name = "base widget";
};

#endif /*EV_WIDGET*/