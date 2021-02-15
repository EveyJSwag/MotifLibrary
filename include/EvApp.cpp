#include "EvApp.h"
void XtAppMainLoop(XtAppContext app)
{
    XEvent event;
    for (;;)
    {
        XtAppNextEvent(app, &event);
        XtDispatchEvent(&event);
    }
}
XtAppContext EvApp::w_base_app_p;

EvApp::EvApp()
{
    name = "MainApp";
}

void EvApp::MainLoop()
{
    XtAppMainLoop(w_base_app_p);
}