#include <Adafruit_NeoPixel.h>

#define DATA_PIN 52
#define NUM_LEDS 107
#define NUM_STARTS 1
#define NUM_LETTERS 3
#define RED_POT A0
#define GRN_POT A1
#define BLU_POT A2
#define B1 53
#define B2 41

Adafruit_NeoPixel strip;
int curDelay;
int startPins[] = {10};//, 38, 65, 91};
bool b2PushedDown = 0;

void setColor(int i)
{
  strip.setPixelColor(i, analogRead(RED_POT)/4, analogRead(GRN_POT)/4, analogRead(BLU_POT)/4);
}

void moveClockwise()
{
  for (int i = NUM_LEDS - 1; i >= 0; --i)
  {
    strip.setPixelColor(i, strip.getPixelColor(i == 0 ? NUM_LEDS - 1 : i - 1));
  }
  strip.show();
  delay(curDelay);
}

void moveCClockwise()
{
  for (int i = 0; i < NUM_LEDS; ++i)
  {
    strip.setPixelColor(i, strip.getPixelColor(i == NUM_LEDS - 1 ? 0 : i + 1));
  }
  strip.show();
  delay(curDelay);
}


//bool name[][30] = 
//{
//  { //A
//       0, 1, 1, 1, 1, 0, //t-b
//    0, 0, 0, 1, 0, 1, 0, //b-t
//    0, 1, 0, 1, 0, 0, 0, //t-b
//    0, 1, 1, 1, 1, 0, 0, //b-t
//    0, 0, 0 //extra
//  },
//  { //S
//       0, 1, 0, 0, 1, 0, //t-b
//    0, 1, 0, 1, 0, 1, 0, //b-t
//    0, 1, 0, 1, 0, 1, 0, //t-b
//    0, 0, 1, 0, 0, 1, 0, //b-t
//    0, 0, 0 //extra
//  },
//  {
//    //H
//       1, 1, 1, 1, 1, 0, //t-b
//    0, 0, 0, 1, 0, 0, 0, //b-t
//    0, 0, 0, 1, 0, 0, 0, //t-b
//    0, 1, 1, 1, 1, 1, 0, //b-t
//    0, 0, 0 //extra
//  }
//};

int b1Val;
int b1Old = HIGH;
int b2Val;
int b2Old = HIGH;
bool clockwise = true;

long lastDebounceTimeB1 = 0;
long lastDebounceTimeB2 = 0;
long debounceDelay = 500;

void initRandom()
{
  for (int i = 0; i < NUM_LEDS; ++i)
  {
    strip.setPixelColor(i, random(0, 256), random(0, 256), random(256));
  }
  strip.show();
}

void setup() {
  // put your setup code here, to run once:
  //pinMode(RED_PIN, INPUT);
  //pinMode(GRN_PIN, INPUT);
  //pinMode(BLU_PIN, INPUT);
  Serial.begin(9600);
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN);
  strip.begin();
  strip.show();
  strip.setBrightness(255);
  curDelay = 100;
  randomSeed(analogRead(15));
  initRandom();
}

void loop() {
  // put your main code here, to run repeatedly:
//  int b1Read = digitalRead(B1);
//  if (b1Read != b1Old) 
//  {
//    lastDebounceTimeB1 = millis();
//    Serial.println("State Changed: B1");
//  }
//  if ((millis() - lastDebounceTimeB1) > debounceDelay)
//  {
//    if (b1Read != b1Val)
//    {
//      b1Val = b1Read;
//    }
//
//    if (b1Val == LOW)
//    {
//      for (int i = 0; i < NUM_STARTS; ++i)
//      {
//        setColor(startPins[i]);
//      }
//    }
//  }
//  b1Old = b1Read;
//  
//  int b2Read = digitalRead(B2);
//  if (b2Read != b2Old) 
//  {
//    lastDebounceTimeB2 = millis();
//    Serial.println("State Changed: B2");
//  }
//  if ((millis() - lastDebounceTimeB2) > debounceDelay)
//  {
//    if (b2Read != b2Val)
//    {
//      b2Val  = b2Read;
//    }
//    if (!b2PushedDown && b2Val == LOW)
//    {
//      clockwise = !clockwise;
//      b2PushedDown = true;
//    }
//    if (b2PushedDown && b2Val == HIGH)
//    {
//      b2PushedDown = false;
//    }
//  }
//  b2Old = b2Read;
//  
//  

//  if (millis() - lastTime > 1000)
//  {
//    
//  }
  for (int i = 0; i < NUM_STARTS; ++i)
  {
    setColor(startPins[i]);
  }
  //if (clockwise)
  //{
    moveClockwise();
  //}
//  int redValue = analogRead(RED_POT)/4;
//  int grnValue = analogRead(GRN_POT)/4;
//  int bluValue = analogRead(BLU_POT)/4;
//  char buffer [50];
//  int i=sprintf (buffer, "%rgb: %d, %d, %d\n", redValue, grnValue, bluValue);
//  for(int l= 0; l<=i; l++) 
//  Serial.print(buffer[l]);
//  for (int i = 0; i < NUM_LEDS; ++i)
//  {
//    strip.setPixelColor(i, redValue, grnValue, bluValue);
//  }
//  strip.show();
}




