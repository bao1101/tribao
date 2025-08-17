#include <stdio.h>
#include <unistd.h>
#include "system_data.h"
#include "controller.h"

void handleUserInput(SystemData *data, int *refreshRate) {
    int choice;
    printf("1. Refresh\t2. Change Refresh Rate\t3. Backup Config\t4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            updateSystemData(data);
            checkAlerts(data);
            displayDashboard(data);
            break;
        case 2:
            printf("Enter update frequency (seconds): ");
            scanf("%d", refreshRate);
            break;
        case 3:
            backupConfig(data);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
}

void runController(SystemData *data) {
    int refreshRate = 1; // Default 1 second
    while (1) {
        handleUserInput(data, &refreshRate);
        sleep(refreshRate);
    }
}