#include "EvArt.h"
#include <Xm/DrawingA.h>

EvArt::EvArt(const char* a_name)
{
   name = a_name;
}

void EvArt::DisplayW(Widget w_base)
{
   w_widget = XtVaCreateManagedWidget(name, xmDrawingAreaWidgetClass, w_base, NULL);
   window = XtWindow(w_widget);
   XtVaGetValues(w_widget, XmNuserData, &grph_ctx, NULL);

}

void EvArt::AddCallback(Widget w, XtCallbackProc func, XtPointer caller)
{
   XtAddCallback(w_widget, XmNactivateCallback, (XtCallbackProc)func, (XtPointer)caller);
}

void EvArt::SetPos(unsigned int x, unsigned int y)
{
   // *******************************************
   // * Widgets will be positioned from top left
   // *******************************************
   XtVaSetValues(w_widget, XmNtopAttachment, XmATTACH_FORM, XmNleftAttachment, XmATTACH_FORM, XmNleftOffset, x, XmNtopOffset, y, NULL);
}

void EvArt::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}

void EvArt::DrawSquare(coord t, coord b, coord l, coord r)
{

}

void EvArt::DrawCircle(coord center, unsigned int radius)
{

}

void EvArt::DrawLine(coord c1, coord c2)
{

}

void EvArt::DrawArc(coord c1, coord c2)
{

}