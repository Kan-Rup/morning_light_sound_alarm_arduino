

/*
 * 
 * Morning Light Wakeup Sound Alarm - Arduino Code
 * -------------------------------------------------
 * Copyright © Kanishka Rupasinghe , 2021 onward
 * 
 * 
 * This code works when uploaded to the arduino board of the morning-light-alarm circuit.
 * 
 * The alarm is activated at a specific level of light, and increases in the frequency of
 * beeping as the light levels increase.
 * 
 * 
 * This code is provided to you under the MIT Licence.
 * 
 * https://mit-license.org/
 * 
 */



//holds the pin number for the sound output.
//
const int SPEAKER = 13;

//holds the analogue pin number for reading the light levels.
//
const int light_sensor_A_input = 0;

//the actual light level read from the sensor is held here.
//
int lightAmount = 0;


//if the sensed light level is below a defined level, the alarm is not sounded
//if above the defined level, alarm is sounded.
//
int alarmLevel = 0;


void setup() {

  //set SPEAKER digital pin as role output
  //
  pinMode(SPEAKER,OUTPUT);
  
}


void loop() {


  //read and store the amount of light sensed by the light sensor component
  //
  lightAmount = analogRead(light_sensor_A_input);


  //depending on the light level, decide if to sound the alarm or not.
  //alarm is sounded only if light amount is above 400.
  //
  if(lightAmount < 350){

    alarmLevel = 0;
    
  } else {

    alarmLevel = 1;

  } 


  //if alarmLevel indicates do sound alarm
  //
  if(alarmLevel != 0){

    //the length of the beeps and silences depends on the amount of light hitting sensor
    //the shortness of beeps silences increases with increasing light
    //so the darker it is, the slower the speaker beeps.

    //division by 4 done to scale down the  delay time (light amount is represented in larger numbers)


    digitalWrite(SPEAKER,HIGH);

    delay(100000/lightAmount);
  
    digitalWrite(SPEAKER,LOW);

    delay(100000/lightAmount);

  }
  
}
