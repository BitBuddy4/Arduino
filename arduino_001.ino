const int switch1 = 10;  // connect switch 1 to digital pin D10
const int switch2 = 11;  // connect switch 2 to digital pin D11
const int switch3 = 12;  // connect switch 3 to digital pin D12

const int ledPins[] = {2, 3, 4, 5, 6, 7, 8};  // connect LEDs to these digital pins

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // initialize all LEDs to off
  }

  pinMode(switch1, INPUT_PULLDOWN);
  pinMode(switch2, INPUT_PULLDOWN);
  pinMode(switch2, INPUT_PULLDOWN);
}

void loop() {
  int binaryValue = 0;

  // Read the state of each switch and update the binary value
  binaryValue |= digitalRead(switch1) << 0;
  binaryValue |= digitalRead(switch2) << 1;
  binaryValue |= digitalRead(switch3) << 2;

  Serial.print(digitalRead(switch1));
  Serial.print(digitalRead(switch2));
  Serial.print(digitalRead(switch3));

  // Use the binary value to control the LEDs
  for (int i = 0; i < 7; i++) {
    //int bit = (binaryValue >> i) & 1;
    //Serial.print(ledPins[i]);
    //Serial.print(bit);
    if (i == binaryValue - 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }

  Serial.println(binaryValue);
}
