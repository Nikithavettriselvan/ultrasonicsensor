#define echoPin 2
#define trigPin 3
#define ledPin 13

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse duration with a timeout
  duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timeout
  if (duration == 0) {
    Serial.println("Sensor timeout! Check connections.");
    distance = -1; // Indicate invalid distance
  } else {
    distance = duration * 0.034 / 2;
  }

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED logic
  if (distance > 0 && distance < 100) {
    Serial.println("Object detected! LED ON");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    Serial.println("No object detected. LED OFF");
    digitalWrite(ledPin, LOW);
  }

  delay(200);  // Small delay for stability
}
