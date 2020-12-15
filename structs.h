/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Structures for handling multiple grade crossings from a single Arduino
 *
 */

#define MAX_SENSORS   5

struct crossing_data {
  int LED_PinA      = -1;
  int LED_PinB      = -1;
  // Array of sensor pins, max 5 per crossing
  // The 3rd sensor pin, SensorPin[2], is treated special as an "island"
  // for override purposes
  int SensorPin[MAX_SENSORS]  = {-1, -1, -1, -1, -1};
  int OverridePin   = -1;
  bool activated    = false;             // Has the sensor been activated
  bool wasActivated = false;          // Was the sensor previously activated
  bool even         = true;                   // Is the LED flash on the even stroke?
  bool overridden    = false;
  unsigned long previousMillis = 0;   // will store last time LED was updated
  struct crossing_data *next;
};

typedef struct crossing_data Crossing;
