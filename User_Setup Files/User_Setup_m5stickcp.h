//                            USER DEFINED SETTINGS
//                         (For For M5Stick CPlus 1)
//
//   Set driver type, fonts to be loaded, pins used and SPI control method etc
//
//   See the User_Setup_Select.h file if you wish to be able to define multiple
//   setups and then easily select which setup file is used by the compiler.
//
//   If this file is edited correctly then all the library example sketches should
//   run without the need to make any more changes for a particular hardware setup!
//   Note that some sketches are designed for a particular TFT pixel width/height

// ##############################################################################################
// Section 1. Call up the driver file and any options for it
//
   #define CGRAM_OFFSET  // (Character Generator RAM), a specific memory region in the LCD controller.
// 
   #define ST7789_2_DRIVER  // M5stick C Plus 1&2 driver
   
// ##############################################################################################

// ##############################################################################################
// Define additional parameters below for this display
// Define the colour order IF the blue and red are swapped on your display
// Try ONE option at a time to find the correct colour order for your display
//
   #define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
// #define TFT_RGB_ORDER TFT_BGR  // Colour order Blue-Green-Red

// ##############################################################################################

// ##############################################################################################
// For M5stick, define the pixel width and height in portrait orientation
//
   #define TFT_WIDTH  135 // M5Stick CPlus 1&2
   #define TFT_HEIGHT 240 // M5Stick CPlus 1&2
   
// ##############################################################################################

// ##############################################################################################
// If colours are inverted (white shows as black) then uncomment one of the next
// 2 lines try both options, one of the options should correct the inversion.
//
// #define TFT_INVERSION_ON
// #define TFT_INVERSION_OFF

// ##############################################################################################

// ##############################################################################################
// If a backlight control signal is available then define the TFT_BL pin in Section 2
// below. The backlight will be turned ON when tft.begin() is called, but the library
// needs to know if the LEDs are ON with the pin HIGH or LOW. If the LEDs are to be
// driven with a PWM signal or turned OFF/ON then this must be handled by the user
// sketch. e.g. with digitalWrite(TFT_BL, LOW);
//
   #define TFT_BACKLIGHT_ON LOW  // (LOW For minigotchi on M5StickCPlus1) (Normally is LOW)
   
// ##############################################################################################

// ##############################################################################################
// ########## DISPLAY PIN NUMBERS FOR M5STICKCPLUS1.1 ###############
// The hardware SPI can be mapped to any pins
// For the M5StickCPlus1 module use these #define lines
//
// #define TOUCH_CS -1 
// #define TFT_MISO 19
   #define TFT_CS   5      // 5 normally. Chip select control pin D8
   #define TFT_DC   23     // 23 normally. Data Command control pin
   #define TFT_RST  18     // 18 normally. Reset pin (could connect to NodeMCU RST, see next line)
   #define TFT_MOSI 15     // 15 normally.
   #define TFT_SCLK 13     // 13 normally.
   #define TFT_BL   -1     // -1 normally
   
// ##############################################################################################
   
// ##############################################################################################
// Section 3. Define the fonts that are to be used here
// Comment out the #defines below with // to stop that font being loaded
// The ESP8366 and ESP32 have plenty of memory so commenting out fonts is not
// normally necessary. If all fonts are loaded the extra FLASH space required is
// about 17Kbytes. To save FLASH space only enable the fonts you need!
//
   #define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
   #define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
   #define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
   #define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
   #define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
   #define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
// #define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
   #define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts
   
// ##############################################################################################

// ##############################################################################################
// Comment out the #define below to stop the SPIFFS filing system and smooth font code being loaded
// this will save ~20kbytes of FLASH
//
   #define SMOOTH_FONT
   
// ##############################################################################################   
   
// ##############################################################################################
//
// Section 4. Other options
//
// Define the SPI clock frequency, this affects the graphics rendering speed. Too
// fast and the TFT driver will not keep up and display corruption appears.
// With an ILI9341 display 40MHz works OK, 80MHz sometimes fails
// With a ST7735 display more than 27MHz may not work (spurious pixels and lines)
// With an ILI9163 display 27 MHz works OK.
// 
// #define SPI_FREQUENCY   1000000
// #define SPI_FREQUENCY   5000000
// #define SPI_FREQUENCY  10000000
   #define SPI_FREQUENCY  20000000
// #define SPI_FREQUENCY  27000000 // Marauder // Actually sets it to 26.67MHz = 80/3
// #define SPI_FREQUENCY  40000000
// #define SPI_FREQUENCY  80000000

// Optional reduced SPI frequency for reading TFT
   #define SPI_READ_FREQUENCY  20000000

// The XPT2046 requires a lower SPI clock rate of 2.5MHz so we define that here:
   #define SPI_TOUCH_FREQUENCY  2500000

// The ESP32 has 2 free SPI ports i.e. VSPI and HSPI, the VSPI is the default.
// If the VSPI port is in use and pins are not accessible (e.g. TTGO T-Beam)
// then uncomment the following line:
// #define USE_HSPI_PORT

// Comment out the following #define if "SPI Transactions" do not need to be
// supported. When commented out the code size will be smaller and sketches will
// run slightly faster, so leave it commented out unless you need it!

// Transaction support is needed to work with SD library but not needed with TFT_SdFat
// Transaction support is required if other SPI devices are connected.

// Transactions are automatically enabled by the library for an ESP32 (to use HAL mutex)
// so changing it here has no effect

// #define SUPPORT_TRANSACTIONS