#include <Stepper.h>
#include <Servo.h>

#define STEPS 32
#define BZ1 2 // Melody Buzzer
#define BZ2 3 // Bass/Chord Buzzer

Servo myservo;

const int buttonPin1 = 12; 
const int buttonPin2 = 13;
const int LED1 = 6;         
const int LED2 = 7;

int pos = 0;
bool servoMoved = false;

// Note frequencies - Fixed: Added NOTE_D4 definition
#define NOTE_FS3 185
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_CS4 277
#define NOTE_D4  294  
#define NOTE_E4  330
#define NOTE_FS4 370
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_CS5 554
#define NOTE_E5  659

// Complicated 24-step arrangement
// Buzzer 1: High Vocal Hook Melody
int melody[] = {
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_B4,  NOTE_A4,  0,        
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_A4,  NOTE_B4,  0,        
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_B4,  NOTE_A4,  0,        
  NOTE_FS4, NOTE_A4,  NOTE_B4,  NOTE_CS5, NOTE_B4,  NOTE_A4
};

// Buzzer 2: Complex Bass Line
int bassline[] = {
  NOTE_FS3, NOTE_FS3, NOTE_A3,  NOTE_A3,  NOTE_CS4, NOTE_CS4, 
  NOTE_D4,  NOTE_D4,  NOTE_B3,  NOTE_B3,  NOTE_E4,  NOTE_E4,  
  NOTE_FS3, NOTE_FS3, NOTE_A3,  NOTE_A3,  NOTE_CS4, NOTE_CS4, 
  NOTE_D4,  NOTE_D4,  NOTE_B3,  NOTE_B3,  NOTE_E4,  NOTE_E4
};

// Explicitly lengthened step durations (in milliseconds)
int stepDuration[] = {
  300, 300, 300, 300, 450, 150,
  300, 300, 300, 300, 450, 150,
  300, 300, 300, 300, 450, 150,
  300, 300, 300, 300, 300, 600
};

Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(BZ1, OUTPUT);
  pinMode(BZ2, OUTPUT);
  myservo.attach(5);
 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  stepper.setSpeed(500); 
}

void loop() {
  int btn1 = digitalRead(buttonPin1);
  int btn2 = digitalRead(buttonPin2);

  // SUCCESS: Both buttons pressed simultaneously
  if (btn1 == LOW && btn2 == LOW) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    
    if (!servoMoved) { 
      for (pos = 0; pos <= 180; pos++) {
        myservo.write(pos);
        delay(15);
      }
      servoMoved = true;
    }

    // Play complex polyphonic arrangement (24 steps)
    for (int i = 0; i < 24; i++) {
      int duration = stepDuration[i];
      int halfDuration = duration / 2;

      // Sub-step 1: Start melody note, punch bass note
      if (melody[i] > 0) tone(BZ1, melody[i]);
      tone(BZ2, bassline[i]);
      delay(halfDuration);
      
      // Sub-step 2: Keep melody note holding, but shift bass note to create movement
      noTone(BZ2); 
      tone(BZ2, (int)(bassline[i] * 1.2)); 
      delay(halfDuration * 0.8);

      // Clean cutoff between steps so notes don't turn into a messy hum
      noTone(BZ1);
      noTone(BZ2);
      delay(halfDuration * 0.2); 
    }

    // Safety timeout for button release
    int timeout = 0;
    while((digitalRead(buttonPin1) == LOW || digitalRead(buttonPin2) == LOW) && timeout < 600) {
      delay(10);
      timeout++; 
    }
    
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  } 
  // Individual button controls
  else {
    if (btn1 == LOW) {
      digitalWrite(LED1, HIGH);   
      stepper.step(50);           
    } else {
      digitalWrite(LED1, LOW);    
    }

    if (btn2 == LOW) {
      digitalWrite(LED2, HIGH);
      stepper.step(-50);          
    } else {
      digitalWrite(LED2, LOW);    
    }
    
    servoMoved = false; 
  }
}
