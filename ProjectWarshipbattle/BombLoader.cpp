#include "BombLoader.h"

BombLoader::~BombLoader()
{
}

Bomb BombLoader::DropTheBomb() {
	if (Usable()) {
		UseAmmo();//c’e‚ªŒ¸‚é
		return bombOnThisPlane;//”š’e‚Ìó‘Ô‚ğ•Ô‚·
	}
}