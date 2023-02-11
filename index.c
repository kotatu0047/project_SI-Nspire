// #include <math.h>
#include <limits.h>
#include <math.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <XPT2046_Touchscreen.h>
// #include <Wire.h>
// #include <Adafruit_STMPE610.h>

// color define
/************************************************************************************************/
#define WHITE_COLOR 0x0000
#define DEEP_BULE_COLOR 0x617c
#define BULE_COLOR 0x2d5f
#define CYAN_COLOR 0x07FF
/************************************************************************************************/

// display define
/************************************************************************************************/
#define DISPLAY_X_CENTER 120
#define DISPLAY_Y_CENTER 160
/************************************************************************************************/

// display value define
/************************************************************************************************/
#define DISPLAY_VALUE_COLOR 0x07FF
#define DISPLAY_VALUE_RIGHT_END 215 // 240 -25
#define DISPLAY_VALUE_X 25
#define DISPLAY_VALUE_Y 50
#define DISPLAY_VALUE_WIDTH 190
#define DISPLAY_VALUE_HEIGHT 25
#define DISPLAY_VALUE_FONT_SIZE 3

/************************************************************************************************/

// OPERATOR_BUTTON define
/************************************************************************************************/
#define OPERATORWRAP_WIDTH 40
#define OPERATORWRAP_HEIGHT 60

const PROGMEM uint16_t operatorWrapBitmap[OPERATORWRAP_WIDTH * OPERATORWRAP_HEIGHT] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0x0000, 0x0000, 0x0000, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0xdfff, 0x0000, 0x0000, 0x0000, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0xb699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};

#define ADD_BUTTON_X 25
#define SUB_BUTTON_X 65
#define MUL_BUTTON_X 135
#define DIV_BUTTON_X 175
#define OPERATOR_BUTTON_Y 80
#define OPERATOR_BUTTON_TEXT_COLOR 0x2d5f
#define OPERATOR_BUTTON_FONT_SIZE 2
#define OPERATOR_BUTTON_FONT_X_OFFSET 15
#define OPERATOR_BUTTON_FONT_Y_OFFSET 24
/************************************************************************************************/

// num button (1~9)  define
/************************************************************************************************/
#define NUM_BUTTON_CIRCLE_COLOR 0x2d5f
#define NUM_BUTTON_FILL_COLOR 0x0000
#define NUM_BUTTON_TEXT_COLOR 0x2d5f
#define NUM_BUTTON_TEXT_SIZE 2

#define NUM_BUTTON_TEXT_X_OFFSET -5 // ボタン中央からのオフセット
#define NUM_BUTTON_TEXT_Y_OFFSET -8 // ボタン中央からのオフセット

#define NUM_BUTTON_1_ROW_Y_CENTER 150   // 1行目(1番上のY座標)
#define NUM_BUTTON_Y_OFFSET 28          // 2行目以降は、前の行のボタンY + 30 の高さにレンダリングする
#define NUM_BUTTON_1_COLUMN_X_CENTER 44 // 1列目(左揃端のX座標)
#define NUM_BUTTON_X_OFFSET 38          // 2列目以降は、前の列のボタンX + 40 右にレンダリングする

#define NUM_BUTTON_CIRCLE_R 20
#define NUM_BUTTON_CIRCLE_FILL_R 17
/************************************************************************************************/

// 0 button  define
/************************************************************************************************/
#define ZERO_BUTTON_TEXT_X_OFFSET -12 // ボタン中央からのオフセット
#define ZERO_BUTTON_TEXT_Y_OFFSET -17 // ボタン中央からのオフセット

#define ZERO_BUTTON_CIRCLE_R 28
#define ZERO_BUTTON_CIRCLE_FILL_R 26
/************************************************************************************************/

// appボタン C,=,A,D  define
/************************************************************************************************/
#define APP_BUTTON_CIRCLE_COLOR 0x2d5f
#define APP_BUTTON_FILL_COLOR 0x0000
#define APP_BUTTON_TEXT_COLOR 0x2d5f
#define APP_BUTTON_TEXT_SIZE 2
#define APP_BUTTON_TEXT_X_OFFSET -4 // ボタン中央からのオフセット
#define APP_BUTTON_TEXT_Y_OFFSET -8 // ボタン中央からのオフセット
#define APP_BUTTON_CIRCLE_R 12
#define APP_BUTTON_CIRCLE_FILL_R 11
/************************************************************************************************/

// appボタン C,=,A,D  define
/************************************************************************************************/
#define APP_BUTTON_CIRCLE_COLOR 0x2d5f
#define APP_BUTTON_FILL_COLOR 0x0000
#define APP_BUTTON_TEXT_COLOR 0x2d5f
#define APP_BUTTON_TEXT_SIZE 2
#define APP_BUTTON_TEXT_X_OFFSET -4 // ボタン中央からのオフセット
#define APP_BUTTON_TEXT_Y_OFFSET -7 // ボタン中央からのオフセット
#define APP_BUTTON_CIRCLE_R 12
#define APP_BUTTON_CIRCLE_FILL_R 11
/************************************************************************************************/

// touch screen define
/************************************************************************************************/
#define TOUCH_SCREEN_TOP_X 280.0     // 左上
#define TOUCH_SCREEN_TOP_Y 300.0     // 左上
#define TOUCH_SCREEN_BOTTOM_X 3780.0 // 右下
#define TOUCH_SCREEN_BOTTOM_Y 3680.0 // 右下

typedef struct PointPx PointPx;

struct PointPx
{
  int x;
  int y;
};
/************************************************************************************************/

// タッチ判定系 define
/************************************************************************************************/

// タッチ判定関数の種類
typedef enum
{
  SQUARE,
  CIRCLE,
} TouchFuncKind;

