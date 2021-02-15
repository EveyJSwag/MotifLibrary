#ifndef EV_FORM
#define EV_FORM

#include <Xm/Xm.h>
#include <Xm/Form.h>
#include <Xm/FormP.h>
#include "EvWidget.h"
#include <iostream>
#include <string>

class EvForm : EvWidget
{

public:
   EvForm(const char* a_name);
   void Display(Widget);
   const char* GetName() {return name;}
   Widget GetWidget() {return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
private:
   const char* name;
   Widget w_widget;
};

#endif /*EV_FORM*/