#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    6
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    68
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];

// ten seconds per color palette makes a good demo
// 20-120 is better for deployment
#define SECONDS_PER_PALETTE 10


void setupLedStrip() {
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS)
  //.setCorrection(TypicalLEDStrip) // cpt-city palettes have different color balance
  .setDither(BRIGHTNESS < 255);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

// Forward declarations of an array of cpt-city gradient palettes, and
// a count of how many there are.  The actual color palette definitions
// are at the bottom of this file.
extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];
extern const uint8_t gGradientPaletteCount;

// Current palette number from the 'playlist' of color palettes
uint8_t gCurrentPaletteNumber = 0;

CRGBPalette16 gCurrentPalette( CRGB::Black);
CRGBPalette16 gTargetPalette( gGradientPalettes[0] );


void loopLedStrip()
{
  int hourNow = TIME_NOW.hour();
  if (DEBUG) {
    hourNow = TIME_NOW.minute() % 24;
  }

  EVERY_N_SECONDS( SECONDS_PER_PALETTE ) {
    gTargetPalette = gGradientPalettes[ hourNow ];
  }

  EVERY_N_MILLISECONDS(40) {
    nblendPaletteTowardPalette( gCurrentPalette, gTargetPalette, 16);
  }

  if (IS_PAUSED) {
    fill_solid( leds, NUM_LEDS, CRGB( 100, 100, 225));
    FastLED.setBrightness(BRIGHTNESS);
  }
  else if (!RELAY3_HOURS[hourNow]) {
    fill_solid( leds, NUM_LEDS, CRGB( 0, 0, 0));
    FastLED.setBrightness(0);
  }
  else {
    colorwaves( leds, NUM_LEDS, gCurrentPalette);
    FastLED.setBrightness(BRIGHTNESS);
  }

  FastLED.show();
  FastLED.delay(20);
}


// This function draws color waves with an ever-changing,
// widely-varying set of parameters, using a color palette.
void colorwaves( CRGB* ledarray, uint16_t numleds, CRGBPalette16& palette)
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;

  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 300, 1500);

  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5, 9);
  uint16_t brightnesstheta16 = sPseudotime;

  for ( uint16_t i = 0 ; i < numleds; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;
    uint16_t h16_128 = hue16 >> 7;
    if ( h16_128 & 0x100) {
      hue8 = 255 - (h16_128 >> 1);
    } else {
      hue8 = h16_128 >> 1;
    }

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);

    uint8_t index = hue8;
    //index = triwave8( index);
    index = scale8( index, 240);

    CRGB newcolor = ColorFromPalette( palette, index, bri8);

    uint16_t pixelnumber = i;
    pixelnumber = (numleds - 1) - pixelnumber;

    nblend( ledarray[pixelnumber], newcolor, 128);
  }
}

// Alternate rendering function just scrolls the current palette
// across the defined LED strip.
void palettetest( CRGB* ledarray, uint16_t numleds, const CRGBPalette16& gCurrentPalette)
{
  static uint8_t startindex = 0;
  startindex--;
  fill_palette( ledarray, numleds, startindex, (256 / NUM_LEDS) + 1, gCurrentPalette, 255, LINEARBLEND);
}


DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
  0, 120,  0,  0,
  22, 179, 22,  0,
  51, 255, 104,  0,
  85, 167, 22, 18,
  135, 100,  0, 103,
  198,  16,  0, 130,
  255,   0,  0, 160
};

DEFINE_GRADIENT_PALETTE( retro2_16_gp ) {
  0, 188, 135,  1,
  255,  46,  7,  1
};

DEFINE_GRADIENT_PALETTE( es_landscape_33_gp ) {
  0,   1,  5,  0,
  19,  32, 23,  1,
  38, 161, 55,  1,
  63, 229, 144,  1,
  66,  39, 142, 74,
  255,   1,  4,  1
};

DEFINE_GRADIENT_PALETTE( GMT_drywet_gp ) {
  0,  47, 30,  2,
  42, 213, 147, 24,
  84, 103, 219, 52,
  127,   3, 219, 207,
  170,   1, 48, 214,
  212,   1,  1, 111,
  255,   1,  7, 33
};

DEFINE_GRADIENT_PALETTE( ib15_gp ) {
  0, 113, 91, 147,
  72, 157, 88, 78,
  89, 208, 85, 33,
  107, 255, 29, 11,
  141, 137, 31, 39,
  255,  59, 33, 89
};

DEFINE_GRADIENT_PALETTE( gr65_hult_gp ) {
  0, 247, 176, 247,
  48, 255, 136, 255,
  89, 220, 29, 226,
  160,   7, 82, 178,
  216,   1, 124, 109,
  255,   1, 124, 109
};

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_036_gp ) {
  0,   1,  6,  7,
  89,   1, 99, 111,
  153, 144, 209, 255,
  255,   0, 73, 82
};

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_068_gp ) {
  0, 100, 156, 153,
  51,   1, 99, 137,
  101,   1, 68, 84,
  104,  35, 142, 168,
  178,   0, 63, 117,
  255,   1, 10, 10
};

DEFINE_GRADIENT_PALETTE( Pink_Purple_gp ) {
  0,  19,  2, 39,
  25,  26,  4, 45,
  51,  33,  6, 52,
  76,  68, 62, 125,
  102, 118, 187, 240,
  109, 163, 215, 247,
  114, 217, 244, 255,
  122, 159, 149, 221,
  149, 113, 78, 188,
  183, 128, 57, 155,
  255, 146, 40, 123
};

DEFINE_GRADIENT_PALETTE( Blue_Cyan_Yellow_gp ) {
  0,   0,  0, 255,
  63,   0, 55, 255,
  127,   0, 255, 255,
  191,  42, 255, 45,
  255, 255, 255,  0
};

DEFINE_GRADIENT_PALETTE( es_rivendell_15_gp ) {
  0,   1, 14,  5,
  101,  16, 36, 14,
  165,  56, 68, 30,
  242, 150, 156, 99,
  255, 150, 156, 99
};

DEFINE_GRADIENT_PALETTE( Analogous_1_gp ) {
  0,   3,  0, 255,
  63,  23,  0, 255,
  127,  67,  0, 255,
  191, 142,  0, 45,
  255, 255,  0,  0
};

const TProgmemRGBGradientPalettePtr gGradientPalettes[] = {
  Sunset_Real_gp,
  Sunset_Real_gp,
  Sunset_Real_gp,
  Sunset_Real_gp,
  Sunset_Real_gp,
  Sunset_Real_gp,
  Sunset_Real_gp,     //6
  retro2_16_gp,
  es_landscape_33_gp,
  es_landscape_33_gp, //9
  GMT_drywet_gp,
  GMT_drywet_gp,
  ib15_gp,            //12
  ib15_gp,
  GMT_drywet_gp,
  es_landscape_33_gp, //15
  retro2_16_gp,
  retro2_16_gp,
  Sunset_Real_gp,         //18
  es_ocean_breeze_036_gp,
  es_ocean_breeze_068_gp,
  Pink_Purple_gp,         //21
  Blue_Cyan_Yellow_gp,
  es_rivendell_15_gp
};

const uint8_t gGradientPaletteCount = sizeof( gGradientPalettes) / sizeof( TProgmemRGBGradientPalettePtr );
