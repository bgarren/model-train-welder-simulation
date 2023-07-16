#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int led1Pin = 5;         // Connect LED 1 to digital pin 4
const int irSensorPin = 2;     // Connect IR sensor output to digital pin 2

SoftwareSerial softwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini dfPlayer;

bool led1State = false;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(irSensorPin, INPUT_PULLUP);

  digitalWrite(led1Pin, LOW);  // Initialize LED 1 as OFF

  softwareSerial.begin(9600);
  dfPlayer.begin(softwareSerial);

  dfPlayer.volume(30);  // Set volume to maximum
}

void loop() {
  int irSensorState = digitalRead(irSensorPin);

  if (irSensorState == LOW) {
    // Sensor triggered
    led1State = !led1State;
    digitalWrite(led1Pin, led1State);

    dfPlayer.play(1);   // Play track 1
   

    // LED_BUILTIN flashing
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(4000);
    digitalWrite(LED_BUILTIN, LOW);digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(4000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}


