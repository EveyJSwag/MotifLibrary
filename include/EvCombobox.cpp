#include "EvCombobox.h"

EvCombobox::EvCombobox(const char* a_name)
{
   name = a_name;
}

void EvCombobox::DisplayW(Widget a_widget)
{
   w_widget = XtVaCreateManagedWidget(name, xmComboBoxWidgetClass, a_widget, XmNeditable, False, NULL);
}

void EvCombobox::AddToList(const char* a_item)
{
   XmString entry = XmStringCreate((char *)a_item, XmFONTLIST_DEFAULT_TAG);
   XmComboBoxAddItem(w_widget, entry, pos, 0);
   pos++;
}

void EvCombobox::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvCombobox::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}
