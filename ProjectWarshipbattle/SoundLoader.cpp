#include "SoundLoader.h"

SoundLoader::SoundLoader()
{
}

SoundLoader::~SoundLoader()
{
}

void SoundLoader::Inif() {
	LoadSound();
}

void SoundLoader::FreeAll() {
	DeleteSound();
}

void SoundLoader::LoadSound() {
	shipSoundEngine = LoadSoundMem(
	"SoundData/Ships/Enging/Ship_Sound_Enging_Moving.mp3");

	shipSoundMoving = LoadSoundMem(
	"SoundData/Ships/Moving/Ship_Sound_Sea_Moving.mp3");
}

void SoundLoader::DeleteSound() {
	DeleteSoundMem(shipSoundEngine);
	DeleteSoundMem(shipSoundMoving);
}