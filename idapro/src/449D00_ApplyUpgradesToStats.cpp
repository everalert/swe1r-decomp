#include "449D00_ApplyUpgradesToStats.hpp"

// presumably, copies base stats TO pActiveStats
// then applies all the upgrades to that
// if so, *pBaseStats should be the pointer to the base stats class?

//[TODO] verify the above

void __cdecl ApplyUpgradesToStats(PodHandlingData *pActiveStats, PodHandlingData *pBaseStats, char *pUpgradeLevels, char *pUpgradeHealths)
{
 	float upgradeHealth;
 	memcpy(pActiveStats, pBaseStats, 0x3Cu);
 	for (int i = 0; i < 7; ++i) {
 	 	upgradeHealth = *(pUpgradeHealths+i) * 0.0039215689;// convert upgrade health (byte) to float
 	 	CalculateUpgradedStat(pActiveStats, i, *(pUpgradeLevels+i), upgradeHealth);
 	}
}