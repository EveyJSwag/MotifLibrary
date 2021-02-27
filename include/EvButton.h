#ifndef EV_BUTTON
#define EV_BUTTON

#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include "EvWidget.h"
#include <iostream>
#include <string>

typedef void (*ButtonCallback) (Widget, XtPointer, XmPushButtonCallbackStruct*);

class EvButton : EvWidget
{

public:
   EvButton(const char* a_label);
   void Display(Widget);
   void AddCallback(Widget w, XtCallbackProc func, XtPointer caller);
   const char* GetLabel() {return label;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
private:
   const char* label;
   Widget w_widget;
   ButtonCallback callback;
};

#endif /*EV_BUTTON*/