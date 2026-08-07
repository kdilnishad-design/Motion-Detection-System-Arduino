#include <Adafruit_LiquidCrystal.h>

// LCD I2C Address
Adafruit_LiquidCrystal lcd_1(0);

// Pin Definitions
const int PIR = 7;     // PIR OUT pin
const int LED = 12;    // LED pin

int motion = 0;

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);

  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);

  lcd_1.setCursor(0, 0);
  lcd_1.print("Motion Detector");

  lcd_1.setCursor(0, 1);
  lcd_1.print("Initializing");

  delay(2000);
  lcd_1.clear();
}

void loop()
{
  motion = digitalRead(PIR);

  Serial.println(motion);

  lcd_1.setCursor(0, 0);
  lcd_1.print("Value: ");
  lcd_1.print(motion);
  lcd_1.print(" ");

  if (motion == HIGH)
  {
    digitalWrite(LED, HIGH);

    lcd_1.setCursor(0, 1);
    lcd_1.print("Motion Detected");
  }
  else
  {
    digitalWrite(LED, LOW);

    lcd_1.setCursor(0, 1);
    lcd_1.print("No Motion      ");
  }

  delay(200);
}
