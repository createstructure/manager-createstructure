/**
 * memory.cpp
 *
 * Library to mamange memory
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "memory.hpp"

// Definitions
// #define DEBUG

// Function(s)
Memory::Memory(MEMORY_UNIT unit)
{
        /**
         * Constructor
         *
         * @param unit: memory unit
         */
        Memory::memoryUnit = unit;
}

void Memory::getMemoryInfo()
{
        /**
         * Get memory info
         */
        sysinfo(&memInfo);
}

long long Memory::getTotalMemory()
{
        /**
         * Get total memory
         *
         * @return total RAM memory in bytes
         */
        Memory::getMemoryInfo();
        return round(memInfo.totalram * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

long long Memory::getFreeMemory()
{
        /**
         * Get free memory
         *
         * @return free RAM memory in bytes
         */
        Memory::getMemoryInfo();
        return round(memInfo.freeram * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

long long Memory::getUsedMemory()
{
        /**
         * Get used memory
         *
         * @return used RAM memory in bytes
         */
        Memory::getMemoryInfo();
        return round((memInfo.totalram - memInfo.freeram) * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

double Memory::getUsedMemoryPercent()
{
        /**
         * Get used memory percent
         *
         * @return used RAM memory percent
         */
        Memory::getMemoryInfo();
        return (memInfo.totalram - memInfo.freeram) * 100 / memInfo.totalram;
}

long long Memory::getTotalMemory(MEMORY_UNIT unit)
{
        /**
         * Get total memory
         *
         * @param unit: memory unit
         * @return total RAM memory in bytes
         */

        Memory memory(unit);
        return memory.getTotalMemory();
}

long long Memory::getFreeMemory(MEMORY_UNIT unit)
{
        /**
         * Get free memory
         *
         * @param unit: memory unit
         * @return free RAM memory in bytes
         */

        Memory memory(unit);
        return memory.getFreeMemory();
}

long long Memory::getUsedMemory(MEMORY_UNIT unit)
{
        /**
         * Get used memory
         *
         * @param unit: memory unit
         * @return used RAM memory in bytes
         */

        Memory memory(unit);
        return memory.getUsedMemory();
}

double Memory::getUsedMemoryPercent(MEMORY_UNIT unit)
{
        /**
         * Get used memory percent
         *
         * @param unit: memory unit
         * @return used RAM memory percent
         */

        Memory memory(unit);
        return memory.getUsedMemoryPercent();
}

#undef DEBUG
