#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SaeWonImage()
{
	_loading->loadFrameImage("Idle", "resource/foxPlayer/nickIdle.bmp", 3600, 360, 20, 2, true, MAGENTA);
	_loading->loadFrameImage("Run", "resource/foxPlayer/run.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump", "resource/foxPlayer/jump.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump2", "resource/foxPlayer/jump.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall2", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fire", "resource/foxPlayer/bowFire.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("UpAtt", "resource/foxPlayer/upAtt.bmp", 870, 348, 5, 2, true, MAGENTA);
	_loading->loadFrameImage("SitAtt", "resource/foxPlayer/sitAtt.bmp", 852, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Sit", "resource/foxPlayer/sit.bmp", 540, 360, 3, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt", "resource/foxPlayer/jumpAtt.bmp", 2034, 360, 6, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt2", "resource/foxPlayer/jumpAtt2.bmp", 1704, 426, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("DownAtt", "resource/foxPlayer/downAtt.bmp", 564, 318, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Hurt", "resource/foxPlayer/hurt.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("arrow", "resource/foxPlayer/arrow.bmp", 66, 46, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Weather", "resource/foxPlayer/weather.bmp", 1620, 360, 9, 2, true, MAGENTA);
	_loading->loadFrameImage("Die", "resource/foxPlayer/dead.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Twinkle", "resource/foxPlayer/twinkle.bmp", 5805, 384, 15, 1, true, MAGENTA);
	_loading->loadImage("Cuticle", "resource/foxPlayer/cuticle.bmp", 21, 21, true, MAGENTA);
	_loading->loadFrameImage("Poison", "resource/foxPlayer/poison2.bmp", 350, 140, 5, 2, true, MAGENTA);
	

	_loading->loadFrameImage("��������1", "resource/foxPlayer/��������1.bmp", 864, 960, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("����̵�", "resource/foxPlayer/����̵�.bmp", 648, 636, 2, 1, true, MAGENTA);

	_loading->loadImage("����Ʈ�޾�", "resource/foxPlayer/����Ʈ�޾�.bmp", 417, 447, true, MAGENTA);
	_loading->loadImage("����Ʈ�޾� �׸���", "resource/foxPlayer/����Ʈ�޾� �׸���.bmp", 417, 447, true, MAGENTA);
}

void loadingScene::SaeWonSound()
{
	//���� ü����################################################################################################
	_loading->loadSound("�����������", "resource/�ڱ�ȭ/���帮�ҽ�/���� �ٲܶ� ����.wav");
	_loading->loadSound("������������", "resource/�ڱ�ȭ/���帮�ҽ�/���� �����Ҷ� ����.wav");

	//������ ���� ################################################################################################
	_loading->loadSound("����������", "resource/�ڱ�ȭ/���帮�ҽ�/���� ��� ����.wav", true, true);
	_loading->loadSound("�����������û���", "resource/�ڱ�ȭ/���帮�ҽ�/���� ���� ���� ����.wav");
	_loading->loadSound("��������ĵ������", "resource/�ڱ�ȭ/���帮�ҽ�/���� ���� ĵ�� ����.wav");
	_loading->loadSound("�����ڸ�������", "resource/�ڱ�ȭ/���帮�ҽ�/�����λ���.wav");

	//����� ����##################################################################################################
	_loading->loadSound("����ʹ�����", "resource/�ڱ�ȭ/���帮�ҽ�/����� ��� ����.wav", true, true);

	//���ʹ� ���� ����
	_loading->loadSound("���ʹ��״»���", "resource/�ڱ�ȭ/���帮�ҽ�/���ʹ� �״� ����.wav");
	_loading->loadSound("���λ�������", "resource/�ڱ�ȭ/���帮�ҽ�/���� �������� ����.wav");
	_loading->loadSound("����ȹ�����", "resource/�ڱ�ȭ/���帮�ҽ�/���� �Ծ����� ����.wav");
}
