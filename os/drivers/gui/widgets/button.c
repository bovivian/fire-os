#include <gui.h>

void button_keydown(struct widget* widget, uint32_t key);
void button_keyup(struct widget* widget, uint32_t key);
void button_mouse_move(struct widget* widget, int32_t x, int32_t y, uint32_t flags);
void button_mouse_event(struct widget* widget, int32_t x, int32_t y, uint32_t flags);
void button_click(struct widget* widget);

button_t*
button_create(const char* caption, widget_t* parent) {
  button_t* btn = (button_t*)malloc(sizeof(struct button));

  if( !btn ) return NULL;

  memset(btn, 0, sizeof(struct button));

  WIDGET(btn)->class = W_BUTTON;
  WIDGET(btn)->next = NULL;
  WIDGET(btn)->child = NULL;
  WIDGET(btn)->x = 0;
  WIDGET(btn)->y = 0;
  WIDGET(btn)->w = 30;
  WIDGET(btn)->h = 12;
  WIDGET(btn)->parent = parent;
  WIDGET(btn)->visible = W_VIS_PARENT;
  WIDGET(btn)->fgcolor = (color_t){ 0x0 };
  WIDGET(btn)->bgcolor = (color_t){ 0xD4D4D4 };
  widget_set_padding(WIDGET(btn),0,2,2,0);
  WIDGET(btn)->OnPaint = NULL;
  WIDGET(btn)->OnKeyUp = button_keyup;
  WIDGET(btn)->OnKeyDown = button_keydown;
  WIDGET(btn)->OnMouseMove = button_mouse_move;
  WIDGET(btn)->OnMouseEvent = button_mouse_event;
  WIDGET(btn)->OnClick = button_click;
  btn->pressed = 0;

  widget_set_parent(WIDGET(btn), parent);

  btn->label = label_create(caption, WIDGET(btn));
  WIDGET(btn->label)->bgcolor = WIDGET(btn)->bgcolor;

  WIDGET(btn->label)->x = 0;//(WIDGET(btn)->w) / 2;
  // debug_printf("%d %d label->x = %d", WIDGET(btn->label)->w, WIDGET(btn)->w, WIDGET(btn->label)->x);

  return btn;
}

void
button_click(struct widget* widget) {
  debug_printf("clicked!");
}

void
button_mouse_event(struct widget* widget, int32_t x, int32_t y, uint32_t flags) {
  if( flags & 1)
    BUTTON(widget)->pressed = 1;
  else {
    if( BUTTON(widget)->pressed == 1 ) {
      BUTTON(widget)->pressed = 0;
      widget->OnClick(widget);
    }
  }

}

void
button_mouse_move(struct widget* widget, int32_t x, int32_t y, uint32_t flags) {


    // debug_printf("button mouse move (%d,%d)", x, y);

}

void
button_keydown(struct widget* widget, uint32_t key) {

  if( (key & 0xFF) == 0x0A) // is enter key?
    BUTTON(widget)->pressed = 1;
    //
    //
    // widget_t* wnd = WINDOW(window_create(100,50)); // just for testing!
    // window_move(WINDOW(wnd), (gfx_width() - 100)/2, (gfx_height() - 50)/2 );
    // window_set_name(WINDOW(wnd), "Message Box");
    // label_create("Button has been clicked! :)", wnd);
    // gui_set_active_window(WINDOW(wnd));

  if(widget->OnKeyDown_User)
    widget->OnKeyDown_User(widget,key);
}

void
button_keyup(struct widget* widget, uint32_t key) {

  if( (key & 0xFF) == 0x0A) // is enter key?
    BUTTON(widget)->pressed = 0;

  if(widget->OnKeyUp_User)
    widget->OnKeyUp_User(widget,key);
}

void
button_draw(button_t* btn) {

  uint32_t  x0, y0;

  if( btn == NULL )
    return;

  if(WIDGET(btn)->parent == NULL)
    return;

  widget_absolute_xy(WIDGET(btn), &x0, &y0);

  // shadow
  if(btn->pressed == 0) {
    gfx_rect( x0 + 1,
              y0 + 1,
              x0 + WIDGET(btn)->w,
              y0 + WIDGET(btn)->h,
              (color_t){0x404040});
  }


  // button
  gfx_rect( x0 + btn->pressed,
            y0 + btn->pressed,
            x0 + WIDGET(btn)->w - 1 + btn->pressed,
            y0 + WIDGET(btn)->h - 1 + btn->pressed,
            WIDGET(btn)->bgcolor );
}

void
button_size(button_t* btn, uint32_t x, uint32_t y, uint32_t w, uint32_t h) {

  if(btn == NULL)
    return;

  widget_move(WIDGET(btn), x, y);
  WIDGET(btn)->w = w;
  WIDGET(btn)->h = h;
  // widget_resize()

  label_size_request(btn->label);
}
