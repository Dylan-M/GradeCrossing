/* Grade Crossing Display Controller
 * ------------------ 
 *
 * Structures for handling multiple grade crossings from a single Arduino
 *
 */

 struct crossing {
  int LED_PinA;
  int LED_PinB;
  int SensorPin;
 };

 typedef struct crossing Crossing;
