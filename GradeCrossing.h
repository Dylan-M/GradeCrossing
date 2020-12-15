/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Grade Crossing Definitions
 *
 */

#define potPin     A2               // select the input pin for the potentiometer
#define usePotPin   0               // If pin is grounded, use potentiometer for interval

const unsigned long interval = 800; // Default interval 800ms if not using a pot to control interval timing
unsigned long potVal = interval;    // variable to store the value coming from the sensor
bool even = true;                   // Is the LED flash on the even stroke?
char buf[175];                      // Buffer for text output with sprintf()