// 全ボタンの種別をここに登録すること ウィンドウ名__ボタン種別__ボタン詳細
typedef enum
{
  CALC__NUMBUTTON__ZERO = 0, // 0
  // 1-9
  CALC__NUMBUTTON__NUM01 = 1,
  CALC__NUMBUTTON__NUM02 = 2,
  CALC__NUMBUTTON__NUM03 = 3,
  CALC__NUMBUTTON__NUM04 = 4,
  CALC__NUMBUTTON__NUM05 = 5,
  CALC__NUMBUTTON__NUM06 = 6,
  CALC__NUMBUTTON__NUM07 = 7,
  CALC__NUMBUTTON__NUM08 = 8,
  CALC__NUMBUTTON__NUM09 = 9,

  EMPTY_SET_BUTTON = 10, // どのボタンでもない

  CALC__OPERATOR__ADD, // +
  CALC__OPERATOR__SUB, // -
  CALC__OPERATOR__MUL, // *
  CALC__OPERATOR__DIV, // /

  // App button
  CALC__APPBUTTON__AC,    // C
  CALC__APPBUTTON__DEL,   // D
  CALC__APPBUTTON__EQUAL, // =
  CALC__APPBUTTON__ANS,   // A
} ButtonKind;

typedef struct TouchFuncCallParams TouchFuncCallParams;

// 部分適用されたタッチ検出関数...のようなもの
struct TouchFuncCallParams
{
  TouchFuncKind touchFuncKind; // 呼び出す関数の種類
  ButtonKind buttonKind;       // ボタンの種類
  int param2;                  // 第2以降の引数 (第1引数はPointPx) 使わない引数は0で初期化する
  int param3;
  int param4;
  int param5;
};
/************************************************************************************************/

// 電卓処理系  define
/************************************************************************************************/
// 演算子の種類
typedef enum
{
  OPERATOR_EMPTY_SET = 0, // どの演算子でもない
  OPERATOR_ADD,
  OPERATOR_SUB,
  OPERATOR_MUL,
  OPERATOR_DIV,
} CalcOperatorKind;

/************************************************************************************************/

// 処理分岐系系  define
/************************************************************************************************/
// エラー種別
typedef enum
{
  ERROR_EMPTY_SET = 0,
  ERROR_OVERFLOW,
} ErrorKind;

/************************************************************************************************/

// global variable define
/************************************************************************************************/
long G_afterValue = 0;                              // 以前入力した値
long G_curValue = 0;                                // 現在の入力値(大きい方)
CalcOperatorKind G_curOprator = OPERATOR_EMPTY_SET; // 現在選択している演算子
bool G_hasError = false;                            // trueの時はエラーメッセージを表示中

// 各入力ボタンによって入力される数  インデックスがButtonKindと対応している
int G_inputNumSet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

#define TOUCH_EVENT_LISTENER_LIST_LENGTH 25
// 有効になっているタッチ判定関数のリスト(ボタンを表示したらこの配列の中に登録すること& ボタンを削除したら
//                                     登録したものをNULLにすること)
TouchFuncCallParams *G_touchEventListenerList[TOUCH_EVENT_LISTENER_LIST_LENGTH] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

// エラーメッセージ
String G_notHasError = "";
String G_overflowMessage = "overflow!";

/************************************************************************************************/

// Use SPI
/************************************************************************************************/
#define TFT_CS 10
#define TFT_DC 9
#define LED_PIN 4

#define CS_PIN 8
// MOSI=11, MISO=12, SCK=13

// XPT2046_Touchscreen ts(CS_PIN);
#define TIRQ_PIN 2
// XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
// XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN); // Param 2 - Touch IRQ Pin - interrupt enabled polling
/************************************************************************************************/

