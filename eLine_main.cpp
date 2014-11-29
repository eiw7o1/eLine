#include "eLine_fb.h"

#define LCD_FB_NAME "/dev/fb0"

#define ARGB_RED        (0x00FF0000)
#define ARGB_GREEN      (0x0000FF00)
#define ARGB_BLUE       (0x000000FF)
#define ARGB_YELLOW     (ARGB_RED | ARGB_GREEN)
#define ARGB_PURPLE     (ARGB_RED | ARGB_BLUE)

int main(int argc, char *argv[])
{
    uint32_t lcd_xmax;
    uint32_t lcd_ymax;
    
    eLineFb lcd(LCD_FB_NAME);
    lcd.init();
    lcd_xmax = lcd.getResX();
    lcd_ymax = lcd.getResY();
    
    printf("ResX=%d\n", lcd_xmax);
    printf("ResY=%d\n", lcd_ymax);
#if 0    
    //lcd.showInfo();
    lcd.draw(0, 0, 0xFF0000);
    lcd.draw(lcd.getResX() - 1, lcd.getResY() - 1, 0x00FF00);
    lcd.draw(0, lcd.getResY() - 1, 0x0000FF);
    lcd.draw(lcd.getResX() - 1, 0, 0xFFFFFF);
#endif

#if 0
    lcd.drawSolidRect(0, lcd_xmax, 0, lcd_ymax, ARGB_RED);
    sleep(1);
    lcd.drawSolidRect(0, lcd_xmax, 0, lcd_ymax, ARGB_GREEN);
    sleep(1);
    lcd.drawSolidRect(0, lcd_xmax, 0, lcd_ymax, ARGB_BLUE);
    sleep(1);
    lcd.drawSolidRect(0, lcd_xmax, 0, lcd_ymax, ARGB_YELLOW);
    sleep(1);
    lcd.drawSolidRect(0, lcd_xmax, 0, lcd_ymax, ARGB_PURPLE);
    sleep(1);
#endif

    lcd.clear(ARGB_BLUE);
    lcd.drawSolidRect(0, lcd_xmax/2, 0, lcd_ymax/2, ARGB_RED | (0xD0 << 24));
    //lcd.drawSolidRect(lcd_xmax/2, lcd_xmax/2, lcd_ymax/2, lcd_ymax/2, ARGB_BLUE);

    lcd.exit();
    return 0;
}
