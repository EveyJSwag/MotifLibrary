#ifndef EV_LIST
#define EV_LIST
#include "EvWidget.h"

class EvList : EvWidget
{
public:
   EvList(const char*);
   EvList(const char*, Widget);
   void Display(Widget);
   const char* GetName() {return name;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
   void AddToList(const char*);
private:
   const char* name;
   Widget w_widget;
   unsigned int index;
};

#endif