// setup
/************************************************************************************************/
void setup(void)
{
  Serial.begin(9600);
  Serial.println("\n\n\n\n");
  Serial.println("start!");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, 1);

  //   Serial.println( INT_MIN); -32768
  //   Serial.println( INT_MAX); 32767
  //   Serial.println( UINT_MAX); -65535
  //   Serial.println( LONG_MIN); -2147483648
  //   Serial.println( LONG_MAX); 2147483647
  //   Serial.println( ULONG_MAX); 4294967295

  tft.begin();
  ts.begin();
  ts.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);

  PointPx px = {0, 0};

  renderOperatorButton(OPERATOR_ADD, &px);
  addTouchEventListner(SQUARE, CALC__OPERATOR__ADD, px.x, px.y, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
  renderOperatorButton(OPERATOR_SUB, &px);
  addTouchEventListner(SQUARE, CALC__OPERATOR__SUB, px.x, px.y, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
  renderOperatorButton(OPERATOR_MUL, &px);
  addTouchEventListner(SQUARE, CALC__OPERATOR__MUL, px.x, px.y, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
  renderOperatorButton(OPERATOR_DIV, &px);
  addTouchEventListner(SQUARE, CALC__OPERATOR__DIV, px.x, px.y, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);

  renderAfterValue(0);
  renderCurrentValue(0);

  renderNumButton(CALC__NUMBUTTON__NUM09, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM09, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM08, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM08, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM07, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM07, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM06, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM06, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM05, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM05, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM04, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM04, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM03, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM03, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM02, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM02, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);
  renderNumButton(CALC__NUMBUTTON__NUM01, false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__NUM01, px.x, px.y, NUM_BUTTON_CIRCLE_R, 0);

  renderZeroButton(false, &px);
  addTouchEventListner(CIRCLE, CALC__NUMBUTTON__ZERO, px.x, px.y, ZERO_BUTTON_CIRCLE_R, 0);

  renderAppButton(CALC__APPBUTTON__AC, false, &px);
  addTouchEventListner(CIRCLE, CALC__APPBUTTON__AC, px.x, px.y, APP_BUTTON_CIRCLE_R, 0);
  renderAppButton(CALC__APPBUTTON__DEL, false, &px);
  addTouchEventListner(CIRCLE, CALC__APPBUTTON__DEL, px.x, px.y, APP_BUTTON_CIRCLE_R, 0);
  renderAppButton(CALC__APPBUTTON__EQUAL, false, &px);
  addTouchEventListner(CIRCLE, CALC__APPBUTTON__EQUAL, px.x, px.y, APP_BUTTON_CIRCLE_R, 0);
  renderAppButton(CALC__APPBUTTON__ANS, false, &px);
  addTouchEventListner(CIRCLE, CALC__APPBUTTON__ANS, px.x, px.y, APP_BUTTON_CIRCLE_R, 0);

  // Serial.print(G_touchEventListenerList[0]->buttonKind);
  // Serial.print(G_touchEventListenerList[0]->param2  );
}
/************************************************************************************************/

// loop
/************************************************************************************************/
void loop()
{
  if (ts.touched())
  {
    PointPx px = {0, 0};
    getTouchPoint(&px);
    Serial.print("px, x = ");
    Serial.print(px.x);
    Serial.print(",px y = ");
    Serial.print(px.y);
    Serial.println();

    TouchFuncCallParams *isTouchUi = excuteTouchEventFunc(&px);
    ButtonKind crurrentTouchButton = EMPTY_SET_BUTTON;
    while (ts.touched())
    {
      if (isTouchUi != NULL)
      {
        if (crurrentTouchButton == EMPTY_SET_BUTTON)
        { // タッチペンを離した状態から、直接ボタンをタッチした時
          Serial.print("crurrentTouchButton 359:");
          Serial.println(isTouchUi->buttonKind);
          callEventOnButtonTouch(isTouchUi->buttonKind);
          crurrentTouchButton = isTouchUi->buttonKind;
        }
        if (crurrentTouchButton != isTouchUi->buttonKind)
        { // タッチペンをスライドさせて、押してるボタンから別のボタンに移動した時
          Serial.print("crurrentTouchButton 366:");
          Serial.println(crurrentTouchButton);
          callEventOnButtonUnTouch(crurrentTouchButton); // 外れたボタンのアンタッチイベントを実行
          callEventOnButtonTouch(isTouchUi->buttonKind); // スライド先ボタンのタッチイベントを実行
          crurrentTouchButton = isTouchUi->buttonKind;
        }
      }
      else if (crurrentTouchButton != EMPTY_SET_BUTTON)
      { // タッチペンをスライドさせて、押してるボタンから何もない領域に移動した時
        Serial.print("crurrentTouchButton 379:");
        Serial.println(crurrentTouchButton);
        callEventOnButtonUnTouch(crurrentTouchButton);
        crurrentTouchButton = EMPTY_SET_BUTTON;
      }
      getTouchPoint(&px);
      isTouchUi = excuteTouchEventFunc(&px);
    }

    // タッチペンを離した時に、ボタンを押した状態で離した場合、そのボタンのアンタッチイベントを実行
    if (crurrentTouchButton != EMPTY_SET_BUTTON)
    {
      Serial.print("crurrentTouchButton 398:");
      Serial.println(crurrentTouchButton);
      callEventOnButtonUnTouch(crurrentTouchButton);
      crurrentTouchButton = EMPTY_SET_BUTTON;
    }

    // Serial.print("touch UI ,");
    // Serial.print(isTouchUi->touchFuncKind);
    // Serial.println(isTouchUi->buttonKind);
    // Serial.print("::");
    // Serial.print(isTouchUi->param2);
    // Serial.print(",");
    // Serial.print(isTouchUi->param3);
    // Serial.print(",");
    // delay(30);
  }
}
/************************************************************************************************/

// レンダリング系関数
/************************************************************************************************/

/**
 * todo 定数化　docコメント
 *
 */
void renderMessage(String msg, bool useErrorColor)
{
  clearMessage();

  tft.setTextColor(useErrorColor ? ILI9341_RED : BULE_COLOR);
  tft.setTextSize(1);
  tft.setCursor(5, 5);
  tft.println(msg);
}

/**
 * todo 定数化　docコメント
 *
 */
void clearMessage()
{
  tft.fillRect(5, 5, ILI9341_TFTWIDTH, 10, ILI9341_BLACK);
}

/**
   @param _operator +|-|*|/
   @param  px レンダリングしたボタンの中央座標が格納された構造体のメモリアドレス


    todo 掛け算、割り算記号のフォント作成

*/
void renderOperatorButton(CalcOperatorKind _operator, PointPx *px)
{
  tft.setTextColor(BULE_COLOR);
  tft.setTextSize(OPERATOR_BUTTON_FONT_SIZE);
  int x;
  char c;

  switch (_operator)
  {
  case OPERATOR_ADD:
    x = ADD_BUTTON_X;
    c = '+';
    break;
  case OPERATOR_SUB:
    x = SUB_BUTTON_X;
    c = '-';
    break;
  case OPERATOR_MUL:
    x = MUL_BUTTON_X;
    c = '*';
    break;
  case OPERATOR_DIV:
    x = DIV_BUTTON_X;
    c = '/';
    break;
  default:
    Serial.println("error! invalid argument");
    return;
    break;
  }

  tft.drawRGBBitmap(x, OPERATOR_BUTTON_Y, operatorWrapBitmap, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
  tft.setCursor(x + OPERATOR_BUTTON_FONT_X_OFFSET, OPERATOR_BUTTON_Y + OPERATOR_BUTTON_FONT_Y_OFFSET);
  tft.println(c);

  if (px != NULL)
  {
    px->x = x;
    px->y = OPERATOR_BUTTON_Y;
  }
}

/**
 * 実行しようとしている演算子を画面中央に表示
 * todo 定数化
 *
 */
void renderCurrentOperator(CalcOperatorKind operator_)
{
  clearCurrentOperator();
  if (operator_ == OPERATOR_EMPTY_SET)
    return;

  tft.setTextColor(BULE_COLOR);
  tft.setTextSize(3);
  tft.setCursor(105, OPERATOR_BUTTON_Y + 5);
  char c;

  switch (operator_)
  {
  case OPERATOR_ADD:
    c = '+';
    break;
  case OPERATOR_SUB:
    c = '-';
    break;
  case OPERATOR_MUL:
    c = '*';
    break;
  case OPERATOR_DIV:
    c = '/';
    break;
  default:
    Serial.println("error! invalid argument");
    return;
    break;
  }

  tft.println(c);
}

/**
 * 　todo 定数化

*/
void clearCurrentOperator()
{
  tft.fillRect(105, OPERATOR_BUTTON_Y + 5, 20, 20, ILI9341_BLACK);
}

/**
 * 以前の入力値を表示
  桁数+符号に応じて、右揃えになるようにレンダリングされる

 *
 　todo 定数化
 *
*/
void renderAfterValue(long nextAfterValue)
{
  clearAfterValue();

  // if (nextAfterValue == 0)
  //   return; // 0の場合、何も表示せず真っ黒にする

  Serial.print("nextAfterValue");
  Serial.println(nextAfterValue);
  int x = DISPLAY_VALUE_RIGHT_END - getTextLengthPx(nextAfterValue, 1);
  tft.setTextColor(DISPLAY_VALUE_COLOR);
  tft.setTextSize(1);
  tft.setCursor(x, 25);
  tft.println(nextAfterValue);
}

/**
 * 　todo 定数化

*/
void clearAfterValue()
{
  tft.fillRect(100, 25, ILI9341_TFTWIDTH, 10, ILI9341_BLACK);
}

/**
 * 現在の入力値を表示
   桁数+符号に応じて、右揃えになるようにレンダリングされる

   @param  nextValue 表示する値

*/
void renderCurrentValue(long nextValue)
{
  clearCurrentValue();

  Serial.print("next val");
  Serial.println(nextValue);
  int x = DISPLAY_VALUE_RIGHT_END - getTextLengthPx(nextValue, DISPLAY_VALUE_FONT_SIZE);

  tft.setTextColor(DISPLAY_VALUE_COLOR);
  tft.setTextSize(DISPLAY_VALUE_FONT_SIZE);
  tft.setCursor(x, DISPLAY_VALUE_Y);
  tft.println(nextValue);
}

/**
 * 現在の入力値を表示する欄をクリア
 */
void clearCurrentValue()
{
  tft.fillRect(DISPLAY_VALUE_X, DISPLAY_VALUE_Y, ILI9341_TFTWIDTH, DISPLAY_VALUE_HEIGHT, ILI9341_BLACK);
}

/**
   数値入力ボタンをレンダリング

   @param  kind ボタンの種類(1～9)
   @param  highlight  光った状態で表示するか否か
   @param  px レンダリングしたボタンの中央座標が格納された構造体のメモリアドレス
*/
void renderNumButton(ButtonKind kind, bool highlight, PointPx *px)
{
  // Serial.print("start renderNumButton||");
  // Serial.println(highlight);

  int x, y;  // ボタンの中央
  char cNum; // ボタンに表示する数

  switch (kind)
  {
  // 1:上,2:右の優先度で記述
  case CALC__NUMBUTTON__NUM09:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 2);
    y = NUM_BUTTON_1_ROW_Y_CENTER;
    cNum = '9';
    break;
  case CALC__NUMBUTTON__NUM07:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 1);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 1);
    cNum = '7';
    break;
  case CALC__NUMBUTTON__NUM08:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 3);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 1);
    cNum = '8';
    break;
  case CALC__NUMBUTTON__NUM04:
    x = NUM_BUTTON_1_COLUMN_X_CENTER;
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 2);
    cNum = '4';
    break;
  case CALC__NUMBUTTON__NUM05:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 2);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 2);
    cNum = '5';
    break;
  case CALC__NUMBUTTON__NUM06:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 4);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 2);
    cNum = '6';
    break;
  case CALC__NUMBUTTON__NUM02:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 1);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 3);
    cNum = '2';
    break;
  case CALC__NUMBUTTON__NUM03:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 3);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 3);
    cNum = '3';
    break;
  case CALC__NUMBUTTON__NUM01:
    x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET * 2);
    y = NUM_BUTTON_1_ROW_Y_CENTER + (NUM_BUTTON_Y_OFFSET * 4);
    cNum = '1';
    break;
  default:
    Serial.println("error! invalid argument");
    break;
  }

  // Serial.println(cNum);

  tft.fillCircle(x, y, NUM_BUTTON_CIRCLE_R, NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle(x, y, NUM_BUTTON_CIRCLE_FILL_R, highlight ? ILI9341_WHITE : NUM_BUTTON_FILL_COLOR);

  tft.setCursor(x + NUM_BUTTON_TEXT_X_OFFSET, y + NUM_BUTTON_TEXT_Y_OFFSET);
  tft.setTextColor(highlight ? ILI9341_BLACK : NUM_BUTTON_TEXT_COLOR);
  tft.setTextSize(NUM_BUTTON_TEXT_SIZE);
  tft.println(cNum);

  if (px != NULL)
  {
    px->x = x;
    px->y = y;
  }
}

