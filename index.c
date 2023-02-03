// #include <math.h>
#include <limits.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"



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
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

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

#define NUM_BUTTON_TEXT_X_OFFSET -5 //ボタン中央からのオフセット
#define NUM_BUTTON_TEXT_Y_OFFSET -8 //ボタン中央からのオフセット

#define NUM_BUTTON_1_ROW_Y_CENTER  150  //1行目(1番上のY座標)
#define NUM_BUTTON_Y_OFFSET  28 // 2行目以降は、前の行のボタンY + 30 の高さにレンダリングする
#define NUM_BUTTON_1_COLUMN_X_CENTER  44 // 1列目(左揃端のX座標)
#define NUM_BUTTON_X_OFFSET  38 // 2列目以降は、前の列のボタンX + 40 右にレンダリングする

#define NUM_BUTTON_CIRCLE_R 20
#define NUM_BUTTON_CIRCLE_FILL_R 17
/************************************************************************************************/



// global variable define
/************************************************************************************************/
long curValue = 0;

/************************************************************************************************/

// Use SPI
#define TFT_CS 10
#define TFT_DC 9
#define LED_PIN 4
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup(void)
{
  Serial.begin(9600);
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
  tft.fillScreen(ILI9341_BLACK);

  renderOperatorButton('+');
  renderOperatorButton('-');
  renderOperatorButton('*');
  renderOperatorButton('/');

  renderDisplayValue(0);

  renderNumButton(0x9);
  renderNumButton(0x8);
  renderNumButton(0x7);
  renderNumButton(0x6);
  renderNumButton(0x5);
  renderNumButton(0x4);
  renderNumButton(0x3);
  renderNumButton(0x2);
  renderNumButton(0x1);

  renderZEROButton();
  renderAppButton();




}

void loop()
{
}

/**
   @param operator_ '+' | '-' | '*' | '/'

    todo 掛け算記号のフォント作成

*/
void renderOperatorButton(char operator_)
{
  tft.setTextColor(BULE_COLOR);
  tft.setTextSize(OPERATOR_BUTTON_FONT_SIZE);

  switch (operator_)
  {
    case '+':
      tft.drawRGBBitmap(ADD_BUTTON_X, OPERATOR_BUTTON_Y, operatorWrapBitmap, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
      tft.setCursor(ADD_BUTTON_X + OPERATOR_BUTTON_FONT_X_OFFSET, OPERATOR_BUTTON_Y + OPERATOR_BUTTON_FONT_Y_OFFSET);
      tft.println("+");
      break;
    case '-':
      tft.drawRGBBitmap(SUB_BUTTON_X, OPERATOR_BUTTON_Y, operatorWrapBitmap, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
      tft.setCursor(SUB_BUTTON_X + OPERATOR_BUTTON_FONT_X_OFFSET, OPERATOR_BUTTON_Y + OPERATOR_BUTTON_FONT_Y_OFFSET);
      tft.println("-");
      break;
    case '*':
      tft.drawRGBBitmap(MUL_BUTTON_X, OPERATOR_BUTTON_Y, operatorWrapBitmap, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
      tft.setCursor(MUL_BUTTON_X + OPERATOR_BUTTON_FONT_X_OFFSET, OPERATOR_BUTTON_Y + OPERATOR_BUTTON_FONT_Y_OFFSET);
      tft.println("*");
      break;
    case '/':
      tft.drawRGBBitmap(DIV_BUTTON_X, OPERATOR_BUTTON_Y, operatorWrapBitmap, OPERATORWRAP_WIDTH, OPERATORWRAP_HEIGHT);
      tft.setCursor(DIV_BUTTON_X + OPERATOR_BUTTON_FONT_X_OFFSET, OPERATOR_BUTTON_Y + OPERATOR_BUTTON_FONT_Y_OFFSET);
      tft.println("/");
      break;
    default:
      Serial.println("error! invalid argument");
      break;
  }
}

/**
   桁数に応じて、左揃えになるようにレンダリングされる

   @param  nextValue 表示する値

*/
void renderDisplayValue(long nextValue)
{
  clearDisplayValue();

  curValue = nextValue;
  unsigned int digit = getDigit(nextValue);
  //   Serial.println("digit");
  //   Serial.println(digit);
  int textLengthPx = getFontSizePx(DISPLAY_VALUE_FONT_SIZE) * digit;
  //   Serial.println("textLengthPx");
  //   Serial.println(textLengthPx);
  int x = DISPLAY_VALUE_RIGHT_END - textLengthPx;
  //   Serial.println("x");
  //   Serial.println(x);
  tft.setTextColor(DISPLAY_VALUE_COLOR);
  tft.setTextSize(DISPLAY_VALUE_FONT_SIZE);
  tft.setCursor(x, DISPLAY_VALUE_Y);
  tft.println(nextValue);
}

void clearDisplayValue()
{
  tft.fillRect(DISPLAY_VALUE_X, DISPLAY_VALUE_Y, DISPLAY_VALUE_WIDTH, DISPLAY_VALUE_HEIGHT, ILI9341_BLACK);
}


/**
   数値入力ボタンをレンダリング

   @param  num ボタンの中の数字(1～9)

*/
void renderNumButton(uint8_t num)
{
  tft.setTextColor(NUM_BUTTON_TEXT_COLOR );
  tft.setTextSize(NUM_BUTTON_TEXT_SIZE  );

  int x, y; //ボタンの中央
  char c_num; //ボタンに表示する数

  switch (num)
  {
    // 1:上,2:右の優先度で記述
    case 0x9:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 2);
      y = NUM_BUTTON_1_ROW_Y_CENTER;
      c_num = '9';
      break;
    case 0x7:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 1);
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 1 );
      c_num = '7';
      break;
    case 0x8:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 3);
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 1 );
      c_num = '8';
      break;
    case 0x4:
      x = NUM_BUTTON_1_COLUMN_X_CENTER  ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 2 );
      c_num = '4';
      break;
    case 0x5:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 2) ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 2 );
      c_num = '5';
      break;
    case 0x6:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 4) ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 2 );
      c_num = '6';
      break;
    case 0x2:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 1) ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 3 );
      c_num = '2';
      break;
    case 0x3:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 3) ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 3 );
      c_num = '3';
      break;
    case 0x1:
      x = NUM_BUTTON_1_COLUMN_X_CENTER + (NUM_BUTTON_X_OFFSET  * 2) ;
      y = NUM_BUTTON_1_ROW_Y_CENTER   + (NUM_BUTTON_Y_OFFSET * 4 );
      c_num = '1';
      break;
    default:
      Serial.println("error! invalid argument");
      break;
  }

  tft.fillCircle( x, y, NUM_BUTTON_CIRCLE_R, NUM_BUTTON_CIRCLE_COLOR );
  tft.fillCircle(x, y, NUM_BUTTON_CIRCLE_FILL_R, NUM_BUTTON_FILL_COLOR  );
  tft.setCursor(x + NUM_BUTTON_TEXT_X_OFFSET, y + NUM_BUTTON_TEXT_Y_OFFSET );
  tft.println(c_num);
}


