#include "TorpedoLoader.h"

TorpedoLoader::~TorpedoLoader()
{
}

Torpedo TorpedoLoader::DropTheTorpedo() {
	if (Usable()) {
		UseAmmo();//�c�e������
		return torpedoOnThisPlane;//�����̏�Ԃ�Ԃ�
	}
}