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
	summer = IMAGEMANAGER->findImage("보스여름");
	fall = IMAGEMANAGER->findImage("보스가을");
	pixel = IMAGEMANAGER->findImage("보스픽셀");

	SOUNDMANAGER->play("보스배경사운드",0.2f);

	for (int i = 0; i < 20; i++)
	{
		leaf[i].img = IMAGEMANAGER->findImage("낙엽");
		leaf[i].x = RND->getFromIntTo(-500,0);
		leaf[i].y = RND->getFromIntTo(10, 600);
		leaf[i].count = 0;
		leaf[i].index = 0;
	}

	rc = RectMake(1160, 0, 80, 625);
	//exit = RectMakeCenter(0, 550, 50, 100);

	isSeason = false;
	count = 0;
	alpha = 250;
	_player = SAVEDATA->getPlayer();
	_player->setX(100);
	_player->setY(500);
	_player->setBgPixel(pixel);

	_eMG = SAVEDATA->getEnemyManager();
	_iMG = SAVEDATA->getItemManager();

	_player->setEnemyManager(_eMG);
	_player->setItemManager(_iMG);




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
		SOUNDMANAGER->stop("보스배경사운드");
		SCENEMANAGER->loadScene("타운씬");
	}
	//else
	//{
	//	RECT temp;
	//	if(IntersectRect(&temp, &_player->getCollisionRc(), &exit))
	//	{
	//		SCENEMANAGER->loadScene("타운씬");
	//	}
	//}

	_bee->update();

	if (_bee->getState() == ENEMY_ATTACK)
	{
		_bee->setAttackCount(_bee->getAttackCount() + 1);
		_bee->setFireCount(_bee->getFireCount() + 1);
		_bee->setIsFire(true);
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
			if (_bee->getAttackCount() == 200)
			{
				_bee->setState(ENEMY_WALK);
				_bee->setAttackCount(0);
			}
		}
		else
		{
			if (_bee->getIsLeft())
			{
			
				_bee->setX(_bee->getX() - 1);
			}
			else if (!_bee->getIsLeft())
			{
				_bee->setX(_bee->getX() + 1);
			}

			_bee->setAngle(_bee->getAngle() + 0.05f);
			_bee->setY(_bee->getY() - sinf(_bee->getAngle())*2.0f);

			if (_bee->getIsFire() && _bee->getFireCount() % 60 == 0)
			{
				if (_bee->getIsLeft())
				{
					_bee->getBullet()->fire(_bee->getX() - 190, _bee->getY() + 220, 12);

				}
				else
				{
					_bee->getBullet()->fire(_bee->getX() + 220, _bee->getY() + 220, 12);

				}
			}

			for (int i = 0; i <_bee->getBullet()->getVBullet().size(); ++i)
			{
				if (_bee->getBullet()->getVBullet()[i].fire)
				{
					_bee->getBullet()->update();
				}
			
			}
			
			if (_bee->getFireCount() % 500 == 0)
			{
				//_beeBullet->release();
				_bee->getBullet()->release();
				_bee->setState(ENEMY_WALK);
				_bee->setFireCount(0);
				_bee->setIndexX(0);
				//_bee->setIsFire(false);
			}



		}

		if (_player->getX() < _bee->getX())
		{
			_bee->setIsLeft(true);
		}
		else
		{
			_bee->setIsLeft(false);

		}

		
		RECT _rcT;

		for (int i = 0; i < _player->getArrow()->getVArrow().size(); ++i)
		{
			if (IntersectRect(&_rcT, &_player->getArrow()->getVArrow()[i].rc, &_bee->getRc()))
			{

				if (_bee->getDizzyCount() < 5)
				{
					_bee->setDizzyCount(_bee->getDizzyCount() + 1);

				}
				_player->removeArrow(i);

			}

		}

		RECT pRc;
		for (int i = 0; i < _player->getPoison()->getVPoison().size(); ++i)
		{
			if (IntersectRect(&pRc, &_player->getPoison()->getVPoison()[i].rc, &_bee->getRc()))
			{

				if (_bee->getDizzyCount() < 5)
				{
					_bee->setDizzyCount(_bee->getDizzyCount() + 1);
				}
				_player->removePoison(i);

			}

		}




	}
	if (_bee->getState() == ENEMY_SPAWN)
	{
		if (_player->getAng())
		{
			_bee->setX(_bee->getX() + 8);
			if (_bee->getX() > 1000)
			{
				_bee->setHp(_bee->getHp() - 1);
				_bee->setIndexX(0);

				_bee->setState(ENEMY_IDLE);
			}
		}
	}

	if (_bee->getHp() == 0)
	{
		SCENEMANAGER->loadScene("엔딩씬");
	}

	alpha -= 20;
	if (alpha <= 0)
	{
		alpha = 250;
	}
	RECT tempRc;
	if (IntersectRect(&tempRc, &_player->getCollisionRc(), &_bee->getRc()) && _player->getUnHit()>20 && _player->getPlayerState() != HIT)
	{
		_player->setState(HIT);
		_player->setUnHit(0);
		_player->setHp(_player->getHp() - 5);
	}

	for (int i = 0; i < _bee->getBullet()->getVBullet().size(); ++i)
	{
		RECT collRc;
		if (IntersectRect(&collRc, &_player->getCollisionRc(), &_bee->getBullet()->getVBullet()[i].rc) && _player->getUnHit() >20 && _player->getPlayerState() != HIT)
		{
			_player->setState(HIT);
			_player->setUnHit(0);
			_player->setHp(_player->getHp() - 5);
		}
	}

	if (_player->getHp() < 0)
	{


		//_player->setState(DEATH);
		//this->init();

		SCENEMANAGER->loadScene("타운씬");
		//_bee->getBullet()->release();
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

	//벌몸체
	_bee->getBodyImage()->frameRender(getMemDC(), _bee->getRc().left , _bee->getRc().top, _bee->getBodyImage()->getFrameX(), _bee->getBodyImage()->getFrameY());
	//디지카운트표시
	for (int i = 0; i < _bee->getDizzyCount(); ++i)
	{
		IMAGEMANAGER->alphaRender("디지카운트", getMemDC(), _bee->getX() - 250 + i * 150, _bee->getY() , alpha);

	}
	//벌총알
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
