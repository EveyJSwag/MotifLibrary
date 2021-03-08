#include "DBStatus.h"
#include <pthread.h>
#include <X11/cursorfont.h>




DBStatus::DBStatus(Widget a_main_window)
{
   parent_window = a_main_window;
   // **********************************
   // * Init app/widgets
   // **********************************
   /*
   d_name = "Yeet";

   main_app           = new EvApp();



   w_title_l          = new EvLabel("CATS");

   w_status_list_lst  = new EvList("Status list");

   w_connect_to_db    = new EvButton("Connect to DB");

   main_widget        = new EvWidget();
   */
   // **********************************
   // * Display/Position the widgets
   // **********************************
   /*
   main_widget->AppInitialize();

   w_main_form_f->Display(main_widget->w_widget);
   w_main_form_f->SetSize(500, 500);
   
   w_title_l->Display(w_main_form_f->GetWidget());
   w_title_l->SetPos(120, 4);

   w_status_list_lst->Display(w_main_form_f->GetWidget());
   w_status_list_lst->SetPos(90, 100);
   w_status_list_lst->SetSize(40, 100);

   w_connect_to_db->Display(w_main_form_f->GetWidget());
   w_connect_to_db->SetPos(5,220);
   w_connect_to_db->AddCallback(w_connect_to_db->GetWidget(), (XtCallbackProc)connect_to_db_cb, (XtPointer)this);

   main_widget->RealizeWidget();
   
   EvApp::MainLoop();
   */
}

void DBStatus::connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   DBStatus* obj = (DBStatus*)client_data;
   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());


   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
}

void DBStatus::DisplayWindow()
{
   w_db_shell = XtVaCreatePopupShell("Database Status", vendorShellWidgetClass, parent_window, XmNheight, 200, XmNwidth, 300, NULL);
   XtManageChild(w_db_shell);

   w_connect_to_db    = new EvButton("Connect to DB");
   w_connect_to_db->Display(w_db_shell);
}

