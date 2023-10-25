#include <algorithm>
#include "4493F0_CalculateUpgradedStat.hpp"


void PodUpgradeAlgo1(float &Stat, PodUpgradeLevels *LevelData, int Level, float Health)
{
	Stat = std::clamp(Health * LevelData->level[Level-1] + Stat, LevelData->min, LevelData->max);
}

void PodUpgradeAlgo2(float &Stat, PodUpgradeLevels *LevelData, int Level, float Health)
{
	Stat = std::clamp(((1.0f-Health) * LevelData->level[Level-1] + (1.0f-LevelData->level[Level-1])) + Stat, LevelData->min, LevelData->max);
}

void CalculateUpgradedStat(PodHandlingData *PodHandlingData, int upgradeCategory, int upgradeLevel, float upgradeHealth)
{
	switch (upgradeCategory)
	{
		case 0: PodUpgradeAlgo1(PodHandlingData->AntiSkid, &AntiSkidData, upgradeLevel, upgradeHealth); break;
		case 1: PodUpgradeAlgo1(PodHandlingData->TurnResponse, &TurnResponseData, upgradeLevel, upgradeHealth); break;
		case 2: PodUpgradeAlgo2(PodHandlingData->Acceleration, &AccelerationData, upgradeLevel, upgradeHealth); break;
		case 3: PodUpgradeAlgo1(PodHandlingData->MaxSpeed, &MaxSpeedData, upgradeLevel, upgradeHealth); break;
		case 4: PodUpgradeAlgo2(PodHandlingData->AirBrakeInv, &AirBrakeInvData, upgradeLevel, upgradeHealth); break;
		case 5: PodUpgradeAlgo1(PodHandlingData->CoolRate, &CoolRateData, upgradeLevel, upgradeHealth); break;
		case 6: PodUpgradeAlgo1(PodHandlingData->RepairRate, &RepairRateData, upgradeLevel, upgradeHealth); break;
	}
}