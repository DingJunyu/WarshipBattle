#include "BombLoader.h"

BombLoader::~BombLoader()
{
}

Bomb BombLoader::DropTheBomb() {
	if (Usable()) {
		UseAmmo();//�c�e������
		return bombOnThisPlane;//���e�̏�Ԃ�Ԃ�
	}
}