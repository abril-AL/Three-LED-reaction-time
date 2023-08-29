// LED variables
#define redPin 10
#define greenPin 11
#define bluePin 12
// An analog signal is one that can take on any number of values,
// unlike a digital signal which has only two values: HIGH and LOW

// each LED needs own brightness level
#define redBrightness 190
#define greenBrightness 10
#define blueBrightness 1500

int redState = LOW;
int greenState = LOW;
int blueState = LOW;

// Button variables
#define redButtonPin 7
int redButtonState = LOW;

#define greenButtonPin 8
int greenButtonState = LOW;

#define blueButtonPin 9
int blueButtonState = LOW;

/* add later
// Time variables
long randDelay;
long newT;
long oldT;
long deltaT;
*/

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
    for (int i = 0; i <= 3; i++)
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

void loop()
{
}
