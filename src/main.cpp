#include "EAXReverb.h"

AudioEffect* createEffectInstance (audioMasterCallback audioMaster)
{
	return new EAXReverb (audioMaster);
}
