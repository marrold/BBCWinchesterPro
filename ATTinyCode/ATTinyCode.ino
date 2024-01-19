const int ledPin = 3; // LED connected to physical pin 2
const int inputPin = 4; // Input pin on physical pin 3

bool lastInputState = LOW;    // Last stable state of the input pin
bool lastReadState = LOW;     // Last read state of the input pin
unsigned long ledOffTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
  digitalWrite(ledPin, HIGH);
  pinMode(inputPin, INPUT_PULLUP); // Set the input pin as input with pull-up resistor
  lastInputState = digitalRead(inputPin);
  lastReadState = lastInputState;
}

void loop() {
  bool currentReadState = digitalRead(inputPin);

  // Check if the read state is different from the last read state
  if (currentReadState != lastReadState) {
    lastReadState = currentReadState; // Update the last read state
  }

  // Check if the stable input state is different from the last stable state
  if (currentReadState != lastInputState) {
    lastInputState = currentReadState; // Update the last stable input state

    // Edge detected
    digitalWrite(ledPin, LOW); // Turn on the LED
    ledOffTime = millis() + 50; // Set the time to turn off LED
  }

  // Turn off the LED after the delay
  if (millis() >= ledOffTime && digitalRead(ledPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  }
}
