#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GeunHwaImage()
{
	_loading->loadImage("���̾�1���", "resource/��������1/���̾�1 ���.bmp", 1280, 2550);
	_loading->loadImage("���̾�1�������", "resource/��������1/���̾�1 �������.bmp", 1280, 2550);
	_loading->loadImage("���̾�2���", "resource/��������1/���̾�2 ���", 1280, 220, true, MAGENTA);
	
	// ��ŸƮ�� �̹���
	_loading->loadImage("��ŸƮ�� ���", "resource/�ڱ�ȭ/��ŸƮ��/�κ�� ���.bmp", 1280, 720);
	_loading->loadImage("��ŸƮ�� �ΰ�", "resource/�ڱ�ȭ/��ŸƮ��/�κ�� �ΰ�.bmp", 650, 274, true, MAGENTA);
	_loading->loadImage("��ŸƮ�� ����", "resource/�ڱ�ȭ/��ŸƮ��/�κ�� ����.bmp", 400, 545, true, MAGENTA);
	_loading->loadImage("��ŸƮ�� ��ѱ�", "resource/�ڱ�ȭ/��ŸƮ��/�κ�� ��ѱ�.bmp", 217, 228, true, MAGENTA);
	_loading->loadImage("��ŸƮ�� ��ư", "resource/�ڱ�ȭ/��ŸƮ��/�κ�� ��ư.bmp", 130, 105, true, MAGENTA);
	
	//����Ʈ�� �̹���
	_loading->loadImage("����Ʈ�� ���", "resource/�ڱ�ȭ/��ŸƮ��/����Ʈ�����.bmp", 1280, 720);
	_loading->loadImage("����Ʈ�� ����â", "resource/�ڱ�ȭ/��ŸƮ��/����Ʈ�� ����â.bmp", 546, 299);
	_loading->loadImage("����Ʈ�� �����ڽ�", "resource/�ڱ�ȭ/��ŸƮ��/����Ʈ�� �����ڽ�.bmp", 480, 106, true, MAGENTA);
	//���� �̹���
	_loading->loadImage("�������", "resource/�ڱ�ȭ/Ÿ���/�������.bmp", 1792, 720, true, MAGENTA);
	_loading->loadImage("�������̾�1", "resource/�ڱ�ȭ/Ÿ���/�������̾�1.bmp", 1536, 720);
	_loading->loadImage("�������̾�2", "resource/�ڱ�ȭ/Ÿ���/�������̾�2.bmp", 1792, 189, true, MAGENTA);
	_loading->loadImage("�������̾�3", "resource/�ڱ�ȭ/Ÿ���/�������̾�3.bmp", 1792, 720, true, MAGENTA);
	_loading->loadImage("�����ȼ�", "resource/�ڱ�ȭ/Ÿ���/�����ȼ�.bmp", 1792, 720, true, MAGENTA);

	//���� �̹���
	_loading->loadImage("��������", "resource/�ڱ�ȭ/����/��������.bmp", 1280, 720);
	_loading->loadImage("��������", "resource/�ڱ�ȭ/����/��������.bmp", 1280, 720);
	_loading->loadImage("�����ȼ�", "resource/�ڱ�ȭ/����/�����ȼ�.bmp", 1280, 720, true, MAGENTA);
	_loading->loadFrameImage("����", "resource/�ڱ�ȭ/����/����.bmp", 192, 48, 4, 1, true, MAGENTA);

	//����� �̹���
	_loading->loadFrameImage("����ʹ��", "resource/�ڱ�ȭ/�����/�����.bmp", 5120, 720, 4, 1, true, MAGENTA);
	_loading->loadImage("Ÿ������Ʈ", "resource/�ڱ�ȭ/�����/��������Ʈ.bmp", 63, 45, true, MAGENTA);
	_loading->loadImage("����ʷε�", "resource/�ڱ�ȭ/�����/wayroad.bmp", 183, 48, true, MAGENTA);
	_loading->loadImage("������������Ʈ", "resource/�ڱ�ȭ/�����/������������Ʈ.bmp", 33, 27, true, MAGENTA);
	_loading->loadImage("�����Ÿ��", "resource/�ڱ�ȭ/�����/������Ʈ�ö���.bmp", 634, 50, true, MAGENTA);
	_loading->loadImage("����ʽ�������", "resource/�ڱ�ȭ/�����/��������1ǥ��.bmp", 787, 50, true, MAGENTA);
	_loading->loadFrameImage("��������Ʈ", "resource/�ڱ�ȭ/�����/��������Ʈ.bmp", 114, 57, 2, 1, true, MAGENTA);
	_loading->loadImage("�����ε�", "resource/�ڱ�ȭ/�����/�����ε�.bmp", 207, 111, true, MAGENTA);
}

