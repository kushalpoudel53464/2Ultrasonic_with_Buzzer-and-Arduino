// Pin definitions //nepro
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int buzzerPin = 6;

// Maximum distance threshold in centimeters
const int maxDistance = 15;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set up pins
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Measure distance for sensor 1
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Measure distance for sensor 2
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Print distances to Serial Monitor
  Serial.print("Distance Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");
  Serial.print("Distance Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Check if either sensor detects an object within 15cm
  if (distance1 <= maxDistance || distance2 <= maxDistance) {
    // If so, activate the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Otherwise, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Delay before next measurement
  delay(100);
}
