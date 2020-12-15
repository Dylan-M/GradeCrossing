/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Control circuit to flash a simulated railroad crossing
 * Potentiometer used to control flash speed
 * Activation controlled via a sensor such as a PIR
 * Designed for UNO & Leonardo boards, will require changes for other boards
 *
 */

#include "structs.h"
#include "utils.h"
#include "GradeCrossing.h"

struct crossing_data *crossing_list = NULL;

void setup() {
  Serial.begin(9600);               // start a serial connection on the USB port for debugging
  Serial.println("Initializing");

  // Set up the pins for crossings
  struct crossing_data *crossing;
  for (crossing = crossing_list; crossing; crossing = crossing->next) {
    pinMode(crossing->LED_PinA, OUTPUT); // declare the LED_PinA as an OUTPUT
    pinMode(crossing->LED_PinB, OUTPUT); // declare the LED_PinB as an OUTPUT
    digitalWrite(crossing->LED_PinA, HIGH);      // start with all LEDs turned off
    digitalWrite(crossing->LED_PinB, HIGH);      // start with all LEDs turned off
    for (int i = 0; i < MAX_SENSORS; i++) { // declare sensor pins as INPUT
      if (crossing->SensorPin[i] == -1) {
        continue;
      }
      pinMode(crossing->SensorPin[i], INPUT);
    }

    // Override Pin Capability
    if (crossing->OverridePin != -1) {
      pinMode(crossing->OverridePin, INPUT_PULLUP);
    }
  }
  
  pinMode(potPin, INPUT);           // declare the pin for a pot as input
  pinMode(usePotPin, INPUT_PULLUP); // declare the pin for using a pot as input_pullup
  Serial.println("Initialized");
}

/*
 * Main loop with decision making
 */
void loop() {
  // If we're using a pot, read the potVal in
  if (digitalRead(usePotPin) == LOW) {
    potVal = analogRead(potPin);
  }

  struct crossing_data *crossing;
  for (crossing = crossing_list; crossing != NULL; crossing = crossing->next) {
    if (crossing->OverridePin != -1) {
      crossing->overridden = (digitalRead(crossing->OverridePin) == LOW);
    }
    bool island = false;
    crossing->activated = false;
    // Was a sensor active on this pass?
    for (int i = 0; i < MAX_SENSORS && crossing->activated == false; i++) {
      if (crossing->SensorPin[i] == -1) {
        continue;
      }
      if (digitalRead(crossing->SensorPin[i]) == HIGH); {
        crossing->activated = true;
      }
      island = (i == 2 && digitalRead(crossing->SensorPin[i]) == HIGH);
    }

    if (crossing->activated && !crossing->wasActivated) {
      sprintf(buf, "Status of activation: %s", crossing->activated ? "true" : "false");
      Serial.println(buf);
    }
  
    // If a sensor was activated, start running the lights
    if (crossing->activated && (!crossing->overridden || island)) {
      unsigned long milliseconds = millis(); // Get our current milliseconds
      if ((milliseconds - crossing->previousMillis) >= potVal) {
        sprintf(buf, "Switching LEDs at %lu millis, previous millis of %lu with a interval of %lu\r\n", milliseconds, crossing->previousMillis, potVal);
        Serial.print(buf);
        switchLED(crossing->LED_PinA, crossing->LED_PinB);
        crossing->previousMillis = milliseconds;
        crossing->wasActivated = true;
      }
    // If we were previously activated, but aren't now, shut everything down
    } else if (crossing->wasActivated) {
      Serial.print("Turning LEDs Off\r\n");
      digitalWrite(crossing->LED_PinA, HIGH);
      digitalWrite(crossing->LED_PinB, HIGH);
      crossing->wasActivated = false;
      crossing->overridden = false;
      sprintf(buf, "Status of activation: %s", crossing->activated ? "true" : "false");
      Serial.println(buf);
    }
  }
}

/*
 * switchLED()
 * This function will alternate the flashin of the LEDs
 * It is called from loop() when the interval in milliseconds has passed
 * Also flashes onboard LED for debugging
 */
void switchLED(int ledPinA, int ledPinB) {
  if (even) {
    digitalWrite(ledPinA, HIGH);  // turn the ledPin off
    digitalWrite(ledPinB, LOW);   // turn the ledPin on
  } else {
    digitalWrite(ledPinA, LOW);   // turn the ledPin on
    digitalWrite(ledPinB, HIGH);  // turn the ledPin off
  }

  even = !even; // swap even
}

void create_crossings () {
  struct crossing_data *crossing;

  CREATE(crossing, struct crossing_data, 1);
  crossing->next = crossing_list;
  crossing->LED_PinA = 3;
  crossing->LED_PinB = 4;
  crossing->SensorPin[0] = 5;
  crossing->SensorPin[1] = 6;
  // Can add up to SensorPin[4] here, for a total of 5 per crossing.
  crossing->OverridePin = -1; // Set this to a valid pin number to enable usage
  crossing_list = crossing;

/* Crossing 2
  CREATE(crossing, struct crossing_data, 1);
  crossing->next = crossing_list;
  crossing->LED_PinA = 3;
  crossing->LED_PinB = 4;
  crossing->SensorPin[0] = 5;
  crossing->SensorPin[1] = 6;
  // Can add up to SensorPin[4] here, for a total of 5 per crossing.
  crossing->OverridePin = -1; // Set this to a valid pin number to enable usage
  crossing_list = crossing;
*/

/* Crossing 3
  CREATE(crossing, struct crossing_data, 1);
  crossing->next = crossing_list;
  crossing->LED_PinA = 3;
  crossing->LED_PinB = 4;
  crossing->SensorPin[0] = 5;
  crossing->SensorPin[1] = 6;
  // Can add up to SensorPin[4] here, for a total of 5 per crossing.
  crossing->OverridePin = -1; // Set this to a valid pin number to enable usage
  crossing_list = crossing;
*/
}
