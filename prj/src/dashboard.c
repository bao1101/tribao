#include <stdio.h>
#include "system_data.h"

void displayDashboard(SystemData *data) {
    printf("=== SYSTEM MONITOR DASHBOARD - %s ===\n", data->systemTime);
    printf("CPU: %.1f%% (Frequency: %.1f MHz, Temperature: %.1f°C)\n", data->totalCpuUsage, data->frequency, data->temperature);
    for (int i = 0; i < data->coreCount; i++) {
        printf("Core %d: %.1f%%\n", i, data->coreUsage[i]);
    }
    printf("RAM: %lu/%lu MB, Swap: %lu MB, Cache: %lu KB\n", data->ramUsed, data->ramTotal, data->swapUsed, data->cacheSize);
    printf("Disk: %lu/%lu MB, Read/Write: %.1f/%.1f MB/s, IOPS: %lu\n", data->diskUsed, data->diskTotal, data->readSpeed, data->writeSpeed, data->iops);
    printf("Network: Upload %.1f MB/s, Download %.1f MB/s, Bandwidth %.1f Mbps, Connections: %d\n", data->uploadSpeed, data->downloadSpeed, data->bandwidth, data->connections);
    printf("IP: %s, Packets: %lu/%lu\n", data->ipAddress, data->packetsSent, data->packetsReceived);
    printf("Uptime: %ld seconds, Kernel: %s, Load Avg: %.1f %.1f %.1f\n", data->uptime, data->kernelVersion, data->loadAvg[0], data->loadAvg[1], data->loadAvg[2]);
    printf("Top 5 CPU: ");
    for (int i = 0; i < 5 && data->topCpuProcesses[i].cpuUsage > 0; i++) {
        printf("%s(%.1f%%) ", data->topCpuProcesses[i].name, data->topCpuProcesses[i].cpuUsage);
    }
    printf("\nTop 5 RAM: ");
    for (int i = 0; i < 5 && data->topRamProcesses[i].ramUsage > 0; i++) {
        printf("%s(%.1fMB) ", data->topRamProcesses[i].name, data->topRamProcesses[i].ramUsage);
    }
    printf("\n");
}