/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Structures for handling multiple grade crossings from a single Arduino
 *
 */

 struct crossing {
  int LED_PinA    = -1;
  int LED_PinB    = -1;
  int SensorPin   = -1;
  int OverridePin = -1;
  int bytePosit   = -1;
  struct crossing nextCrossing;
 };

 typedef struct crossing Crossing;
