#include "EvWidget.h"

EvWidget::EvWidget()
{
}

void EvWidget::RealizeWidget()
{
   XtRealizeWidget(w_widget);
}
void EvWidget::AppInitialize()
{
   int argc = 0;
   char** argv;
   w_widget = XtVaAppInitialize(&(w_base_app_p), "base_widget", NULL, 0, &argc, argv, NULL, NULL);
}

void EvWidget::SetPos(unsigned int x, unsigned int y)
{
   // *************************************
   // * Virtual declaration
   // *************************************
}

void EvWidget::SetSize(unsigned int height, unsigned int width)
{
   XtVaSetValues(w_widget, XmNheight, height, XmNwidth, width, NULL);
}
