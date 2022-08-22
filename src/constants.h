#ifndef KANACRUSH__CONSTANTS_H_
#define KANACRUSH__CONSTANTS_H_


enum gameState {Ready, Crush, Win, Loss};

static int Colors_codes[6] {1, 2, 3, 4, 91, 232};
static int cell_potential_values[6] {Colors_codes[0], Colors_codes[1], Colors_codes[2], Colors_codes[3], Colors_codes[4], Colors_codes[5]};


static const double refreshPerSecond = 60;

static const int windowWidth = 450;
static const int windowHeight = 450;

//static const bool DEBUG = true;
#endif //KANACRUSH__CONSTANTS_H_
