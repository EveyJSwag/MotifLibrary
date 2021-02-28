#include "EvCursor.h"
#include <X11/cursorfont.h>

EvCursor* EvCursor::Singleton;

EvCursor::EvCursor()
{
   main_cursor = (Cursor) 0;
}

void EvCursor::ChangeCursor(unsigned char a_cursor, Widget a_widget)
{
   main_cursor = XCreateFontCursor(XtDisplay(a_widget), a_cursor);
   XDefineCursor(XtDisplay(a_widget), XtWindow(a_widget), main_cursor);  
}

EvCursor* EvCursor::GetInstance()
{
   if (EvCursor::Singleton == NULL)
   {
      EvCursor::Singleton = new EvCursor();   
   }
   return EvCursor::Singleton;
}
