#ifndef SYSTEM_DATA_H
#define SYSTEM_DATA_H

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

void initSystemData(SystemData *data);
void updateSystemData(SystemData *data);
void checkAlerts(SystemData *data);
void backupConfig(SystemData *data);

#endif