#ifndef EV_LABEL
#define EV_LABEL

#include "EvWidget.h"

class EvLabel : EvWidget
{
public:
   EvLabel(const char*);
   EvLabel(const char*, const Widget);
   void DisplayW(Widget);
   const char* GetName() {return name;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
   void SetName(const char*);

private:
   const char* name;
   Widget w_widget;
};

#endif /*EV_LABEL*/
