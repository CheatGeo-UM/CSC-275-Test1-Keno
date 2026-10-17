#include "Game.h"

int main() {
    //Run this in debug mode for fully correct spacing output.
    //See long message below for explanation of the issue I was having.
    Game game; //This is abstraction of the entirety of Game.cpp, which itself uses KenoNumbers and Player to run.
    return 0;
}

// When the Keno program is run in debug mode, spacing for the program functions exactly as it is supposed to.
// When it is run normally, the single space between Pick #X: and the input is not there, and
// other parts of the output have full lines of space added between them.
// No testing or changes I made ultimately fixed this issue.
// I am still unsure at this point what is causing it, but it seems to only affect the visual output,
// not the actual running of the program.

// If you find out what happened to cause this, or if it doesn't happen when you run it normally, please inform me (George Cheatham).
