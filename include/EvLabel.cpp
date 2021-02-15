#include "EvLabel.h"
#include <Xm/Label.h>

EvLabel::EvLabel(const char* a_name, const Widget a_widget)
{
    name = a_name;
    w_widget = a_widget;
}

EvLabel::EvLabel(const char* a_name)
{
   name = a_name;
}

void EvLabel::Display(Widget a_widget)
{
   w_widget = XtVaCreateManagedWidget(name, xmLabelWidgetClass, a_widget, NULL);
}

void EvLabel::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvLabel::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}

void EvLabel::SetName(const char* a_name)
{
   XmString xm_label = XmStringCreate((char *)a_name, XmFONTLIST_DEFAULT_TAG);
   XtVaSetValues(w_widget, XmNlabelString, xm_label, NULL);
   XmStringFree(xm_label);
   name = a_name;
}
