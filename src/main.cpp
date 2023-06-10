//
// Created by unknown on 05.06.23.
//

#include "main.h"
#include "simple_data_race.h"
#include "fasttrack_incomplete.h"
#include "unsoundness.h"
#include "vector_clock_limitation_example.h"
#include "shadow_word_limitation.h"

int main() {
    shadow_word_limitation::run();
}