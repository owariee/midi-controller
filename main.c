#include "bankController.h"

void setup() {
  Serial.begin(115200);
  bankControllerSetup();
}

void loop() {
  bankControllerLogic();
}

