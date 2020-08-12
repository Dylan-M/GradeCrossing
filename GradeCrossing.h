/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Grade Crossing Definitions
 *
 */

#define potPin     A2               // select the input pin for the potentiometer
#define usePotPin   0               // If pin is grounded, use potentiometer for interval
#define ledPinA     3               // select the pin for the 1st LED
#define ledPinB     4               // select the pin for the 2nd LED
#define SensorPinA  5               // Input pin for the first Passive Infrared Receiver
#define SensorPinB  6               // Input pin for the second PIR

const unsigned long interval = 800; // Default interval 800ms if not using a pot to control interval timing
unsigned long potVal = interval;    // variable to store the value coming from the sensor
bool even = true;                   // Is the LED flash on the even stroke?
unsigned long previousMillis = 0;   // will store last time LED was updated
char buf[175];                      // Buffer for text output with sprintf()
bool activated = false;             // Has the sensor been activated
bool wasActivated = false;          // Was the sensor previously activated
