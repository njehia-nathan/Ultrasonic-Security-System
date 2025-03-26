const int echo = 13;
const int trig = 12;
int redLEDs = 2;  // All Red LEDs connected to D2

int duration = 0;
int distance = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redLEDs, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read echo response
  duration = pulseIn(echo, HIGH, 30000); // Timeout to avoid errors
  distance = (duration / 2) / 28.5;  // Convert to cm

  // Control the Red LEDs
  if (distance > 0 && distance <= 15) {
    // Flash Red LEDs
    for (int i = 0; i < 5; i++) {  // Flash 5 times for visibility
      digitalWrite(redLEDs, HIGH);
      delay(100);
      digitalWrite(redLEDs, LOW);
      delay(100);
    }
  } 
  else if (distance > 15) {
    // Keep Red LEDs ON
    digitalWrite(redLEDs, HIGH);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);  // Fast response time
}
