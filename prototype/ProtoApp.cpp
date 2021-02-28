#include "ProtoApp.h"
#include <X11/cursorfont.h>

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

   main_widget        = new EvWidget();

   // **********************************
   // * Display/Position the widgets
   // **********************************
   main_widget->AppInitialize();

   w_main_form_f->Display(main_widget->w_widget);
   w_main_form_f->SetSize(250, 250);
   
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
}

void ProtoApp::connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{

   ProtoApp* obj = (ProtoApp*)client_data;
   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());
   obj->w_status_list_lst->AddToList("CONNECTING...");
}