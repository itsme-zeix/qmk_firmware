    // Copyright 2022 Aidan Smith (@Aidan-OS)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include <qp.h>
#include "graphics/lain_image.qgf.h"

static painter_device_t display;
// static painter_image_handle_t image;
// static deferred_token animation;

uint32_t deferred_init(uint32_t trigger_time, void *cb_arg)
{   
    display = qp_st7789_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0); // tested with mode 0, 1 and 3
    qp_init(display, QP_ROTATION_180);
    
    // image = qp_load_image_mem(gfx_lain_image);
    // if (image != NULL)
    // {
    //     // qp_drawimage(display, (239 - image->width), (239 - image->height), image);
    //     qp_drawimage(display, 0, 0, image);
    // }
    qp_circle(display, 35, 35, 30, 85, 255, 255, true); //Green
    qp_circle(display, 200, 35, 30, 169, 255, 255, true); //Blue
    qp_circle(display, 35, 200, 30, 21, 255, 255, true); //Orange
    qp_circle(display, 200, 200, 30, 127, 255, 255, true); //Cyan
    
    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable = true;
    defer_exec(3000, deferred_init, NULL);
}