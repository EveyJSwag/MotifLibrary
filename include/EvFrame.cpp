#include "EvFrame.h"

EvFrame::EvFrame(const char* a_name)
{
   name = a_name;
}

void EvFrame::DisplayW(Widget w_base)
{
   w_widget = XtVaCreateManagedWidget(name, xmFrameWidgetClass, w_base, NULL);
}

void EvFrame::SetPos(unsigned int x, unsigned int y)
{

}

void EvFrame::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}
