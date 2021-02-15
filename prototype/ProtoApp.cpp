#include "ProtoApp.h"


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
   Boolean test  = FALSE;
   main_app      = new EvApp();

   w_main_form_f = new EvForm("Protoform");

   w_title_l     = new EvLabel("Cats");

   w_ok_button_l = new EvLabel("Ok Button");
   w_ok_button_b = new EvButton("OK");

   w_cat_list_dl = new EvDropdown("Cat");

   main_widget   = new EvWidget();

   // **********************************
   // * Display/Position the widgets
   // **********************************
   main_widget->AppInitialize();
   w_main_form_f->Display(main_widget->w_widget);
   w_main_form_f->SetSize(500, 500);
   
   w_title_l->Display(w_main_form_f->GetWidget());
   w_title_l->SetPos(220, 4);

   w_ok_button_l->Display(w_main_form_f->GetWidget());
   w_ok_button_l->SetPos(5, 440);

   w_ok_button_b->Display(w_main_form_f->GetWidget());
   w_ok_button_b->SetPos(5, 460);

   w_cat_list_dl->Display(w_main_form_f->GetWidget());
   w_cat_list_dl->SetLabel("YEET");
   w_cat_list_dl->AddToList("1");
   w_cat_list_dl->AddToList("3");
   w_cat_list_dl->AddToList("5");
   w_cat_list_dl->SetPos(110, 200);

   main_widget->RealizeWidget();
   
   EvApp::MainLoop();
}