void loadingScene::GeunHwaSound()
{
	//BGM ����##################################################################################################

	//��ŸƮ��
	_loading->loadSound("��ŸƮ��BGM", "resource/�ڱ�ȭ/���帮�ҽ�/��ŸƮ�� ��� ����.wav", true, true);
	_loading->loadSound("����Ʈȿ����", "resource/�ڱ�ȭ/���帮�ҽ�/���� ����.wav");
	_loading->loadSound("�����̵�����", "resource/�ڱ�ȭ/���帮�ҽ�/���� �̵� ����.wav");

	//��������1
	_loading->loadSound("��������1 ����", "resource/�ڱ�ȭ/���帮�ҽ�/�������� 1 ��� ����.wav", true, true);
	_loading->loadSound("��������1 �ܿ�", "resource/�ڱ�ȭ/���帮�ҽ�/�ܿ� ��� ����.wav", true, true);
	_loading->loadSound("���� ���", "resource/�ڱ�ȭ/���帮�ҽ�/���� ���.wav", true, true);
	//�÷��̾����###############################################################################################

	//����
	_loading->loadSound("��������", "resource/�ڱ�ȭ/���帮�ҽ�/1������ ����.wav");
	_loading->loadSound("2����������", "resource/�ڱ�ȭ/���帮�ҽ�/2������ ����.wav");

	//��������
	_loading->loadSound("1���������ݻ���", "resource/�ڱ�ȭ/���帮�ҽ�/1������ ���� ����.wav");
	_loading->loadSound("2���������ݻ���", "resource/�ڱ�ȭ/���帮�ҽ�/2������ ���� ����.wav");

	//����
	_loading->loadSound("����", "resource/�ڱ�ȭ/���帮�ҽ�/����.wav");
	//_loading->loadSound("����", "resource/�ڱ�ȭ/���帮�ҽ�/����.wav");


	//����
	_loading->loadSound("ȭ��߻����", "resource/�ڱ�ȭ/���帮�ҽ�/ȭ��߻� ȿ������.wav");
	_loading->loadSound("ȭ���޽�����", "resource/�ڱ�ȭ/���帮�ҽ�/ȭ��߻� �޽� ȿ����.wav");
	_loading->loadSound("�������ݻ���", "resource/�ڱ�ȭ/���帮�ҽ�/�������� ����.wav");
	_loading->loadSound("��ܺ���", "resource/�ڱ�ȭ/���帮�ҽ�/��ܺ���.wav");
	_loading->loadSound("��ȭ��", "resource/�ڱ�ȭ/���帮�ҽ�/��ȭ��.wav");
	_loading->loadSound("����Ʈ�޾�", "resource/�ڱ�ȭ/���帮�ҽ�/����Ʈ�޾�.wav");
	_loading->loadSound("���", "resource/�ڱ�ȭ/���帮�ҽ�/���.wav");

	//����, ��Ʈ
	_loading->loadSound("����ȹ�����", "resource/�ڱ�ȭ/���帮�ҽ�/���������� �ο��.wav");
	_loading->loadSound("�����˶�����", "resource/�ڱ�ȭ/���帮�ҽ�/���� �˶� ����.wav", false, true);
	_loading->loadSound("��Ʈ����", "resource/�ڱ�ȭ/���帮�ҽ�/��Ʈ����.wav");














}