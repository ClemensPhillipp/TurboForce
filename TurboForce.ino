#include <Servo.h>
#include <Stepper.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
const int stepsPerRevolution = 2048;
const int half_round = stepsPerRevolution / 2;
Stepper stepper(stepsPerRevolution, 2, 4, 3, 5);

int min_pos = 85;
int max_pos = 100;
int pos = min_pos;


void setup() {
  stepper.setSpeed(5);
  myservo.attach(9);   // attaches the servo on pin 9 to the Servo object
  myservo.write(pos);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  delay(1000);
  plattform_up();
  delay(1000);
  plattform_down();
  delay(1000);
  stepper.step(half_round);
  delay(1000);
  stepper.setSpeed(16);

  plattform_up();
  delay(1000);
  plattform_down();
  delay(1000);
  stepper.step(stepsPerRevolution * 5);
  stepper.setSpeed(5);

}

void plattform_down() {
  for (pos; pos >= min_pos; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                           // waits 15 ms for the servo to reach the position
  }
}
void plattform_up() {

    for (pos; pos <= 110; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15 ms for the servo to reach the position
  }
}