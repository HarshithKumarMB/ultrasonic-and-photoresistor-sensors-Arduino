
#include <afstandssensor.h>
#define AD5 A5
#define NOTE_D0 -1
#define NOTE_D1 262
#define NOTE_D2 293
#define NOTE_D3 329
#define NOTE_D4 349
#define NOTE_D5 392
#define NOTE_D6 440
#define NOTE_D7 494

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278
#define AD5 A5


#define NOTE_DH1 523
#define NOTE_DH2 586
#define NOTE_DH3 658
#define NOTE_DH4 697
#define NOTE_DH5 783
#define NOTE_DH6 879
#define NOTE_DH7 987  

#define WHOLE 1

#define HALF 0.5

#define QUARTER 0.25

#define EIGHTH 0.25
#define SIXTEENTH 0.625
int Intensity = 0;
int x;



int tune[] = 

{

  NOTE_DH1,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,

  
};
float duration[]={
  0.5,0.5,0.5,0.5,0.5,
};

int length;

int tonePin=9;
AfstandsSensor afstandssensor(13, 12);
int a;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  int a;
  pinMode(5,OUTPUT);

  length = sizeof(tune)/sizeof(tune[0]);


}

void loop() {
  digitalWrite(8,HIGH);
  delay(1);
  digitalWrite(8,LOW);
  delay(2); 
  Intensity = analogRead(AD5);  //Read the value of the analog port AD5 into the Intensity variable.
  Serial.print("Intensity = ");  //Serial port output "Intensity ="
  Serial.println(Intensity);
  delay(2);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  if(Intensity<400)
  {
   
    digitalWrite(9,LOW); 
    delay(1);               
    
    digitalWrite(10,LOW); 
    delay(1);               
   
  }
    else
    
    
    //Serial.println(afstandssensor.afstandCM());
    delay(2);
    a=afstandssensor.afstandCM();
    delay(20);
    if(a<=40&&a>0){
    for(int x=0;x<length;x++)
  {
    tone(5,tune[x]);//This function plays the array in the tune sequence in turn.

    delay(400*duration[x]);//The duration of each note.

    noTone(5);//Stop the current note and move on to the next note.

  }
    }
}


    


 
