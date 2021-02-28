#include "EvWidget.h"

class EvCursor : EvWidget
{
public:
   const char* d_name;
   static EvCursor* GetInstance();
   void ChangeCursor(unsigned char, Widget);

private:
   EvCursor();
   Cursor main_cursor;
   static EvCursor* Singleton;
};