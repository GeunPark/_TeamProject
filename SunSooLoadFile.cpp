#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SunSooImage()
{
	//��
	//���ڸ�
	_loading->loadFrameImage("���ڸ�spawn", "resource/�̼���/����/���ڸ�spawn.bmp", 1536, 384, 8, 2);
	_loading->loadFrameImage("���ڸ�move", "resource/�̼���/����/���ڸ�move.bmp", 768, 192, 8, 2);

	//�����ΰ�
	_loading->loadFrameImage("�����ΰ�spawn", "resource/�̼���/����/�����ΰ�spawn2.bmp", 1680, 444, 14, 2);
	_loading->loadFrameImage("�����ΰ�move", "resource/�̼���/����/�����ΰ�move.bmp", 770, 300, 7, 2);
	_loading->loadFrameImage("�����ΰ�attack", "resource/�̼���/����/�����ΰ�attack.bmp", 2448, 384, 8, 2);

	//����
	_loading->loadFrameImage("����move", "resource/�̼���/����/����move.bmp", 540, 80, 6, 2);

	//�볪��
	_loading->loadFrameImage("�볪��move", "resource/�̼���/����/�볪��move.bmp", 1280, 516, 8, 2);

	//�β���
	_loading->loadFrameImage("�β���spawn", "resource/�̼���/����/�β���spawn.bmp", 480, 288, 6, 2);
	_loading->loadFrameImage("�β���move", "resource/�̼���/����/�β���move.bmp", 1176, 288, 7, 2);
	_loading->loadFrameImage("�β���attack", "resource/�̼���/����/�β���attack.bmp", 792, 288, 9, 2);
	_loading->loadFrameImage("�β���tongue", "resource/�̼���/����/�β���tongue.bmp", 200, 18, 1, 2);

	//�����
	_loading->loadFrameImage("�����spawn", "resource/�̼���/����/�����spawn.bmp", 810, 60, 6, 1);
	_loading->loadFrameImage("�����move", "resource/�̼���/����/�����move2.bmp", 4290, 186, 26, 1);

	//��������
	_loading->loadFrameImage("����spawn", "resource/�̼���/����/��������/��������spawn.bmp", 800,267, 6, 2);
	_loading->loadFrameImage("����attack", "resource/�̼���/����/��������/��������attack.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("����dead", "resource/�̼���/����/��������/��������dead.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("�����Ѿ�", "resource/�̼���/����/��������/��������bullet.bmp", 200, 50, 4, 1);

	//������
	_loading->loadFrameImage("��attack", "resource/�̼���/����/������/��attact.bmp", 1000, 982, 2, 2);
	_loading->loadFrameImage("��dizzy", "resource/�̼���/����/������/��dizzy.bmp", 3000, 1141, 6, 2);
	_loading->loadFrameImage("��hurt", "resource/�̼���/����/������/��hurt.bmp", 4500, 1800, 5, 2);
	_loading->loadFrameImage("��idle", "resource/�̼���/����/������/��idle.bmp", 3000, 1141, 6, 2);
	_loading->loadImage("����ī��Ʈ", "resource/�̼���/����/������/����ī��Ʈ.bmp", 100, 100, true, MAGENTA);
	//������ �Ѿ�
	_loading->loadFrameImage("��bullet", "resource/�̼���/����/������/��bullet.bmp", 150, 50, 3, 1);



	//������
	_loading->loadFrameImage("�ｺ����", "resource/�̼���/������/��ƮL2.bmp", 665, 30, 19, 1);
	_loading->loadFrameImage("�ｺ��", "resource/�̼���/������/��ƮB.bmp", 300, 14, 20, 1);
	_loading->loadFrameImage("������", "resource/�̼���/������/����B.bmp", 660, 60, 11, 1);
	_loading->loadFrameImage("��������", "resource/�̼���/������/����S.bmp", 660, 60, 11, 1);
	//����
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);

	//����
	_loading->loadFrameImage("����", "resource/�̼���/������/�����ۻ���.bmp", 200, 100, 2, 1);


	//����Ʈ
	//����
	//Left
	_loading->loadFrameImage("���ڸ�deadL", "resource/�̼���/����/����Ʈ/���ڸ�deadL.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("�����ΰ�deadL", "resource/�̼���/����/����Ʈ/�����ΰ�deadL.bmp", 1752, 174, 8, 1);
	_loading->loadFrameImage("����deadL", "resource/�̼���/����/����Ʈ/����deadL.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("�볪��deadL", "resource/�̼���/����/����Ʈ/�볪��deadL.bmp", 1896, 255, 8, 1);
	_loading->loadFrameImage("�β���deadL", "resource/�̼���/����/����Ʈ/�β���deadL.bmp", 2442, 174, 11, 1);
	_loading->loadFrameImage("�����deadL", "resource/�̼���/����/����Ʈ/�����deadL.bmp", 2220, 174, 10, 1);
	//Right
	_loading->loadFrameImage("���ڸ�deadR", "resource/�̼���/����/����Ʈ/���ڸ�deadR.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("�����ΰ�deadR", "resource/�̼���/����/����Ʈ/�����ΰ�deadR.bmp", 1752, 174, 8, 1);
	_loading->loadFrameImage("����deadR", "resource/�̼���/����/����Ʈ/����deadR.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("�볪��deadR", "resource/�̼���/����/����Ʈ/�볪��deadR.bmp", 1896, 255, 8, 1);
	_loading->loadFrameImage("�β���deadR", "resource/�̼���/����/����Ʈ/�β���deadR.bmp", 2442, 174, 11, 1);
	_loading->loadFrameImage("�����deadR", "resource/�̼���/����/����Ʈ/�����deadR.bmp", 2220, 174, 10, 1);
	
	//������
	_loading->loadFrameImage("����������Ʈ", "resource/�̼���/������/����Ʈ/����������Ʈ.bmp", 360, 60, 6, 1, true, MAGENTA);

}

void loadingScene::SunSooSound()
{

}