
class KeyboardManager {
  private:
  // pin array
  uint8_t* pins;

  // number of packets in the array
  uint8_t packetNumber;

  // button state for each packet
  bool* buttons;
  bool* buttonPress;
  bool* buttonRelease;

  // get number of elements in one array
  uint8_t getArrayLenght(uint8_t array[]) {
    return (uint8_t)(sizeof(array)/sizeof(array[0]));
  }

  // get number of packets in one array
  uint8_t getPacketNumber(uint8_t array[]) {
    return (uint8_t)(this->getArrayLenght(array)/2);
  }

  // get the pin number for a button in the packet index
  uint8_t getButtonPin(uint8_t index) {
    return this->pins[index*2];
  }

  // get the pin number for a led in the packet index
  uint8_t getLedPin(uint8_t index) {
    return this->pins[(index*2)+1];
  }

  // init button
  void initButton(uint8_t index) {
    pinMode(this->getButtonPin(index), INPUT_PULLUP);
  }

  // init led
  void initLed(uint8_t index) {
    pinMode(this->getLedPin(index), OUTPUT);
  }

  // init packet
  void initPacket(uint8_t index) {
    this->initButton(index);
    if(index != 128) {
      this->initLed(index);
    }
  }

  // inite pin state for each packet
  void initPins() {
    for(uint8_t i = 0; i < this->packetNumber; i++) {
      this->initPacket(i);
    }
  }

  // read button
  bool readButton(uint8_t index) {
    return digitalRead(this->getButtonPin(index)) == LOW;
  }

  // set led state
  void setLed(uint8_t index, bool state) {
    digitalWrite(getLedPin(index), state);
  }

  // update button press state
  void updateButtonPress(uint8_t index, bool oldRead, bool newRead) {
    this->buttonPress[index] = !oldRead && newRead;
  }

  // update button release state
  void updateButtonRelease(uint8_t index, bool oldRead, bool newRead) {
    this->buttonRelease[index] = oldRead && !newRead;
  }

  public:
  // init variables and pins
  KeyboardManager(uint8_t pins[]) {
    this->pins = pins;
    this->packetNumber = this->getPacketNumber(pins);
    this->buttons = new bool[this->packetNumber];
    this->buttonPress = new bool[this->packetNumber];
    this->buttonRelease = new bool[this->packetNumber];

    this->initPins();
  };

  // terminate variables
  ~KeyboardManager() {
    delete this->buttons;
    delete this->buttonPress;
    delete this->buttonRelease;
  }

  // update button state for each packet
  void loop() {
    for(uint8_t i = 0; i < this->packetNumber; i++) {
      bool oldRead = this->buttons[i];
      bool newRead = readButton(i);
      updateButtonPress(i, oldRead, newRead);
      updateButtonRelease(i, oldRead, newRead);
      this->buttons[i] = buffer;
    }
  }

  // return one time on button press
  bool getButtonPress(uint8_t index) {
    return this->buttonPress[index-1];
  }

  // return one time on button release
  bool getButtonRelease(uint8_t index) {
    return this->buttonRelease[index-1];
  }

  // return button state
  bool getButtonState(uint8_t index) {
    return this->buttons[index-1];
  }

  // turn on led in packet index
  void setLedOff(uint8_t index) {
    this->setLed(index-1, LOW);
  }

  // turn off led in packet index
  void setLedOn(uint8_t index) {
    this->setLed(index-1, HIGH);
  }
};

