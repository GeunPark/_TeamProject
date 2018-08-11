#include "stdafx.h"
#include "townScene.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init(void)
{
	
	SOUNDMANAGER->play("����������");
	//_backGround = IMAGEMANAGER->findImage("Ÿ��� ���");
	//_layer1 = IMAGEMANAGER->findImage("Ÿ��� ���̾�1");
	//_layer2 = IMAGEMANAGER->findImage("Ÿ��� ���̾�2");
	//_layer3 = IMAGEMANAGER->findImage("Ÿ��� ���̾�3");

	_bg.img = IMAGEMANAGER->findImage("�������");
	_bg.x = 0;
	_bg.y = 0;
		
	_lyr1.img = IMAGEMANAGER->findImage("�������̾�1");
	_lyr1.x = 0;
	_lyr1.y = 0;

	_lyr2.img = IMAGEMANAGER->findImage("�������̾�2");


	_lyr3.img = IMAGEMANAGER->findImage("�������̾�3");


	_pixel.img = IMAGEMANAGER->findImage("�����ȼ�");


	_player = SAVEDATA->getPlayer();
	if (test == false)
	{
		_player->init();
	}
	_player->setX(100);
	_player->setY(500);
	_player->setBgPixel(_pixel.img);


	_ui = SAVEDATA->getUI();
	_ui->setPlayerManager(_player);
	if(test == false)
		_ui->init();
	

	_shop = SAVEDATA->getShop();
	_shop->setPlayerManager(_player);
	_shop->init();


	_shopRc = RectMakeCenter(1210, 520, 250, 200);

	return S_OK;
}

void townScene::release(void)
{
}

void townScene::update(void)
{
	_player->update();
	_ui->update();
	_shop->update();

	if (_player->getRight())
	{
		if (_player->getX() < WINSIZEX)
		{
			_lyr1.x += 1.f;
		}
	}

	if (_player->getLeft())
	{
		if (_player->getX() > WINSIZEX / 2)
		{
			_lyr1.x -= 1.f;
		}
	}
	RECT temp;
	if (IntersectRect(&temp, &_player->getCollisionRc(), &_shopRc))
	{
		if (KEYMANAGER->isOnceKeyDown('Q'))
		{
			shopCount++;
			if (shopCount < 2)
				_shop->setOpen(true);
			else
			{
				_shop->setOpen(false);
				shopCount = 0;
			}
		}
	}
	if (_player->getX() < 0)
	{
		test = true;
		SCENEMANAGER->loadScene("��������1");
		SOUNDMANAGER->stop("����������");
	}

}

void townScene::render(void)
{
	_lyr1.img->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, 720), (int)_lyr1.x, _lyr1.y);
	_lyr3.img->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	_lyr2.img->render(getMemDC(), 0, 500, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, 182);
	_bg.img->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);


	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		_pixel.img->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	}
	//Rectangle(getMemDC(), _shopRc.left - _player->getPlayerCam().left, _shopRc.top - _player->getPlayerCam().top, _shopRc.right - _player->getPlayerCam().left, _shopRc.bottom - _player->getPlayerCam().top);
	//���ٶ� �׳���!!!(��¦)(����ô)
	_ui->render();
	_player->render();
	if (_shop->getOpen())
	{
		_shop->render();
	}
}
