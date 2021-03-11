#ifndef EV_COMBOBOX
#define EV_COMBOBOX

#include <Xm/Xm.h>
#include <Xm/ComboBox.h>
#include "EvWidget.h"
#include <iostream>
#include <string>

//typedef void (*ButtonCallback) (Widget, XtPointer, XmPushButtonCallbackStruct*);

class EvCombobox : EvWidget
{
public:
   EvCombobox(const char*);
   void DisplayW(Widget);
   const char* GetName() {return name;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);

   // *********************************
   // * Combobox specific functions : )
   // *********************************
   void AddToList(const char*);
   void AddListToList(const char*[]);
   void DeleteFromList(int);

private:
   int pos;
   const char* name;
   Widget w_widget;
   //ButtonCallback callback;
};

#endif /*EV_COMBOBOX*/
