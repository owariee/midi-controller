//const std::uint8_t joyPin = 0;
//const std::uint16_t joyRangeLow = 379;
//const std::uint16_t joyRangeHigh = 637;
//
//uint16_t joyValue = 0;
//uint16_t oldJoyValue = 0;
//uint16_t joyValueDiff = 0;
//const std::uint8_t joyUpdateDiff = 2;
//
//uint8_t joyMap() {
//  return map(joyValue, joyRangeLow, joyRangeHigh, 0, 127);
//}
//
//uint8_t joyControllerGetPercentage() {
//  return map(joyValue, joyRangeLow, joyRangeHigh, 0, 100);
//}
//
//void joyControllerLogic() {
//  joyValue = analogRead(joyPin);
//  joyValueDiff = joyValue - oldJoyValue;
//
//  if(joyValueDiff > joyUpdateDiff) {
//    midiMessage(176, 1, joyMap());
//    oldJoyValue = joyValue;
//  }
//  delay(2);
//}
