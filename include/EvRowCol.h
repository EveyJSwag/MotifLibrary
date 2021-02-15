#ifndef EV_ROWCOL
#define EV_ROWCOL

#include "EvWidget.h"
#include <Xm/Xm.h>
#include <Xm/RowColumn.h>
class EvRowCol : EvWidget
{
public:
  EvRowCol(const char*);   
  Widget GetWidget(){return w_widget;}
  void SetPos(unsigned int, unsigned int);
  void SetSize(unsigned int, unsigned int);
  void Display(Widget);
private:
  Widget w_widget;
  const char* name;
};


#endif /*EV_ROWCOL*/