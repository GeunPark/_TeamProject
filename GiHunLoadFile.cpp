#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GiHunImage()
{

	// �������� 1 �̹���
	_loading->loadImage("��������1", "resource/��������1/��������1.bmp", 20000, 2750, true, MAGENTA);
	_loading->loadImage("��������1 ����", "resource/��������1/��������1 ����.bmp", 20000, 2750, true, MAGENTA);
	_loading->loadImage("��������1 �ȼ�", "resource/��������1/��������1 �ȼ�.bmp", 20000, 2750, true, RGB(255, 0, 255));
	_loading->loadImage("��������1 ���� �ȼ�", "resource/��������1/��������1 ���� �ȼ�.bmp", 20000, 2750, true, RGB(255, 0, 255));
	// ��Ÿ �̹���
	_loading->loadImage("ūǮ", "resource/��������1/ūǮ.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadFrameImage("����", "resource/��������1/����2 ������.bmp", 4608, 1000, 16, 1);
	_loading->loadFrameImage("������", "resource/��������1/������.bmp", 4320, 48, 15, 1);
	_loading->loadFrameImage("�������", "resource/��������1/�������.bmp", 3480, 435, 8, 1);
	_loading->loadFrameImage("����", "resource/��������1/�� ����.bmp", 11520, 120, 8, 1);

}


void loadingScene::GiHunSound()
{

}
