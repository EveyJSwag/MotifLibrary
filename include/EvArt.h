#ifndef EV_ART
#define EV_ART

#include "EvWidget.h"
#include <string>

typedef struct coord
{
   unsigned short x;
   unsigned short y;
} coord;

class EvArt : EvWidget
{
public:
   EvArt(const char*);
   EvArt(const char*, const Widget);
   void AddCallback(Widget w, XtCallbackProc func, XtPointer caller);
   void DisplayW(Widget);
   const char* GetName() {return name;}
   Widget GetWidget(){return w_widget;}
   void SetPos(unsigned int, unsigned int);
   void SetSize(unsigned int, unsigned int);
   void SetName(const char*);
   void DrawSquare(coord t, coord b);
   void DrawCircle(coord center, unsigned int radius);
   void DrawLine(coord, coord);
   void DrawArc(coord, coord);
   void DrawFont(std::string& a_str, coord pos);

private:
   const char* name;
   Widget    w_widget;
   Display*  display;
   Screen*   screen_ptr;
   Window    window;
   GC        grph_ctx;
   XGCValues grph_ctx_val;

   // *********************************
   // * Need callbacks for art
   // *********************************
   static void ExposeArt(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cbk);

};
#endif /* EV_ART */
