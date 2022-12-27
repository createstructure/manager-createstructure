/**
 * memory.hpp
 *
 * Library to mamange memory
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef CREATESTRUCTURE_MEMORY
// If not imported yet
#define CREATESTRUCTURE_MEMORY

// Dependencies
#include <thread>
#include <chrono>
#include <cmath>
#include "sys/types.h"
#include "sys/sysinfo.h"

// using ...
using namespace std;
using namespace std::this_thread;

// Classes prototipe(s)
class Memory
{
public:
        enum MEMORY_UNIT
        {
                BYTE,
                KB,
                MB,
                GB,
                TB,
                PB,
                EB,
                ZB,
                YB
        };

        Memory(MEMORY_UNIT unit);

        long long getTotalMemory();
        long long getFreeMemory();
        long long getUsedMemory();
        double getUsedMemoryPercent();

        static long long getTotalMemory(MEMORY_UNIT unit);
        static long long getFreeMemory(MEMORY_UNIT unit);
        static long long getUsedMemory(MEMORY_UNIT unit);
        static double getUsedMemoryPercent(MEMORY_UNIT unit);

private:
        struct sysinfo memInfo;

        void getMemoryInfo();

        MEMORY_UNIT memoryUnit;
};

#endif
