#ifndef EV_FRAME
#define EV_FRAME

#include <Xm/Xm.h>
#include <Xm/Frame.h>
#include <iostream>
#include <string>

#include "EvWidget.h"

class EvFrame : EvWidget
{
public:
   EvFrame(const char* a_name);
   void DisplayW(Widget);
   const char* GetName() {return name;}
   Widget GetWidget() {return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
private:
   const char* name;
   Widget w_widget;
};

#endif /*EV_FRAME*/
