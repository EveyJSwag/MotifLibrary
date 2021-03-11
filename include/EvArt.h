#ifndef EV_ART
#define EV_ART

#include "EvWidget.h"

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
   void DrawSquare(coord t, coord b, coord l, coord r);
   void DrawCircle(coord center, unsigned int radius);
   void DrawLine(coord, coord);
   void DrawArc(coord, coord);

private:
   const char* name;
   Widget    w_widget;
   Display*  display;
   Screen*   screen_ptr;
   Window    window;
   GC        grph_ctx;
   XGCValues grph_ctx_val;

};
#endif /* EV_ART */
