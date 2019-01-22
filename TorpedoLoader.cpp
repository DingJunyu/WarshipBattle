#include "TorpedoLoader.h"

TorpedoLoader::~TorpedoLoader()
{
}

Torpedo TorpedoLoader::DropTheTorpedo() {
	if (Usable()) {
		UseAmmo();//c’e‚ªŒ¸‚é
		return torpedoOnThisPlane;//‹›—‹‚Ìó‘Ô‚ğ•Ô‚·
	}
}