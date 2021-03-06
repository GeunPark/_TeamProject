#include "stdafx.h"
#include "foxPlayer.h"
#include "enemyManager.h"


//ToDo : init
HRESULT foxPlayer::init(void)
{
	imageSetting();

	_arrow = new arrow;
	_arrow->init(3, 600);

	_cuticle = new cuticle;
	_cuticle->init(500);

	_poison = new poison;
	_poison->init(600.f);

	_magic = new magic;
	_magic->init();

	_player.x = 6500;
	_player.y = MAX_HEIGHT - 150;
	_player.speed = 6.f;
	_player.jumpSpeed = 0.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.arrowAngle = 0;
	_player.isLeft = _player.isUp = _player.isDown = _player.isRight = _player.isAtt = _player.isChange = _player.isFoxLeft = false;
	_player.isJump = false;

	index = count = actionCount = index2 = jumpCount = hitCount = unDamage = weatherIndex = effectIndex = effectCount = jumpAttCount = unDamage = alphaCount = 0;
	animationSpeed = 6;

	_player.maxMana = _player.mana = 100;
	_player.HP = _player.MaxHp = 50;
	_player.gold = 9999;
	eftChk = false;
	_state = IDLE;

	_camera.x = _player.x;
	_camera.y = _player.y;

	arrowNum = 1;
	arrowNumChk = 0;

	magicNum = 0;
	magicNumCHk = 0;

	_magicUseCount = 0;
	_magicUseChk = false;
	_magicUseChk2 = false;

	isTouch = false;
	isArrowChange = false;

	tempX = tempY = 0;
	_bpx = IMAGEMANAGER->findImage("스테이지1 픽셀");


	clearCount = 0;

	return S_OK;
}

void foxPlayer::release(void)
{
}

//ToDo : update
void foxPlayer::update(void)
{
	playerUI();
	this->pixelCollision();		//픽셀충돌 함수 호출
	this->frameMove();		//프레임 움직이는 함수 호출
	//여우 상태 
	this->foxState();
	this->camera();	//카메라 움직이는 함수 호출

	this->keySetting();	  //키셋팅 함수 호출

	this->attRect();

	_magic->update();
	_arrow->update();


	_player.gravity += 0.58f;
	if (_state == JUMP)
	{
		if (-sinf(_player.angle) * _player.jumpSpeed + _player.gravity > 0)
		{
			_state = FALL;
		}
	}

	if (_state == DOUBLEJUMP)
	{
		if (-sinf(_player.angle)*_player.jumpSpeed + _player.gravity > 0)
		{
			_state = FALL2;
		}
	}

	//점프할때랑 픽셀충돌하지않을때 플레이어를 밑으로 내려줌
	_player.y += -sinf(_player.angle) * _player.jumpSpeed + _player.gravity;
	_player.collisionRc = RectMakeCenter(_player.x, _player.y + 40, 50, 85);

	this->pixelCollision();		//픽셀충돌 함수 호출

	//적과 충돌
	//if (KEYMANAGER->isToggleKey(VK_F3))
	//{
	
		//this->enemyCollision();
		//this->enemyAttCollision();
	//}

	_magic->setvthundwe(_camera.rc.left, _camera.rc.top);
	_magic->nightMove(_camera.rc.right - 400 - a, _camera.rc.top + 200);
	
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		if (magicNum > 0 && _player.mana == _player.maxMana)
		{
			if (magicNumCHk == 0)
			{
				SOUNDMANAGER->play("나이트메어");
				_magicUseChk2 = true;
				
			}
			else if (magicNumCHk == 1)
			{
				SOUNDMANAGER->play("썬더");
				_magicUseChk = true;
			}
			_player.mana = 0;
		}

	}
	

	if (_magicUseChk == true)
	{
		_magicUseCount += 1;
		for (int i = 0; i < _magic->getvthunder().size(); i++)
		if (_magicUseCount > 60)
		{
			_magicUseCount = 0;
			_magicUseChk = false;
		}
	}
	
	if (_magicUseChk2 == true)
	{
		_magic->a();
		a+= 10;
		if (_magic->getvnightMare()[0]._rc.right < _camera.rc.left)
		{
			a = 0;
			_magicUseChk2 = false;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		SOUNDMANAGER->play("셀렉이동사운드");
		if (!isArrowChange &&  arrowNum>1)
			isArrowChange = true;
		else
			isArrowChange = false;

		arrowNumChk += 1;
		if (arrowNumChk > arrowNum - 1)arrowNumChk = 0;
		
	}


	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		SOUNDMANAGER->play("셀렉이동사운드");
		magicNumCHk += 1;
		if (magicNumCHk > magicNum - 1)magicNumCHk = 0;
	}
	

	_cuticle->update();

	_poison->update();


	this->camera();			//카메라 움직이는 함수 호출

	_player.rc = RectMakeCenter(_player.x, _player.y, nick[_state]->getFrameWidth(), nick[_state]->getFrameHeight());
	twinkleRc = RectMakeCenter(_player.x, _player.y + 50, _twinkle->getFrameWidth(), _twinkle->getFrameHeight());
	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//ToDo : render
