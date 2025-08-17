#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "system_data.h"

void handleUserInput(SystemData *data, int *refreshRate);
void runController(SystemData *data);

#endif