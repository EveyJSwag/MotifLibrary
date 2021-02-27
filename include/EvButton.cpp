#include "EvButton.h"

EvButton::EvButton(const char* a_label)
{
   label = a_label;
}

void EvButton::Display(Widget w_base)
{
   w_widget = XtVaCreateManagedWidget(label, xmPushButtonWidgetClass, w_base, NULL);
}

void EvButton::AddCallback(Widget w, XtCallbackProc func, XtPointer caller)
{
   XtAddCallback(w_widget, XmNactivateCallback, (XtCallbackProc)func, (XtPointer)caller);
}

void EvButton::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvButton::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}