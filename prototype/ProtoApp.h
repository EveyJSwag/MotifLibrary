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

   EvDropdown* w_cat_list_dl;
};

#endif /* PROTO_APP */