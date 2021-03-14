#include "EvArt.h"
#include <Xm/DrawingA.h>
#include <sstream>

EvArt::EvArt(const char* a_name)
{
   name = a_name;
}

void EvArt::DisplayW(Widget w_base)
{
   w_widget = XtVaCreateManagedWidget(name, xmDrawingAreaWidgetClass, w_base, XmNheight, 100, XmNwidth, 400, NULL);
   display = XtDisplay(w_widget);
   screen_ptr = XtScreen(w_widget);
   window = XtWindow(w_widget);

   XtVaSetValues(w_base, XmNworkWindow, w_widget, NULL);
   XtAddCallback(w_widget, XmNexposeCallback, (XtCallbackProc)EvArt::ExposeArt, (XtPointer)this);
   grph_ctx_val.foreground = BlackPixelOfScreen(screen_ptr);
   grph_ctx = XCreateGC(display, RootWindowOfScreen(screen_ptr), GCForeground, &grph_ctx_val);
   long int fill_pixel = 1;
   
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

void EvArt::DrawSquare(coord t, coord b)
{
   XDrawRectangle(display, window, grph_ctx, t.x, t.y, (b.y - t.y), (b.x - t.x));
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

void EvArt::ExposeArt(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk)
{
   EvArt* obj = (EvArt*)client_data;
   coord t = {2,2};
   coord b = {80, 300};
   coord pos_title = {10,18};
   coord pos_fdbh  = {10,32};
   std::string title = "DATABASE STATUS";
   std::string db_name = "ev-db";
   std::string ip_addr = "127.0.0.1";
   std::ostringstream full_db_host;
   full_db_host << "Hostname: " << db_name << "     " << "IP: " << ip_addr;
   std::string full_db_host_str = full_db_host.str();
   obj->DrawFont(title, pos_title);
   obj->DrawFont(full_db_host_str, pos_fdbh);
   obj->DrawSquare(t, b);
}


void EvArt::DrawFont(std::string& a_str, coord pos)
{
   XDrawString(display, window, grph_ctx, pos.x, pos.y, a_str.c_str(), a_str.size());
}