/**
   0入力ボタンをレンダリング

   todo 定数化

   @param  highlight  光った状態で表示するか否か
   @param  px レンダリングしたボタンの中央座標が格納された構造体のメモリアドレス
*/
void renderZeroButton(bool highlight, PointPx *px)
{
  int x = 30, y = 290;

  tft.fillCircle(x, y, ZERO_BUTTON_CIRCLE_R, NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle(x, y, ZERO_BUTTON_CIRCLE_FILL_R, highlight ? ILI9341_WHITE : NUM_BUTTON_FILL_COLOR);
  tft.setCursor(x + ZERO_BUTTON_TEXT_X_OFFSET, y + ZERO_BUTTON_TEXT_Y_OFFSET);
  tft.setTextColor(highlight ? ILI9341_BLACK : NUM_BUTTON_TEXT_COLOR);
  tft.setTextSize(5);
  tft.println(0);

  if (px != NULL)
  {
    px->x = x;
    px->y = y;
  }
}

/**
   右下の6コのボタンをレンダリング

   @param  kind ボタンの種類
   @param  highlight  光った状態で表示するか否か
   @param  px レンダリングしたボタンの中央座標が格納された構造体のメモリアドレス

                   ->[ボタンに表示する文字]
　　AC:リセット     ->[C]
  　DEL:1文字削除   ->[D]
  　=:計算実行       ->[=]
  　ANS:計算実行     ->[A]
    他未定

   todo どのようなボタンを配置してどのような機能を持たせるのか考える
   todo 定数化&リファクタリング
*/
void renderAppButton(ButtonKind kind, bool highlight, PointPx *px)
{

  int xb = 220; // 1番上のボタンのX座標
  int yb = 232; // 1番上のボタンのY座標
  int xo = -16; //  2行目以降は、前のボタンX -16 右にレンダリングする
  int yo = 23;  // 2行目以降は、前のボタンY + 23 の高さにレンダリングする

  int x = 0, y = 0;
  char c; // ボタンに表示する文字

  switch (kind)
  {
  // 1:上,2:右の優先度で記述
  case CALC__APPBUTTON__AC:
    x = xb;
    y = yb;
    c = 'C';

    // 右下2コ 機能が決まってないのでここに仮置き todo 上と同じようにリファクタする
    tft.fillCircle(xb, yb + yo * 2, APP_BUTTON_CIRCLE_R, APP_BUTTON_CIRCLE_COLOR);
    tft.fillCircle(xb, yb + yo * 2, APP_BUTTON_CIRCLE_FILL_R, APP_BUTTON_FILL_COLOR);
    tft.fillCircle(xb + xo, yb + yo * 3, APP_BUTTON_CIRCLE_R, APP_BUTTON_CIRCLE_COLOR);
    tft.fillCircle(xb + xo, yb + yo * 3, APP_BUTTON_CIRCLE_FILL_R, APP_BUTTON_FILL_COLOR);

    break;
  case CALC__APPBUTTON__DEL:
    x = xb + xo;
    y = yb + yo;
    c = 'D';
    break;
  case CALC__APPBUTTON__EQUAL:
    x = xb + xo * 2;
    y = yb + yo * 2;
    c = '=';
    break;
  case CALC__APPBUTTON__ANS:
    x = xb + xo * 3;
    y = yb + yo * 3;
    c = 'A';
    break;
  default:
    Serial.println("error! invalid argument");
    break;
  }

  tft.fillCircle(x, y, APP_BUTTON_CIRCLE_R, APP_BUTTON_CIRCLE_COLOR);
  tft.fillCircle(x, y, APP_BUTTON_CIRCLE_FILL_R, highlight ? ILI9341_WHITE : APP_BUTTON_FILL_COLOR);

  tft.setCursor(x + APP_BUTTON_TEXT_X_OFFSET, y + APP_BUTTON_TEXT_Y_OFFSET);
  tft.setTextColor(highlight ? ILI9341_BLACK : APP_BUTTON_TEXT_COLOR);
  tft.setTextSize(APP_BUTTON_TEXT_SIZE);
  tft.println(c);

  if (px != NULL)
  {
    px->x = x;
    px->y = y;
  }
}
/************************************************************************************************/

// レンダリング系サブ関数
/************************************************************************************************/

/**
 * 桁数に応じて、テキストが取る横幅を取得
 * 負数の場合、ー記号があるため、一文字分増える
 *
 * todo docコメント
 *
 */
int getTextLengthPx(long value, uint8_t fontSize)
{
  uint8_t textLength = getDigit(value);
  if (value < 0)
    textLength++;
  return getFontSizePx(fontSize) * textLength;
}

/************************************************************************************************/

// フォント系関数
/************************************************************************************************/

/**
 * フォントの横幅を取得
 *
 * @param size Adafruit_GFXライブラリのサイズ
 *
 * @return 横幅
 *
 */
int getFontSizePx(int size)
{
  return size * 6;
}
/************************************************************************************************/

// touch screen タッチされた座標の取得
/************************************************************************************************/

/**
 *  タッチされた座標を、240*320に変換して取得する
 *
 *
   @param px 取得した座標を、格納する構造体のポインター
*/
void getTouchPoint(PointPx *px)
{
  int count = 1;
  float toucheSumX = 0.0;
  float toucheSumY = 0.0;
  TS_Point p;
  while (ts.touched() && count <= 10)
  {
    p = ts.getPoint();
    toucheSumX += p.x;
    toucheSumY += p.y;
    count++;
  }

  float caliblationX = toucheSumX / 10.0;
  // Serial.print("caliblationX,");
  // Serial.print(caliblationX);
  float caliblationY = toucheSumY / 10.0;
  // Serial.print("caliblationY,");
  // Serial.println(caliblationY);

  convertTouchScreenToPx(caliblationX, caliblationY, px);
}

/**
 *  座標を、240*320に変換
 *
 * @param caliblationX タッチされた座標 TS_Point.x
 * @param caliblationY タッチされた座標 TS_Point.y
 *
   @param px 変換した座標を格納する構造体のポインター
*/
void convertTouchScreenToPx(float caliblationX, float caliblationY, PointPx *px)
{

  int x = ((caliblationX - TOUCH_SCREEN_TOP_X) / (TOUCH_SCREEN_BOTTOM_X - TOUCH_SCREEN_TOP_X)) * ILI9341_TFTWIDTH;
  int y = ((caliblationY - TOUCH_SCREEN_TOP_Y) / (TOUCH_SCREEN_BOTTOM_Y - TOUCH_SCREEN_TOP_Y)) * ILI9341_TFTHEIGHT;
  // PointPx instance ={ (int)x, (int)y } ;
  px->x = x >= ILI9341_TFTWIDTH ? ILI9341_TFTWIDTH : x;
  px->y = y >= ILI9341_TFTHEIGHT ? ILI9341_TFTHEIGHT : y;
  // Serial.print("||||");
  // Serial.print(px->x);
  // Serial.print("||");
  // Serial.print(px->y);
  // Serial.println("||||");
}
/************************************************************************************************/

// タッチ判定系関数
/************************************************************************************************/

/**
 * 四角の中がタッチされたかどうか判定する

 *  @param px 現在タッチされている座標
 *  @param x 四角の左上 x
 *  @param y 四角の左上 y
 *  @param width 四角の横幅
 *  @param height 四角の縦幅
 *
 * @return タッチされた:true,タッチされていない:false
 *
*/
bool isTouchedOnSquare(PointPx *px, int x, int y, int width, int height)
{
  // Serial.println("isTouchedOnSquare");
  // Serial.print("  ,px.x:");
  // Serial.print(px->x);
  // Serial.print("  ,px.y:");
  // Serial.print(px->y);
  // Serial.print("  ,x:");
  // Serial.print(x);
  // Serial.print("  ,y:");
  // Serial.print(y);
  // Serial.print("  ,width:");
  // Serial.print(width);
  // Serial.print("  ,height:");
  // Serial.println(height);

  if (px->x < x || px->x > x + width)
    return false;
  if (px->y < y || px->y > y + height)
    return false;

  return true;
}

/**
 * 円の中がタッチされたかどうか判定する

 *  @param px 現在タッチされている座標
 *  @param centerX 円の中心 x
 *  @param centerY 円の中心 y
 *  @param r 円の半径
 *
 * @return タッチされた:true,タッチされていない:false
 *
*/
bool isTouchedOnCircle(PointPx *px, int centerX, int centerY, int r)
{
  // Serial.print("centerX:");
  // Serial.print(centerX);
  // Serial.print(",centerY:");
  // Serial.print(centerY);

  // 一度原点を0にする
  int x = px->x - centerX;
  int y = px->y - centerY;
  // Serial.print("   x:");
  // Serial.print(x);
  // Serial.print(",y:");
  // Serial.print(y);

  // 原点からの距離を求める
  long line = ((long)x * x + (long)y * y);
  if (line <= 0)
    return false;
  double d = sqrt(line);
  // Serial.print(",d:");
  // Serial.println(d);

  // 原点からの距離が半径R以下なら、円の中がタッチされた判定にする
  if (d <= r)
  {
    return true;
  }

  return false;
}

/************************************************************************************************/

// タッチイベント管理系関数
/************************************************************************************************/

/**
 * ボタンが押された時のイベントを呼ぶ
 *
 * @param kind 押されたボタンの種類
 *
 */
void callEventOnButtonTouch(ButtonKind kind)
{
  switch (kind)
  {
  case CALC__NUMBUTTON__NUM09:
  case CALC__NUMBUTTON__NUM08:
  case CALC__NUMBUTTON__NUM07:
  case CALC__NUMBUTTON__NUM06:
  case CALC__NUMBUTTON__NUM05:
  case CALC__NUMBUTTON__NUM04:
  case CALC__NUMBUTTON__NUM03:
  case CALC__NUMBUTTON__NUM02:
  case CALC__NUMBUTTON__NUM01:
    onNumButtonTouch(kind);
    break;
  case CALC__NUMBUTTON__ZERO:
    onZeroButtonTouch();
    break;
  // todo 演算子ボタンが押された時のリアクション
  case CALC__OPERATOR__ADD:
  case CALC__OPERATOR__SUB:
  case CALC__OPERATOR__MUL:
  case CALC__OPERATOR__DIV:
    break;
  case CALC__APPBUTTON__AC:
  case CALC__APPBUTTON__DEL:
  case CALC__APPBUTTON__EQUAL:
  case CALC__APPBUTTON__ANS:
    onAppButtonTouch(kind);
    break;
  default:
    Serial.println("error! invalid argument"); // todo 他のボタンを押した時のイベントを実装する
    break;
  }
}

/**
 * 1-9の数値入力ボタンが押された時のイベントを呼ぶ
 *
 * @param kind 押されたボタンの種類
 *
 */
void onNumButtonTouch(ButtonKind kind)
{
  renderNumButton(kind, true, NULL);
}

/**
 * 0力ボタンが押された時のイベントを呼ぶ
 *
 */
void onZeroButtonTouch()
{
  renderZeroButton(true, NULL);
}

/**
 * APPボタンが押された時のイベントを呼ぶ
 *
 * @param kind 押されたボタンの種類
 *
 */
void onAppButtonTouch(ButtonKind kind)
{
  renderAppButton(kind, true, NULL);
}

/**
 * ボタンの領域から、タッチペンが離れた時のイベントを呼ぶ
 *
 * @param kind 離したボタンの種類
 *
 */
void callEventOnButtonUnTouch(ButtonKind kind)
{
  // エラーメッセージ表示中に、何かボタンを押した場合、エラーメッセージを非表示にする
  if (G_hasError)
  {
    G_hasError = false;
    renderMessage(G_notHasError, G_hasError)
  }

  switch (kind)
  {
  case CALC__NUMBUTTON__NUM09:
  case CALC__NUMBUTTON__NUM08:
  case CALC__NUMBUTTON__NUM07:
  case CALC__NUMBUTTON__NUM06:
  case CALC__NUMBUTTON__NUM05:
  case CALC__NUMBUTTON__NUM04:
  case CALC__NUMBUTTON__NUM03:
  case CALC__NUMBUTTON__NUM02:
  case CALC__NUMBUTTON__NUM01:
    onNumButtonUnTouch(kind);
    break;
  case CALC__NUMBUTTON__ZERO:
    onZeroButtonUnTouch();
    break;
  case CALC__OPERATOR__ADD:
  case CALC__OPERATOR__SUB:
  case CALC__OPERATOR__MUL:
  case CALC__OPERATOR__DIV:
    ErrorKind hasErrorOnCalc = onOperatorButtonUnTouch(kind);
    if (hasErrorOnCalc == ERROR_OVERFLOW)
    {
      G_hasError = true;
      renderMessage(G_overflowMessage, G_hasError)
    }
    break;
  case CALC__APPBUTTON__AC:
  case CALC__APPBUTTON__DEL:
  case CALC__APPBUTTON__EQUAL:
  case CALC__APPBUTTON__ANS:
    ErrorKind hasErrorOnCalc = onAppButtonUnTouch(kind);
    if (hasErrorOnCalc == ERROR_OVERFLOW)
    {
      G_hasError = true;
      renderMessage(G_overflowMessage, G_hasError)
    }
    break;
  case EMPTY_SET_BUTTON: // 何もしない
    break;
  default:
    Serial.println("error! invalid argument"); // todo 他のボタンのイベントを実装する
    break;
  }
}

/**
 * 1-9の数値入力ボタンを押して離した時のイベントを呼ぶ
 * 押された数を、現在の入力値の末尾に追加、つまり現在の入力値を10倍した後に押された数を加算
 *
 *
 * @param kind 押されたボタンの種類 CALC__NUMBUTTON__NUM01-CALC__NUMBUTTON__NUM09
 *
 */
void onNumButtonUnTouch(ButtonKind kind)
{
  int input = G_inputNumSet[kind];

  // longの範囲は-2,147,483,648から2,147,483,647
  // curValueが整数の場合
  // curValueが 1,000,000,000以上の場合、桁あふれするので10倍にはできない => 入力スルー、何もしない
  // curValueが負数の場合
  // curValueが -1,000,000,000以下の場合、桁あふれするので10倍にはできない => 入力スルー、何もしない

  if (G_curValue >= 1000000000 || G_curValue <= -1000000000)
  {
    return;
  }

  G_curValue = G_curValue * 10 + input;
  renderCurrentValue(G_curValue);
  renderNumButton(kind, false, NULL);
}

/**
 * 0入力ボタンを押して離した時のイベントを呼ぶ
 */
void onZeroButtonUnTouch()
{
  // 桁あふれ対策はonNumButtonUnTouchと同じ
  if (G_curValue >= 1000000000 || G_curValue <= -1000000000)
  {
    return;
  }

  G_curValue = G_curValue * 10;
  renderCurrentValue(G_curValue);
  renderZeroButton(false, NULL);
}

/**
 * 演算子ボタンを押して離した時のイベントを呼ぶ
 *
 * @param buttonKind 押された演算子ボタンの種類

   @return ErrorKind オーバフロー:ERROR_OVERFLOW,それ意外:ERROR_EMPTY_SET

 */
ErrorKind onOperatorButtonUnTouch(ButtonKind buttonKind)
{
  CalcOperatorKind _operator = getCalcOperatorKindFromButtonKind(buttonKind);

  if (_operator == OPERATOR_EMPTY_SET)
    return ERROR_EMPTY_SET;

  // 初期状態orリセット後に演算子ボタンを押した時 現在の入力値を上(G_afterValue)にコピーし、押した演算子を表示する
  if (G_afterValue == 0 && G_curOprator == OPERATOR_EMPTY_SET)
  {

    G_afterValue = G_curValue;
    renderAfterValue(G_afterValue);
    G_curOprator = _operator;
    renderCurrentOperator(G_curOprator);
    return ERROR_EMPTY_SET;
  }

  // G_afterValue,curValueが同じ場合
  //  表示する演算子のみ変える
  if (G_afterValue == G_curValue)
  {
    G_curOprator = _operator;
    renderCurrentOperator(G_curOprator);
    return ERROR_EMPTY_SET;
  }

  // todo 共通化
  // 演算実行 実行する計算は前回入力された演算子を使い、今回入力された演算子は、画面中央に表示するだけ
  // 表示するafterValue,curValueはどちらも、演算結果で上書きする
  if (!checkOverflow(G_afterValue, G_curOprator, G_curValue))
    return ERROR_OVERFLOW;
  long nextValue = calculate(G_afterValue, G_curOprator, G_curValue);

  G_curValue = nextValue;
  renderCurrentValue(G_curValue);
  G_afterValue = nextValue;
  renderAfterValue(G_afterValue);
  G_curOprator = _operator;
  renderCurrentOperator(G_curOprator);
  return ERROR_EMPTY_SET;
}

/**
 * APPボタンが押された時のイベントを呼ぶ
 *
 * @param kind 押されたボタンの種類
 *
   @return ErrorKind オーバフロー:ERROR_OVERFLOW,それ意外:ERROR_EMPTY_SET
 */
ErrorKind onAppButtonUnTouch(ButtonKind kind)
{
   ErrorKind errorKind = ERROR_EMPTY_SET;

  switch (kind)
  {
  // 1:上,2:右の優先度で記述
  case CALC__APPBUTTON__AC:
    G_curValue = 0;
    renderCurrentValue(G_curValue);
    G_afterValue = 0;
    renderAfterValue(G_afterValue);
    G_curOprator = OPERATOR_EMPTY_SET;
    renderCurrentOperator(G_curOprator);
    break;
  case CALC__APPBUTTON__DEL:
    G_curValue = (long)(G_curValue / 10);
    renderCurrentValue(G_curValue);
    break;
  case CALC__APPBUTTON__EQUAL:
    // 演算実行 todo 共通化
    if (!checkOverflow(G_afterValue, G_curOprator, G_curValue))
      errorKind = ERROR_OVERFLOW;
    long nextValue = calculate(G_afterValue, G_curOprator, G_curValue);

    G_curValue = nextValue;
    renderCurrentValue(G_curValue);
    G_afterValue = nextValue;
    renderAfterValue(G_afterValue);
    break;
  case CALC__APPBUTTON__ANS:
    // 演算実行 todo 共通化
    if (!checkOverflow(G_afterValue, G_curOprator, G_curValue))
      return ERROR_OVERFLOW;
    long nextValue = calculate(G_afterValue, G_curOprator, G_curValue);

    G_curValue = nextValue;
    renderCurrentValue(G_curValue);
    G_afterValue = nextValue;
    renderAfterValue(G_afterValue);
  default:
    Serial.println("error! invalid argument");
    break;
  }

  renderAppButton(kind, false, NULL);

  return errorKind;
}

/**
 * タッチ判定関数を登録し、監視を有効化する
 *
 * @param touchFuncKind 呼び出すタッチ判定関数の種類
 * @param buttonKind ボタンの種類
 * @param param2 第2以降の引数 (第1引数はPointPx) 使わない引数は0で初期化する
 * @param param3
 * @param param4
 * @param param5
 *
 */
void addTouchEventListner(TouchFuncKind touchFuncKind, ButtonKind buttonKind,
                          int param2, int param3, int param4, int param5)
{
  TouchFuncCallParams *p = (TouchFuncCallParams *)malloc(sizeof(TouchFuncCallParams));
  p->touchFuncKind = touchFuncKind;
  p->buttonKind = buttonKind;
  p->param2 = param2;
  p->param3 = param3;
  p->param4 = param4;
  p->param5 = param5;
  for (size_t i = 0; i < TOUCH_EVENT_LISTENER_LIST_LENGTH; i++)
  {
    if (G_touchEventListenerList[i] == NULL)
    {
      G_touchEventListenerList[i] = p;
      // Serial.print("add ,  ");
      // Serial.print("x:");
      // Serial.print(G_touchEventListenerList[i]->param2);
      // Serial.print("y:");
      // Serial.println(G_touchEventListenerList[i]->param3);
      return;
    }
  }
}

/**
 * タッチ判定関数を削除し、監視を無効化する
 *
 * @param touchFuncKind 登録した、呼び出すタッチ判定関数の種類
 * @param buttonKind 登録した、ボタンの種類
 * @param param2 登録した、第2以降の引数 (第1引数はPointPx) 使わない引数は0で登録しているはず
 * @param param3
 * @param param4
 * @param param5
 *
 */
void removeTouchEventListner(TouchFuncKind touchFuncKind, ButtonKind buttonKind,
                             int param2, int param3, int param4, int param5)
{
  TouchFuncCallParams *p = NULL;
  for (size_t i = 0; i < TOUCH_EVENT_LISTENER_LIST_LENGTH; i++)
  {
    if (G_touchEventListenerList[i] != NULL)
    {
      p = G_touchEventListenerList[i];
      if (p->touchFuncKind == touchFuncKind && p->buttonKind == buttonKind && p->param2 == param2 && p->param3 == param3 && p->param4 == param4 && p->param5 == param5)
      {
        free(G_touchEventListenerList[i]);
        //?   free(p);
        G_touchEventListenerList[i] = NULL;
        p = NULL;
      }
    }
  }
}

/**
 * タッチ判定関数を実行する
 * touchEventListenerListの関数を先頭から実行していく
 *
 * @param px タッチしている座標
 *
 * @return タッチした場所がボタンの上:実行に使用したTouchFuncCallParams , タッチした場所に何もUIがない:NULL
 *
 */
TouchFuncCallParams *excuteTouchEventFunc(PointPx *px)
{
  bool result = false;
  TouchFuncCallParams *p = NULL;
  for (size_t i = 0; i < TOUCH_EVENT_LISTENER_LIST_LENGTH; i++)
  {
    if (G_touchEventListenerList[i] != NULL)
    {
      p = G_touchEventListenerList[i];
      if (p->touchFuncKind == SQUARE)
      {
        // Serial.println("call isTouchedOnSquare");
        if (isTouchedOnSquare(px, p->param2, p->param3, p->param4, p->param5))
        {
          Serial.println("isTouchedOnSquare:True");
          Serial.print("G_touchEventListenerList index , is ");
          Serial.println(i);
          return G_touchEventListenerList[i];
        }
      }

      if (p->touchFuncKind == CIRCLE)
      {
        // Serial.println("call isTouchedOnCircle");
        if (isTouchedOnCircle(px, p->param2, p->param3, p->param4))
        {
          // Serial.println(i);
          return G_touchEventListenerList[i];
        }
      }
    }
  }

  return NULL;
}

/************************************************************************************************/

//  電卓用算術系関数
/************************************************************************************************/

/**
 * 整数のみ対応
 * 2項の演算結果がオーバフローしないか検出
 * 0割り検査も含む
 * 参考: https://hiroyukichishiro.com/arithmetic-overflow-in-c-language/
 *
 * todo エラー原因詳細を返して、詳細なエラーメッセージを出す
 *
 * @param a 演算対象
 * @param kind 演算子
 * @param b 演算対象
 *
 *
 * @return 正常:true,オーバフロー検出:false
 */
bool checkOverflow(long a, CalcOperatorKind kind, long b)
{
  bool aIsNum = a >= 0;
  bool bIsNum = b >= 0;

  switch (kind)
  {
  case OPERATOR_ADD:

    if ((aIsNum && bIsNum) && (LONG_MAX - a < b))
    {
      return false;
    }
    if ((!aIsNum && !bIsNum) && (a < LONG_MIN - b))
    {
      return false;
    }

    return true;
    break;
  case OPERATOR_SUB:
    if (!(aIsNum ^ bIsNum)) // 同じ符号同士ならオーバフローしない
    {
      return true;
    }
    if ((a > 0 && 0 > b) && (a > LONG_MAX + b))
    {
      return false;
    }
    if ((b > 0 && 0 > a) && (a < LONG_MIN + b))
    {
      return false;
    }

    return true;
    break;
  case OPERATOR_MUL:
    if (a == 0 || b == 0)
    {
      return true;
    }
    long x = a * b;
    if (x / a != b)
    {
      return false;
    }

    return true;
    break;
  case OPERATOR_DIV:
    if (a == LONG_MIN && b == -1)
      return false;
    if (b == 0)
      return false;
    return true;
    break;
  default:
    Serial.println("error! invalid argument");
    break;
  }
}

/**
 * 整数のみ対応
 * 2項の演算
 *
 * @param a 演算対象
 * @param kind 演算子
 * @param b 演算対象
 *
 * @return 演算結果
 */
long calculate(long a, CalcOperatorKind kind, long b)
{
  switch (kind)
  {
  case OPERATOR_ADD:
    return a + b;
    break;
  case OPERATOR_SUB:
    return a - b;
    break;
  case OPERATOR_MUL:
    return a * b;
    break;
  case OPERATOR_DIV:
    return (long)(a / b);
    break;
  default:
    Serial.println("error! invalid argument");
    return 0;
    break;
  }
}

/************************************************************************************************/

// その他関数
/************************************************************************************************/

/**
   getCalcOperatorKindFromButtonKind 名前の通り
   @param  ButtonKind

   @return  CalcOperatorKind
*/
CalcOperatorKind getCalcOperatorKindFromButtonKind(ButtonKind buttonKind)
{
  switch (buttonKind)
  {
  case CALC__OPERATOR__ADD:
    return OPERATOR_ADD;
    break;
  case CALC__OPERATOR__SUB:
    return OPERATOR_SUB;
    break;
  case CALC__OPERATOR__MUL:
    return OPERATOR_MUL;
    break;
  case CALC__OPERATOR__DIV:
    return OPERATOR_DIV;
    break;
  default:
    return OPERATOR_EMPTY_SET;
    break;
  }
}
/************************************************************************************************/

// 計算系汎用関数
/************************************************************************************************/

/**
   10進整数の桁数を求める

   @param  n: 対象の整数
   @return n の桁数。0 は 1桁とみなす。
*/
uint8_t getDigit(long n)
{
  uint8_t digit = 1;

  while (n /= 10)
  {
    ++digit;
  };

  return digit;
}
/************************************************************************************************/
