/**
 * @file memory.cpp
 *
 * @brief Library to mamange memory
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "memory.hpp"

// Definitions
// #define DEBUG

// Function(s)
/**
 * @brief Construct a new Memory:: Memory object
 *
 * @param unit define memory unit
 */
Memory::Memory(MEMORY_UNIT unit)
{
	Memory::memoryUnit = unit;
}

/**
 * @brief get the RAM memory information
 */
void Memory::getMemoryInfo()
{
	sysinfo(&memInfo);
}

/**
 * @brief Returns the RAM memory in the selected memory unit
 *
 * @return long long RAM memory in the selected memory unit
 */
long long Memory::getTotalMemory()
{
	Memory::getMemoryInfo();
	return round(memInfo.totalram * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

/**
 * @brief Returns free RAM memory in the selected memory unit
 *
 * @return long long Free RAM memory in the selected memory unit
 */
long long Memory::getFreeMemory()
{
	Memory::getMemoryInfo();
	return round(memInfo.freeram * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

/**
 * @brief Returns used RAM memory in the selected memory unit
 *
 * @return long long Used RAM memory in the selected memory unit
 */
long long Memory::getUsedMemory()
{
	Memory::getMemoryInfo();
	return round((memInfo.totalram - memInfo.freeram) * memInfo.mem_unit / pow(1024, (int)Memory::memoryUnit));
}

/**
 * @brief Returns used RAM memory in percentage
 *
 * @return double Used RAM memory in percentage
 */
double Memory::getUsedMemoryPercent()
{
	Memory::getMemoryInfo();
	return (memInfo.totalram - memInfo.freeram) * 100 / memInfo.totalram;
}

/**
 * @brief Returns the RAM memory in the selected memory unit, without inizialization
 *
 * @return long long RAM memory in the selected memory unit
 */
long long Memory::getTotalMemory(MEMORY_UNIT unit)
{
	Memory memory(unit);
	return memory.getTotalMemory();
}

/**
 * @brief Returns free RAM memory in the selected memory unit, without inizialization
 *
 * @return long long Free RAM memory in the selected memory unit
 */
long long Memory::getFreeMemory(MEMORY_UNIT unit)
{
	Memory memory(unit);
	return memory.getFreeMemory();
}

/**
 * @brief Returns used RAM memory in the selected memory unit, without inizialization
 *
 * @return long long Used RAM memory in the selected memory unit
 */
long long Memory::getUsedMemory(MEMORY_UNIT unit)
{
	Memory memory(unit);
	return memory.getUsedMemory();
}

/**
 * @brief Returns used RAM memory in percentage, without inizialization
 *
 * @return double Used RAM memory in percentage
 */
double Memory::getUsedMemoryPercent(MEMORY_UNIT unit)
{
	Memory memory(unit);
	return memory.getUsedMemoryPercent();
}

#undef DEBUG
