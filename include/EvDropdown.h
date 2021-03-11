#ifndef EV_DROPDOWN
#define EV_DROPDOWN

#include "EvWidget.h"
#include "EvList.h"
#include "EvLabel.h"
#include "EvApp.h"
#include "EvButton.h"

class EvDropdown : EvWidget
{
public:
   EvDropdown(const char*);
   void DisplayW(Widget);
   const char* GetName() {return name;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);

   // ****************************************
   // * Dropdown specific methods
   // ****************************************
   void AddToList(const char*);
   void SetLabel(const char*);

private:
   Widget w_widget;
   // ****************************************
   // * Wrapper classes for dropdown widgets
   // ****************************************
   EvList*      w_evlist;
   EvLabel*     w_evlabel;
   // * Will need a text class too...

   const char*  name;
   ArgList      a_list;

   unsigned int index;
};

#endif /* EV_DROPDOWN */
