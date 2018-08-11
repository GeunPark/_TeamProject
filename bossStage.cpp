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
	summer = IMAGEMANAGER->findImage("��������");
	fall = IMAGEMANAGER->findImage("��������");
	pixel = IMAGEMANAGER->findImage("�����ȼ�");



	for (int i = 0; i < 20; i++)
	{
		leaf[i].img = IMAGEMANAGER->findImage("����");
		leaf[i].x = RND->getFromIntTo(-500,0);
		leaf[i].y = RND->getFromIntTo(10, 600);
		leaf[i].count = 0;
		leaf[i].index = 0;
	}

	rc = RectMake(1160, 0, 80, 625);
	//exit = RectMakeCenter(0, 550, 50, 100);

	isSeason = false;
	count = 0;

	_player = SAVEDATA->getPlayer();
	_player->setX(100);
	_player->setY(500);
	_player->setBgPixel(pixel);

	_ui = SAVEDATA->getUI();
	_ui->setPlayerManager(_player);

	_bee = new bee;
	_bee->init();


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
	if (_player->getX() < 0)
	{
		SCENEMANAGER->loadScene("Ÿ���");
	}
	//else
	//{
	//	RECT temp;
	//	if(IntersectRect(&temp, &_player->getCollisionRc(), &exit))
	//	{
	//		SCENEMANAGER->loadScene("Ÿ���");
	//	}
	//}

	_bee->update();

	if (_bee->getState() == ENEMY_ATTACK)
	{
		_bee->setAttackCount(_bee->getAttackCount() + 1);
		if (_bee->getHp() > 3)
		{
			if (_bee->getY() > 600 || _bee->getX() < 250 || _bee->getX() > 1100)
			{
				_bee->setX(_bee->getX());
				_bee->setY(_bee->getY());
				//_bee->setState(ENEMY_WALK);

			}
			else
			{
				_bee->setAngle(getAngle(_bee->getX(), _bee->getY(), _player->getX(), _player->getY()));
				_bee->setX(_bee->getX() + cosf(_bee->getAngle())*_bee->getSpeed());
				_bee->setY(_bee->getY() - sinf(_bee->getAngle())*_bee->getSpeed());

			}
		}
		else
		{

		}

		if (_player->getX() < _bee->getX())
		{
			_bee->setIsLeft(true);
		}
		else
		{
			_bee->setIsLeft(false);

		}

		if (_bee->getAttackCount() == 200)
		{
			_bee->setState(ENEMY_WALK);
			_bee->setAttackCount(0);
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


	//����ü
	_bee->getBodyImage()->frameRender(getMemDC(), _bee->getRc().left , _bee->getRc().top, _bee->getBodyImage()->getFrameX(), _bee->getBodyImage()->getFrameY());

	//���Ѿ�
	for (int i = 0; i < _bee->getBullet()->getVBullet().size(); ++i)
	{
		if (_bee->getBullet()->getVBullet()[i].fire)
		{
			_bee->getBullet()->getVBullet()[i].bulletImage->frameRender(getMemDC(), _bee->getBullet()->getVBullet()[i].rc.left , _bee->getBullet()->getVBullet()[i].rc.top , _bee->getBullet()->getIndex(), 0);

		}

	}
	_player->render();

	_ui->render();

	//Rectangle(getMemDC(), exit);

	//cout << _player->getX() << ", " << _player->getY() << endl;
}
