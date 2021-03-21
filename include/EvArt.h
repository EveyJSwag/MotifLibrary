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
#define SET_COLOR_EV(r,g,b)        ((r << 16) | (g << 8) | (b << 0))
#define RED_EV                     SET_COLOR_EV(0xFF, 0, 0)
#define GREEN_EV                   SET_COLOR_EV(0, 0xFF, 0)
#define BLUE_EV                    SET_COLOR_EV(0, 0, 0xFF)
#define PURPLE_EV                  (RED_EV | BLUE_EV)
#define GRBL_EV                    (GREEN_EV | BLUE_EV)
#define WHITE_EV                   SET_COLOR_EV(0xFF, 0xFF, 0xFF)
#define BLACK_EV                   0
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
   void DrawSquare(coord t, coord b, unsigned long a_color);
   void DrawCircle(coord center, unsigned int radius, unsigned long a_color);
   void DrawLine(coord, coord, unsigned long a_color);
   void DrawArc(coord, coord, unsigned long a_color);
   void DrawFont(std::string& a_str, coord pos, unsigned long a_color);

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
