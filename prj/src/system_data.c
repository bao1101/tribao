#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 50
#define MAX_SERVICES 100
#define MAX_CORES 16

// ==================== PROCESS ====================
typedef struct {
    char name[64];
    float cpuUsage;      // %
    float ramUsage;      // MB
    unsigned long pid;   // Process ID
} Process;

// ==================== CPU ====================
typedef struct {
    float totalUsage;              // %
    float coreUsage[MAX_CORES];    // %
    float frequency;               // MHz
    float temperature;             // °C
    int coreCount;
    Process topProcesses[MAX_PROCESSES];
} CPUInfo;

// ==================== MEMORY ====================
typedef struct {
    unsigned long used;      // MB
    unsigned long total;     // MB
    unsigned long swapUsed;  // MB
    unsigned long swapTotal; // MB
    unsigned long cache;     // MB
    Process topProcesses[MAX_PROCESSES];
} MemoryInfo;

// ==================== DISK ====================
typedef struct {
    unsigned long used;     // MB
    unsigned long total;    // MB
    float readSpeed;        // MB/s
    float writeSpeed;       // MB/s
    unsigned long iops;
} DiskInfo;

// ==================== NETWORK ====================
typedef struct {
    char ipAddress[40];      // Hỗ trợ cả IPv6
    float uploadSpeed;       // MB/s
    float downloadSpeed;     // MB/s
    float bandwidth;         // Mbps
    unsigned long packetsSent;
    unsigned long packetsReceived;
    int connections;
} NetworkInfo;

// ==================== SYSTEM ====================
typedef struct {
    long uptime;             // seconds
    char systemTime[32];     // "YYYY-MM-DD HH:MM:SS"
    char kernelVersion[64];
    char services[MAX_SERVICES][64];
    float loadAvg[3];
} SystemInfo;

// ==================== HỆ THỐNG CHÍNH ====================
typedef struct {
    CPUInfo cpu;
    MemoryInfo memory;
    DiskInfo disk;
    NetworkInfo network;
    SystemInfo system;
} SystemData;

void initSystemData(SystemData *data) {
    // Initialize CPU
    data->cpu.totalUsage = 23.9;
    data->cpu.coreUsage[0] = 17.9; data->cpu.coreUsage[1] = 18.3;
    data->cpu.coreUsage[2] = 0.0; data->cpu.coreUsage[3] = 0.0;
    data->cpu.frequency = 3200.5;
    data->cpu.temperature = 45.7;
    data->cpu.coreCount = 4;
    strcpy(data->cpu.topProcesses[0].name, "Microsoft Edge"); data->cpu.topProcesses[0].cpuUsage = 17.9; data->cpu.topProcesses[0].pid = 1234;
    strcpy(data->cpu.topProcesses[1].name, "Antimalware Service"); data->cpu.topProcesses[1].cpuUsage = 0.2; data->cpu.topProcesses[1].pid = 5678;

    // Initialize Memory
    data->memory.used = 4096; data->memory.total = 16384;
    data->memory.swapUsed = 512; data->memory.swapTotal = 2048;
    data->memory.cache = 1024;
    strcpy(data->memory.topProcesses[0].name, "Microsoft Edge"); data->memory.topProcesses[0].ramUsage = 2.5; data->memory.topProcesses[0].pid = 1234;

    // Initialize Disk
    data->disk.used = 50000; data->disk.total = 100000;
    data->disk.readSpeed = 50.0; data->disk.writeSpeed = 30.0;
    data->disk.iops = 1000;

    // Initialize Network
    strcpy(data->network.ipAddress, "192.168.1.1");
    data->network.uploadSpeed = 0.2; data->network.downloadSpeed = 0.1;
    data->network.bandwidth = 0.1;
    data->network.packetsSent = 10000; data->network.packetsReceived = 15000;
    data->network.connections = 10;

    // Initialize System
    data->system.uptime = 172800;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(data->system.systemTime, sizeof(data->system.systemTime), "%Y-%m-%d %H:%M:%S", tm);
    strcpy(data->system.kernelVersion, "Windows 10 22H2");
    strcpy(data->system.services[0], "Service1");
    data->system.loadAvg[0] = 1.5; data->system.loadAvg[1] = 1.2; data->system.loadAvg[2] = 1.0;
}

void updateSystemData(SystemData *data) {
    data->cpu.totalUsage += 1.0;
    data->cpu.temperature += 0.5;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(data->system.systemTime, sizeof(data->system.systemTime), "%Y-%m-%d %H:%M:%S", tm);
}

void checkAlerts(SystemData *data) {
    float cpuThreshold = 80.0;
    float tempThreshold = 60.0;
    if (data->cpu.totalUsage > cpuThreshold) {
        printf("Warning: CPU usage exceeds threshold %.1f%%\n", cpuThreshold);
    }
    if (data->cpu.temperature > tempThreshold) {
        printf("Warning: CPU temperature exceeds threshold %.1f°C\n", tempThreshold);
    }
    FILE *logFile = fopen("logs/system_log.txt", "a");
    if (logFile) {
        fprintf(logFile, "Time: %s, CPU: %.1f%%, Temp: %.1f°C\n", data->system.systemTime, data->cpu.totalUsage, data->cpu.temperature);
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