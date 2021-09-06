#ifndef _LCD_H_
#define _LCD_H_

#include <stdint.h>

#define cs SPI_CHIP_SELECT_2
#define sc FUNC_SPI0_SS2

#define LCD_X_MAX (320)
#define LCD_Y_MAX (240)

#define BLACK 0x0000
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F
#define USER_COLOR 0xAA55

#define NO_OPERATION 0x00
#define SOFTWARE_RESET 0x01
//#define READ_ID 0x04
#define READ_STATUS 0x09
#define READ_POWER_MODE 0x0A
#define READ_MADCTL 0x0B
#define READ_PIXEL_FORMAT 0x0C
#define READ_IMAGE_FORMAT 0x0D
#define READ_SIGNAL_MODE 0x0E
#define READ_SELT_DIAG_RESULT 0x0F
#define SLEEP_ON 0x10
#define SLEEP_OFF 0x11
#define PARTIAL_DISPLAY_ON 0x12
#define NORMAL_DISPLAY_ON 0x13
#define INVERSION_DISPLAY_OFF 0x20
#define INVERSION_DISPLAY_ON 0x21
#define GAMMA_SET 0x26
#define DISPLAY_OFF 0x28
#define DISPLAY_ON 0x29
#define HORIZONTAL_ADDRESS_SET 0x2A
#define VERTICAL_ADDRESS_SET 0x2B
#define MEMORY_WRITE 0x2C
#define COLOR_SET 0x2D
#define MEMORY_READ 0x2E
#define PARTIAL_AREA 0x30
#define VERTICAL_SCROLL_DEFINE 0x33
#define TEAR_EFFECT_LINE_OFF 0x34
#define TEAR_EFFECT_LINE_ON 0x35
#define MEMORY_ACCESS_CTL 0x36
#define VERTICAL_SCROLL_S_ADD 0x37
#define IDLE_MODE_OFF 0x38
#define IDLE_MODE_ON 0x39
#define PIXEL_FORMAT_SET 0x3A
#define WRITE_MEMORY_CONTINUE 0x3C
#define READ_MEMORY_CONTINUE 0x3E
#define SET_TEAR_SCANLINE 0x44
#define GET_SCANLINE 0x45
#define WRITE_BRIGHTNESS 0x51
#define READ_BRIGHTNESS 0x52
#define WRITE_CTRL_DISPLAY 0x53
#define READ_CTRL_DISPLAY 0x54
#define WRITE_BRIGHTNESS_CTL 0x55
#define READ_BRIGHTNESS_CTL 0x56
#define WRITE_MIN_BRIGHTNESS 0x5E
#define READ_MIN_BRIGHTNESS 0x5F
#define READ_ID1 0xDA
#define READ_ID2 0xDB
#define READ_ID3 0xDC
#define RGB_IF_SIGNAL_CTL 0xB0
#define NORMAL_FRAME_CTL 0xB1
#define IDLE_FRAME_CTL 0xB2
#define PARTIAL_FRAME_CTL 0xB3
#define INVERSION_CTL 0xB4
#define BLANK_PORCH_CTL 0xB5
#define DISPLAY_FUNCTION_CTL 0xB6
#define ENTRY_MODE_SET 0xB7
#define BACKLIGHT_CTL1 0xB8
#define BACKLIGHT_CTL2 0xB9
#define BACKLIGHT_CTL3 0xBA
#define BACKLIGHT_CTL4 0xBB
#define BACKLIGHT_CTL5 0xBC
#define BACKLIGHT_CTL7 0xBE
#define BACKLIGHT_CTL8 0xBF
#define POWER_CTL1 0xC0
#define POWER_CTL2 0xC1
#define VCOM_CTL1 0xC5
#define VCOM_CTL2 0xC7
#define NV_MEMORY_WRITE 0xD0
#define NV_MEMORY_PROTECT_KEY 0xD1
#define NV_MEMORY_STATUS_READ 0xD2
#define READ_ID4 0xD3
#define POSITIVE_GAMMA_CORRECT 0xE0
#define NEGATIVE_GAMMA_CORRECT 0xE1
#define DIGITAL_GAMMA_CTL1 0xE2
#define DIGITAL_GAMMA_CTL2 0xE3
#define INTERFACE_CTL 0xF6

#define SPI_CHANNEL 0
#define SPI_SLAVE_SELECT 2

void io_init(void);
void st7789_init(void);
void set_cmd(uint8_t cmd);
void set_data(uint8_t *data, uint8_t len);

/* LCD显示方向 */
typedef enum _lcd_dir {
  DIR_XY_RLUD = 0x00,
  DIR_YX_RLUD = 0x20,
  DIR_XY_LRUD = 0x40,
  DIR_YX_LRUD = 0x60,
  DIR_XY_RLDU = 0x80,
  DIR_YX_RLDU = 0xA0,
  DIR_XY_LRDU = 0xC0,
  DIR_YX_LRDU = 0xE0,
  DIR_XY_MASK = 0x20,
  DIR_MASK = 0xE0,
} lcd_dir_t;

/* LCD结构体 */
typedef struct _lcd_ctl {
  uint8_t dir;
  uint16_t width;
  uint16_t height;
} lcd_ctl_t;

void lcd_init(void);                                      // as you see
void lcd_clear(uint16_t color);                           //清屏
void tft_fill_data(uint32_t *data_buf, uint32_t length);  //发送同样的数据
void lcd_set_area(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);  //画框
void lcd_set_direction(lcd_dir_t dir);                                  //方向
void set_data(uint8_t *data, uint8_t len);                 // as you see
void set_cmd(uint8_t cmd);                                 // as you see
void draw_point(uint16_t x, uint16_t y, uint16_t colocr);  // point
void write_16bit(uint16_t *data_buf, uint32_t length);     // as you see
void draw_line(uint16_t, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void lcd_draw_char(uint16_t x, uint16_t y, char c, uint16_t color);
void lcd_draw_string(uint16_t x, uint16_t y, char *str, uint16_t color);
void lcd_draw_picture(uint16_t x1, uint16_t y1, uint16_t width, uint16_t height,
                      uint32_t *ptr);
void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                        uint16_t width, uint16_t color);
#endif
