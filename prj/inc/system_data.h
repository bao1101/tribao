#ifndef SYSTEM_DATA_H
#define SYSTEM_DATA_H

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

// ==================== MAIN SYSTEM ====================
typedef struct {
    CPUInfo cpu;
    MemoryInfo memory;
    DiskInfo disk;
    NetworkInfo network;
    SystemInfo system;
} SystemData;

void initSystemData(SystemData *data);
void updateSystemData(SystemData *data);
void checkAlerts(SystemData *data);
void backupConfig(SystemData *data);

#endif