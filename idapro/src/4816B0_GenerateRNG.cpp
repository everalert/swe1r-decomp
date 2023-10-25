// original decomp looked parameterless
// probably just the C rand() using globals

// Linear Congruential Generator
// m = 0x7FFFFFFF (2**31-1)
// a = 1103515245
// c = 12345

int GenerateRNG(int &RandomNumber, bool &IsSeeded)
{
	if (!IsSeeded) {
		RandomNumber = 41222736;
		IsSeeded = true;
	}
	return RandomNumber = (1103515245 * RandomNumber + 12345) & 0x7FFFFFFF;
	//[TODO] verify that " & 0x7FFFFFFF" actually does the same thing as the original asm,
	//       might be mixing up my logic for how int bits work
}