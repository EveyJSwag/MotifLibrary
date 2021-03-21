#include "DBStatus.h"
#include <pthread.h>
#include <X11/cursorfont.h>
#include <Xm/DrawingA.h>
#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <sstream>
void dumb_function();
DBStatus::DBStatus(Widget a_main_window)
{
   parent_window = a_main_window;
   cur_status = db_status::CONNECTING;
   db_thread_id = 0;
}

void DBStatus::connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   DBStatus* obj = (DBStatus*)client_data;
   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());

   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
}

 Widget DBStatus::GetWidget()
 {
    return w_db_shell;
 }

void DBStatus::DisplayWindow()
{
   w_db_shell = XtVaCreatePopupShell("Database Status", vendorShellWidgetClass, parent_window, XmNheight, 115, XmNwidth, 304, NULL);
   XtManageChild(w_db_shell);

   w_main_form_f = new EvForm("Main DB Form");
   w_main_form_f->DisplayW(w_db_shell);

   w_db_stat_art = new EvArt("DB Status Art");
   w_db_stat_art->DisplayW(w_main_form_f->GetWidget());
   XtAddCallback(w_db_stat_art->GetWidget(), XmNexposeCallback, (XtCallbackProc)expose_art_cb, (XtPointer)this);

   w_connect_to_db_pb    = new EvButton("Connect to DB");
   w_connect_to_db_pb->DisplayW(w_main_form_f->GetWidget());
   w_connect_to_db_pb->SetPos(1,85);

   w_clear_art_pb = new EvButton("Clear Art");
   w_clear_art_pb->DisplayW(w_main_form_f->GetWidget());
   w_clear_art_pb->AddCallback(w_clear_art_pb->GetWidget(), (XtCallbackProc)clear_art_cb, this);
   w_clear_art_pb->SetPos(100,85);
}


void DBStatus::clear_art_cb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk)
{
   DBStatus* obj = (DBStatus*)client_data;
   XClearWindow(XtDisplay(obj->w_db_stat_art->GetWidget()), XtWindow(obj->w_db_stat_art->GetWidget()));
}

void DBStatus::expose_art_cb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk)
{
   DBStatus* obj = (DBStatus*)client_data;

   const unsigned int MAX_WIDTH_db_stat = 300;
   const unsigned int MAX_HEIGHT_db_stat = 80;
   const unsigned int START_POS_X_db_stat = 2;
   const unsigned int START_POS_Y_db_stat = 2;

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

   switch(obj->cur_status)
   {
      case obj->db_status::CONNECTING:
      {
         status = "Connecting";
         obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());
         break;
      }
      case obj->db_status::DB_DOWN:
      {
         status = "Database is uncreachable";
         obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
         break;
      }
      case obj->db_status::DB_UP:
      {
         status = "Database is up";
         obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
         break;
      }
      case obj->db_status::HOST_DOWN:
      {
         status = "The host is unreachable";
         obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
      }
      case obj->db_status::HOST_UP:
      {
         status = "The host is alive";
         obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
         break;
      }
   }

   std::ostringstream full_db_status;
   full_db_status << status_title << "               " << status;
   std::string full_db_status_str = full_db_status.str();

   obj->w_db_stat_art->DrawSquare(t, b, RED_EV);
   t = {START_POS_X_db_stat+1, START_POS_Y_db_stat+1};
   b = {MAX_HEIGHT_db_stat-1, MAX_WIDTH_db_stat-1};
   obj->w_db_stat_art->DrawSquare(t, b, BLUE_EV);
   t = {START_POS_X_db_stat+2, START_POS_Y_db_stat+2};
   b = {MAX_HEIGHT_db_stat-2, MAX_WIDTH_db_stat-2};
   obj->w_db_stat_art->DrawSquare(t, b, GREEN_EV);
   obj->w_db_stat_art->DrawFont(title, pos_title, PURPLE_EV);
   obj->w_db_stat_art->DrawFont(full_db_host_str, pos_fdbh, BLACK_EV);
   obj->w_db_stat_art->DrawFont(full_db_status_str, pos_fdbs, BLACK_EV);


   /*
   if (obj->db_thread_id == 0)
   {
      try {
         int thread_rt = pthread_create(&(obj->db_thread_id), NULL, (DB_THREAD_PROC)obj->d_evdb->GetInstance(), NULL);
         pthread_detach(obj->db_thread_id);
      }
      catch (EvDBMain::DBException& e)
      {
         std::cout << e.GetReason();
      }
   }
   */
   /*
   
   */  
}

void dumb_function()
{
   while(1);
}