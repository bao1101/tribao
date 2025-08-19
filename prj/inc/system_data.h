#ifndef SYSTEM_DATA_H
#define SYSTEM_DATA_H

#define MAX_PROCESSES 50
#define MAX_SERVICES 100
#define MAX_CORES 16

// ==================== PROCESS ====================
typedef struct {
    char name[64];
    float cpuUsage;    
    float ramUsage;     
    unsigned long pid;   
} Process;

// ==================== CPU ====================
typedef struct {
    float totalUsage;             
    float coreUsage[MAX_CORES];  
    float frequency;               
    float temperature;          
    int coreCount;
    Process topProcesses[MAX_PROCESSES];
} CPUInfo;

// ==================== MEMORY ====================
typedef struct {
    unsigned long used;     
    unsigned long total;     
    unsigned long swapUsed;  
    unsigned long swapTotal; 
    unsigned long cache;     
    Process topProcesses[MAX_PROCESSES];
} MemoryInfo;

// ==================== DISK ====================
typedef struct {
    unsigned long used;     
    unsigned long total;   
    float readSpeed;       
    float writeSpeed;       
    unsigned long iops;
} DiskInfo;

// ==================== NETWORK ====================
typedef struct {
    char ipAddress[40];      
    float uploadSpeed;       
    float downloadSpeed;    
    float bandwidth;        
    unsigned long packetsSent;
    unsigned long packetsReceived;
    int connections;
} NetworkInfo;

// ==================== SYSTEM ====================
typedef struct {
    long uptime;             
    char systemTime[32];     
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