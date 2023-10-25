#include "4787F0_ApplyBoost.hpp"

float ApplyBoost(PodEngineData *PodEngine)
{
 	if ( PodEngine->Flags0060 & PODENGINE_IS_BOOSTING )
 	 	PodEngine->BoostFactor = FrameTime * 1.5f + PodEngine->BoostFactor;
 	else
 	{
 	 	if ( PodEngine->BoostFactor > 0.0f )
 	 	 	PodEngine->BoostFactor = GetDecelerationFactor(5.0f, FrameTime) * PodEngine->BoostFactor;
 	 	if ( PodEngine->BoostFactor < 0.001f )
 	 	 	PodEngine->BoostFactor = 0.0f;
 	}
 	if ( PodEngine->Flags0060 & PODENGINE_IS_BRAKING )
 	 	PodEngine->Flags0060 &= ~PODENGINE_IS_BOOSTING;
	return std::max(0.0f, PodEngine->BoostFactor * PodEngine->StatBoostThrust / (PodEngine->BoostFactor - -0.33f));
}	