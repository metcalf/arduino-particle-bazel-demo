/*
 * Project particle-bazel-demo
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

SYSTEM_THREAD(ENABLED);

Adafruit_SSD1306 *display;

// setup() runs once, when the device is first turned on.
void setup(TwoWire *wire = &Wire) {
  display = new Adafruit_SSD1306(128, 32, wire, -1);
  display->begin(SSD1306_SWITCHCAPVCC, 0);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}
