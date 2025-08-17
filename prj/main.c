#include <stdio.h>
#include "system_data.h"
#include "dashboard.h"
#include "controller.h"

int main() {
    SystemData data;
    initSystemData(&data);
    displayDashboard(&data);
    runController(&data);
    return 0;
}