/**
   0入力ボタンをレンダリング

   todo 定数化
*/
void renderZEROButton()
{
  tft.fillCircle( 30, 290, 28,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( 30, 290, 26,  NUM_BUTTON_FILL_COLOR);
  tft.setCursor( 30 - 12, 290 - 17);
  tft.setTextSize(5);
  tft.println(0);
}



/**
   右下の6コのボタンをレンダリング

   Cボタン:リセットボタン

   todo どのようなボタンを配置してどのような機能を持たせるのか考える
   todo 定数化&リファクタリング
*/
void renderAppButton()
{

  int xb = 220 ;
  int yb = 232;
  int xo = -16;
  int yo = 23;


  tft.fillCircle( xb, yb, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb, yb, 11,  NUM_BUTTON_FILL_COLOR);
  tft.setCursor( xb - 4, yb - 8);
  tft.setTextSize(2);
  tft.println('c');

  tft.fillCircle( xb + xo, yb + yo, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb + xo, yb + yo, 11,  NUM_BUTTON_FILL_COLOR);

  tft.fillCircle( xb + xo * 2, yb + yo * 2, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb + xo * 2, yb + yo * 2, 11,  NUM_BUTTON_FILL_COLOR);

  tft.fillCircle( xb + xo * 3, yb + yo * 3, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb + xo * 3, yb + yo * 3, 11,  NUM_BUTTON_FILL_COLOR);

  // 右下
  tft.fillCircle( xb, yb + yo * 2, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb, yb + yo  * 2, 11,  NUM_BUTTON_FILL_COLOR);

  tft.fillCircle( xb + xo, yb + yo * 3, 12,  NUM_BUTTON_CIRCLE_COLOR);
  tft.fillCircle( xb + xo, yb + yo * 3, 11,  NUM_BUTTON_FILL_COLOR);
}

// 座標算出用関数
/************************************************************************************************/

int getFontSizePx(int size)
{
  return size * 6;
}
/************************************************************************************************/

// 計算系汎用関数
/************************************************************************************************/

/**
   10進整数の桁数を求める

   @param  n: 対象の整数
   @return n の桁数。0 は 1桁とみなす。
*/
unsigned int getDigit(long n)
{
  unsigned int digit = 1;

  while (n /= 10)
  {
    ++digit;
  };

  return digit;
}
/************************************************************************************************/