void foxPlayer::render()
{
	if (KEYMANAGER->isToggleKey('T'))
	{
		Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
		if (_player.isAtt)
		{
			Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
			Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);
		}
	}
	//Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	
	//if (_player.isAtt)
	//{
		//Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
		//Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);
	//}
	if (_player.isChange)
	{
		_twinkle->frameRender(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, _twinkle->getFrameX(), _twinkle->getFrameY());

		for (int i = 0; i < _cuticle->getCuticle().size(); i++)
		{
			_cuticle->getCuticle()[i].cuticleImage->render(getMemDC(), _cuticle->getCuticle()[i].rc.left - _camera.rc.left, _cuticle->getCuticle()[i].rc.top - _camera.rc.top);
		}
	}
	
	if (KEYMANAGER->isToggleKey('O'))
	{
		Rectangle(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, _player.rc.right - _camera.rc.left, _player.rc.bottom - _camera.rc.top);
	}
	if (_state == HIT)
	{
		if (alphaCount < 10 || alphaCount > 20)
		{
			nick[HIT]->frameAlphaRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, 170);
		}
		else
		{
			nick[HIT]->frameAlphaRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, 200);
		}
	}
	else
	{
		nick[_state]->frameRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, nick[_state]->getFrameX(), nick[_state]->getFrameY());
	}
	//화살 그려주는 부분
	for (int i = 0; i < _arrow->getVArrow().size(); i++)
	{
		_arrow->getVArrow()[i].arrowImage->frameRender(getMemDC(), _arrow->getVArrow()[i].rc.left - _camera.rc.left, _arrow->getVArrow()[i].rc.top - _camera.rc.top);
	}
	// 독화살 그려주는 부분
	for (int i = 0; i < _poison->getVPoison().size(); i++)
	{

		_poison->getVPoison()[i].poisonImage->frameRender(getMemDC(), _poison->getVPoison()[i].rc.left - _camera.rc.left, _poison->getVPoison()[i].rc.top - _camera.rc.top, _poison->getIndexX(), _poison->getIndexY());
	}
	//썬더스킬 그려주는 부분
	for (int i = 0; i <_magic->getvthunder().size(); ++i)
	{
		if (_magicUseChk == true)_magic->getvthunder()[i]._img->frameRender(getMemDC(), _magic->getvthunder()[i]._x - _camera.rc.left, _magic->getvthunder()[i]._y - _camera.rc.top);
	}
	if (_magicUseChk2 == true)
	{
		_magic->getvnightMare()[0]._img2->render(getMemDC(), (_magic->getvnightMare()[0]._x + 25) - _camera.rc.left, (_magic->getvnightMare()[0]._y - 25) - _camera.rc.top);
		_magic->getvnightMare()[0]._img->render(getMemDC(), _magic->getvnightMare()[0]._x - _camera.rc.left, _magic->getvnightMare()[0]._y - _camera.rc.top);

	}
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
		{
			if (_magicUseChk == true)Rectangle(getMemDC(), _enemyManger->getEnemy()[i]->getRc().left - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().top - _camera.rc.top, _enemyManger->getEnemy()[i]->getRc().right - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().bottom - _camera.rc.top);
		}
	}
	for (int i = 0; i < _magic->getvthunder().size(); i++)
	{
		//Rectangle(getMemDC(), _magic->getvthunder()[i]._rc);
	}


	//Rectangle(getMemDC(), _magic->getvnightMare()[0]._rc);


	/*char str[128];
	sprintf(str, "중력 : %f, 점프카운터 : %d, 상태 : %d, 체력 : %d", _player.gravity, jumpCount, magicNumCHk);
	TextOut(getMemDC(), 100, 600, str, strlen(str));*/
}

