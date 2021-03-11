#ifndef PROTO_APP
#define PROTO_APP

#include <vector>
#include "EvApp.h"
#include "EvWidget.h"
#include "EvForm.h"
#include "EvButton.h"
#include "EvLabel.h"
#include "EvList.h"
#include "EvDropdown.h"
#include "EvCursor.h"
#include "EvDBMain.h"
#include "DBStatus.h"




class ProtoApp
{
public:
   typedef void* (*DB_THREAD_PROC)(void *);

   const char* d_name;
   static ProtoApp* GetInstance();

private:
   
   ProtoApp();
   static ProtoApp* Singleton;

   EvDBMain* d_evdb;

   EvApp*    main_app;
   EvWidget* main_widget;

   EvCursor* cursor_mgr;

   EvLabel*  w_title_l;

   EvForm*   w_main_form_f;

   EvList*   w_status_list_lst;

   EvButton* w_connect_to_db;

   EvButton* w_db_status;

   DBStatus* db_status_window;

   pthread_t db_thread_id; 

   unsigned char db_ins_amt = 0;

   static void connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs);
   static void spawn_db_status_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs);

};

#endif /* PROTO_APP */