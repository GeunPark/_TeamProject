#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SunSooImage()
{
	//��
	//���ڸ�
	_loading->loadFrameImage("���ڸ�spawn", "resource/�̼���/����/���ڸ�spawn.bmp", 1536, 384, 8, 2);
	_loading->loadFrameImage("���ڸ�move", "resource/�̼���/����/���ڸ�move.bmp", 768, 192, 8, 2);
	_loading->loadFrameImage("���ڸ�dead", "resource/�̼���/����/���ڸ�dead.bmp", 2220, 384, 10, 2);

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
	//�����
	//IMAGEMANAGER->addFrameImage("�����spawn", "resource/�����spawn.bmp", 810, 60, 6, 1);
	_loading->loadFrameImage("�����move", "resource/�̼���/����/�����move2.bmp", 4290, 186, 26, 1);



	//������
	_loading->loadFrameImage("�ｺ����", "resource/�̼���/������/��ƮL2.bmp", 665, 30, 19, 1);
	_loading->loadFrameImage("�ｺ��", "resource/�̼���/������/��ƮB.bmp", 300, 14, 20, 1);
	_loading->loadFrameImage("������", "resource/�̼���/������/����B.bmp", 660, 60, 11, 1);
	_loading->loadFrameImage("��������", "resource/�̼���/������/����S.bmp", 660, 60, 11, 1);
	//����
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("��ȭ", "resource/�̼���/������/��ȭ2.bmp", 256, 32, 8, 1);



}

void loadingScene::SunSooSound()
{

}