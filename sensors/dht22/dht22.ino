/**
 * Sensor DHT-22 (temperature & humidity).
 */

// Load sensor library.
// Source: https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>


// Configuration.
const int DATA_PIN = 2; // Arduino pin connected to the sensor data pin.
const int DHT_TYPE = DHT22; // Sensor type (cf. DHT library).
const int MEASURE_DELAY = 2000; // Sensor measurement takes place every 2 seconds.


// Measures.
float temperature;
float humidity;


// Initialize sensor.
DHT dht(DATA_PIN, DHT_TYPE);


/**
 * The `setup()` function is called when a sketch starts.
 * Use it to initialize variables, pin modes, start using libraries, etc.
 * It will only run once, after each powerup or reset of the Arduino board.
 */
void setup() {
    // Initialize serial port.
    while (!Serial); // Wait for serial port to connect.
    Serial.begin(9600); // Open serial port and set data rate to 9600 bps.
    Serial.println(F("Serial port ready."));

    // Setup sensor pins.
    dht.begin();

    Serial.println(F("Setup done."));
}


/**
 * The `loop()` function does precisely what its name suggests, and loops
 * consecutively, allowing your program to change and respond.
 * Use it to actively control the Arduino board.
 */
void loop() {
    // Read measures.
    temperature = dht.readTemperature(); // In Celsius.
    humidity = dht.readHumidity(); // In percent.

    // Log measures.
    logMeasures(temperature, humidity);

    // Wait for the next measures to be available.
    delay(MEASURE_DELAY);
}


/**
 * Logs the measures on the serial port.
 */
void logMeasures(float temperature, float humidity) {
  Serial.print(F("[DHT-22] Temperature: "));
  safePrintValue(temperature);
  Serial.print(F("°C, Humidity: "));
  safePrintValue(humidity);
  Serial.println(F("%."));
}


/**
 * Prints the value or a "?" if NaN.
 */
void safePrintValue(float value) {
  if (isnan(value)) {
    Serial.print(F("?"));
  } else {
    Serial.print(value);
  }
}
