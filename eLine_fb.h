#ifndef __ELINE_FB_H__
#define __ELINE_FB_H__

#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

#include "eLine_define.h"
#include "eLine_debug.h"

/**
 * Provide an easy way to manipulate framebuffer. 
 */
class eLineFb
{
public: /* public datatype */

    enum eLineFbFormat
    {
        FB_FMT_32_
    };
public: /* public methods */
    eLineFb(const char *fb_name);
    
    int32_t init(void);
    int32_t exit(void);
    void showInfo(void);
    uint32_t getResX(void);
    uint32_t getResY(void);
    
    void draw(int32_t x, int32_t y, uint32_t color);
    

private: /* private methods */
    void printFbBitfield(struct fb_bitfield *bf);
    void printFbVarScreenInfo(struct fb_var_screeninfo *vinfo);
    void printFbFixScreenInfo(struct fb_fix_screeninfo *finfo);

private: /* private data */
    char fb_name[50];
    int32_t fb_fd;
    struct fb_var_screeninfo fb_var;
    struct fb_fix_screeninfo fb_fix;
    size_t fb_size;
    uint8_t *fb_start;
};

#endif /* #ifndef __ELINE_FB_H__ */
