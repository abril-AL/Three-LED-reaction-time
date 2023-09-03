/*
  project_4al.ino
  Abril A. L.

  Version DD/MM/YY
  1.00    28/08/2023   Running code
  1.10    03/09/2023   Mostly working for three leds minus hardware issues
*/

// =======================================================================
//                  V A R I A B L E   D E C L A R A T I O N S
// =======================================================================
// LED variables
#define redPin 9
#define greenPin 10
#define bluePin 11

// each LED needs its own brightness level
#define redBrightness 125
#define greenBrightness 50
#define blueBrightness 220

// LEDS States
int redState = LOW;
int greenState = LOW;
int blueState = LOW;

// Button variables
#define redButtonPin 2
#define greenButtonPin 4
#define blueButtonPin 7

// Button States
int redButtonState = LOW;
int greenButtonState = LOW;
int blueButtonState = LOW;

// Time variables
long randDelay;
long newT;
long oldT;
long deltaT;

// LED Variables
#define numOfLEDs 3
char LEDs[numOfLEDs] = {'R', 'G', 'B'};
char currLED;
int randLED;

// =======================================================================
//                              S  E  T  U  P
// =======================================================================

void setup()
{
    // initialize LED pins as an output
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // initialize button pins as input
    pinMode(redButtonPin, INPUT);
    pinMode(greenButtonPin, INPUT);
    pinMode(blueButtonPin, INPUT);

    // initialize serial communication.
    Serial.begin(9600);

    // The LED will blink 3 times for 250 ms to indicate the start of the experiment
    Serial.println("Prepare. Reaction time experiments will begin shortly!");
    for (int i = 0; i < 3; i++)
    {
        analogWrite(redPin, redBrightness);
        analogWrite(greenPin, greenBrightness);
        analogWrite(bluePin, blueBrightness);
        delay(250);
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        delay(250);
    }
    // Create a random seed for the random number generator.
    // then delay a random amount of time - between 0.5 to 2.0 seconds
    randomSeed(analogRead(A0));
    randDelay = random(500, 2000);
    delay(randDelay);
    // pick first LED (rand) to light up
    randLED = random(0, numOfLEDs);
    currLED = LEDs[randLED];
    // Serial.println(currLED);
    delay(randDelay);
}

// =======================================================================
//                              L  O  O  P
// =======================================================================

void loop()
{

    // Check to see if buttons are pressed
    redButtonState = digitalRead(redButtonPin);
    greenButtonState = digitalRead(greenButtonPin);
    blueButtonState = digitalRead(blueButtonPin);

    // check which led is going to turn on and criteria to start trial

    if (redState == LOW && redButtonState == LOW && currLED == 'R')
    {
        // Turn the LED on and record the time, trial has begun
        analogWrite(redPin, redBrightness);
        oldT = millis();
        redState = HIGH;
    }
    if (greenState == LOW && greenButtonState == LOW && currLED == 'G')
    {
        analogWrite(greenPin, greenBrightness);
        oldT = millis();
        greenState = HIGH;
    }
    if (blueState == LOW && blueButtonState == LOW && currLED == 'B')
    {
        analogWrite(bluePin, blueBrightness);
        oldT = millis();
        blueState = HIGH;
    }

    // criteria to end trial (add later)

    if (redState == HIGH && redButtonState == HIGH && currLED == 'R')
    {
        // Record time when button was pressed and turn off LED.
        newT = millis();
        analogWrite(redPin, 0);

        // Print to serial monitor the time difference between LED turn off to button press.
        //  This is the reaction time
        deltaT = newT - oldT;
        Serial.print(deltaT);
        Serial.print(',');
        Serial.println(currLED);

        // Reset trial and wait a random amount of time for next trial.
        redState = LOW;
        randDelay = random(1000, 3000);
        currLED = LEDs[random(0, numOfLEDs)];
        delay(randDelay);
    }
    if (greenState == HIGH && greenButtonState == HIGH && currLED == 'G')
    {
        newT = millis();
        analogWrite(greenPin, 0);

        deltaT = newT - oldT;
        Serial.print(deltaT);
        Serial.print(',');
        Serial.println(currLED);

        greenState = LOW;
        randDelay = random(1000, 3000);
        currLED = LEDs[random(0, numOfLEDs)];
        delay(randDelay);
    }
    if (blueState == HIGH && blueButtonState == HIGH && currLED == 'B')
    {
        newT = millis();
        analogWrite(bluePin, 0);

        deltaT = newT - oldT;
        Serial.print(deltaT);
        Serial.print(',');
        Serial.println(currLED);

        blueState = LOW;
        randDelay = random(1000, 3000);
        currLED = LEDs[random(0, numOfLEDs)];
        delay(randDelay);
    }
}

// =======================================================================
//                       F  U  N  C  T  I  O  N  S
// =======================================================================
