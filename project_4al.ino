/*
  project_4al.ino
  Abril A. L.

  Version DD/MM/YY
  1.00    28/08/2023   Running code

*/

// =======================================================================
//                  V A R I A B L E   D E C L A R A T I O N S
// =======================================================================
// LED variables
#define redPin 10
#define greenPin 11
#define bluePin 12
enum LEDS
{ // enumeration for switch statement support
    RED,
    GREEN,
    BLUE
};
long currLED;

// each LED needs its own brightness level
#define redBrightness 190
#define greenBrightness 10
#define blueBrightness 1500

// LEDS States
int redState = LOW;
int greenState = LOW;
int blueState = LOW;

// Button variables
#define redButtonPin 7
#define greenButtonPin 8
#define blueButtonPin 9

// Button States
int redButtonState = LOW;
int greenButtonState = LOW;
int blueButtonState = LOW;

// Time variables
long randDelay;
long newT;
long oldT;
long deltaT;

// =======================================================================
//                              S  E  T  U  P
// =======================================================================

void setup()
{
    // initialize analog pins as an output
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // initialize button pins as input
    pinMode(redButtonPin, INPUT);
    pinMode(greenButtonPin, INPUT);
    pinMode(blueButtonPin, INPUT);

    Serial.println("Prepare. Reaction time experiments will begin shortly!");
    blink();
    // Create a random seed for the random number generator.
    // then delay a random amount of time - between 1 to 2.5 seconds
    randomSeed(analogRead(A0));
    randDelay = random(3000, 3000);
    delay(randDelay);
    // pick first LED (rand) to light up
    currLED = random(0, 3); // rand num 1-3 -> corresponds to enum #
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
    switch (currLED)
    {
    case 0: // red
        if (redState == LOW && redButtonState == LOW)
        {
            // Turn the LED on and record the time, trial has begun
            analogWrite(redPin, redBrightness);
            oldT = millis();
            redState = HIGH;
        }
        break;
    case 1: // green
        if (greenState == LOW && greenButtonState == LOW)
        {
            // Turn the LED on and record the time, trial has begun
            analogWrite(greenPin, greenBrightness);
            oldT = millis();
            greenState = HIGH;
        }
        break;
    case 2: // blue
        if (blueState == LOW && blueButtonState == LOW)
        {
            // Turn the LED on and record the time, trial has begun
            analogWrite(bluePin, blueBrightness);
            oldT = millis();
            blueState = HIGH;
        }
        break;
    default:
        // somethings broken with rand LED assignment if it goes here
        Serial.println("ERR ===== What the scallop !? =====");
        break;
    }

    // testing stuff:
    delay(2000);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    redButtonState = LOW;
    greenButtonState = LOW;
    blueButtonState = LOW;
    /////////////////////////

    // criteria to end trial (add later)
    switch (currLED)
    {
    case 0: // red
    case 1: // green
    case 2: // blue
    default:
        // somethings broken with button/checks if it goes here
        Serial.println("ERR ===== What the button !? =====");
        break;
    }

    currLED = random(0, 3); // set next LED to be lit up (rand)
}

// =======================================================================
//                       F  U  N  C  T  I  O  N  S
// =======================================================================

void blink()
{
    // three lights blink three times
    for (int i = 0; i <= 2; i++)
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
}