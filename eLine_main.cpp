#include "eLine_fb.h"

#define LCD_FB_NAME "/dev/fb0"



int main(int argc, char *argv[])
{
    eLineFb lcd(LCD_FB_NAME);
    lcd.init();
    printf("ResX=%d\n", lcd.getResX());
    printf("ResY=%d\n", lcd.getResY());
    //lcd.showInfo();
    lcd.draw(0, 0, 0xFF0000);
    lcd.draw(lcd.getResX() - 1, lcd.getResY() - 1, 0x00FF00);
    lcd.draw(0, lcd.getResY() - 1, 0x0000FF);
    lcd.draw(lcd.getResX() - 1, 0, 0xFFFFFF);
    lcd.exit();
    return 0;
}
