https://github.com/abekjohnson17-ui/Ball-Launcher.git
#include <Arduino.h>

// Target Velocity
float targetVelocity_m_s = 2.0;

// Motor Speeds
const int MOTOR_MAX = 255;
const int MOTOR_HALF = MOTOR_MAX / 2;

// Globals
int currentWheelMotorSpeed = MOTOR_MAX;
float currentVelocity_m_s = 0.0;

// Laser Sensor variables
const float DISTANCE_CM = 2.54;  // distance between sensors
const int SENSOR1 = 2;  // first trip sensor
const int SENSOR2 = 3;  // second trip sensor
volatile unsigned long timeA = 0;
volatile unsigned long timeB = 0;
volatile bool triggeredA = false;
volatile bool triggeredB = false;

// Servo
const int servoPin = 13;

// Motor 1 (Bottom Wheel) pins
const int EN1 = 9;
const int IN1 = 8;
const int IN2 = 7;

// Motor 2 (Top Wheel) pins
const int EN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

// Motor 3 (Feeder) pins
const int EN3 = 10;
const int IN5 = 11;
const int IN6 = 12;

void sensorA_ISR() {
  if (!triggeredA) {
    timeA = micros();
    triggeredA = true;
  }
  Serial.println("Sensor A Triggered!");
}

void sensorB_ISR() {
  if (!triggeredB) {
    timeB = micros();
    triggeredB = true;
  }
  Serial.println("Sensor B Triggered!");
}


float calculateVelocity() {
  unsigned long dt = timeB - timeA;  // microseconds
  float seconds = dt / 1e6;          // convert to seconds

  float velocity_cm_s = DISTANCE_CM / seconds;
  float velocity_m_s  = velocity_cm_s / 100.0;

  // Reset for next object
  triggeredA = false;
  triggeredB = false;

  return velocity_m_s;
}

// Setup motor pins
void setupMotor(int en, int in1, int in2) {
  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void setupLaserSensors() {
  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(SENSOR2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SENSOR1), sensorA_ISR, FALLING); // Found online https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/
  attachInterrupt(digitalPinToInterrupt(SENSOR2), sensorB_ISR, FALLING); // attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)
}  // the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. This function is sometimes referred to as an interrupt service routine.

void setMotorSpeed(int en, int speed) {
  // Constrain speed to valid PWM range
  speed = constrain(speed, 0, 255);

  // Apply PWM duty cycle to enable pin
  analogWrite(en, speed);

  // Print statements
  Serial.print("Speed of pin ");
  Serial.print(en);
  Serial.print(": ");
  Serial.println(speed);
}

void setWheelSpeeds(int speed, int spin) {
  int motor1_speed = speed; 
  int motor2_speed = speed;

  // Back-Spin 
  if (spin < 0) {
    motor2_speed = speed + spin;
    motor2_speed = constrain(motor2_speed, 0, 255);
  }
  // Top-Spin
  else if (spin > 0) {
    motor1_speed = speed + spin;
    motor1_speed = constrain(motor2_speed, 0, 255);
  }
  // Else spin = 0: both motors same speed

  // Apply Motor Speeds accounting for spin
  setMotorSpeed(EN1, motor1_speed);
  setMotorSpeed(EN2, motor2_speed);
}

void setupMotorDirections() {
    // Motor 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Motor 2
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    // Motor 3
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
}

void dropBall () {
  // Turns motor at max speed for 15s
  digitalWrite(EN3, HIGH);

  delay(20000);

  digitalWrite(EN3, LOW);
}

void setup() {
  // Initialize serial terminal
  Serial.begin(9600);
  
  // Setup random seed to randomize servo direction
  randomSeed(analogRead(0)); // reads noise on pin 0 which gives random number (Found Online: https://forum.arduino.cc/t/randomseed-analogread-0/109478)

  // Setup Servo pwm pin
  pinMode(servoPin, OUTPUT);

  // Setup Motor Pins
  setupMotor(EN1, IN1, IN2);
  setupMotor(EN2, IN3, IN4);
  setupMotor(EN3, IN5, IN6);

  // Setup Motor directions using H-bridge (L293d) inputs
  setupMotorDirections();

  // Setup Laser pins for interrupts
  setupLaserSensors();

  Serial.println("Motors initialized.");

}

void loop() {
  setWheelSpeeds(currentWheelMotorSpeed, 0);
  
  // dropBall(); // Comment out if not working

  // Waits until the lazers are tripped
  while (triggeredA == 0 || triggeredB == 0); // Wait for both sensors to trip

  currentVelocity_m_s = calculateVelocity();
 
  Serial.print("Velocity: ");
  Serial.print(currentVelocity_m_s);
  Serial.println("m/s");

  float targetCurrentVelocityRatio = targetVelocity_m_s / currentVelocity_m_s;

  // Current < target : ratio < 1
  if (targetCurrentVelocityRatio != 1) {
    currentWheelMotorSpeed = constrain(currentWheelMotorSpeed * targetCurrentVelocityRatio, 0, 255);
  }
}