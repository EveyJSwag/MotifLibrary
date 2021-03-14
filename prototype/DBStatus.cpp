#include "DBStatus.h"
#include <pthread.h>
#include <X11/cursorfont.h>
#include <Xm/DrawingA.h>
#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>

DBStatus::DBStatus(Widget a_main_window)
{
   parent_window = a_main_window;
}

void DBStatus::connect_to_db_cb(Widget w, XtPointer client_data, XmPushButtonCallbackStruct* cbs)
{
   DBStatus* obj = (DBStatus*)client_data;
   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_watch, obj->w_main_form_f->GetWidget());


   obj->cursor_mgr->GetInstance()->ChangeCursor(XC_arrow, obj->w_main_form_f->GetWidget());
}

void DBStatus::DisplayWindow()
{
   w_db_shell = XtVaCreatePopupShell("Database Status", vendorShellWidgetClass, parent_window, XmNheight, 200, XmNwidth, 700, NULL);
   XtManageChild(w_db_shell);
   w_main_form_f = new EvForm("Main DB Form");
   w_main_form_f->DisplayW(w_db_shell);

   w_db_stat_art = new EvArt("DB Status Art");
   w_db_stat_art->DisplayW(w_main_form_f->GetWidget());

   w_connect_to_db_pb    = new EvButton("Connect to DB");
   w_connect_to_db_pb->DisplayW(w_main_form_f->GetWidget());
   w_connect_to_db_pb->SetPos(1,170);
}

