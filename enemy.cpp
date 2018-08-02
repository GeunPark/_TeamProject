#include "stdafx.h"
#include "enemy.h"

void dragonFly::init()
{
	for (int i = 0; i < 5; i++)
	{
		_bodyImage[i] = new image;
	}

	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("잠자리spawn");
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("잠자리spawn");
	_bodyImage[ENEMY_WALK]= IMAGEMANAGER->findImage("잠자리move");
	//_bodyImage[ENEMY_FIRE]= IMAGEMANAGER->findImage("잠자리move");
	_bodyImage[ENEMY_DEAD]= IMAGEMANAGER->findImage("잠자리dead");


	//_gunImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("총평상시");
	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_state = ENEMY_SPAWN;
	_type = DRAGONFLY;
	_x = 0.f;
	_y = 0.f;
	_isLeft = false;
}

void dragonFly::idle()
{
	//cout << "나는 솔져" << endl;
	
}

void dragonFly::spawn()
{
}

void dragonFly::attack()
{
}

void dragonFly::move()
{

}

void dragonFly::dead()
{

}

void vineMan::init()
{
	_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("나무인간spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("나무인간move");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("나무인간dead");
	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 3.f;
	_isActived = true;
	_state = ENEMY_IDLE;
	_type = VINEMAN;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = false;
}

void vineMan::idle()
{
	//cout << "나는 브로빌" << endl;
}

void vineMan::spawn()
{
}

void vineMan::attack()
{
}

void vineMan::move()
{
}

void vineMan::dead()
{
}


void bug::init()
{
}

void bug::idle()
{
}

void bug::spawn()
{
}

void bug::attack()
{
}

void bug::move()
{
}

void bug::dead()
{
}

void treeMan::init()
{
}

void treeMan::idle()
{
}

void treeMan::spawn()
{
}

void treeMan::attack()
{
}

void treeMan::move()
{
}

void treeMan::dead()
{
}

void plantFrog::init()
{
}

void plantFrog::idle()
{
}

void plantFrog::spawn()
{
}

void plantFrog::attack()
{
}

void plantFrog::move()
{
}

void plantFrog::dead()
{
}

void electriceel::init()
{
}

void electriceel::idle()
{
}

void electriceel::spawn()
{
}

void electriceel::attack()
{
}

void electriceel::move()
{
}

void electriceel::dead()
{
}











enemy * enemyFactory::createEnemy(ENEMY_TYPE type)
{
	enemy* _enemy;
	switch (type)
	{
	case DRAGONFLY:
		_enemy = new dragonFly;
		break;
	case VINEMAN:
		_enemy = new vineMan;
		break;

	case BUG:
		_enemy = new bug;
		break;

	case TREEMAN:
		_enemy = new treeMan;
		break;

	case PLANTFROG:
		_enemy = new plantFrog;
		break;

	case ELECTRICEEL:
		_enemy = new electriceel;


	default:
		//누구냐 넌??
		break;
	}

	_enemy->init();

	return _enemy;
}

void enemy::update()
{
	switch (_state)
	{
	case ENEMY_IDLE:
		idle();
		break;
	case ENEMY_SPAWN:
		spawn();
		break;
	case ENEMY_WALK:
		move();
		break;
	case ENEMY_FIRE:
		attack();
		break;
	case ENEMY_DEAD:
		dead();
		break;
	default:
		//누구냐 넌?
		break;
	}

	//_gravity += 0.98f;
	//if (_gravity >= 10.f)
	//{
	//	_gravity = 10.f;
	//}
	//
	//_y += _gravity;

	_count++;

	if (_count % _animationSpeed == 0)
	{
		_index++;
		if (_index > _bodyImage[_state]->getMaxFrameX())
		{
			if (_state != ENEMY_DEAD)
				_state = ENEMY_WALK;
			_index = 0;
		}
		_bodyImage[_state]->setFrameX(_index);

		
	}

	if (_isLeft)
	{
		_bodyImage[_state]->setFrameY(0);
	}
	else
	{
		_bodyImage[_state]->setFrameY(1);
	}

	_rc = RectMakeCenter(_x, _y, _bodyImage[_state]->getFrameWidth(), _bodyImage[_state]->getFrameHeight());


	//if (COLLISIONMANAGER->pixelCollision(RectMake(_x, _y, _bodyImage[_state]->getFrameWidth(), _bodyImage[_state]->getFrameHeight()), _x, _y, _speed, _gravity, ENEMY_BOTTOM))
	//{
	//	_gravity = 0.f;
	//}
	//
	//FRAMEMANAGER->frameChange(_bodyImage[_state], _count, _index, _animationSpeed, _isLeft);
}




//HRESULT enemy::init(void)
//{
//
//	return S_OK;
//}
//
//HRESULT enemy::init(const char* idleImageName, const char* spawnImageName, const char* moveImageName, const char* attackImageName, const char* deadImageName, POINT position, int currentFrameX, int moveCount, int gold, int silver, int bronze)
//{
//
//
//	enemyState = E_LEFT;
//	enemyAction = E_SPAWN;
//
//
//	//프레임 초기화
//	_count = 0;
//	_currentFrameX = currentFrameX;
//	_currentFrameY = 0;
//
//	//이미지, 이미지렉트 초기화
//	IMAGEMANAGER->addFrameImage("두꺼비혀", "resource/두꺼비tongue.bmp", 200, 18, 1, 2);
//
//
//	_image[E_IDLE] = IMAGEMANAGER->findImage(idleImageName);
//	_image[E_SPAWN] = IMAGEMANAGER->findImage(spawnImageName);
//	_image[E_MOVE] = IMAGEMANAGER->findImage(moveImageName);
//	_image[E_ATTACK] = IMAGEMANAGER->findImage(attackImageName);
//	_image[E_DEAD] = IMAGEMANAGER->findImage(deadImageName);
//
//
//	_x = position.x;
//	_y = position.y;
//	gravity = 0;
//
//	//랜덤으로 총알 쿨타임 주기
//	_fireCount = 0;
//	_rndFireCount = RND->getFromIntTo(1, 1000);
//
//	//움직임
//	_moveCount = moveCount;
//	//혀
//	isTongue = false;
//	//item
//	isDead = false;
//	isDrop = false;
//	_gold = gold;
//	_silver = silver;
//	_bronze = bronze;
//
//	//_goldCoin = new goldCoin[gold];
//	//_silverCoin = new silverCoin[silver];
//	//_bronzeCoin = new bronzeCoin[bronze];
//
//	return S_OK;
//}
//
//void enemy::release(void)
//{
//
//}
//
//void enemy::update(void)
//{
//	if (enemyAction == E_MOVE)
//		this->move();
//
//	if (enemyAction != E_ATTACK)
//	{
//		_rc = RectMakeCenter(_x, _y, _image[enemyAction]->getFrameWidth(), _image[enemyAction]->getFrameHeight());
//		_collRc = RectMakeCenter(_x, _y, _image[E_MOVE]->getFrameWidth()/2, _image[E_MOVE]->getFrameHeight());
//		_sensor = RectMakeCenter(_x, _y, 400, _image[enemyAction]->getFrameHeight());
//	}
//
//	this->animation();
//	this->attack();
//	// this->enemyDead();
//	// this->coinDrop();
//}
//
//void enemy::render(float FX, float FY)
//{
//	draw(FX, FY);
//
//}
//
////알아서 만들면 된다
//void enemy::move()
//{
//}
//
//void enemy::attack()
//{
//}
//
//void enemy::draw(float FX, float FY)
//{
//	//_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
//	if (KEYMANAGER->isToggleKey(VK_F1))
//	{
//		Rectangle(getMemDC(), _sensor.left - FX, _sensor.top - FY, _sensor.right - FX, _sensor.bottom - FY);
//		Rectangle(getMemDC(), _collRc.left - FX, _collRc.top - FY, _collRc.right - FX, _collRc.bottom - FY);
//		Rectangle(getMemDC(), _attRc.left - FX, _attRc.top - FY, _attRc.right - FX, _attRc.bottom - FY);
//		Rectangle(getMemDC(), _tongueRc.left - FX, _tongueRc.top - FY, _tongueRc.right - FX, _tongueRc.bottom - FY);
//
//	}
//	if (isTongue)
//		IMAGEMANAGER->frameRender("두꺼비혀", getMemDC(), _tongueRc.left - FX, _tongueRc.top - FY, 0, _currentFrameY);
//
//
//	_image[enemyAction]->frameRender(getMemDC(), _rc.left - FX, _rc.top - FY, _currentFrameX, _currentFrameY);//, _currentFrameX, _currentFrameY);
//
//	//if (isDrop)
//	//{
//	//	for (int i = 0; i < _gold; ++i)
//	//	{
//	//		_goldCoin[i].render(FX, FY);
//	//	}
//	//	for (int i = 0; i < _silver; ++i)
//	//	{
//	//		_silverCoin[i].render(FX, FY);
//	//
//	//	}
//	//	for (int i = 0; i < _bronze; ++i)
//	//	{
//	//		_bronzeCoin[i].render(FX, FY);
//	//	}
//	//}
//}
//
//void enemy::animation()
//{
//	_count++;
//	
//	if (enemyAction == E_DEAD)
//	{
//		if (_count % 6 == 0)
//		{
//			if (enemyState == E_RIGHT)
//			{
//				_currentFrameX--;
//				if (_currentFrameX < 0)
//				{
//					//_currentFrameX = _image[enemyAction]->getMaxFrameX();
//					isDrop = true;
//					_count = 0;
//				}
//			}
//			else if (enemyState == E_LEFT)
//			{
//				_currentFrameX++;
//				if (_currentFrameX > _image[enemyAction]->getMaxFrameX())
//				{
//					//_currentFrameX = 0;
//					isDrop = true;
//					_count = 0;
//				}
//
//			}
//		}
//
//
//	}
//	else
//	{
//		if (_count % 10 == 0)
//		{
//			if (enemyState == E_RIGHT)
//			{
//				_currentFrameX--;
//				if (_currentFrameX < 0)
//				{
//					_currentFrameX = _image[enemyAction]->getMaxFrameX();
//					enemyAction = E_MOVE;
//					_count = 0;
//				}
//			}
//			else if (enemyState == E_LEFT)
//			{
//				_currentFrameX++;
//				if (_currentFrameX > _image[enemyAction]->getMaxFrameX())
//				{
//					_currentFrameX = 0;
//					enemyAction = E_MOVE;
//					_count = 0;
//				}
//
//			}
//		}
//	}
//	
//	
//	if (enemyState == E_RIGHT)
//		_currentFrameY = 1;
//	else if (enemyState == E_LEFT)
//		_currentFrameY = 0;
//	
//}
//
//// void enemy::enemyDead()
//// {
//// 	if (enemyAction == E_DEAD)
//// 	{
//// 		isDead = true;
//// 	}
//// 
//// }
// 
// //void enemy::coinDrop()
// //{
// //	if (isDrop)
// //	{
// //		for (int i = 0; i < _gold; ++i)
// //		{
// //			_goldCoin[i].update();
// //		}
// //		for (int i = 0; i < _silver; ++i)
// //		{
// //			_silverCoin[i].update();
// //
// //		}
// //		for (int i = 0; i < _bronze; ++i)
// //		{
// //			_bronzeCoin[i].update();
// //		}
// //	}
// //
// //
// //}
//
//bool enemy::bulletCountFire()
//{
//	_fireCount++;
//	if (_fireCount % _rndFireCount == 0)
//	{
//		_rndFireCount = RND->getFromIntTo(1, 1000);
//		_fireCount = 0;
//		return true;
//	}
//
//	return false;
//}
//
//
//
//
//void dragonfly::move()
//{
//	_moveCount++;
//
//	angle += 0.05;
//	_y += sinf(angle) * 1.0f;
//	if (_moveCount % 300 <= 150)
//	{
//		_x += 1;
//		enemyState = E_RIGHT;
//	}
//	else if (_moveCount % 300 <= 300)
//	{
//		_x -= 1;
//		enemyState = E_LEFT;
//	}
//}
//
//void dragonfly::attack()
//{
//}
//
//
//
//
//void vineman::move()
//{
//	_moveCount++;
//
//	if (_moveCount % 300 <= 150)
//	{
//		_x += 1;
//		enemyState = E_RIGHT;
//	}
//	else if (_moveCount % 300 <= 300)
//	{
//		_x -= 1;
//		enemyState = E_LEFT;
//	}
//}
//
//void vineman::attack()
//{
//	if (enemyAction == E_ATTACK)
//	{
//		_rc = RectMake(_x - _image[E_ATTACK]->getFrameWidth() / 2, _y - _image[E_ATTACK]->getFrameHeight() + _image[E_MOVE]->getFrameHeight() / 2, _image[E_ATTACK]->getFrameWidth(), _image[E_ATTACK]->getFrameHeight());
//		_attRc = RectMakeCenter(_x, _y + 15, 0, 20);
//
//		_count++;
//		if (_count % 10 == 0)
//		{
//			//_image[enemyAction]->setFrameX(_image[enemyAction]->getFrameX() + 1);
//
//			if (enemyState == E_LEFT)
//			{
//				_currentFrameX++;
//
//				if (_currentFrameX > 5)
//				{
//					_attRc.left -= 130;
//				}
//				if (_currentFrameX >= _image[enemyAction]->getMaxFrameX())
//				{
//					_currentFrameX = 0;
//					enemyAction = E_MOVE;
//					_count = 0;
//					_attRc.left = _attRc.right;
//
//				}
//			}
//			else if (enemyState == E_RIGHT)
//			{
//				_currentFrameX--;
//
//				if (_currentFrameX < 1)
//				{
//					_attRc.right += 155;
//				}
//				if (_currentFrameX < 0)
//				{
//					_currentFrameX = _image[enemyAction]->getMaxFrameX();
//					enemyAction = E_MOVE;
//					_count = 0;
//					_attRc.right = _attRc.left;
//
//				}
//			}
//		}
//	}
//
//
//}
//
//
//void bug::move()
//{
//	_moveCount++;
//
//	if (_moveCount % 300 <= 150)
//	{
//		_x += 1;
//		enemyState = E_RIGHT;
//	}
//	else if (_moveCount % 300 <= 300)
//	{
//		_x -= 1;
//		enemyState = E_LEFT;
//	}
//
//}
//
//void bug::attack()
//{
//
//
//}
//
//
//
//void treeman::move()
//{
//	_moveCount++;
//
//	if (_moveCount % 300 <= 150)
//	{
//		_x += 1;
//		enemyState = E_RIGHT;
//	}
//	else if (_moveCount % 300 <= 300)
//	{
//		_x -= 1;
//		enemyState = E_LEFT;
//	}
//
//}
//
//void treeman::attack()
//{
//
//
//}
//
//
//void plantfrog::move()
//{
//	_moveCount++;
//	gravity += 0.2f;
//	if (_moveCount % 600 <= 300)
//	{
//		_x += cosf(angle)*5.0f;
//		_y += -sinf(angle)*10.0f + gravity;
//		enemyState = E_RIGHT;
//
//	}
//	else if (_moveCount % 600 <= 600)
//	{
//		_x -= cosf(angle)*5.0f;
//		_y += -sinf(angle)*10.0f + gravity;
//		enemyState = E_LEFT;
//	}
//}
//
//void plantfrog::attack()
//{
//
//	if (enemyAction == E_ATTACK)
//	{
//		_rc = RectMake(_x - _image[E_ATTACK]->getFrameWidth() / 2, _y - _image[E_ATTACK]->getFrameHeight() + _image[E_MOVE]->getFrameHeight() / 2, _image[E_ATTACK]->getFrameWidth(), _image[E_ATTACK]->getFrameHeight());
//
//		_count++;
//		if (_count % 12 == 0)
//		{
//			//_image[enemyAction]->setFrameX(_image[enemyAction]->getFrameX() + 1);
//
//			if (enemyState == E_LEFT)
//			{
//				_tongueRc = RectMake(_x - 200, _y + 21, 0, 10);
//
//				_currentFrameX++;
//
//				if (_currentFrameX > 6)
//				{
//					_tongueRc.right += 200;
//					isTongue = true;
//
//				}
//
//				if (_currentFrameX > _image[enemyAction]->getMaxFrameX())
//				{
//					isTongue = false;
//
//					_currentFrameX = 0;
//					enemyAction = E_MOVE;
//					_count = 0;
//					_tongueRc.right = _tongueRc.left;
//
//				}
//			}
//			else if (enemyState == E_RIGHT)
//			{
//				_tongueRc = RectMake(_x + 20, _y + 18, 0, 10);
//
//				_currentFrameX--;
//
//				if (_currentFrameX < 3)
//				{
//					_tongueRc.right += 200;
//					isTongue = true;
//				}
//				if (_currentFrameX <= 0)
//				{
//					isTongue = false;
//					_currentFrameX = _image[enemyAction]->getMaxFrameX();
//					enemyAction = E_MOVE;
//					_count = 0;
//					_tongueRc.right = _tongueRc.left;
//
//				}
//			}
//		}
//	}
//}
//
////void plantfrog::pixelCollision()
////{
////	for (int i = _image[E_MOVE]->getX(); i < _image[E_MOVE]->getX() + _image[E_MOVE]->getFrameWidth(); i += _image[E_MOVE]->getFrameWidth() / 2)
////	{
////		for (int j = _rc.bottom - 10; j < _rc.bottom; j++)
////		{
////			COLORREF color = GetPixel(_player->getTestBgImage()->getMemDC(), i, j);
////			int r = GetRValue(color);
////			int g = GetGValue(color);
////			int b = GetBValue(color);
////
////			if ((r == 0 && g == 255 && b == 255))
////			{
////				_y = j -_image[E_MOVE]->getFrameHeight();
////				break;
////			}
////
////		}
////	}
////
////
////
////}
//
//void electriceel::move()
//{
//
//
//}
//
//void electriceel::attack() // 명시적으로 어텍이지만 움직임에 관련해서 변경 ( 이렇게 하는 이유는 스폰이나 무브 상태에서 움직임을 주기위해서이다)
//{
//
//
//	if (_count % 7 == 0)
//	{
//		if (enemyState == E_LEFT)
//		{
//			_currentFrameX++;
//			if (_currentFrameX > _image[enemyAction]->getMaxFrameX())
//			{
//				_currentFrameX = 0;
//				enemyAction = E_MOVE;
//				_count = 0;
//			}
//		}
//	}
//
//	if (_currentFrameX >= 7 && _currentFrameX <= 11)
//	{
//		_y -= 7;
//	}
//	else if (_currentFrameX >= 21 && _currentFrameX <= 26)
//	{
//		_y += 7;
//	}
//
//
//
//}
//
