#ifndef PROTO_APP
#define PROTO_APP

#include "EvApp.h"
#include "EvWidget.h"
#include "EvForm.h"
#include "EvButton.h"
#include "EvLabel.h"
#include "EvList.h"
#include "EvDropdown.h"

class ProtoApp
{
public:
   const char* d_name;
   static ProtoApp* GetInstance();

private:
   
   ProtoApp();
   static ProtoApp* Singleton;

   EvApp*    main_app;
   EvWidget* main_widget;

   EvLabel*  w_title_l;

   EvForm*   w_main_form_f;
   EvButton* w_ok_button_b;
   EvLabel*  w_ok_button_l;

   EvButton* w_connect_to_db;

   EvDropdown* w_cat_list_dl;

   static void connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs);
};

#endif /* PROTO_APP */