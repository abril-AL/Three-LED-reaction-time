# Three-LED-reaction-time

## Overview

### Introduction
Reaction time is the time between the presentation of a stimulus and the occurrence of a specific response to it.
Our project will focus on an LED stimulus, with red, green, and blue LEDS; as well as a button pressing response, one for each, in order to record the time. 
This project is similar to Lab 1C (UCLA Physics Dept.), which compares reaction time for two different stimuli types. 
Similar reaction time labs have been done but do not measure the effect of different distractions in addition to multiple color LEDs. 
This approach brings a unique perspective to our project.  

### Project Goal 
Our goal for this project is to test reaction time with regards to distractions, specifically, to test how reaction time differs when the subject is exposed to varying levels of distractions. 
We plan to achieve this goal by collecting reaction time data in 3 different levels of distraction. 
The control will be with no distractions. The first level will be a movie playing. 
The second level will be TV and music playing. We will have 3 LED stimuli and record the time it takes for the subject to press a button in response to one specific color of light, which will vary randomly for each participant. 
We plan to collect 80 sets of data using the arduino setup below.

## Methods

### Software Setup

#### Installation
- Need the Arduino leagcy version IDE
- only need to download `project_4al.ino` from this repository

#### Running the Program
- To run, open `project_4al.ino`, from the arduino IDE, press upload and the three leds will blink 3 times to signal the trials will start
- from the Arduino IDE, open the serial monitor to collect the reaction time data


### Hardware Setup
- Arduino Layout
  - ![image](https://github.com/abril-AL/Three-LED-reaction-time/assets/103137140/267f9cef-1452-41e9-9186-4748f2b6845d)
  - Credit: circuit by [Abril Aguilar-Lopez](https://www.tinkercad.com/things/jwfZ7pfeivH) on Tinkercad
 
- Circuit Schematic
  - ![image](https://github.com/abril-AL/Three-LED-reaction-time/assets/103137140/b3148ff7-9fd7-48bf-969b-2c9f58adea06)


### Data Collection
- Controls
  - Same time of day - noon until before 8pm
  - All participants will do the experiment in the same place 
  - Participants will do the no distractions trial with noise cancelling headphones/earphones on
  - Each participant will be instructed to use their right hand and index finger to press the buttons
  - Participants will take the same amount of break time between conditions (3-5 minutes)
  - Movie distraction: Despicable Me 2
  - Volume leel of show: less than half
  - Song played: As It Was by Harry Styles (on loop)
  - Researcher out of sight during trials
  - duration of conditions: 4-5 minutes
- Order of number of distractions
  - order in which the conditions are being presented to the participants
  - purpose: prevent fatigue effects
  - Ex. Participant #1 will do 0 distractions 1st, then 1 distraction 2nd, and finally 2 distractions.
  - Ex. Participant #2 will do 2 distractions 1st, then 0 distraction 2nd, and finally 1 distraction.

| Participant # | 0 Dist. | 1 Dist. | 2 Dist. |
|---------------|----------------|---------------|----------------|
| #1            | 1              | 2             | 3              |
| #2            | 2              | 3             | 1              |
| #3            | 3              | 1             | 2              |
| #4            | 1              | 2             | 3              |
| #5            | 2              | 3             | 1              |
| #6            | 3              | 1             | 2              |

### Data

Data is sent to the serial port in the format:
```
reaction time , LED color
```
Reaction time will be the difference in time from when the LED is turned on, until its corresponding button is pressed

LED color will be the color od the LED that was turned on

## Credits

### Team Members
- Alejandra Vargas
- Verna Chen
- [Swetha Sethuraj](https://github.com/ssethu1886)
- [Abril Aguilar-Lopez](https://github.com/abril-AL)