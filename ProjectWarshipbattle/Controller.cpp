#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

int Controller::GetCommand() {
	GetHitKeyStateAll(KeyBuf);
	//�o�̓R���g���[��
	if (KeyBuf[KEY_INPUT_UP] && GetInputChar(TRUE))
		return CommandSerial::INCREASE_OUTPUT;
	if (KeyBuf[KEY_INPUT_DOWN] && GetInputChar(TRUE))
		return CommandSerial::DECREASE_OUTPUT;

	//�����R���g���[��
	if (KeyBuf[KEY_INPUT_RIGHT])
		return CommandSerial::TURN_RIGHT;
	if (KeyBuf[KEY_INPUT_LEFT])
		return CommandSerial::TURN_LEFT;
	if (KeyBuf[KEY_INPUT_X] && GetInputChar(TRUE))
		return CommandSerial::TURN_RETURN;

	//�e�X�g�r���[
	if (KeyBuf[KEY_INPUT_F1] && GetInputChar(TRUE))
		return CommandSerial::TEST_VIEW_ON;

	//Debug
	if (KeyBuf[KEY_INPUT_P])
		WaitKey();
}