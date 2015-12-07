
// We will set this variable here outside the scope of the loop
// This allows us to ensure that even when the loop repeats itself that this value stored in it is remembered
int pressed = 0;

void setup() {
  // put your setup code here, to run once:

    //Set-up the pin heads for input or outpuy
    // Output means we are sending a signal out of the board
    // Input means we are expecting a signal back

    // Red LED
    pinMode(13,OUTPUT);
    // Yellow LED
    pinMode(12,OUTPUT);
    // Green LED
    pinMode(11,OUTPUT);  
    // Pedestrian Green Man LED
    pinMode(9,OUTPUT);
    // Pedestrian Red Man LED
    pinMode(7,OUTPUT);
    // Pedestrian Button
    pinMode(3,INPUT);  
    // This sets the board to send serial messages back to use through the serial monitor
    // The 9600 is the baud rate.... this must sync with the serial monitor baud rate
    Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // We use the digitalWrite function to send or stop sending signal out the digital headers
  // Syntax: digtialWrite(Digital Pin Number, High or Low);
  // Use Low to remove signal and High to send signal.

  // Yellow LED off
  digitalWrite(12, LOW);
  // Red LED on
  digitalWrite(13, HIGH);
  // Red Man LED on
  digitalWrite(9, HIGH);

  // If the pedestrian button was pressed on a previous loop.....
  if(pressed == 1){
         // Wait three seconds....
         // Delay works in miliseconds remember: 1000 miliseconds in 1 second
         delay(3000);

          // Red Man LED off
          digitalWrite(9, LOW);
          // Green Man LED on
          digitalWrite(7, HIGH);
          // Wait eight seconds
          delay(8000);

           // set a count variable to control the while loop
           int count = 0;
           // a while loop will keep running until the conditions are no longe met
           // this loop will keep running until count is not less than 10
           while(count < 10){
              //on each loop......
              digitalWrite(7, LOW);
              delay(250);
              digitalWrite(7, HIGH);
              delay(250);

              // add an extra "1" to the valye of count
              count++;
              // this loop should produce the flashing green light at intevals of half a second
            }

    // Return our Red and Green Man LEDs to their original state
    digitalWrite(7, LOW);
    digitalWrite(9, HIGH);
    // Wait three seconds before going from Red "Stop" LED to Red and Yellow
    delay(3000);

    // Since we want to ensure that the Green man won't activate next loop unless a pedestrian presses it again
    // We need to set "pressed" to 0
    pressed = 0;
    }
    // if the predestrian button wasn't pressed...
    else{
      delay(5000);
    }
  // Yellow "Prepare" LED on
  digitalWrite(12, HIGH);

  // Wait five seconds.....
  delay(5000);

  // Turn off RED and Yellow LEDs & switch on the Green 
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  
  // Get the state of the Pedestrian button
  int button1State = digitalRead(3);

  // If button state is "LOW"....
  if(button1State == LOW){
    // Don't do anything....
      Serial.print("no");


    
  }
  // Else if the button state isn't LOW....
  else{
      Serial.print("Pressed");
      // Set our pressed variable to 1 for our next loop around to pick up
        pressed = 1;


    }
  // Wait five seconds...
  delay(5000);
  // Set Green LED off and Yellow LED on
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  // Wait five seconds before looping around again....
  delay(5000);
  

}
