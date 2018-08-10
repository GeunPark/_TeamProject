#include "stdafx.h"
#include "foxPlayer.h"
#include "enemyManager.h"
#include "shop.h"
#include "UI.h"

//ToDo : init
HRESULT foxPlayer::init(void)
{
	imageSetting();

	// �� UI ������ �ϲ�  ����
	_ui = new UI;
	_ui->init();

	_arrow = new arrow;
	_arrow->init(3, 600);

<<<<<<< HEAD
	_cuticle = new cuticle;
	_cuticle->init(500);

	_player.x = 3000;
	_player.y = MAX_HEIGHT - 150;
=======
	_player.x = 9500;
	_player.y = 1250;//MAX_HEIGHT - 150;
>>>>>>> 98047fece4d62ecad27ee9170f535d98ed775727
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
	_player.gold = 0;

	_state = IDLE;

	_camera.x = _player.x;
	_camera.y = _player.y;

	_bpx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	return S_OK;
}

void foxPlayer::release(void)
{
	//_arrow->release();

}

//ToDo : update
void foxPlayer::update(void)
{
	playerUI();

	_player.gravity += 0.58f;

	this->keySetting();	  //Ű���� �Լ� ȣ��

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

	//�����Ҷ��� �ȼ��浹���������� �÷��̾ ������ ������
	_player.y += -sinf(_player.angle) * _player.jumpSpeed + _player.gravity;

	_player.collisionRc = RectMakeCenter(_player.x, _player.y + 40, 50, 85);



	this->pixelCollision();		//�ȼ��浹 �Լ� ȣ��

	this->frameMove();		//������ �����̴� �Լ� ȣ��
							//���� �浹
	if (KEYMANAGER->isToggleKey(VK_F3))
	{
		this->enemyCollision();
		this->enemyAttCollision();
	}

	//���ݷ�Ʈ ����
	this->attRect();
	//���� ���� 
	this->foxState();
	
	_arrow->update();

	_cuticle->update();

	_ui->update();

	this->camera();			//ī�޶� �����̴� �Լ� ȣ��

	_player.rc = RectMakeCenter(_player.x, _player.y, nick[_state]->getFrameWidth(), nick[_state]->getFrameHeight());
	twinkleRc = RectMakeCenter(_player.x, _player.y + 50, _twinkle->getFrameWidth(), _twinkle->getFrameHeight());
	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//ToDo : render
void foxPlayer::render()
{
	Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	
	if (_player.isAtt)
	{
		Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
		Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);
	}
	if (_player.isChange)
	{
		//Rectangle(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, twinkleRc.right - _camera.rc.left, twinkleRc.bottom - _camera.rc.top);
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
	
	_ui->render();

	for (int i = 0; i < _arrow->getVArrow().size(); i++)
	{
		_arrow->getVArrow()[i].arrowImage->frameRender(getMemDC(), _arrow->getVArrow()[i].rc.left - _camera.rc.left, _arrow->getVArrow()[i].rc.top - _camera.rc.top);
	}
	
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
		{
			Rectangle(getMemDC(), _enemyManger->getEnemy()[i]->getRc().left - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().top - _camera.rc.top, _enemyManger->getEnemy()[i]->getRc().right - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().bottom - _camera.rc.top);
		}
	}

	char str[128];
	sprintf(str, "�߷� : %f, �ε��� : %d, ���� : %d, �ε���2 : %d, ���� : %d", _player.gravity, index, _state, index2, weatherIndex);
	TextOut(getMemDC(), 100, 600, str, strlen(str));


}

