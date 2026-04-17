#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
// Hardware pin definitions
#define DHTPIN D5
#define DHTTYPE DHT11
#define FAN_PIN D0
// Create sensor and screen objects
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Define the logical thermal threshold
float thresholdTemp = 33;
void setup() {
Serial.begin(9600);
delay(1000);
// Set D0 (FAN_PIN) as an output to drive the transistor
pinMode(D0, OUTPUT);
// Initialize I2C communication (SDA = D2, SCL = D1)
Wire.begin(D2, D1);
// Initialize the LCD and turn on the backlight
lcd.init();
lcd.backlight();
// Start the DHT11 sensor
dht.begin();
pinMode(FAN_PIN, OUTPUT);
// Display startup message for visual verification
lcd.setCursor(0,0);
lcd.print("System Starting");
delay(3000);
lcd.clear();
}
void loop() {
// Poll the sensor for current environmental data
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
// Control Fan Logic (Threshold Evaluation)
if (temperature >= thresholdTemp)
digitalWrite(FAN_PIN, HIGH);
else
digitalWrite(FAN_PIN, LOW);
// Display Data on LCD
lcd.clear();
// Primary Row: Temperature
lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.print(temperature);
lcd.print(" C");
// Secondary Row: Humidity
lcd.setCursor(0,1);
lcd.print("Hum: ");
lcd.print(humidity);
lcd.print(" %");
// Cycle delay to maintain bus stability
delay(500);
