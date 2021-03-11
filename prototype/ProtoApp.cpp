#include "ProtoApp.h"
#include <pthread.h>
#include <X11/cursorfont.h>
#include <Xm/DialogS.h>

ProtoApp* ProtoApp::Singleton;

ProtoApp* ProtoApp::GetInstance()
{
   if (ProtoApp::Singleton == NULL)
      ProtoApp::Singleton = new ProtoApp();
   return ProtoApp::Singleton;
}

ProtoApp::ProtoApp()
{
   // **********************************
   // * Init app/widgets
   // **********************************
   d_name = "Yeet";

   main_app           = new EvApp();

   w_main_form_f      = new EvForm("Protoform");

   w_title_l          = new EvLabel("CATS");

   w_status_list_lst  = new EvList("Status list");

   w_connect_to_db    = new EvButton("Connect to DB");

   w_db_status        = new EvButton("DB Status Window");

   main_widget        = new EvWidget();

   // **********************************
   // * Display/Position the widgets
   // **********************************
   main_widget->AppInitialize();

   w_main_form_f->DisplayW(main_widget->w_widget);
   w_main_form_f->SetSize(500, 500);
   
   w_title_l->DisplayW(w_main_form_f->GetWidget());
   w_title_l->SetPos(120, 4);

   w_status_list_lst->DisplayW(w_main_form_f->GetWidget());
   w_status_list_lst->SetPos(90, 100);
   w_status_list_lst->SetSize(40, 100);

   //w_connect_to_db->Display(w_main_form_f->GetWidget());
   //w_connect_to_db->SetPos(5,220);
   //w_connect_to_db->AddCallback(w_connect_to_db->GetWidget(), (XtCallbackProc)connect_to_db_cb, (XtPointer)this);
   w_db_status->DisplayW(w_main_form_f->GetWidget());
   w_db_status->SetPos(5,220);
   w_db_status->AddCallback(w_db_status->GetWidget(), (XtCallbackProc)spawn_db_status_cb, (XtPointer)this);


   main_widget->RealizeWidget();
   
   EvApp::MainLoop();
}

void ProtoApp::connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   ProtoApp* obj = (ProtoApp*)client_data;
   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());
   


   
   pthread_create(&obj->db_thread_id, NULL, (DB_THREAD_PROC)obj->d_evdb->GetInstance, NULL);
   obj->w_status_list_lst->AddToList("CONNECTING...");
   pthread_join(obj->db_thread_id, NULL);

   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
   
}



Widget GetTopShell (Widget w)
{
    while (w && !XtIsWMShell (w))
    w = XtParent (w);
    return w;
}

void ProtoApp::spawn_db_status_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   ProtoApp* obj = (ProtoApp*) client_data;
   if (obj->db_ins_amt == 0)
   {
      obj->db_status_window = new DBStatus(obj->w_main_form_f->GetWidget());
      obj->db_status_window->DisplayWindow();
      obj->db_ins_amt++;
   }
}