//ToDo : �̹��� ����
void foxPlayer::imageSetting()
{
	nick[IDLE] = IMAGEMANAGER->findImage("Idle");		//���̵�
	nick[RUN] = IMAGEMANAGER->findImage("Run");			//�޸���
	nick[JUMP] = IMAGEMANAGER->findImage("Jump");		//����
	nick[DOUBLEJUMP] = IMAGEMANAGER->findImage("Jump2");	//�̴�����
	nick[FALL] = IMAGEMANAGER->findImage("Fall");		//��������
	nick[FALL2] = IMAGEMANAGER->findImage("Fall2");		//�̴������ϰ� ��������
	nick[FIRE] = IMAGEMANAGER->findImage("Fire");		//�߻�
	nick[UPATT] = IMAGEMANAGER->findImage("UpAtt");		//��ܺ���
	nick[SITATT] = IMAGEMANAGER->findImage("SitAtt");	//�ɾư���
	nick[SIT] = IMAGEMANAGER->findImage("Sit");			//�ɱ�
	nick[JUMPATT] = IMAGEMANAGER->findImage("JumpAtt");	//��������
	nick[JUMPATT2] = IMAGEMANAGER->findImage("JumpAtt2");	//��������2 ȸ��ȸ����~!
	nick[DOWNATT] = IMAGEMANAGER->findImage("DownAtt");	//�������
	nick[HIT] = IMAGEMANAGER->findImage("Hurt");		//�´��̹���
	nick[WEATHER] = IMAGEMANAGER->findImage("Weather");		//���� �ٲٴ� ���
	nick[DEATH] = IMAGEMANAGER->findImage("Die");			//����
	_twinkle = IMAGEMANAGER->findImage("Twinkle");			//��¦��
}
//ToDo : ������ ������
void foxPlayer::frameMove()
{
	if (_player.isFoxLeft)
	{
		count++;
		nick[_state]->setFrameY(1);
		if ((count & animationSpeed) == 0)
		{
			index2--;
			if (index2 < 0)
			{
				index2 = nick[_state]->getMaxFrameX();
			}
			nick[_state]->setFrameX(index2);
		}
	}
	else//������������
	{
		count++;
		nick[_state]->setFrameY(0);
		if ((count & animationSpeed) == 0)
		{
			index++;
			if (index > nick[_state]->getMaxFrameX())
			{
				index = 0;
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

//ToDo : Ű ����
void foxPlayer::keySetting()
{
	if (_state != FIRE && _state != HIT && KEYMANAGER->isStayKeyDown(VK_RIGHT))
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
	if (_state != FIRE && _state != HIT && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_state == IDLE)
		{
			_state = RUN;
		}
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

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.isUp = false;
		if (_state != SITATT && _state != HIT)		//�Ӹ�~! �̰��ϳ��� �ذ�Ǵ°��ڳ�! ���Ŷȶ� ������!!! �̰� �� ȭ���� �ʹ� ����ſ��� ȭ����   -����-
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

	if (jumpCount < 2)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			++jumpCount;
			_player.jumpSpeed = 10.f;
			_state = JUMP;
			if (jumpCount >= 2)
			{
				_player.gravity = 0.f;
				_player.jumpSpeed = 10.f;
				actionCount = 0;
				_state = DOUBLEJUMP;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		//ȭ�� �߻�
		if (_state != FIRE && _state != SIT && _state != JUMP && _state != DOUBLEJUMP && _state != FALL && _state != FALL2 && !_player.isUp && _state != JUMPATT && _state != JUMPATT2)
		{
			if (_player.isFoxLeft)
			{
				_state = FIRE;
				_arrow->fire(_player.x - 15, _player.y + 30, _player.arrowAngle);
				index2 = nick[FIRE]->getMaxFrameX();
				count = 0;
			}
			else
			{
				_state = FIRE;
				_arrow->fire(_player.x + 15, _player.y + 30, _player.arrowAngle);
				index = 0;
				count = 0;
			}
		}

		//�ɾ� ����
		if (_state == SIT)
		{
			if (_player.isFoxLeft)
			{
				_state = SITATT;
				index2 = nick[SITATT]->getMaxFrameX();
				count = 0;
			}
			else
			{
				_state = SITATT;
				index = 0;
				count = 0;
			}
		}
		//��������
		if ((_state == JUMP || _state == FALL) && actionCount == 0)
		{
			if (_player.isFoxLeft)
			{
				_state = JUMPATT;
				index2 = nick[JUMPATT]->getMaxFrameX();
				count = 0;
				actionCount++;
			}
			else
			{
				_state = JUMPATT;
				index = 0;
				count = 0;
				actionCount++;
			}
		}
		//���� ����2 ȸ��~ȸ����~~!!
		if ((_state == DOUBLEJUMP || _state == FALL2) && actionCount == 0)
		{
			if (_player.isFoxLeft)
			{
				_state = JUMPATT2;
				index2 = nick[JUMPATT2]->getMaxFrameX();
				count = 0;
				actionCount++;
			}
			else
			{
				_state = JUMPATT2;
				index = 0;
				count = 0;
				actionCount++;
			}
		}
		//��ܺ���
		if (_player.isUp)
		{
			if (_player.isFoxLeft)
			{
				_state = UPATT;
				index2 = nick[UPATT]->getMaxFrameX();
				count = 0;
			}
			else
			{
				_state = UPATT;
				index = 0;
				count = 0;
			}
		}
	}

	//ȭ��߻� �� ����
	if (_state == FIRE && index >= nick[FIRE]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (_state == FIRE && index2 <= 0 && _player.isFoxLeft)
	{
		_state = IDLE;
	}
	//�ɾ� ���� �� ����
	if (_state == SITATT && index >= nick[SITATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = SIT;

	}
	if (_state == SITATT && index2 <= 0 && _player.isFoxLeft)
	{
		_state = SIT;

	}
	//�������� �� ����
	if ((_state == JUMPATT || _state == FALL) && index >= nick[JUMPATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = FALL;

	}
	if ((_state == JUMPATT || _state == FALL) && index2 <= 0 && _player.isFoxLeft)
	{
		_state = FALL;

	}
	//��������2 �� ����
	if ((_state == JUMPATT2 || _state == FALL2) && index >= nick[JUMPATT2]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = FALL2;

	}
	if ((_state == JUMPATT2 || _state == FALL2) && index2 <= 0 && _player.isFoxLeft)
	{
		_state = FALL2;

	}
	//��ܺ��� �� ����
	if (_player.isUp && index >= nick[UPATT]->getMaxFrameX() && !_player.isFoxLeft)
	{
		_state = IDLE;
	}
	if (_player.isUp && index2 <= 0 && _player.isFoxLeft)
	{
		_state = IDLE;
	}
	//������ ������ falseó��
	if ((index <= nick[_state]->getMaxFrameX() || index2 >= 0) && _state != FIRE && _state != IDLE && _state != JUMP && _state != DOUBLEJUMP && _state != SIT && _state != RUN && _state != WEATHER && _state != FALL && _state != FALL2)
	{
		_player.isAtt = true;
	}
	else
	{
		_player.isAtt = false;
	}

	if (KEYMANAGER->isOnceKeyDown('S') && _state == IDLE)
	{
		if (!ang && _player.mana > 30)
		{
			ang = true;
		}
		else
		{
			ang = false;
		}
		if (_state != WEATHER)
		{
			if (_player.isFoxLeft)
			{
				_state = WEATHER;
				_cuticle->fire(_player.x, _player.y + 35, 100);
				index2 = nick[WEATHER]->getMaxFrameX();
				count = 0;
				_player.isChange = true;
			}
			else
			{
				_state = WEATHER;
				_cuticle->fire(_player.x, _player.y + 35, 100);
				index = 0;
				count = 0;
				_player.isChange = true;
			}
		}

		weatherIndex++;
		if (weatherIndex > 1)
		{
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

//ToDo : ī�޶�
void foxPlayer::camera()		//ī�޶� �����̴� �Լ�
{
	_camera.x = _player.x;
	_camera.y = _player.y;

	if (_camera.x - WINSIZEX / 2 < 0)
	{
		_camera.x = WINSIZEX / 2;
	}
	if (_camera.x + WINSIZEX / 2 > MAX_WIDTH)
	{
		_camera.x = MAX_WIDTH - WINSIZEX / 2;
	}
	if (_camera.y - WINSIZEY / 2 < 0)
	{
		_camera.y = WINSIZEY / 2;
	}
	if (_camera.y + WINSIZEY / 2 > MAX_HEIGHT)
	{
		_camera.y = MAX_HEIGHT - WINSIZEY / 2;
	}
}
//ToDo : �ȼ��浹
void foxPlayer::pixelCollision()		//�ȼ� �浹
{
	for (int i = _player.collisionRc.left + _player.speed; i >= _player.collisionRc.left; i--)
	{
		COLORREF color = GetPixel(_bpx->getMemDC(), i, _player.y + 30);
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
		COLORREF color = GetPixel(_bpx->getMemDC(), _player.x, i);
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
		COLORREF color = GetPixel(_bpx->getMemDC(), i, _player.y + 30);
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
		COLORREF color = GetPixel(_bpx->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255) || (r == 255 && g == 0 && b == 0))
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
//ToDo : ������ �浹
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

			if (IntersectRect(&tempRc, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getCollisionRc()) && _enemyManger->getEnemy()[i]->getState() != ENEMY_SPAWN && _state != HIT)
			{

			}
		}
	}
}

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
				_state = HIT;
				unDamage = 0;
			}
			//if(IntersectRect(&temp, &_player.collisionRc, &_enemyManger->getGhost()[i]->getAttRc()))
		}
	}

	//for(int i = 0; i < _enemyManger->)
}

void foxPlayer::removeArrow(int index)
{
	_arrow->removeArrow(index);
}

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
	if (_player.HP == 0)
	{
		_state = DEATH;
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
		if (_player.mana <= 0)ang = false;
	}
	else
	{
		if (_player.maxMana > _player.mana)_player.mana += 0.05f;
	}
	if (_player.HP > _player.MaxHp)_player.HP = _player.MaxHp;
	if (_player.HP < 0)_player.HP = 0;
	if (_player.maxMana < _player.mana)_player.mana = _player.maxMana;
	if (_player.maxMana > 216)_player.maxMana = 216;
}