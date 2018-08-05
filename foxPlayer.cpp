#include "stdafx.h"
#include "foxPlayer.h"
#include "enemyManager.h"

#include "UI.h"


//ToDo : init
HRESULT foxPlayer::init(void)
{
	imageSetting();

	// �� UI ������ �ϲ�  ����
	_ui = new UI;
	_ui->init();


	_state = IDLE;
	
	_player.x = 100;
	_player.y = MAX_HEIGHT - 200;
	_player.speed = 30.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.arrowAngle = 0;
	_player.radian = 90;
	_player.isJump = _player.isLeft = _player.isUp = _player.isDown = _player.isRight = _player.isAtt = false;

	
	index = count = actionCount = actionIndex = jumpCount = hitCount = unDamage = 0;

	_player.maxMana = _player.mana  =  100;
	index = count = actionCount = actionIndex = jumpCount = 0;


	_arrow = new arrow;
	_arrow->init(3, 600);

	_camera.x = _player.x;
	_camera.y = _player.y;

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");
	return S_OK;
}

void foxPlayer::release(void)
{
	//_arrow->release();
	
}

//ToDo : update
void foxPlayer::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (!ang)ang = true;
		else ang = false;

	}

	if (ang)
	{
		_player.mana -= 0.1f;
		if (_player.mana <= 0)ang = false;
	}
	else
	{
		if (_player.maxMana > _player.mana)_player.mana += 0.3f;
	}
	this->keySetting();	  //Ű���� �Լ� ȣ��

	this->foxState();		//�÷��̾� ���� �Լ� ȣ��

	this->frameMove();		//������ �����̴� �Լ� ȣ��
	
	this->camera();			//ī�޶� �����̴� �Լ� ȣ��

	_player.rc = RectMakeCenter(_player.x, _player.y, nick[_state]->getFrameWidth(), nick[_state]->getFrameHeight());

	//�浹��Ʈ ��ġ ����   �Ϻ������ʾƤ̤� �ϴ� �ٸ��͵� ������ ���ΰ� �����Ҳ�!����
	this->collisionRcChange();

	//���� �浹
	if (KEYMANAGER->isToggleKey(VK_F3))
	{
		this->enemyCollision();
	}
	

	//_player.collisionRc = RectMakeCenter(_player.x , _player.y , _player.radian, 110);
	this->pixelCollision();		//�ȼ��浹 �Լ� ȣ��

	//���ݷ�Ʈ ����
	if (_player.isAtt && _state == JUMPATT)
	{
		attRc = RectMakeCenter(_player.x, _player.y, 200, 30);
		//attRc2 = RectMakeCenter(_player.x - _player.radian - 50, _player.y, 50, 50);
	}
	else if (_player.isAtt && _state == JUMPATT2)
	{
		//EllipseMakeCenter(getMemDC(), _player.x - _camera.rc.left, _player.y-_camera.rc.top, 300-_camera.rc.left, 300-_camera.rc.top);
		attRc = RectMakeCenter(_player.x, _player.y, 200, 200);
	}
	else if (_player.isAtt && _state == SITATT)
	{ 
		if (_player.isLeft)
		{
			attRc = RectMakeCenter(_player.x - 100, _player.y + 50, 100, 30);
		}
		else
		{
			attRc = RectMakeCenter(_player.x + 100, _player.y + 50, 100, 30);
		}
		
	}
	else
	{
		attRc = RectMakeCenter(-10000,-10000 , 300, 300);
	}

	_arrow->update();

	_ui->update();

	

	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//void foxPlayer::render(float FX, float FY)
//{
//	Rectangle(getMemDC(), _player.rc.left -FX , _player.rc.top -FY , _player.rc.right - FX, _player.rc.bottom - FY);
//}

