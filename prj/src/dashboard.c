#include <stdio.h>
#include "system_data.h"

void displayDashboard(SystemData *data) {
    printf("=== SYSTEM MONITOR DASHBOARD - %s ===\n", data->system.systemTime);
    printf("CPU: %.1f%% (Frequency: %.1f MHz, Temperature: %.1f°C)\n", data->cpu.totalUsage, data->cpu.frequency, data->cpu.temperature);
    for (int i = 0; i < data->cpu.coreCount; i++) {
        printf("Core %d: %.1f%%\n", i, data->cpu.coreUsage[i]);
    }
    printf("Memory: %lu/%lu MB, Swap: %lu/%lu MB, Cache: %lu MB\n", data->memory.used, data->memory.total, data->memory.swapUsed, data->memory.swapTotal, data->memory.cache);
    printf("Disk: %lu/%lu MB, Read/Write: %.1f/%.1f MB/s, IOPS: %lu\n", data->disk.used, data->disk.total, data->disk.readSpeed, data->disk.writeSpeed, data->disk.iops);
    printf("Network: IP %s, Upload %.1f MB/s, Download %.1f MB/s, Bandwidth %.1f Mbps, Connections: %d\n", data->network.ipAddress, data->network.uploadSpeed, data->network.downloadSpeed, data->network.bandwidth, data->network.connections);
    printf("Packets: %lu sent, %lu received\n", data->network.packetsSent, data->network.packetsReceived);
    printf("Uptime: %ld seconds, Kernel: %s, Load Avg: %.1f %.1f %.1f\n", data->system.uptime, data->system.kernelVersion, data->system.loadAvg[0], data->system.loadAvg[1], data->system.loadAvg[2]);
    printf("Top 5 CPU: ");
    for (int i = 0; i < 5 && data->cpu.topProcesses[i].cpuUsage > 0; i++) {
        printf("%s(PID:%lu, %.1f%%) ", data->cpu.topProcesses[i].name, data->cpu.topProcesses[i].pid, data->cpu.topProcesses[i].cpuUsage);
    }
    printf("\nTop 5 RAM: ");
    for (int i = 0; i < 5 && data->memory.topProcesses[i].ramUsage > 0; i++) {
        printf("%s(PID:%lu, %.1fMB) ", data->memory.topProcesses[i].name, data->memory.topProcesses[i].pid, data->memory.topProcesses[i].ramUsage);
    }
    printf("\n");
}