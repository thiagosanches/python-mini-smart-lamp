#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    23
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define SEPARATOR ':'
#define EOL '\n'
int rgbColor[] = {255, 255, 0};

CRGB leds[NUM_LEDS];
#define DATA_PIN 5

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  delay(500);
}

void loop() {

  delay(500);
  if (Serial.available() > 0)
  {
    char input = Serial.read();
    switch (input)
    {
      case 'C':
        setRGBColor(input);
        animate(rgbColor[0], rgbColor[1], rgbColor[2]);
        turnOff();
        break;
      case '1':
        setRGBColor(input);
        turnOnByColor(rgbColor[0], rgbColor[1], rgbColor[2]);
        break;
    }
  }
}

void animate(int R, int G, int B) {
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
    leds[i - 1] = CRGB::Black;
    delay(25);
    FastLED.show();
  }

  for (int i = NUM_LEDS; i >= 0; i--)
  {
    leds[i] = CRGB(R, G, B);
    leds[i + 1] = CRGB::Black;
    delay(25);
    FastLED.show();
  }
}

void turnOff() {
  for (int i = NUM_LEDS; i >= 0; i--)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void setRGBColor(char input)
{
  int currentSeparator = 0;
  String value = "";
  while (input != EOL)
  {
    input = Serial.read();
    value += input;

    if (input == SEPARATOR)
    {
      rgbColor[currentSeparator] = (int)value.toInt();
      value = "";
      currentSeparator++;
    }
  }
  rgbColor[2] = (int)value.toInt();

  Serial.println(rgbColor[0]);
  Serial.println(rgbColor[1]);
  Serial.println(rgbColor[2]);
}

void turnOnByColor(int R, int G, int B)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
  }
  FastLED.show();
}
