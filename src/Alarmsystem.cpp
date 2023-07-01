/*
 * Alarm System - LN3
 * 
 * Alarm System for Sparkfun Inventor's Kit for Photon using the OLED Display.
 * 
 * This Programm was written by Jan Nägeli
 */

/* Include Librarys */
#include <SparkFunMicroOLED.h>
#include "math.h"

/* Defining Input and Output Pins */
#define PIN_BT_BL D3            /* Connect Blue Button to Pin D3 */
#define PIN_BT_GN D4            /* Connect Green Button to Pin D4 */
#define PIN_BT_RD D5            /* Connect Blue Button to Pin D5 */
#define PIN_SPEAKER D2          /* Connect Speaker to Pin D2 */
#define PIN_DOOR D1             /* Connect Door Sensor to Pin D1 */

/* MicroOLED using SPI Interface */
#define PIN_DISPLAY_RST D7      /* Connect MicroOLED RST to Pin D7 */
#define PIN_DISPLAY_DC  D6      /* Connect MicroOLED DC to Pin D6 */
#define PIN_DISPLAY_CS  A2      /* Connect MicroOLED CS to Pin A2 */
/* 
 * Conect MicroOLED SCK to Pin A3 and SDI to Pin A5 (required for SPI Interface)
 * Conect MicroOLED 3.3V to Power, to Ground
 */
MicroOLED display(MODE_SPI, PIN_DISPLAY_RST, PIN_DISPLAY_DC, PIN_DISPLAY_CS);

/* Defining Constants */
#define DISPLAY_SLEEP_TIME 120  /* Display sleep time in seconds */
#define ALARM_DELAY_TIME 30     /* Alarm delay time in seconds */
#define SECRET_CODE 1234        /* Secret code for alarm system */
#define CODE_LENGTH 4           /* Length of the alarm code */
#define NOTE_LENGTH 500         /* Length of 1 Note in miliseconds */

/* Bitmaps for Display */

