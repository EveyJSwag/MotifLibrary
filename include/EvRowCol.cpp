#include "EvRowCol.h"

EvRowCol::EvRowCol(const char* a_name)
{
   name = a_name;
}

void EvRowCol::DisplayW(Widget w_base)
{
   w_widget = XtVaCreateManagedWidget(name, xmRowColumnWidgetClass, w_base, NULL);
}

void EvRowCol::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvRowCol::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}
