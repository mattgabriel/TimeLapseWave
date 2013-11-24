#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
const int button = 13; //we are attaching a button to pin 13 to choose which shooting mode we'll use
 
//Define wave variables
float x = 0.1; // x starting point (I don't want to start at 0 and have anyone divide by 0 to avoid errors)
float increment = 0.1; // each time the program loops it will increment x by 0.1 (will give us a smoother wave)
int amplitude = 4; // maximum peak (times 10) in seconds seconds (add your minimum to get the final value)
float minValue = 0.5; // minimun value
int frequency = 2; // distance between waves
int coeficient= 8; // sin will be elevated to this
 
void setup() { 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(button,INPUT);
} 
 
void loop() { 
  float val;
  if(digitalRead(button) == 0){ //button off, select timeWaveMode
    val = timeWaveMode();
  } else {
    val = timeFlatMode(); //button on, select timeFlatMode
  }
  myservo.write(100); //rotate Servo to 100 degrees (press shutter)
  delay(300); //wait 0.3 seconds
  myservo.write(90); //rotate back to 90 degrees (release shutter)
  delay(val); //wait Y seconds
} 

float timeWaveMode(){
  float val = (pow(sin(x/frequency),8) * amplitude + minValue) * 10; //calculate the Y axis (time)
  val = val * 1000; //turn it into milliseconds
  x += increment; //Increment x by 0.1 
  return val;
}

float timeFlatMode(){
  return 5000.00; //will always return 5 seconds.
}
