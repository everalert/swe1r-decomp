struct PodHandlingData {
	float AntiSkid;
	float TurnResponse;
	float Acceleration;
	float MaxSpeed;
	float AirBrakeInv;
	float CoolRate;
	float RepairRate;
};

struct PodUpgradeLevels {
	float max;
	float min;
	float level[5];
};

void CalculateUpgradedStat(PodHandlingData *PodHandlingData, int upgradeCategory, int upgradeLevel, float upgradeHealth);

void PodUpgradeAlgo1(float &Stat, PodUpgradeLevels *LevelData, int Level, float Health);

void PodUpgradeAlgo2(float &Stat, PodUpgradeLevels *LevelData, int Level, float Health);

PodUpgradeLevels AntiSkidData =     { 1.0f,    0.01f,  { 0.05f,  0.10f,  0.15f,  0.20f,  0.25f }  };
PodUpgradeLevels TurnResponseData = { 1000.0f, 50.0f,  { 116.0f, 232.0f, 348.0f, 464.0f, 578.0f } };
PodUpgradeLevels AccelerationData = { 5.0f,    0.1f,   { 0.14f,  0.28f,  0.42f,  0.56f,  0.70f }  };
PodUpgradeLevels MaxSpeedData =     { 650.0f,  450.0f, { 40.0f,  80.0f,  120.0f, 160.0f, 200.0f } };
PodUpgradeLevels AirBrakeInvData =  { 1000.0f, 1.0f,   { 0.08f,  0.17f,  0.26f,  0.35f,  0.44f }  };
PodUpgradeLevels CoolRateData =     { 20.0f,   1.0f,   { 1.6f,   3.2f,   4.8f,   6.4f,   8.0f }   };
PodUpgradeLevels RepairRateData =   { 1.0f,    0.0f,   { 0.10f,  0.20f,  0.30f,  0.40f,  0.45f }  };