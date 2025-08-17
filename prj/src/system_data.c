#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PROCESSES 50
#define MAX_CORES 8
#define MAX_SERVICES 100

typedef struct {
    char name[50];
    float cpuUsage;
    float ramUsage;
} Process;

typedef struct {
    float totalCpuUsage;
    float coreUsage[MAX_CORES];
    float frequency;
    float temperature;
    Process topCpuProcesses[MAX_PROCESSES];
    Process topRamProcesses[MAX_PROCESSES];
    unsigned long ramUsed;
    unsigned long ramTotal;
    unsigned long swapUsed;
    unsigned long cacheSize;
    unsigned long diskUsed;
    unsigned long diskTotal;
    float readSpeed;
    float writeSpeed;
    unsigned long iops;
    float uploadSpeed;
    float downloadSpeed;
    float bandwidth;
    int connections;
    char ipAddress[16];
    unsigned long packetsSent;
    unsigned long packetsReceived;
    long uptime;
    char systemTime[20];
    char kernelVersion[20];
    char services[MAX_SERVICES][50];
    float loadAvg[3];
    int coreCount;
} SystemData;

void initSystemData(SystemData *data) {
    data->totalCpuUsage = 23.9;
    data->coreUsage[0] = 17.9; data->coreUsage[1] = 18.3; data->coreUsage[2] = 0.0; data->coreUsage[3] = 0.0;
    data->frequency = 3200.5;
    data->temperature = 45.7;
    strcpy(data->topCpuProcesses[0].name, "Microsoft Edge"); data->topCpuProcesses[0].cpuUsage = 17.9;
    strcpy(data->topCpuProcesses[1].name, "Antimalware Service"); data->topCpuProcesses[1].cpuUsage = 0.2;
    strcpy(data->topCpuProcesses[2].name, "Zalo"); data->topCpuProcesses[2].cpuUsage = 0.1;
    strcpy(data->topCpuProcesses[3].name, "Foxit Reader"); data->topCpuProcesses[3].cpuUsage = 0.0;
    strcpy(data->topCpuProcesses[4].name, "HP Insights"); data->topCpuProcesses[4].cpuUsage = 0.0;
    data->ramUsed = 4096; data->ramTotal = 16384;
    data->swapUsed = 512;
    strcpy(data->topRamProcesses[0].name, "Microsoft Edge"); data->topRamProcesses[0].ramUsage = 2.5;
    strcpy(data->topRamProcesses[1].name, "Windows Explorer"); data->topRamProcesses[1].ramUsage = 0.9;
    data->cacheSize = 1024;
    data->diskUsed = 50000; data->diskTotal = 100000;
    data->readSpeed = 50.0; data->writeSpeed = 30.0;
    data->iops = 1000;
    data->uploadSpeed = 0.2; data->downloadSpeed = 0.1;
    data->bandwidth = 0.1;
    data->connections = 10;
    strcpy(data->ipAddress, "192.168.1.1");
    data->packetsSent = 10000; data->packetsReceived = 15000;
    data->uptime = 172800;
    strcpy(data->systemTime, "09:16 PM +07");
    strcpy(data->kernelVersion, "Windows 10 22H2");
    strcpy(data->services[0], "Service1"); strcpy(data->services[1], "Service2");
    data->loadAvg[0] = 1.5; data->loadAvg[1] = 1.2; data->loadAvg[2] = 1.0;
    data->coreCount = 4;
}

void updateSystemData(SystemData *data) {
    data->totalCpuUsage += 1.0;
    data->temperature += 0.5;
    strcpy(data->systemTime, "09:16 PM +07"); // Update sample time
}

void checkAlerts(SystemData *data) {
    float cpuThreshold = 80.0;
    float tempThreshold = 60.0;
    if (data->totalCpuUsage > cpuThreshold) {
        printf("Warning: CPU exceeds threshold %.1f%%\n", cpuThreshold);
    }
    if (data->temperature > tempThreshold) {
        printf("Warning: CPU temperature exceeds threshold %.1f°C\n", tempThreshold);
    }
    FILE *logFile = fopen("logs/system_log.txt", "a");
    if (logFile) {
        fprintf(logFile, "Time: %s, CPU: %.1f%%, Temp: %.1f°C\n", data->systemTime, data->totalCpuUsage, data->temperature);
        fclose(logFile);
    }
}

void backupConfig(SystemData *data) {
    FILE *file = fopen("config/config.bin", "wb");
    if (file) {
        fwrite(data, sizeof(SystemData), 1, file);
        fclose(file);
        printf("Configuration has been backed up.\n");
    }
}