#include <stdio.h>
#include <unistd.h>
#include "system_data.h"
#include "controller.h"

#define REFRESH 1
#define CHANGE_REFRESH_RATE 2
#define BACKUP_CONFIG 3
#define EXIT 4

void handleUserInput(SystemData *data, int *refreshRate) {
    int choice;
    printf("1. Refresh\t2. Change Refresh Rate\t3. Backup Config\t4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case REFRESH:
            updateSystemData(data);
            checkAlerts(data);
            displayDashboard(data);
            break;
        case CHANGE_REFRESH_RATE:
            printf("Enter update frequency (seconds): ");
            scanf("%d", refreshRate);
            break;
        case BACKUP_CONFIG:
            backupConfig(data);
            break;
        case EXIT:
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