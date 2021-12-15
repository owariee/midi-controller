void setup() {
  bankControllerSetup();
  Serial.begin(115200);
}

void loop() {
  bankControllerLogic();
  joyControllerLogic();
}
