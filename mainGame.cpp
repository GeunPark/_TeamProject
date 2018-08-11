#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	//�̰����� �ʱ�ȭ�� �Ѵ�
	
	//������ ���ΰ��� Ŭ���� �ȿ����� ���鸸 �����Ѵ�
	//�׸��� ������ ������ ���ΰ��� ������ �ϸ� �ȴ�

	/*���߰�*/
	
	SCENEMANAGER->addScene("�ε�ȭ��", new loadingScene);
	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("Ÿ���", new townScene);
	SCENEMANAGER->addScene("��������1", new stage1);
	SCENEMANAGER->addScene("����", new bossStage);
	SCENEMANAGER->addScene("�����", new worldMapScene);

	_player = new foxPlayer;
	SAVEDATA->setPlayer(_player);

	_ui = new UI;
	SAVEDATA->setUI(_ui);

	_shop = new shop;
	SAVEDATA->setShop(_shop);

	_em = new enemyManager;
	SAVEDATA->setEnemyManager(_em);

	_im = new itemManager;
	SAVEDATA->setItemManager(_im);


	/*����� ����*/
	SCENEMANAGER->loadScene("�ε�ȭ��");

	return S_OK;
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void mainGame::update(void)
{
	//���Ŵ��� ������Ʈ
	SCENEMANAGER->update();

	//����Ŵ��� ������Ʈ
	SOUNDMANAGER->update();

	//����Ʈ�Ŵ��� ������Ʈ
	EFFECTMANAGER->update();
}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ��(�̰͵� ������ �׳� �Ѱ�!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================

	//���Ŵ��� ����
	SCENEMANAGER->render();

	//����Ʈ�Ŵ��� ����
	EFFECTMANAGER->render();

	//Ÿ�ӸŴ��� ����
	TIMEMANAGER->render(getMemDC());

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}
