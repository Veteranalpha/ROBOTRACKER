void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // Set sensor pins as input
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Enable motors
  digitalWrite(enablePinA, HIGH);
  digitalWrite(enablePinB, HIGH);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int leftSensorState = digitalRead(leftSensorPin);
  int rightSensorState = digitalRead(rightSensorPin);

  // Print sensor states to Serial Monitor
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorState);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensorState);

  // Basic logic for obstacle avoidance
  if (leftSensorState == LOW && rightSensorState == LOW) {
    // Move forward
    moveForward();
    Serial.println("Moving Forward");
  } else if (leftSensorState == HIGH && rightSensorState == LOW) {
    // Turn right
    turnRight();
    Serial.println("Turning Right");
  } else if (leftSensorState == LOW && rightSensorState == HIGH) {
    // Turn left
    turnLeft();
    Serial.println("Turning Left");
  } else {
    // Stop
    stopMotors();
    Serial.println("Stopping");
  }

  delay(500); // Small delay for readability in Serial Monitor
}
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Motors moving forward");
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Motors turning right");
}

void turnLeft() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  Serial.println("Motors turning left");
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Motors stopped");
}
void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // Enable motors
  digitalWrite(enablePinA, HIGH);
  digitalWrite(enablePinB, HIGH);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Move motors forward for 5 seconds
  moveForward();
  delay(5000);
  stopMotors();
  delay(5000);
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Motors moving forward");
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Motors stopped");
}
