#include "EvDropdown.h"
#include <Xm/DropDown.h>
#include <Xm/Label.h>
#include <Xm/List.h>

EvDropdown::EvDropdown(const char* a_name)
{
   name = a_name;
}

void EvDropdown::Display(Widget a_widget)
{
   w_widget = XtVaCreateManagedWidget(name, xmDropDownWidgetClass, a_widget, NULL);
   w_evlist =  new EvList ("list", XmDropDownGetList(w_widget));
   w_evlabel = new EvLabel("label", XmDropDownGetLabel(w_widget));
}

void EvDropdown::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvDropdown::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}

void EvDropdown::SetLabel(const char* a_label)
{
   w_evlabel->SetName(a_label);
}

void EvDropdown::AddToList(const char* item)
{
   w_evlist->AddToList(item);
}