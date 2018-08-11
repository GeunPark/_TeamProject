#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	//이곳에서 초기화를 한다
	
	//앞으로 메인게임 클래스 안에서는 씬들만 관리한다
	//그리고 각각의 씬들이 메인게임 역할을 하면 된다

	/*씬추가*/
	
	SCENEMANAGER->addScene("로딩화면", new loadingScene);
	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("타운씬", new townScene);
	SCENEMANAGER->addScene("스테이지1", new stage1);
	SCENEMANAGER->addScene("보스", new bossStage);
	SCENEMANAGER->addScene("월드맵", new worldMapScene);

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


	/*현재씬 설정*/
	SCENEMANAGER->loadScene("로딩화면");

	return S_OK;
}

//=============================================================
//	## 해제 ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
}

//=============================================================
//	## 업데이트 ## update(void)
//=============================================================
void mainGame::update(void)
{
	//씬매니져 업데이트
	SCENEMANAGER->update();

	//사운드매니져 업데이트
	SOUNDMANAGER->update();

	//이펙트매니져 업데이트
	EFFECTMANAGER->update();
}

//=============================================================
//	## 렌더 ## render(void)
//=============================================================
void mainGame::render(void)
{
	//흰색 빈 비트맵(이것도 렌더에 그냥 둘것!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================

	//씬매니져 렌더
	SCENEMANAGER->render();

	//이펙트매니져 렌더
	EFFECTMANAGER->render();

	//타임매니져 렌더
	TIMEMANAGER->render(getMemDC());

//=============================================================
	//백버퍼의 내용을 HDC에 그린다 (이것도 렌더에 그냥 둘것!!)
	this->getBackBuffer()->render(getHDC());
}
