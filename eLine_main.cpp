#include "eLine_fb.h"

#define LCD_FB_NAME "/dev/fb0"



int main(int argc, char *argv[])
{
    eLineFb lcd(LCD_FB_NAME);
    lcd.init();
    printf("ResX=%d\n", lcd.getResX());
    printf("ResY=%d\n", lcd.getResY());
    lcd.showInfo();
    lcd.exit();
    return 0;
}
