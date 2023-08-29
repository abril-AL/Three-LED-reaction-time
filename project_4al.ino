// LED variables
#define redPin 10
#define greenPin 11
#define bluePin 12
// An analog signal is one that can take on any number of values,
// unlike a digital signal which has only two values: HIGH and LOW

int ledBrightness = 125; // will use same for all LEDS
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

void setup()
{
    // initialize analog pins as an output
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    // initialize button pin as input
    pinMode(redButtonPin, INPUT);
    pinMode(greenButtonPin, INPUT);
    pinMode(blueButtonPin, INPUT);
}

void loop()
{
}
