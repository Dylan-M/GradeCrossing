/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Control circuit to flash a simulated railroad crossing
 * Potentiometer used to control flash speed
 * Activation controlled via PIR
 *
 */

#define potPin  A2   // select the input pin for the potentiometer
#define ledPinA  3   // select the pin for the 1st LED
#define ledPinB  4   // select the pin for the 2nd LED
#define PirPinA  5   // Input pin for the first Passive Infrared Receiver
#define PirPinB  6   // Input pin for the second PIR
const unsigned long interval = 800;
unsigned long potVal = interval;   // variable to store the value coming from the sensor
bool even = true;  // Is the LED flash on the even stroke?
unsigned long previousMillis = 0;        // will store last time LED was updated
char buf[175];
bool activated = false;
bool wasActivated = false;

void setup() {
  pinMode(ledPinA, OUTPUT);  // declare the ledPinA as an OUTPUT
  pinMode(ledPinB, OUTPUT);  // declare the ledPinB as an OUTPUT
  pinMode(PirPinA, INPUT);
  pinMode(PirPinB, INPUT);
  //pinMode(potPin, INPUT);
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, HIGH);
  Serial.begin(9600);
  Serial.println("Initializing");
}

void loop() {
  //potVal = analogRead(potPin);    // read the value from the sensor
  activated = (digitalRead(PirPinA) == HIGH || digitalRead(PirPinB) == HIGH);

  if (activated) {
    unsigned long milliseconds = millis(); // Get our current milliseconds
    if ((milliseconds  - previousMillis) >= potVal) {
      sprintf(buf, "Switching LEDs at %lu millis, previous millis of %lu with a interval of %lu\r\n", milliseconds, previousMillis, potVal);
      Serial.print(buf);
      switchLED();
      previousMillis = milliseconds;
      wasActivated = true;
    }
  } else if (wasActivated) {
    Serial.print("Turning LEDs Off\r\n");
    digitalWrite(ledPinA, HIGH);
    digitalWrite(ledPinB, HIGH);
      wasActivated = false;
  }
}

void switchLED() {
  if (even) {
    digitalWrite(ledPinA, HIGH);  // turn the ledPin off
    digitalWrite(ledPinB, LOW);   // turn the ledPin on
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(ledPinA, LOW);   // turn the ledPin on
    digitalWrite(ledPinB, HIGH);  // turn the ledPin off
    digitalWrite(13, LOW);
  }

  even = !even; // swap even
}
