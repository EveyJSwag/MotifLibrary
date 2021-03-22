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

   grph_ctx_val.foreground = BlackPixelOfScreen(screen_ptr);
   grph_ctx = XCreateGC(display, RootWindowOfScreen(screen_ptr), GCForeground, &grph_ctx_val);
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

void EvArt::DrawSquare(coord t, coord b, unsigned long a_color)
{
   XSetForeground(display, grph_ctx, a_color);
   XDrawRectangle(display, window, grph_ctx, t.x, t.y, (b.y - t.y), (b.x - t.x));
   XSetForeground(display, grph_ctx, BLACK_EV);
}

void EvArt::DrawCircle(coord center, unsigned int radius, unsigned long a_color)
{
   XSetForeground(display, grph_ctx, a_color);
   XSetForeground(display, grph_ctx, BLACK_EV);
}

void EvArt::DrawLine(coord c1, coord c2, unsigned long a_color)
{
   XSetForeground(display, grph_ctx, a_color);
   XDrawLine(display, window, grph_ctx, c1.x, c1.y, c2.x, c2.y);
   XSetForeground(display, grph_ctx, BLACK_EV);
}

void EvArt::DrawArc(coord c1, coord c2, unsigned long a_color)
{
   XSetForeground(display, grph_ctx, a_color);
   XSetForeground(display, grph_ctx, BLACK_EV);
}

void EvArt::DrawFont(std::string& a_str, coord pos, unsigned long a_color)
{
   XSetForeground(display, grph_ctx, a_color);
   XDrawString(display, window, grph_ctx, pos.x, pos.y, a_str.c_str(), a_str.size());
   XSetForeground(display, grph_ctx, BLACK_EV);
}

void EvArt::ExposeArt(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk)
{
   const unsigned int MAX_WIDTH_db_stat = 300;
   const unsigned int MAX_HEIGHT_db_stat = 80;
   const unsigned int START_POS_X_db_stat = 2;
   const unsigned int START_POS_Y_db_stat = 2;
 
   EvArt* obj = (EvArt*)client_data;
   coord t = {START_POS_X_db_stat, START_POS_Y_db_stat};
   coord b = {MAX_HEIGHT_db_stat, MAX_WIDTH_db_stat};
   coord pos_title = {10,22};
   coord pos_fdbh  = {10,36};
   coord pos_fdbs  = {10,50};
   std::string title = "DATABASE STATUS";
   std::string db_name = "ev-db";
   std::string ip_addr = "127.0.0.1";
   std::ostringstream full_db_host;
   full_db_host << "Hostname: " << db_name << "        " << "IP: " << ip_addr;
   std::string full_db_host_str = full_db_host.str();
   std::string status_title = "Status: ";
   std::string status       = "";
   std::ostringstream full_db_status;
   full_db_status << status_title << "        " << status;
   std::string full_db_status_str = full_db_status.str();

   obj->DrawSquare(t, b, RED_EV);
   t = {START_POS_X_db_stat+1, START_POS_Y_db_stat+1};
   b = {MAX_HEIGHT_db_stat-1, MAX_WIDTH_db_stat-1};
   obj->DrawSquare(t, b, BLUE_EV);
   t = {START_POS_X_db_stat+2, START_POS_Y_db_stat+2};
   b = {MAX_HEIGHT_db_stat-2, MAX_WIDTH_db_stat-2};
   obj->DrawSquare(t, b, GREEN_EV);
   obj->DrawFont(title, pos_title, PURPLE_EV);
   obj->DrawFont(full_db_host_str, pos_fdbh, BLACK_EV);
   obj->DrawFont(full_db_status_str, pos_fdbs, BLACK_EV);
}
