/**
 * Make the Adruino do nothing.
 */


 /**
  * The `setup()` function is called when a sketch starts.
  * Use it to initialize variables, pin modes, start using libraries, etc.
  * It will only run once, after each powerup or reset of the Arduino board.
  */
void setup() {
  // Turn off the built-in LED.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}


/**
 * The `loop()` function does precisely what its name suggests, and loops
 * consecutively, allowing your program to change and respond.
 * Use it to actively control the Arduino board.
 */
void loop() {
}
