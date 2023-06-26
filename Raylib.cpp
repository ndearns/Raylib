#include "Raylib.h"


bool Raylib::cmatch( Color c1, Color c2 ) 
    { if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a) return true; return false; }
void Raylib::set_trace_log_level(int log_level)
    {SetTraceLogLevel(log_level);}
void Raylib::turn_logging_off()
    {SetTraceLogLevel(LOG_NONE);}
void Raylib::init_window(int width, int height, const std::string &title)
    { InitWindow(width, height, title.data());}
void Raylib::close_window() 
    { CloseWindow(); }
bool Raylib::window_should_close()
    { return WindowShouldClose(); }
void Raylib::set_target_fps( int fps )
    { SetTargetFPS( fps ); }
float Raylib::get_frame_time()
    { return GetFrameTime(); }
int Raylib::get_fps()
    { return GetFPS(); }
bool Raylib::is_key_down(int the_key)
    { return IsKeyDown(the_key); }
bool Raylib::is_key_pressed(int the_key)
    { return IsKeyPressed(the_key); }
bool Raylib::any_key_is_pressed()  
    {   bool result {false};
        if (GetKeyPressed() != 0)  result = true; 
        return result;
    }
bool Raylib::mouse_button_is_down(int button)  
    { return IsMouseButtonDown(button); }
bool Raylib::mouse_button_pressed(int button)  
    { return IsMouseButtonPressed(button); }
bool Raylib::mouse_button_released(int button)  
    { return IsMouseButtonReleased(button); }
Vector2 Raylib::get_mouse_position()    
    { return GetMousePosition(); }
uint16_t Raylib::get_screen_width()
    { return (uint16_t)GetScreenWidth(); }
uint16_t Raylib::get_screen_height()
    { return (uint16_t)GetScreenHeight(); }
void Raylib::begin_drawing()
    { return BeginDrawing(); }
void Raylib::end_drawing()           
    { EndDrawing(); }
void Raylib::clear_background( Color color )      
    { ClearBackground( color );}
void Raylib::draw_fps( int x, int y )
    { DrawFPS( x, y ); }
void Raylib::draw_text(std::string text, int x, int y, int fontSize, Color color)
    { DrawText(text.c_str(), x, y, fontSize, color);}
void Raylib::draw_text(const char* text, int x, int y, int fontSize, Color color)
    { DrawText(text, x, y, fontSize, color);}
void Raylib::draw_text(float f, int x, int y, int fontSize, Color color)
    { DrawText(std::to_string(f).data(), x, y, fontSize, color);}
void Raylib::draw_circle(int center_x, int center_y, int radius, Color color)  
    {  DrawCircle(center_x, center_y, radius, color);}
void Raylib::draw_rectangle(int x, int y, int dx, int dy, Color color)  
    {  DrawRectangle(x, y, dx, dy, color);}
void Raylib::draw_rectangle_lines(int x, int y, int dx, int dy, Color color)  
    {  DrawRectangleLines(x, y, dx, dy, color);}
char* Raylib::time_HHMM() {

    static char buffer[80];
    time_t raw_time;
    struct tm* time_info;

    time(&raw_time);
    time_info = localtime (&raw_time);

    strftime(buffer, 80, "%H:%M", time_info);
    return buffer;
}
char* Raylib::time_HHMMSS() {

    static char buffer[80];
    time_t raw_time;
    struct tm* time_info;

    time(&raw_time);
    time_info = localtime (&raw_time);

    strftime(buffer, 80, "%H:%M:%S", time_info);
    return buffer;
}
Image Raylib::load_image( std::string filename ) {
    return LoadImage( filename.data() );
}
Image Raylib::image_from_image( Image img, Rectangle rect ) {
    return ImageFromImage( img, rect );
}
Image Raylib::gen_image_color( int width, int height, Color color ) {
    return GenImageColor( width, height, color );
}
void Raylib::export_image( Image img ) {
    static char buffer[256];
    time_t raw_time;
    struct tm* time_info;

    time(&raw_time);
    time_info = localtime (&raw_time);

    strftime(buffer, 256, "PixEd_%H%M%S.png", time_info);
    printf( "%s\n", buffer );
    ExportImage( img, buffer );
}
void Raylib::unload_image( Image img ) {
    UnloadImage( img );
}
void Raylib::image_draw_pixel( Image* dst, int posX, int posY, Color color ) {
    ImageDrawPixel( dst, posX, posY, color );
}
void Raylib::draw_image( Image image, int x, int y, Color tint ) {
    Texture t = LoadTextureFromImage( image );
    DrawTexture( t, x, y, tint );
}
Texture Raylib::load_texture( std::string filename ) {
    return LoadTexture( filename.data() );
}
Texture Raylib::load_texture_from_image( Image image ) {
    return LoadTextureFromImage( image );
}
void Raylib::draw_texture( Texture texture, int x, int y, Color tint ) {
    DrawTexture( texture, x, y, tint );
}
void Raylib::draw_texture_rec( Texture texture, Rectangle rect, Vector2 vec, Color tint ) {
    DrawTextureRec( texture, rect, vec, tint );
}