//ToDo : 이미지 셋팅
void foxPlayer::imageSetting()
{
	nick[IDLE] = IMAGEMANAGER->findImage("Idle");		//아이들
	nick[RUN] = IMAGEMANAGER->findImage("Run");			//달리기
	nick[JUMP] = IMAGEMANAGER->findImage("Jump");		//점프
	nick[DOUBLEJUMP] = IMAGEMANAGER->findImage("Jump2");	//이단점프
	nick[FALL] = IMAGEMANAGER->findImage("Fall");		//떨어지는
	nick[FALL2] = IMAGEMANAGER->findImage("Fall2");		//이단점프하고 떨어지는
	nick[FIRE] = IMAGEMANAGER->findImage("Fire");		//발사
	nick[UPATT] = IMAGEMANAGER->findImage("UpAtt");		//상단베기
	nick[SITATT] = IMAGEMANAGER->findImage("SitAtt");	//앉아공격
	nick[SIT] = IMAGEMANAGER->findImage("Sit");			//앉기
	nick[JUMPATT] = IMAGEMANAGER->findImage("JumpAtt");	//점프공격
	nick[JUMPATT2] = IMAGEMANAGER->findImage("JumpAtt2");	//점프공격2 회전회오리~!
	nick[DOWNATT] = IMAGEMANAGER->findImage("DownAtt");	//내려찍기
	nick[HIT] = IMAGEMANAGER->findImage("Hurt");		//맞는이미지
	nick[WEATHER] = IMAGEMANAGER->findImage("Weather");		//날씨 바꾸는 모션
	nick[DEATH] = IMAGEMANAGER->findImage("Die");			//죽음
	_twinkle = IMAGEMANAGER->findImage("Twinkle");			//반짝이
}
//ToDo : 프레임 움직임
void foxPlayer::frameMove()
{

	if (_player.isFoxLeft)
	{
		
		count++;
		nick[_state]->setFrameY(1);
		if ((count % animationSpeed) == 0)
		{
			--index2;
			if (index2 < 0)
			{
				index2 = nick[_state]->getMaxFrameX();
				if (_state == DEATH)
				{
					
					index2 = 0;
						
				}
				isTouch = false;
			}
			nick[_state]->setFrameX(index2);
		}
	}
	else//오른쪽프레임
	{
		count++;
		nick[_state]->setFrameY(0);
		if ((count % animationSpeed) == 0)
		{
			++index;
			if (index > nick[_state]->getMaxFrameX())
			{
				index = 0;
				if (_state == DEATH)
				{
					index = nick[DEATH]->getMaxFrameX();
				}
			
				isTouch = false;
			}
			nick[_state]->setFrameX(index);
		}
	}

	if (_player.isChange)
	{
		effectCount++;
		_twinkle->setFrameY(0);
		if ((effectCount & animationSpeed) == 0)
		{
			effectIndex++;
			if (effectIndex > _twinkle->getMaxFrameX())
			{
				effectIndex = 0;
			}
			_twinkle->setFrameX(effectIndex);
		}
	}
}

