#ifndef KANACRUSH_SRC_PARAMETERS_H_
#define KANACRUSH_SRC_PARAMETERS_H_

#include <string>
//static bool DEBUG = true;
static bool DEBUG = false;
//static bool DEBUG_NODE = true;
static bool DEBUG_NODE = false;
//static bool DEBUG_LINKED_LIST = true;
static bool DEBUG_LINKED_LIST = false;
//static bool DEBUG_BOARD = true;
static bool DEBUG_BOARD = false;
//static bool DEBUG_CANVAS = true;
static bool DEBUG_CANVAS = false;
// static bool DEBUG_CANVAS_REDRAW = true;
static bool DEBUG_CANVAS_REDRAW = false;
// static bool DEBUG_GAME_WINDOW = true;
static bool DEBUG_GAME_WINDOW = false;
//static bool DEBUG_CRUSH = true;
static bool DEBUG_CRUSH = false;

//board
static int BOARD_SIZE = 9;
static std::string BOARD_DATA_STRUCTURE;
//static std::string BOARD_DATA_STRUCTURE = "linked_list";
//orientation
static std::string CELLS_CONTAINERS_HEAD_ORIENTATION;
//static std::string CELLS_CONTAINERS_HEAD_ORIENTATION = "down";
// BOARD_ORIENTATION_OPTIONS = "down, up, left, right";
static std::string CELLS_VALUES_DISTRIBUTION;
//static std::string CELLS_VALUES_DISTRIBUTION = "ascent";
//static std::string CELLS_VALUES_DISTRIBUTION = "random";

static bool PARAMETRIZED;

#endif //KANACRUSH_SRC_PARAMETERS_H_
