#include <stdio.h>

#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include <Xm/Label.h>
#include <Xm/RowColumn.h>
#include <Xm/Frame.h>  /* header file for frame stuff */
#include <Xm/MainW.h>
#include <Xm/DialogS.h>
#include "EvApp.h"
#include "EvWidget.h"
#include "EvButton.h"
#include "EvRowCol.h"
#include "EvForm.h"
#include "EvFrame.h"
#include "EvCombobox.h"
#include "EvDropdown.h"
/* Prototype callback */
#include "ProtoApp.h"
/*
void pushed_fn(Widget , XtPointer, XmPushButtonCallbackStruct *);
Widget testPopupShell;
EvApp MainApp = EvApp();
EvForm*   w_form1   = new EvForm("mehform");
EvFrame*  w_frame1  = new EvFrame("mehframe");
EvButton* w_button1 = new EvButton("button1");
EvButton* w_button2 = new EvButton("why so hard");
EvButton* w_button3 = new EvButton("swag yoloooooooooo");
EvButton* w_button4 = new EvButton("ANOTHER ONE");
EvRowCol* w_rowcol  = new EvRowCol("main_rowcol");
EvWidget* w_top_widget = new EvWidget();

int main(int argc, char **argv)
{
   XmString test;
   w_frame1->Display(w_top_widget->w_widget);
   w_rowcol->Display(w_frame1->GetWidget());
   w_button1->Display(w_rowcol->GetWidget());
   w_button2->Display(w_rowcol->GetWidget());
   w_button3->Display(w_rowcol->GetWidget());
   w_button4->Display(w_rowcol->GetWidget());
   w_button3->AddCallback(pushed_fn);
   w_top_widget->RealizeWidget();
   
   EvApp::MainLoop();
}

void pushed_fn(Widget w, XtPointer client_data, XmPushButtonCallbackStruct *cbs)
{
    EvButton* buttonref = (EvButton*)client_data;
    EvDropdown* dropdowntest = new EvDropdown("drop");
    EvForm* formtest = new EvForm("formtest");
    printf("You pushed %s at: X:%d, Y:%d\n", buttonref->GetLabel(),cbs->event->xbutton.x, cbs->event->xbutton.y);
    testPopupShell = XtVaCreateManagedWidget(buttonref->GetLabel(), vendorShellWidgetClass, w_top_widget->w_widget, XmNwidth, 500, XmNheight, 500, NULL); 
    formtest->Display(testPopupShell);
    dropdowntest->Display(formtest->GetWidget());
    dropdowntest->AddToList("Test1");
    dropdowntest->AddToList("Another one");
}
*/

int main()
{
    ProtoApp::GetInstance();
}