const unsigned char Bitmap_Inactive [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xF0, 0xF0, 0xE0, 0xC0,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC,
0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07,
0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x08, 0x18, 0x3C, 0x3C, 0x3C, 0x3C,
0x3C, 0x3C, 0x3C, 0x7C, 0x78, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x0C, 0x1E, 0x1F, 0x0F, 0x07, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
0xE0, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 0xC0,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0xE0,
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07,
0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 0xC0, 0x83, 0x07, 0x0F, 0x1F, 0x00, 0x00, 0x00, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C,
0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3D, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 0xC0,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x1F, 0x1E, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char Bitmap_Active [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC,
0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x02, 0x07, 0x0F, 0x1F, 0x1E, 0x0C, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x0C, 0x1E, 0x1F, 0x0F, 0x07, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
0xE0, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0xE0,
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char Bitmap_Alert [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0,
0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03,
0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0,
0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xFC, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0,
0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0xFC, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


/* State Maschine */
enum SM_State {
    SM_INACTIV,         /* Alarm system inactive state */
    SM_IDLE,            /* Idle state */
    SM_ACTIV,           /* Active state */
    SM_CODE,            /* Code entry state*/
    SM_ALARM            /* Alarm state*/
};
int SM_State = SM_INACTIV;

/* Variables Declaration */

/* Input States Varibles */
bool ButtonState_Green, ButtonState_Red, ButtonState_Blue, StateChange_Door, State_Door;
bool LastState_Green, LastState_Blue, LastState_Red, LastState_Door;
/* Display Sleep Variables*/
unsigned long LastInput;
bool DisplaySleep;
/* Alarm Variables */
unsigned long AlarmStart, AlarmTime_S, AlarmTime_MS;
/* Code Entry Variables*/
int Code, Code_Nummer, Code_Position = 0;
/* Sound Variables */
unsigned long Note_Time;
bool Note;

/* Setup */

void setup() {
    /*  Set pin modes for Buttons and door sensor */
    pinMode(PIN_BT_BL, INPUT_PULLUP);
    pinMode(PIN_BT_GN, INPUT_PULLUP);
    pinMode(PIN_BT_RD, INPUT_PULLUP);
    pinMode(PIN_DOOR, INPUT_PULLUP);
    /* Set pin mode for speaker */
    pinMode(PIN_SPEAKER, OUTPUT);

    /* Set Start Time for Display Sleep */
    LastInput = millis();

    /* Initialize MicroOLED display */
    display.begin();
    display.setFontType(1); /* small size font (7 columns, 3 rows) */

}

/* Loop */

void loop() {
    /* Update input states */
    updateInputState(PIN_BT_BL, LastState_Blue, ButtonState_Blue);
    updateInputState(PIN_BT_GN, LastState_Green, ButtonState_Green);
    updateInputState(PIN_BT_RD, LastState_Red, ButtonState_Red);
    updateInputState(PIN_DOOR, LastState_Door, StateChange_Door);
    State_Door = digitalRead(PIN_DOOR);

    switch (SM_State) {

    case SM_INACTIV:
        /* Display alarm system inactive */
        display.clear(PAGE);
        display.drawBitmap(Bitmap_Inactive);

        /* Transition to SM_IDLE state when the red button is pressed */
        if (ButtonState_Red && !DisplaySleep) {
            SM_State = SM_IDLE;
        }
    break;

    case SM_IDLE:
        /* Display waiting for door message */
        display.clear(PAGE);
        display.setCursor(0, 0);
        display.print("Waitingfor\nDoor");

        /* Transition to SM_ACTIV state when the door is closed */
        if (State_Door == LOW) {
            tone(PIN_SPEAKER, 523, NOTE_LENGTH);
            SM_State = SM_ACTIV;
        }
    break;
    
    case SM_ACTIV:
        /* Display alarm system active */
        display.clear(PAGE);
        display.drawBitmap(Bitmap_Active);

        /* Transition to SM_CODE state when the door is opend or the red button is pressed */
        if (State_Door == HIGH || (ButtonState_Red && !DisplaySleep)) {   
            tone(PIN_SPEAKER, 523, NOTE_LENGTH);
            AlarmStart = millis();
            Code = 0;
            Code_Nummer = 0;
            Code_Position = 0;
            SM_State = SM_CODE;
        }
    break;
    
    case SM_CODE:
        /* Increase the code number when the blue buttons is pressed */
        if (ButtonState_Blue && !DisplaySleep) {
            Code_Nummer = (Code_Nummer + 1) % 10;
        }

        /* Decrease the code number when the blue buttons is pressed */
        if (ButtonState_Green && !DisplaySleep) {
          Code_Nummer = (Code_Nummer + 9) % 10;
        }

        /* Add the code number to the code when the red button is pressed */
        if (ButtonState_Red && !DisplaySleep) {
            Code = Code * 10 + Code_Nummer;
            Code_Position++;
        }

        /* Calculate remaining alarm time */
        AlarmTime_S = (ALARM_DELAY_TIME * 1000 - (millis() - AlarmStart)) / 1000;
        AlarmTime_MS = (ALARM_DELAY_TIME * 1000 - (millis() - AlarmStart)) % 1000;

        /* Display code entry and remaining alarm time */
        display.clear(PAGE);
        display.setCursor(0, 0);
        display.print("Code:\n");
        display.setFontType(2);
        if (Code_Position > 0) {
            printWithLeadZero(Code,Code_Position);
        }
        display.print(Code_Nummer);
        display.print("\n");
        display.setFontType(0);
        display.print("\nT:");
        printWithLeadZero(AlarmTime_S,2);
        display.print(".");
        printWithLeadZero(AlarmTime_MS,3);
        display.print("s");
        display.setFontType(1);

        /* Check if the code is complete or the alarm delay time has passed */
        if (Code_Position == CODE_LENGTH || (millis() - AlarmStart) >= (ALARM_DELAY_TIME * 1000)) {
            /* Check if the entered code is correct */
            if(Code == SECRET_CODE) {
                tone(PIN_SPEAKER, 523, NOTE_LENGTH);
                SM_State = SM_INACTIV;
            } else {
                SM_State = SM_ALARM;
            }
        }
    break;

    case SM_ALARM:
            /* Display alarm message */
            display.clear(PAGE);
            display.drawBitmap(Bitmap_Alert);

            /* Play alarm sound */
            if ((millis() - Note_Time) >= NOTE_LENGTH) {   
                if (Note) {
                    tone(PIN_SPEAKER, 262, NOTE_LENGTH);
                } else {
                    tone(PIN_SPEAKER, 523, NOTE_LENGTH);
                }
                Note = !Note;
                Note_Time = millis();
            }

            /* Used for Debugging: Transition to SM_INACTIV state when the red button is pressed */
            /* if(ButtonState_Red) {   
                SM_State = SM_INACTIV;
            }
            */
    break;
    }

    /* Clears the display based on Last Time of Input  */
    if (ButtonState_Blue || ButtonState_Green || ButtonState_Red || StateChange_Door) {
        DisplaySleep = false;
        LastInput = millis();
    } else if ((millis() - LastInput) >= DISPLAY_SLEEP_TIME * 1000) {
        DisplaySleep = true;
        display.clear(PAGE);
        /*
        display.setCursor(0, 0);
        display.print("Displayoff");
        */
    }

    display.display(); /* Update Display */
}

/* updateInputState 
 *
 * This Function handle input pin state changes and provide the updated state through the InputState variable.
 */
void updateInputState(int Pin, bool &lastState, bool &InputState) {
    /* Read the current state of the input pin */
    bool currentInputState = !digitalRead(Pin);

    /* Check if the current state is different from the last state */
    if (currentInputState != lastState) {   
        if(Pin == PIN_DOOR) {
            InputState = true;
        } else {
            InputState = currentInputState;
        }
    } else {
        /* If the current state is the same as the last state, set InputState to false */
        InputState = false;
    }
    lastState = currentInputState;
}

/* printWithLeadZero
 *
 * The function printWithLeadZero is a utility function that prints a given number with leading zeros.
 * It takes two parameters: 
 *      "n" represents the number to be printed
 *      "digits" indicates the desired total number of digits.
 */

void printWithLeadZero(unsigned int n, int digits) {
    /* Cycle through digit-1 times */
    for (int i=1; i<digits; i++) {
        /* Check if a number is less than 10^i */
        if (n < (pow(10, i))){
            display.print("0"); /* Print a leading zero */
        }
    }
    display.print(n); /* Print the rest of the number */
}
