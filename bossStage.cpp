#include "stdafx.h"
#include "bossStage.h"


bossStage::bossStage()
{
}


bossStage::~bossStage()
{
}

HRESULT bossStage::init(void)
{
	summer = IMAGEMANAGER->findImage("º¸½º¿©¸§");
	fall = IMAGEMANAGER->findImage("º¸½º°¡À»");
	pixel = IMAGEMANAGER->findImage("º¸½ºÇÈ¼¿");



	for (int i = 0; i < 20; i++)
	{
		leaf[i].img = IMAGEMANAGER->findImage("³«¿±");
		leaf[i].x = RND->getFromIntTo(-500,0);
		leaf[i].y = RND->getFromIntTo(10, 600);
		leaf[i].count = 0;
		leaf[i].index = 0;
	}

	rc = RectMake(1160, 0, 80, 625);
	exit = RectMakeCenter(0, 550, 50, 100);

	isSeason = false;
	count = 0;

	_player = SAVEDATA->getPlayer();
	_player->setX(100);
	_player->setY(600);
	_player->setBgPixel(pixel);

	_ui = SAVEDATA->getUI();
	_ui->setPlayerManager(_player);

	return S_OK;
}

void bossStage::release(void)
{
}

void bossStage::update(void)
{
	_ui->update();
	_player->update();

	if (_player->getAng())
	{
		isSeason = true;
	}
	else
	{
		isSeason = false;
	}
	if (isSeason)
	{
		
		for (int i = 0; i < 20; ++i)
		{
			leaf[i].count++;
			leaf[i].img->setFrameY(0);
			if (leaf[i].count % 5 == 0)
			{
				leaf[i].index++;
				_player->setX(_player->getX() + 0.6f);
				if (leaf[i].index >= leaf[i].img->getMaxFrameX())
				{
					leaf[i].index = 0;
				}
				leaf[i].img->setFrameX(leaf[i].index);
			}
			leaf[i].x += RND->getFromIntTo(10, 20);

			if (leaf[i].x > WINSIZEX)
			{
				leaf[i].x = RND->getFromIntTo(-300,0);
				leaf[i].y = RND->getFromIntTo(0, 600);
			}
		}
	}
	else
	{
		RECT temp;
		if(IntersectRect(&temp, &_player->getCollisionRc(), &exit))
		{
			SCENEMANAGER->loadScene("Å¸¿î¾À");
		}
	}
}

void bossStage::render(void)
{
	if (isSeason)
	{
		fall->render(getMemDC());

		for (int i = 0; i < 20; i++)
		{
			leaf[i].img->frameRender(getMemDC(), leaf[i].x, leaf[i].y);
		}
	}
	else
	{
		summer->render(getMemDC());
	}

	if (KEYMANAGER->isToggleKey('Y'))
	{
		pixel->render(getMemDC());
		Rectangle(getMemDC(), rc);
	}

	_player->render();
	_ui->render();

	Rectangle(getMemDC(), exit);

	//cout << _player->getX() << ", " << _player->getY() << endl;
}
