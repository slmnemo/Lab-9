// nl
// Using GPL 3.0 License, but please don't use this as your own submission in E85.

#include <pwm_nl.h>

// Notes as defined from C2 to C7. This should be enough to write most songs. You could also extend this to 3 different lines using PWM.

#include <notes.h>


// Duration is 3 for a 16th note, 6 for an 8th note, 12 for a quarter note, 24 for a half note, 48 for a whole note. 
// This also allows us to divide all of these into triplets by taking a durations and dividing it by 3 to turn it into triplets. 
// For example, a triplet set over half notes would be three durations of 8, 8, 8.
// Pitches are defined from E3 to A5. This should be enough for most songs.
// BPM is specified above with any song packs.
// (For future reference, please include a way to play 32nds. It might also be worth converting int duration to float duration since it would give us more granular control over the divisions.)

//

// Harris's Tune, uncomment for something boring.

// int pitch[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0};

// int duration[] = {4, 2, 2, 4, 4, 4, 4, 4, 4};

// 

int pitch[] = { Eb6, Eb6, F6, F6, Bb5, Bb5, C6, C6, Ab5, F5,   Db6, Db6, Ab5, Ab5, Eb6, Eb6, Ab5, Ab5, G5, Eb5,   
                Eb6, Eb6, F6, F6, Bb5, Bb5, C6, C6, Ab5, F5,   Db6, Db6, Ab5, Ab5, Eb6, Eb6, Ab6, Ab6, G6, G6,

                Eb6, Eb6, F6, F6, Bb5, Bb5, C6, C6, Ab5, F5,   Db6, Db6, Ab5, Ab5, Eb6, Eb6, Ab5, Ab5, G5, Eb5,   
                Eb6, Eb6, F6, F6, Bb5, Bb5, C6, C6, Ab5, F5,   Db6, Db6, Ab5, Ab5, Eb6, Eb6, Ab6, Ab6, G6, G6,

                0,

                Db6, Db6, Ab5, Ab5, Eb6, Eb6, Ab6, Ab6, G6, G6,

                0,

                Eb5, Eb5, F5, F5, Bb4, Bb4, C5, C5, Ab4, F4,   Db5, Db5, Ab4, Ab4, Eb5, Eb5, Ab4, Ab4, G4, Eb4,
                Eb5, Eb5, F5, F5, Bb4, Bb4, C5, C5, Ab4, F4,   Db5, Db5, Ab4, Ab4, Eb5, Eb5, Ab4, Ab4, G4, Eb4,

                Eb5, Eb5, F5, F5, Bb4, Bb4, C5, C5, Ab4, F4,   Db5, Db5, Ab4, Ab4, Eb5, Eb5, Ab4, Ab4, G4, Eb4,
                Eb5, Eb5, F5, F5, Bb4, Bb4, C5, C5, Ab4, F4,   Db5, Db5, Ab4, Ab4, Eb5, Eb5, Ab4, Ab4, G4, Eb4,

                F4, C5, Bb4, C5, Ab4, C5,   G4, G4, Ab4, G4, Ab4,
                G4, Bb4,   F4, Eb4,
                F4, C5, Bb4, C5, Ab4, C5,   G4, G4, Ab4, G4, Ab4,
                G4, Bb4, Eb5, D5,
                C5,

                F4, C5, Bb4, C5, Ab4, C5,   G4, G4, Ab4, G4, Ab4,
                G4, Bb4,   F4, Eb4,
                F4, C5, Bb4, C5, Ab4, C5,   G4, G4, Ab4, G4, Ab4,
                G4, Bb4, Eb5, D5,
                C5,

                F5, C6, Bb5, C6, Ab5, C6,   G5, G5, Ab5, G5, Ab5,
                G5, Bb5,   F5, Eb5,
                F5, C6, Bb5, C6, Ab5, C6,   G5, G5, Ab5, G5, Ab5,
                G5, Bb5, Eb6, D6,
                C6,

                F5, C6, Bb5, C6, Ab5, C6,   G5, G5, Ab5, G5, Ab5,
                G5, Bb5,   F5, Eb5,
                F5, C5, Eb5, F5,   Ab5, G5, Eb5,
                F5,   F5,

                
                0};

int duration[] = {  3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    
                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6, 

                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    
                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6, 

                    6,

                    3, 6, 3, 6, 3, 6, 3, 6, 3, 9,

                    6,

                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    
                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6, 

                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    
                    3, 6, 3, 6, 3, 6, 3, 6, 6, 6,    3, 6, 3, 6, 3, 6, 3, 6, 6, 6, 

                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    18, 18,   18, 18,
                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    12, 12, 9, 3,
                    36,

                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    18, 18,   18, 18,
                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    12, 12, 9, 3,
                    36,

                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    18, 18,   18, 18,
                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    12, 12, 9, 3,
                    36,

                    6, 6, 6, 6, 6, 6,   12, 6, 6, 6, 6,
                    18, 18,   18, 18,   18, 6, 6, 6,
                    12, 12, 12,   36,   36,
                    48};

int bpm = 150;

int ledl = 2;
int ledm = 1;
int ledh = 0;
int ledoff = 20;

void lightfreq(int pit)
{
    pinMode(ledoff, OUTPUT);
    pinMode(ledl, OUTPUT);
    pinMode(ledm, OUTPUT);
    pinMode(ledh, OUTPUT);
    digitalWrite(ledoff, 0);
    digitalWrite(ledl, 0);
    digitalWrite(ledm, 0);
    digitalWrite(ledh, 0);
    if (pit >= 1100)  {
        digitalWrite(ledl, 1);
        digitalWrite(ledm, 1);
        digitalWrite(ledh, 1);
    }
    if ((800 < pit) && (pit < 1100))  {
        digitalWrite(ledl, 1);
        digitalWrite(ledm, 1);
        digitalWrite(ledh, 0);
    }
    if ((400 < pit) && (pit <= 800))  {
        digitalWrite(ledl, 1);
        digitalWrite(ledm, 0);
        digitalWrite(ledh, 0);
    }
    if (pit <= 400)  {
        digitalWrite(ledl, 0);
        digitalWrite(ledm, 0);
        digitalWrite(ledh, 0);
    }
};

void noteplayer(int pit, int dur, double bpm)
{
    double beatconst = ((12*bpm)/60.0);
    pwm(pit, 0.5);
    lightfreq(pit);
    delay(0.9*dur*beatconst);
    pwm(0,0);
    digitalWrite(ledoff, 1);
    delay(0.1*dur*beatconst);
};


void musicplayer(int pitches[], int durations[], double bpm)
{
    int i = 0;
    pwmInit();
    for (i;(1);i++)  {
        noteplayer(pitches[i], durations[i], bpm);
    }
};

void main(void)
{
    printf(NL);
    musicplayer(pitch, duration, bpm);
};