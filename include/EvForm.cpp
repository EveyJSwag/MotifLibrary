#include "EvForm.h"
EvForm::EvForm(const char* a_name)
{
    name = a_name;
}

void EvForm::Display(Widget w_base)
{
    w_widget = XtVaCreateManagedWidget(name, xmFormWidgetClass, w_base, NULL);
}

void EvForm::SetPos(unsigned int x, unsigned int y)
{

}

void EvForm::SetSize(unsigned int height, unsigned int width)
{
    XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}