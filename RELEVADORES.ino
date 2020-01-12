
   // constants won't change. They're used here to set pin numbers:
const int buttonPin = 0;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);


    //digitalWrite(ledPin, HIGH);

    // turn LED off:
  digitalWrite(ledPin, LOW);
  }
