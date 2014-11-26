#include "eLine_fb.h"

/**
 * Constructor. 
 *
 * @param fb_name - the full path name of framebuffer device node.
 */
eLineFb::eLineFb(const char *fb_name)
{
    strncpy(this->fb_name, fb_name, sizeof(this->fb_name) - 1);    
}

/**
 * Open device node, get information and mmap the framebuffer. 
 * 
 * @retval 0 - success. 
 * @retval -1 - failed!
 */
int32_t eLineFb::init(void)
{
	fb_fd = open(fb_name, O_RDWR);
	if (fb_fd < 0)
	{
		eLineErr("can't open %s\n", fb_name);
		return -1;
	}
	
	if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &fb_var))
	{
		eLineErr("can't get variable information!\n");
		return -1;
	}

	if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &fb_fix))
	{
		eLineErr("can't get fixed information!\n");
		return -1;
	}

	fb_size= fb_var.xres * fb_var.yres * fb_var.bits_per_pixel / 8;
	fb_start= (uint8_t *)mmap(NULL , fb_size, PROT_READ | PROT_WRITE, 
	    MAP_SHARED, fb_fd, 0);
	if ((void *)fb_start == MAP_FAILED)
	{
		eLineErr("mmap failed!\n");
		return -1;
	}
	
	return 0;
}

/** 
 * Unmmap the framebuffer and close device node. 
 */
int32_t eLineFb::exit(void)
{
    if(munmap((void *)fb_start, fb_size) != 0)
    {
        eLineErr("munmap failed!");
    }
    return close(fb_fd);
}

/**
 * Get the resolution in X direction. 
 *
 * @return the value. 
 */
uint32_t eLineFb::getResX(void)
{
    return fb_var.xres;
}

/**
 * Get the resolution in Y direction. 
 *
 * @return the value. 
 */
uint32_t eLineFb::getResY(void)
{
    return fb_var.yres;
}

void eLineFb::showInfo(void)
{
    printFbVarScreenInfo(&fb_var);
    printFbFixScreenInfo(&fb_fix);
}

void eLineFb::printFbBitfield(struct fb_bitfield *bf)
{
    eLineOut("\nfb_bitfield\n{");
    eLineOut("\noffset = %u", bf->offset);
    eLineOut("\nlength = %u", bf->length);
    eLineOut("\nmsb_right = %u", bf->msb_right);
    eLineOut("\n}\n");
}

void eLineFb::printFbVarScreenInfo(struct fb_var_screeninfo *vinfo)
{
    eLineOut("\nfb_var_screeninfo\n{");
    eLineOut("\nxres = %u", vinfo->xres);
    eLineOut("\nyres = %u", vinfo->yres);   
    eLineOut("\nbits_per_pixel = %u", vinfo->bits_per_pixel);
    eLineOut("\ngrayscale = %u", vinfo->grayscale);
    eLineOut("\nrotate = %u", vinfo->rotate);
    eLineOut("\nred =");
    printFbBitfield(&vinfo->red);
    eLineOut("\ngreen =");
    printFbBitfield(&vinfo->green);
    eLineOut("\nblue =");
    printFbBitfield(&vinfo->blue);
    eLineOut("\ntransp =");
    printFbBitfield(&vinfo->transp);
    eLineOut("\n}\n");
}

void eLineFb::printFbFixScreenInfo(struct fb_fix_screeninfo *finfo)
{
    eLineOut("\nfb_fix_screeninfo\n{");
    eLineOut("\nid = %s", finfo->id);
    eLineOut("\nsmem_start = %lu", finfo->smem_start);
    eLineOut("\nsmem_len = %u", finfo->smem_len);
    eLineOut("\nline_length = %u", finfo->line_length);
    eLineOut("\n}\n");
}

