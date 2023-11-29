//Name : A. Apurva

int ledState = LOW; //Initiliazing a variable ledState to LOW

//Using counter variables to be used for obtaining delay instead of using functions like delay, millis, etc.
int counter1 = 0; 
int counter2 = 0;

void setup() {
  pinMode(13, OUTPUT); //Initialising LED pin 13 as output
}

void loop() {
  //Reading LM35 data from pin A0
  int sensorValue = analogRead(A0); 
  float temp = (sensorValue * 0.00488) * 100.0;
  
  //Blink LED according to given conditions.
  if (temp < 30.0) {
    counter1 = 250;
  } else {
    counter1 = 500;
  }

  //Logic for delay without using delay functions.
  if (counter2 < counter1) {
    counter2++;
  } else {
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(13, ledState);
    counter2 = 0;
  }
  
}