//ToDo : 키 셋팅
void foxPlayer::keySetting()
{
	if (_state != FIRE && _state != HIT && _state != SIT && _state != SITATT && _state != UPATT && _state != WEATHER && KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_state == IDLE)
		{
			_state = RUN;
		}
		_player.arrowAngle = 0;
		_player.isFoxLeft = false;
		_player.isRight = true;
		_player.isUp = false;
		_player.x += _player.speed;
	}
	if (_state != FIRE && _state != HIT && _state != SIT && _state != SITATT && _state != UPATT && _state != WEATHER && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_state == IDLE)
		{
			_state = RUN;
		}

		if(isArrowChange)
			_player.arrowAngle = PI / 180 * 150;
		else
			_player.arrowAngle = PI;

		_player.isLeft = true;
		_player.isFoxLeft = true;
		_player.isUp = false;
		_player.x -= _player.speed;
	}

	if (_state == RUN && KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = IDLE;
		_player.isLeft = false;
		_player.isRight = false;

	}
	else if (_state == RUN && KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = IDLE;
		_player.isLeft = false;

	}

	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.isUp = false;
		if (_state != SITATT && _state != HIT && _state != JUMP && _state != DOUBLEJUMP && _state != FALL && _state != FALL2)      //임뫄~! 이거하나면 해결되는거자나! 정신똑띠 차리자!!! 이거 좀 화낫다 너무 쉬운거여서 화낫다   -세원-
			_state = SIT;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN) && _state != SITATT)
	{
		_state = IDLE;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.isUp = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_player.isUp = false;
		_state = IDLE;
	}
	if (jumpCount < 2)
	{
		if (_state != HIT && _state != WEATHER && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			SOUNDMANAGER->play("점프사운드",50.f);
			++jumpCount;
			_player.jumpSpeed = 9.f;
			_state = JUMP;
			if (jumpCount >= 2)
			{
				_player.gravity = 0.f;
				_player.jumpSpeed = 14.f;
				actionCount = 0;
				SOUNDMANAGER->play("2단점프사운드", 50.f);
				_state = DOUBLEJUMP;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		//화살 발사
		if (_state != FIRE && _state != SIT && _state != JUMP && _state != DOUBLEJUMP && _state != FALL && _state != FALL2
			&& !_player.isUp && _state != JUMPATT && _state != JUMPATT2 && _state != HIT && _state != DEATH && _state != SITATT && _state != WEATHER)
		{
			if (!isArrowChange)
			{
				SOUNDMANAGER->play("화살발사사운드");
				if (_player.isFoxLeft)
				{
					SOUNDMANAGER->play("화살발사사운드", 50.f);
					_state = FIRE;
					_arrow->fire(_player.x - 15, _player.y + 30, _player.arrowAngle);
					index2 = nick[FIRE]->getMaxFrameX();
					count = 0;
				}
				else
				{
					SOUNDMANAGER->play("화살발사사운드", 50.f);
					_state = FIRE;
					_arrow->fire(_player.x + 15, _player.y + 30, _player.arrowAngle);
					index = 0;
					count = 0;
				}
			}
			else if(isArrowChange )
			{
				if (_player.isFoxLeft)
				{
					SOUNDMANAGER->play("독화살", 10.f);
					_state = FIRE;
					_poison->fire(_player.x - 15, _player.y + 30, 3, _player.arrowAngle);
					_player.mana -= 15;
					index2 = nick[FIRE]->getMaxFrameX();
					count = 0;
				}
				else
				{
					SOUNDMANAGER->play("독화살", 10.f);
					_state = FIRE;
					_poison->fire(_player.x - 15, _player.y + 30, 3, _player.arrowAngle);
					_player.mana -= 15;
					index = 0;
					count = 0;
				}
			}
		}
		//앉아 공격
		if (_state == SIT)
		{
			if (_player.isFoxLeft)
			{
				SOUNDMANAGER->play("앉은공격사운드", 10.f);
				_state = SITATT;
				index2 = nick[SITATT]->getMaxFrameX();
				count = 0;
			}
			else
			{
				SOUNDMANAGER->play("앉은공격사운드", 10.f);
				_state = SITATT;
				index = 0;
				count = 0;
			}
		}
		//점프공격
		if ((_state == JUMP || _state == FALL) && actionCount == 0)
		{
			if (_player.isFoxLeft)
			{
				SOUNDMANAGER->play("1단점프공격사운드", 10.f);
				_state = JUMPATT;
				index2 = nick[JUMPATT]->getMaxFrameX();
				count = 0;
				actionCount++;
			}
			else
			{
				SOUNDMANAGER->play("1단점프공격사운드", 10.f);
				_state = JUMPATT;
				index = 0;
				count = 0;
				actionCount++;
			}
		}
		//점프 공격2 회전~회오리~~!!
		if ((_state == DOUBLEJUMP || _state == FALL2) && actionCount == 0)
		{
			if (_player.isFoxLeft)
			{
				SOUNDMANAGER->play("2단점프공격사운드", 10.f);
				_state = JUMPATT2;
				index2 = nick[JUMPATT2]->getMaxFrameX();
				count = 0;
				actionCount++;
			}
			else
			{
				SOUNDMANAGER->play("2단점프공격사운드", 10.f);
				_state = JUMPATT2;
				index = 0;
				count = 0;
				actionCount++;
			}
		}
		//상단베기
		if (_player.isUp)
		{
			if (_player.isFoxLeft)
			{
				SOUNDMANAGER->play("상단베기");
				_state = UPATT;
				index2 = nick[UPATT]->getMaxFrameX();
				count = 0;
			}
			else
			{
				SOUNDMANAGER->play("상단베기");
				_state = UPATT;
				index = 0;
				count = 0;
			}
		}
	}

	//화살발사 후 상태
	if (_state == FIRE && index >= nick[FIRE]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (_state == FIRE && index2 <= 0 && _player.isFoxLeft)
	{
		_state = IDLE;
	}
	//앉아 공격 후 상태
	if (_state == SITATT && index >= nick[SITATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = SIT;

	}
	if (_state == SITATT && index2 <= 0 && _player.isFoxLeft)
	{
		_state = SIT;

	}
	//점프공격 후 상태
	if ((_state == JUMPATT || _state == FALL) && index >= nick[JUMPATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = FALL;

	}
	if ((_state == JUMPATT || _state == FALL) && index2 <= 0 && _player.isFoxLeft)
	{
		_state = FALL;

	}
	//점프공격2 후 상태
	if ((_state == JUMPATT2 || _state == FALL2) && index >= nick[JUMPATT2]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = FALL2;

	}
	if ((_state == JUMPATT2 || _state == FALL2) && index2 <= 0 && _player.isFoxLeft)
	{
		_state = FALL2;

	}
	//상단베기 후 상태
	if (_player.isUp && index >= nick[UPATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (_player.isUp && index2 <= 0 && _player.isFoxLeft)
	{
		_state = IDLE;
	}
	//공격이 끝난후 false처리
	if (!isTouch)
	{
		if ((index < nick[_state]->getMaxFrameX() || index2 > 0) && _state != FIRE && _state != IDLE && _state != HIT && _state != JUMP && _state != DOUBLEJUMP && _state != SIT && _state != RUN && _state != WEATHER && _state != FALL && _state != FALL2)
		{
			_player.isAtt = true;
		}
		else
		{
			_player.isAtt = false;
			attRc = RectMakeCenter(-10000, -10000, 180, 180);
			attRc2 = RectMakeCenter(-10000, -10000, 30, 100);
		}
	}
	else
	{
		attRc = RectMakeCenter(-10000, -10000, 180, 180);
		attRc2 = RectMakeCenter(-10000, -10000, 30, 100);
	}

	if (KEYMANAGER->isOnceKeyDown('S') && _state == IDLE)
	{
		if (eftChk == false)eftChk = true;
		if (!ang && _player.mana > 30)
		{
			ang = true;
			SOUNDMANAGER->resume("스테이지1 겨울");
			SOUNDMANAGER->play("계절변경사운드");
			SOUNDMANAGER->pause("스테이지1 여름");
		}
		else
		{
			ang = false;
			
			SOUNDMANAGER->play("계절해제사운드");
			SOUNDMANAGER->resume("스테이지1 여름");
			SOUNDMANAGER->pause("스테이지1 겨울");
		}
		if (_state != WEATHER)
		{
			if (_player.isFoxLeft)
			{
				SOUNDMANAGER->play("계절변경사운드", 10.f);
				_state = WEATHER;
				_cuticle->fire(_player.x, _player.y + 35, 100);
				index2 = nick[WEATHER]->getMaxFrameX();
				count = 0;
				_player.isChange = true;
			}
			else
			{
				SOUNDMANAGER->play("계절변경사운드", 10.f);
				_state = WEATHER;
				_cuticle->fire(_player.x, _player.y + 35, 100);
				index = 0;
				count = 0;
				_player.isChange = true;
			}
		}

		weatherIndex++;
		if (weatherIndex > 1 || _player.mana < 30)
		{
			SOUNDMANAGER->play("계절해제사운드", 10.f);
			_state = IDLE;
			weatherIndex = 0;
			_player.isChange = false;
		}
	}
	if (_state == WEATHER && index >= nick[WEATHER]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (_state == WEATHER && index2 <= 0 && _player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (effectIndex >= _twinkle->getMaxFrameX())
	{
		_player.isChange = false;
		effectIndex = 0;
	}

}
//todo ; 공격 렉트 생성
void foxPlayer::attRect()
{
	if (_player.isAtt && _state == SITATT)
	{
		if (_player.isFoxLeft)
		{
			attRc = RectMakeCenter(_player.x - 55, _player.y + 50, 90, 30);
		}
		else
		{
			attRc = RectMakeCenter(_player.x + 55, _player.y + 50, 90, 30);
		}
	}
	if (_player.isAtt && _state == UPATT)
	{
		if (_player.isFoxLeft)
		{
			attRc = RectMakeCenter(_player.x, _player.y - 30, 100, 30);
			attRc2 = RectMakeCenter(_player.x - 70, _player.y + 20, 30, 100);
		}
		else
		{
			attRc = RectMakeCenter(_player.x, _player.y - 30, 100, 30);
			attRc2 = RectMakeCenter(_player.x + 70, _player.y + 20, 30, 100);
		}
	}
	if (_player.isAtt && _state == JUMPATT)
	{
		if (_player.isFoxLeft)
		{
			attRc = RectMakeCenter(_player.x, _player.y, 200, 30);
		}
		else
		{
			attRc = RectMakeCenter(_player.x, _player.y, 200, 30);
		}
	}
	if (_player.isAtt && _state == JUMPATT2)
	{
		if (_player.isFoxLeft)
		{
			attRc = RectMakeCenter(_player.x, _player.y, 180, 180);
		}
		else
		{
			attRc = RectMakeCenter(_player.x, _player.y, 180, 180);
		}
	}
}

//ToDo : 카메라
void foxPlayer::camera()		//카메라 움직이는 함수
{
	_camera.x = _player.x;
	_camera.y = _player.y;

	if (_camera.x - WINSIZEX / 2 < 0)
	{
		_camera.x = WINSIZEX / 2;
	}
	if (_camera.x + WINSIZEX / 2 > getBgPixel()->getWidth())
	{
		_camera.x = getBgPixel()->getWidth() - WINSIZEX / 2;
	}
	if (_camera.y - WINSIZEY / 2 < 0)
	{
		_camera.y = WINSIZEY / 2;
	}
	if (_camera.y + WINSIZEY / 2 > getBgPixel()->getHeight())
	{
		_camera.y = getBgPixel()->getHeight() - WINSIZEY / 2;
	}
}
//ToDo : 픽셀충돌
void foxPlayer::pixelCollision()		//픽셀 충돌
{
	for (int i = _player.collisionRc.left + _player.speed; i >= _player.collisionRc.left; i--)
	{
		COLORREF color = GetPixel(this->getBgPixel()->getMemDC(), i, _player.y + 30);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_player.x = i + (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isLeft = false;
			break;
		}
		if (ang && (r == 255 && g == 255 && b == 0))
		{
			_player.x = i + (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isLeft = false;
			break;
		}
	}

	for (int i = _player.collisionRc.top + _player.speed; i >= _player.collisionRc.top; i--)
	{
		COLORREF color = GetPixel(this->getBgPixel()->getMemDC(), _player.x, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_player.y = i + (_player.collisionRc.bottom - _player.collisionRc.top) / 2 - 40;
			_player.jumpSpeed = 0.f;
			if (_state == JUMP)
			{
				_state = FALL;
			}
			else if (_state == DOUBLEJUMP)
			{
				_state = FALL2;
			}
			break;
		}
		if (ang && (r == 255 && g == 255 && b == 0))
		{
			_player.y = i + (_player.collisionRc.bottom - _player.collisionRc.top) / 2 - 40;
			_player.jumpSpeed = 0.f;
			if (_state == JUMP)
			{
				_state = FALL;
			}
			else if (_state == DOUBLEJUMP)
			{
				_state = FALL2;
			}
			break;
		}
	}

	for (int i = _player.collisionRc.right - _player.speed; i <= _player.collisionRc.right; i++)
	{
		COLORREF color = GetPixel(this->getBgPixel()->getMemDC(), i, _player.y + 30);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_player.x = i - (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isRight = false;
			break;
		}
		if (ang && (r == 255 && g == 255 && b == 0))
		{
			_player.x = i - (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isRight = false;
			break;
		}
	}

	for (int i = _player.collisionRc.bottom - (_player.speed + _player.gravity); i <= _player.collisionRc.bottom; i++)
	{
		COLORREF color = GetPixel(this->getBgPixel()->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255) || (!ang && (r == 255 && g == 0 && b == 0)))
		{
			_player.y = i - (_player.collisionRc.bottom - _player.collisionRc.top) / 2 - 40;
			_player.gravity = 0.f;
			_player.isJump = false;
			_player.jumpSpeed = 0.f;
			jumpCount = 0;
			actionCount = 0;
			if (_state == FALL || _state == FALL2 || _state == JUMPATT || _state == JUMPATT2)
			{
				_state = IDLE;
			}
			break;
		}
		if (ang && (r == 255 && g == 255 && b == 0))
		{
			_player.y = i - (_player.collisionRc.bottom - _player.collisionRc.top) / 2 - 40;
			_player.gravity = 0.f;
			_player.isJump = false;
			_player.jumpSpeed = 0.f;
			jumpCount = 0;
			actionCount = 0;
			if (_state == FALL || _state == FALL2)
			{
				_state = IDLE;
			}
			break;
		}
	}
}
//ToDo : 적과의 충돌
void foxPlayer::enemyCollision()
{
	for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
	{
		RECT tempRc;
		if (unDamage > 15)
		{
			if (IntersectRect(&tempRc, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getCollisionRc()) && _enemyManger->getEnemy()[i]->getState() != ENEMY_SPAWN && _state != HIT)
			{
				if (chk == false)
				{
					_player.HP -= 5;
					chk = true;
				}
				int width = (tempRc.right - tempRc.left) + 50;
				int height = (tempRc.bottom - tempRc.top) + 50;

				if (_player.x < _enemyManger->getEnemy()[i]->getCollisionRc().left)
				{
					if (_player.x > width)
					{
						_player.x -= 30;
					}
					if (_player.y > height)
					{
						_player.y -= 30;
					}
				}
				else if (_player.x > _enemyManger->getEnemy()[i]->getCollisionRc().right)
				{
					if (_player.x < width)
					{
						_player.x += 30;
					}
					if (_player.y < height)
					{
						_player.y += 30;
					}
				}
				else if (_player.y < _enemyManger->getEnemy()[i]->getCollisionRc().top)
				{
					if (_player.x > width)
					{
						_player.x -= 30;
					}
					if (_player.y > height)
					{
						_player.y -= 30;
					}
				}
				else if (_player.y > _enemyManger->getEnemy()[i]->getCollisionRc().bottom)
				{
					if (_player.x < width)
					{
						_player.x += 30;
					}
					if (_player.y < height)
					{
						_player.y += 30;
					}
				}
				
				_state = HIT;
				unDamage = 0;
			}
		}
	}
}
//todo : 적의 공격에 충돌
void foxPlayer::enemyAttCollision()
{
	for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
	{
		RECT tempRc2;

		if (unDamage > 16)
		{
			if (IntersectRect(&tempRc2, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getAttRc()))
			{
				if (chk == false)
				{
					_player.HP -= 5;
					chk = true;
				}
				int width = (tempRc2.right - tempRc2.left) + 50;
				int height = (tempRc2.bottom - tempRc2.top) + 50;

				if (_player.x < _enemyManger->getEnemy()[i]->getAttRc().left)
				{
					if (_player.x > width)
					{
						_player.x -= 30;
					}
					if (_player.y > height)
					{
						_player.y -= 30;
					}
				}
				else if (_player.x > _enemyManger->getEnemy()[i]->getAttRc().right)
				{
					if (_player.x < width)
					{
						_player.x += 30;
					}
					if (_player.y < height)
					{
						_player.y += 30;
					}
				}
				else if (_player.y < _enemyManger->getEnemy()[i]->getAttRc().top)
				{
					if (_player.x > width)
					{
						_player.x -= 30;
					}
					if (_player.y > height)
					{
						_player.y -= 30;
					}
				}
				else if (_player.y > _enemyManger->getEnemy()[i]->getAttRc().bottom)
				{
					if (_player.x < width)
					{
						_player.x += 30;
					}
					if (_player.y < height)
					{
						_player.y += 30;
					}
				}
				SOUNDMANAGER->play("맞음");
				_state = HIT;
				unDamage = 0;
			}
		}
	}
}

void foxPlayer::removeArrow(int index)
{
	_arrow->removeArrow(index);
}
void foxPlayer::removePoison(int index)
{
	_poison->removePoison(index);
}
//todo : 여우상태
void foxPlayer::foxState()
{
	if (_state == IDLE || _state == RUN || _state == SIT || _state == JUMP || _state == DOUBLEJUMP || _state == FALL || _state == FALL2)
	{
		unDamage++;
	}

	if (_state == HIT)
	{

		hitCount++;
		alphaCount++;
		if (hitCount > 25)
		{
			chk = false;
			_state = IDLE;
			alphaCount = 0;
			hitCount = 0;
		}
	}
	if (_player.HP == 0 || _player.y > 3000)
	{
		//SOUNDMANAGER->play("죽음");
		_state = DEATH;
	}
	if (_state == DEATH)
	{
		this->init();
		_enemyManger->release();
		_itemManager->release();
		SCENEMANAGER->loadScene("타운씬");
		
	}
}

void foxPlayer::magicCollision()
{
	RECT _rcT;
	for (int i = 0; i < _magic->getvthunder().size(); i++)
	{
		for (int j = 0; j < _enemyManger->getEnemy().size(); j++)
		{
			if (IntersectRect(&_rcT, &_magic->getvthunder()[i]._rc, &_enemyManger->getEnemy()[j]->getCollisionRc()))
			{
			
			}
		}
	}
}

void foxPlayer::test()
{
	if (KEYMANAGER->isOnceKeyDown('F') && _player.MaxHp < 100)
	{
		_player.MaxHp += 10;
	}
	if (KEYMANAGER->isOnceKeyDown('G') && _player.MaxHp > 10)
	{
		_player.MaxHp -= 10;
	}
	if (KEYMANAGER->isOnceKeyDown('H') && _player.HP < _player.MaxHp)
	{
		_player.HP += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('J') && _player.HP > 0)
	{
		_player.HP -= 5;
	}
	if (KEYMANAGER->isOnceKeyDown('K') && _player.maxMana < 200)
	{
		_player.maxMana += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('L') && _player.maxMana > 100)
	{
		_player.maxMana -= 5;
	}
	if (KEYMANAGER->isStayKeyDown('N') && _player.gold < 9999)
	{
		_player.gold += 100;
	}
	if (KEYMANAGER->isStayKeyDown('M') && _player.gold > 0)
	{
		_player.gold -= 100;
	}
}
void foxPlayer::playerUI()
{
	if (ang)
	{
		_player.mana -= 0.1f;
		if (_player.mana <= 0)
		{
			SOUNDMANAGER->play("스테이지1 여름");
			SOUNDMANAGER->pause("스테이지1 겨울");
			ang = false;
		}
	}
	else
	{
		if (_player.maxMana > _player.mana)_player.mana += 0.05f;
	}
	if (_player.HP > _player.MaxHp)_player.HP = _player.MaxHp;
	if (_player.HP < 0)_player.HP = 0;
	if (_player.maxMana < _player.mana)_player.mana = _player.maxMana;
	if (_player.maxMana > 216)_player.maxMana = 216;

	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		_player.mana += 30;
	}
}