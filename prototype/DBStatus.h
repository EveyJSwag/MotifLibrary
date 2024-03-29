#ifndef DBSTATUS
#define DBSTATUS

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
#include "EvArt.h"

class DBStatus
{
public:

   typedef void* (*DB_THREAD_PROC)(void *);

   DBStatus(Widget a_main_window);

   const char* d_name;

   void DisplayWindow();

   Widget GetWidget();

   static void UpdateStatus(void* client_data);

private:
   
   Widget    parent_window;

   Widget    w_db_shell;

   Widget    w_db_form;

   EvDBMain* d_evdb;

   EvApp*    main_app;
   EvWidget* main_widget;

   EvCursor* cursor_mgr;

   EvLabel*  w_title_l;

   EvForm*   w_main_form_f;

   EvList*   w_status_list_lst;

   EvButton* w_connect_to_db_pb;

   EvButton* w_clear_art_pb;

   EvArt*    w_db_stat_art;
   
   pthread_t db_thread_id;

   pthread_t window_thread_id;

   bool      is_displayed = false;

   static void connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs);

   static void clear_art_cb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk);

   static void expose_art_cb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk);

   void display_window_thread();
};

#endif /* DBSTATUS */
