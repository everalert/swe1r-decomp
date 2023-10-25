#include "478A70_CalculateTraction.hpp"

void CalculateTraction(PodEngineData *PodEngine, float SpeedTotal, vec3::Vector3 *pEngineFwdVec)
{
	vec3::Vector3 *velocity = &PodEngine->Velocity;
	float *slideFactor = &PodEngine->TractionFactorSlide;

	if (SpeedTotal > 0.0f)
		*pEngineFwdVec *= -1.0f;
	vec3::Vector3 ProjectedVelocity = *pEngineFwdVec * SpeedTotal;
	SpeedTotal = SpeedTotal < 0.0f ? -SpeedTotal : SpeedTotal;

	float FwdVecMagnitude = vec3::sum(*pEngineFwdVec * *velocity);
 	if ( FwdVecMagnitude < 0.0f )
		*velocity += *pEngineFwdVec * -FwdVecMagnitude;

 	float SkidFactor = PodEngine->StatAntiSkid * PodEngine->TractionFactorIce * *slideFactor;
 	float NewSkid = (1.0f - pow(SkidFactor, 2.0f)) * 0.996666f;
 	if ( PodEngine->StatMultiplierMAYBE > 1.0f )
		NewSkid *= PodEngine->StatMultiplierMAYBE <= 2.0f ? (2.0f - PodEngine->StatMultiplierMAYBE) : 0.0f;

	*velocity = 1.0f / FrameTime * (ProjectedVelocity*NewSkid*FrameTime + *velocity*(1.0f-NewSkid)*FrameTime);
 	velocity->normalize();
	*velocity *= SpeedTotal;

 	if (!(PodEngine->Flags0064 & PODENGINE_IS_MANUALSLIDING)) {
 	 	float targetSlide = PodEngine->Flags0064 & PODENGINE_IS_OFFTHROTTLE ? 0.8f : 1.0f;
		
 	 	if (PodEngine->Flags0064 & PODENGINE_IS_SLIDING)
 	 	 	targetSlide *= 0.45f;

		bool lerpDir = targetSlide >= *slideFactor;
		*slideFactor += lerpDir ? FrameTime*2.0f : -FrameTime*2.0f;
		if (lerpDir == (*slideFactor >= targetSlide))
			*slideFactor = targetSlide;
 	}
}