//ToDo : render
void foxPlayer::render()
{
	Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
	nick[_state]->frameRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, nick[_state]->getFrameX(), nick[_state]->getFrameY());
	
	//Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
	//Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);

	if (KEYMANAGER->isToggleKey('O'))
	{
		Rectangle(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, _player.rc.right - _camera.rc.left, _player.rc.bottom - _camera.rc.top);
		//Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	}

	_ui->render();

	//_arrow->render();
	int temp;

	if (_player.isLeft)
	{
		temp = 1;
	}
	else 
	{
		temp = 0;
	}

	for (int i = 0; i < _arrow->getVArrow().size(); i++)
	{
		//Rectangle(getMemDC(), _arrow->getArrow()[i].rc.left - _camera.rc.left, _arrow->getArrow()[i].rc.top - _camera.rc.top, _arrow->getArrow()[i].rc.right - _camera.rc.left, _arrow->getArrow()[i].rc.bottom - _camera.rc.top);
		_arrow->getVArrow()[i].arrowImage->frameRender(getMemDC(), _arrow->getVArrow()[i].rc.left - _camera.rc.left, _arrow->getVArrow()[i].rc.top - _camera.rc.top, 0, temp);
	}
	
	for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
	{
		Rectangle(getMemDC(), _enemyManger->getEnemy()[i]->getRc().left - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().top - _camera.rc.top, _enemyManger->getEnemy()[i]->getRc().right - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().bottom - _camera.rc.top);
	}
	char str[128];
	sprintf(str, "�߷� : %f, ����ī���� : %d, ���� : %d", _player.gravity, jumpCount,0);
	TextOut(getMemDC(), 100, 600, str,strlen(str));
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
}
//ToDo : ������ ������
void foxPlayer::frameMove()
{
	if (_state == FIRE || _state == SITATT || _state == UPATT || _state == JUMPATT || _state == JUMPATT2 || _state == DOWNATT)
	{
		++actionCount;
		if (_player.isLeft)
		{
			nick[_state]->setFrameY(1);
			if (actionCount % 2 == 0)
			{
				actionIndex--;
				if (actionIndex < 0)
				{
					actionIndex = nick[_state]->getMaxFrameX();
				}
				nick[_state]->setFrameX(actionIndex);
			}
		}
		else
		{
			nick[_state]->setFrameY(0);
			if (actionCount % 2 == 0)
			{
				actionIndex++;
				if (actionIndex > nick[_state]->getMaxFrameX())
				{
					actionIndex = 0;
				}
				nick[_state]->setFrameX(actionIndex);
			}
		}
	}
	else              
	{
		++count;
		if (_player.isLeft)
		{
			nick[_state]->setFrameY(1);
			if (count % 8 == 0)
			{
				index--;
				if (index < 0)
				{
					index = nick[_state]->getMaxFrameX();
				}
				nick[_state]->setFrameX(index);
			}
		}
		else
		{
			nick[_state]->setFrameY(0);
			if (count % 8 == 0)
			{
				index++;
				if (index > nick[_state]->getMaxFrameX())
				{
					index = 0;
				}
				nick[_state]->setFrameX(index);
			}
		}
	}
	
}
//�浹 ��Ʈ!
void foxPlayer::collisionRcChange()
{
	if (_player.isRight && !_player.isLeft)
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 35, _player.radian, 110);
	}
	else if (_player.isLeft && !_player.isRight)
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 35, _player.radian, 110);
	}
	else if (!_player.isLeft && _player.isDown)		//���������θ� �������� ��Ʈ �ٲ�̤�
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 53, _player.radian, 75);
	}
	else if (!_player.isRight && _player.isLeft &&_player.isDown)		//�̰� ���� �ɴ°ǵ� �� �ذ��غ�����
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 53, _player.radian, 75);
	}
	else if (_player.isJump)
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 10, _player.radian, 110);
	}
	else if (!_player.isRight && _player.isJump)
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 10, _player.radian, 110);
	}
	else
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 35, _player.radian, 110);
	}
}
//ToDo : ���� ����
void foxPlayer::foxState()
{
	if (_state == IDLE)
	{
		_player.gravity = 0.f;
		jumpCount = 0;
		unDamage++;
		_player.isUp = _player.isDown = false;
	
	}
	if (_state == RUN)
	{
		jumpCount = 0;
		if (_player.isLeft)
		{
			_player.x -= _player.speed / 3;
		}
		else
		{
			_player.x += _player.speed / 3;
		}
	}
	if (_state == JUMP || _state == DOUBLEJUMP)
	{
		_player.gravity += 0.7f;
		_player.x += cosf(_player.angle)*_player.speed;
		_player.y += -sinf(_player.angle)*_player.speed + _player.gravity;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.isLeft = true;
			_player.x -= _player.speed / 3;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.isLeft = false;
			_player.x += _player.speed / 3;
		}
		if (-sinf(_player.angle)*_player.speed + _player.gravity > 0)
		{
			_state = FALL;
		}
		/*else if (_state == DOUBLEJUMP && -sinf(_player.angle)*_player.speed + _player.gravity > 0)
		{
			_state = FALL2;
		}*/
	}
	if (_state == FALL || _state == FALL2)
	{
		_player.y += 9.f;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.isLeft = true;
			_player.x -= _player.speed / 3;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.isLeft = false;
			_player.x += _player.speed / 3;
		}
	}
	
	if (_state == FIRE)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[FIRE]->getMaxFrameX();
				_state = IDLE;
			}
		}
		else
		{
			if (actionIndex >= nick[FIRE]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = IDLE;
			}
		}

	}
	if (_state == UPATT || _state == SITATT)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[_state]->getMaxFrameX();
				_state = IDLE;
			}
		}
		else
		{
			if (actionIndex >= nick[_state]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = IDLE;
			}
		}
	}
	if (_state == JUMPATT || _state == JUMPATT2)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[_state]->getMaxFrameX();
				_state = FALL;
			}
		}
		else 
		{
			if (actionIndex >= nick[_state]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = FALL;
			}
		}
	}
	
	if (_state == DOWNATT)
	{

	}
	if (_state == HIT)
	{
		hitCount++;
		if (hitCount > 25)
		{
			_state = IDLE;
			hitCount = 0;
		}
	}
	
}

