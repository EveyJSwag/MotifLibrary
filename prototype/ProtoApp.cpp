#include "ProtoApp.h"
#include <pthread.h>
#include <X11/cursorfont.h>
#include <Xm/DialogS.h>
#include "StringUtil.h"
#include <sstream>
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

   w_db_art_area      = new EvArt("Art list");

   w_status_list_lst  = new EvList("Status list");

   w_db_status        = new EvButton("DB Status Window");

   main_widget        = new EvWidget();

   // **********************************
   // * Display/Position the widgets
   // **********************************
   main_widget->AppInitialize();

   w_main_form_f->DisplayW(main_widget->w_widget);
   w_main_form_f->SetSize(250, 250);
   
   w_title_l->DisplayW(w_main_form_f->GetWidget());
   w_title_l->SetPos(110, 4);

   w_db_art_area->DisplayW(w_main_form_f->GetWidget());
   w_db_art_area->SetPos(2,10);
   w_db_art_area->SetSize(40, 246);
   XtAddCallback(w_db_art_area->GetWidget(), XmNexposeCallback, (XtCallbackProc)expose_art_cb, (XtPointer)this);
   
   w_status_list_lst->DisplayW(w_main_form_f->GetWidget());
   if (EvDBMain::GetStatus() == EvDBMain::db_status::DB_UP)
   {
      EvDBMain* db_ref = EvDBMain::GetInstance();
      const unsigned char* in_str_name  = (const unsigned char*)"SELECT name FROM kitties";
      const unsigned char* out_str_name = (unsigned char*)malloc(100);
      const unsigned char* in_str_breed  = (const unsigned char*)"SELECT breed FROM kitties";
      const unsigned char* out_str_breed = (unsigned char*)malloc(100);

      db_ref->Select(in_str_breed, out_str_breed);
      char* out_str_breed_trim = (char *)malloc(ev_size(out_str_breed));
      memcpy(out_str_breed_trim, out_str_breed, ev_size(out_str_breed));

      db_ref->Select(in_str_name, out_str_name);
      char* out_str_name_trim = (char *)malloc(ev_size(out_str_name));
      out_str_name_trim[ev_size(out_str_name)] = 0;
      memcpy(out_str_name_trim, out_str_name, 4);
      
      std::ostringstream full_query;
      full_query << out_str_name_trim << " the " << out_str_breed;
      std::string full_query_str = full_query.str();
      w_status_list_lst->AddToList(full_query_str.c_str());
   }
   w_status_list_lst->SetPos(80, 130);
   w_status_list_lst->SetSize(80, 100);

   w_db_status->DisplayW(w_main_form_f->GetWidget());
   w_db_status->SetPos(5,220);
   w_db_status->AddCallback(w_db_status->GetWidget(), (XtCallbackProc)spawn_db_status_cb, (XtPointer)this);

   main_widget->RealizeWidget();
   
   // ********************************************
   // * DB Window should be there at start up
   // ********************************************
   XmPushButtonCallbackStruct* boot_struct;
   spawn_db_status_cb(w_db_status->GetWidget(), (XtPointer)this, boot_struct);
   
   EvApp::MainLoop();
}

void ProtoApp::spawn_db_status_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   ProtoApp* obj = (ProtoApp*) client_data;
   if (obj->db_ins_amt == 0)
   {
      obj->db_status_window = new DBStatus(obj->w_main_form_f->GetWidget());
      obj->db_status_window->DisplayWindow();
      obj->db_ins_amt++;
      XtAddCallback(obj->db_status_window->GetWidget(), XmNdestroyCallback, (XtCallbackProc)destroy_db_status_cb, obj);
   }
}

void ProtoApp::destroy_db_status_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   ProtoApp* obj = (ProtoApp*) client_data;
   if (obj->db_ins_amt == 1) obj->db_ins_amt--;
}

void ProtoApp::expose_art_cb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct* cbs)
{
   ProtoApp* obj = (ProtoApp*) client_data;
   std::string test_test = "lol";
   coord test_coord;
   test_coord.x = 22;
   test_coord.y = 22;
   obj->w_db_art_area->SetWindow(XtWindow(w));
   obj->w_db_art_area->DrawFont(test_test, test_coord,BLACK_EV);
}