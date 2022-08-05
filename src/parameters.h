//
// Created by noe on 05.08.22.
//

#ifndef KANACRUSH_SRC_PARAMETERS_H_
#define KANACRUSH_SRC_PARAMETERS_H_

#include <string>
static bool DEBUG = false;

//board
static int BOARD_SIZE = 10;
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