//ToDo : Ű ����
void foxPlayer::keySetting()
{
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.isRight = true;
		_player.isLeft = false;
		_player.arrowAngle = 0;
		_state = RUN;
	}
	if (_player.isJump == false && _state != HIT && KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.isRight = false;
		_state = IDLE;
	}
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.isLeft = true;
		_player.arrowAngle = PI;
		_state = RUN;
	}
	if (_player.isJump == false && _state != HIT && KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = IDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_player.isUp = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_player.isUp = false;
	}
	if (_player.isJump == false && KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.isDown = true;
		_state = SIT;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_state = IDLE;
	}
	if (jumpCount < 2)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			++jumpCount;
			_player.isJump = true;
			_state = JUMP;
			if (jumpCount >=2)
			{
				//jumpCount = 0;
				_player.gravity = 0.f;
				_state = DOUBLEJUMP;
			}
		}
	}
	if (_state != JUMPATT && _state != JUMPATT2 && KEYMANAGER->isOnceKeyDown('A'))
	{	
		if (_state == SIT)
		{
			_player.isAtt = true;
			_state = SITATT;
		}
		else if (_state == JUMP)
		{
			_player.isAtt = true;
			_state = JUMPATT;
		}
		else if (_state == DOUBLEJUMP)
		{
			_player.isAtt = true;
			_state = JUMPATT2;

		}
		else if (_player.isUp)
		{
			_state = UPATT;
		}
		else if (_state == IDLE)
		{
			_state = FIRE;
			_arrow->fire(_player.x, _player.y + 30, _player.arrowAngle);
		}
		
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_player.isAtt = false;
	}
	/*if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_state = WEATHER1;
	}*/
	
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
	//�÷��̾� ��Ʈ bottom �ȼ��浹
	for (int i = _player.collisionRc.bottom - _player.speed; i < _player.collisionRc.bottom +20; ++i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255 && (_state == FALL || _state == FALL2 ||_state == HIT ||!_player.isJump))
		{
			
			_player.y = i - nick[_state]->getFrameHeight() / 2;
			_player.gravity = 0.f;
			_player.isJump = false;
			//_state = IDLE;
			if (_state == FALL)
			{
				_state = IDLE;
			}
			break; 
		}
		else //if (!(r == 0 && g == 255 && b == 255) && !_player.isJump)
		{
			_player.y += 0.2f;
		}
	}

	//�÷��̾� ��Ʈ right �ȼ� �浹
	for (int i = _player.collisionRc.right - _player.speed; i < _player.collisionRc.right; i++)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i - (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isRight = false;
			
			break;
		}

	}

	//�÷��̾� ��Ʈ left �ȼ� �浹  
	for (int i = _player.collisionRc.left + _player.speed; i > _player.collisionRc.left; --i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i + (_player.collisionRc.right - _player.collisionRc.left) / 2;
			//_player.isLeft = false;			//���� ��������
			break;
		}
	}

	//for (int i = _player.rc.top; i < _player.rc.bottom; i += (_player.rc.bottom - _player.rc.top) / 2)
	//{
	//	for (int j = _player.rc.right; j < _player.rc.right; ++j)
	//	{
	//		COLORREF color = GetPixel(_bfx->getMemDC(), j, i);
	//
	//		int r = GetRValue(color);
	//		int g = GetGValue(color);
	//		int b = GetBValue(color);
	//
	//		if (r == 0 && g == 255 && b == 255 )
	//		{
	//			_player.x = j - _player.radian;
	//			_player.isJump = false;
	//			break;
	//		}
	//	}
	//}

	//for (int i = _player.rc.top-10; i < _player.rc.top; ++i)
	//{
	//	COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);
	//
	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);
	//
	//	if (r == 0 && g == 255 && b == 255)
	//	{
	//		_player.y = i + _player.radian;
	//		
	//		break;
	//	}
	//	else
	//	{
	//		//			_player.y += 0.2f;
	//	}
	//}
}

void foxPlayer::enemyCollision()
{
	for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
	{
		RECT tempRc;
		if (unDamage > 15)
		{
			if (IntersectRect(&tempRc, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getRc()) && _enemyManger->getEnemy()[i]->getState() != ENEMY_SPAWN && _state != HIT)
			{
				int width = (tempRc.right - tempRc.left) + 50;
				int height = (tempRc.bottom - tempRc.top) + 50;

				if (_player.x < _enemyManger->getEnemy()[i]->getRc().left)
				{
					_player.x -= width;
					_player.y -= height;
				}
				else if (_player.x > _enemyManger->getEnemy()[i]->getRc().right)
				{
					_player.x += width;
					_player.y += height;
				}
				else if (_player.y < _enemyManger->getEnemy()[i]->getRc().top)
				{
					_player.x -= width;
					_player.y -= height;
				}
				else if (_player.y > _enemyManger->getEnemy()[i]->getRc().bottom)
				{
					_player.x += width;
					_player.y += height;
				}
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

