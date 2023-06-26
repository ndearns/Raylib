#pragma once
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#define NDEWHITE (Color) {240,240,240,255}

// Facade to wrap raylib C functions

class Raylib {
    public:
    bool cmatch( Color c1, Color c2 ) ;
    void set_trace_log_level(int log_level);
    void turn_logging_off();
    void init_window(int width=800, int height=450, const std::string &title="raylib");
    void close_window() ;
    bool window_should_close();
    void set_target_fps( int fps );
    float get_frame_time();
    int get_fps();
    bool is_key_down(int the_key);
    bool is_key_pressed(int the_key);
    bool any_key_is_pressed()  ;
    bool mouse_button_is_down(int button)  ;
    bool mouse_button_pressed(int button)  ;
    bool mouse_button_released(int button)  ;
    Vector2 get_mouse_position()    ;
    uint16_t get_screen_width();
    uint16_t get_screen_height();
    void begin_drawing();
    void end_drawing()           ;
    void clear_background( Color color )      ;
    void draw_fps( int x, int y );
    void draw_text(std::string text, int x, int y, int fontSize, Color color);
    void draw_text(const char* text, int x, int y, int fontSize, Color color);
    void draw_text(float f, int x, int y, int fontSize, Color color);
    void draw_circle(int center_x, int center_y, int radius, Color color)  ;
    void draw_rectangle(int x, int y, int dx, int dy, Color color)  ;
    void draw_rectangle_lines(int x, int y, int dx, int dy, Color color)  ;
    char* time_HHMM() ;
    char* time_HHMMSS();
    Image load_image( std::string filename );
    Image image_from_image( Image img, Rectangle rect );
    Image gen_image_color( int width, int height, Color color );
    void export_image( Image img );
    void unload_image( Image img );
    void image_draw_pixel( Image* dst, int posX, int posY, Color color );
    void draw_image( Image image, int x, int y, Color tint = WHITE );
    Texture load_texture( std::string filename );
    Texture load_texture_from_image( Image image );
    void draw_texture( Texture texture, int x, int y, Color tint = WHITE );
    void draw_texture_rec( Texture texture, Rectangle rect, Vector2 vec, Color tint = WHITE );
};
