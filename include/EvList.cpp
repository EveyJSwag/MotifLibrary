#include "EvList.h"
#include <Xm/List.h>

EvList::EvList(const char* a_name)
{
   name = a_name;
}

EvList::EvList(const char* a_name, Widget a_widget)
{
   name = a_name;
   w_widget = a_widget;
}

void EvList::Display(Widget a_widget)
{
   w_widget = XtVaCreateManagedWidget(name, xmListWidgetClass, a_widget, NULL);
}

void EvList::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvList::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}

void EvList::AddToList(const char* elem)
{
   XmString xm_elem = XmStringCreate((char *)elem, XmFONTLIST_DEFAULT_TAG);
   XmListAddItem(w_widget, xm_elem, index);
   XmStringFree(xm_elem);
   index++; 
}