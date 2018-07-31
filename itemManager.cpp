#include "stdafx.h"
#include "itemManager.h"
#include "player.h"
#include "enemyManager.h"

HRESULT itemManager::init(void)
{

	this->setItem();

	return S_OK;
}

void itemManager::release(void)
{
}

void itemManager::update(void)
{
	//��Ʈ ū��
	_viHealthLarge = _vHealthLarge.begin();
	for (_viHealthLarge; _viHealthLarge != _vHealthLarge.end(); _viHealthLarge++)
	{
		(*_viHealthLarge)->update();
	}
	//��Ʈ �߰�
	_viHealthBig = _vHealthBig.begin();
	for (_viHealthBig; _viHealthBig != _vHealthBig.end(); _viHealthBig++)
	{
		(*_viHealthBig)->update();
	}
	//���� �߰�(��� ū�� ��)
	_viManaBig = _vManaBig.begin();
	for (_viManaBig; _viManaBig != _vManaBig.end(); _viManaBig++)
	{
		(*_viManaBig)->update();
	}
	//���� ������
	_viManaSmall = _vManaSmall.begin();
	for (_viManaSmall; _viManaSmall != _vManaSmall.end(); _viManaSmall++)
	{
		(*_viManaSmall)->update();
	}

	// ���� //

	//���
	_viCoinGold = _vCoinGold.begin();
	for (_viCoinGold; _viCoinGold != _vCoinGold.end(); _viCoinGold++)
	{
		(*_viCoinGold)->update();
	}
	
	//�ǹ�
	_viCoinSilver = _vCoinSilver.begin();
	for (_viCoinSilver; _viCoinSilver != _vCoinSilver.end(); _viCoinSilver++)
	{
		(*_viCoinSilver)->update();
	}
	
	//�����
	_viCoinBronze = _vCoinBronze.begin();
	for (_viCoinBronze; _viCoinBronze != _vCoinBronze.end(); _viCoinBronze++)
	{
		(*_viCoinBronze)->update();
	}


	
	this->dropCoin();
	//this->dropCoin();

	//this->pixelCollision(_vCoinBronze);
	//this->pixelCollision(_vCoinSilver);
	//this->pixelCollision(_vCoinGold);

}

void itemManager::render(float FX, float FY)
{
	//��Ʈ ū��
	_viHealthLarge = _vHealthLarge.begin();
	for (_viHealthLarge; _viHealthLarge != _vHealthLarge.end(); _viHealthLarge++)
	{
		(*_viHealthLarge)->render(FX, FY);
	}

	//��Ʈ �߰�
	_viHealthBig = _vHealthBig.begin();
	for (_viHealthBig; _viHealthBig != _vHealthBig.end(); _viHealthBig++)
	{
		(*_viHealthBig)->render(FX, FY);
	}

	//���� �߰�(��� ū�� ��)
	_viManaBig = _vManaBig.begin();
	for (_viManaBig; _viManaBig != _vManaBig.end(); _viManaBig++)
	{
		(*_viManaBig)->render(FX, FY);
	}

	//���� ������
	_viManaSmall = _vManaSmall.begin();
	for (_viManaSmall; _viManaSmall != _vManaSmall.end(); _viManaSmall++)
	{
		(*_viManaSmall)->render(FX, FY);
	}

	// ���� //

	//���
	_viCoinGold = _vCoinGold.begin();
	for (_viCoinGold; _viCoinGold != _vCoinGold.end(); _viCoinGold++)
	{
		(*_viCoinGold)->render(FX, FY);
	}
	
	//�ǹ�
	_viCoinSilver = _vCoinSilver.begin();
	for (_viCoinSilver; _viCoinSilver != _vCoinSilver.end(); _viCoinSilver++)
	{
		(*_viCoinSilver)->render(FX, FY);
	}
	
	//�����
	_viCoinBronze = _vCoinBronze.begin();
	for (_viCoinBronze; _viCoinBronze != _vCoinBronze.end(); _viCoinBronze++)
	{
		(*_viCoinBronze)->render(FX, FY);
	}


}



void itemManager::setItem()
{
	//��Ʈū��
	for (int i = 0; i < 1; ++i)
	{
		healthLarge* _healthLarge = new healthLarge;
		_healthLarge->init("�ｺ����", PointMake(2320, 2400 + i * 100), i);
		_vHealthLarge.push_back(_healthLarge);
	}
	for (int i = 0; i < 1; ++i)
	{
		healthLarge* _healthLarge = new healthLarge;
		_healthLarge->init("�ｺ����", PointMake(4444, 2300 + i * 100), i);
		_vHealthLarge.push_back(_healthLarge);
	}
	for (int i = 0; i < 1; ++i)
	{
		healthLarge* _healthLarge = new healthLarge;
		_healthLarge->init("�ｺ����", PointMake(7500, 2200 + i * 100), i);
		_vHealthLarge.push_back(_healthLarge);
	}
	for (int i = 0; i < 2; ++i)
	{
		healthLarge* _healthLarge = new healthLarge;
		_healthLarge->init("�ｺ����", PointMake(9850, 1650 + i * 100), i);
		_vHealthLarge.push_back(_healthLarge);
	}
	for (int i = 0; i < 2; ++i)
	{
		healthLarge* _healthLarge = new healthLarge;
		_healthLarge->init("�ｺ����", PointMake(15850, 1850 + i * 100), i);
		_vHealthLarge.push_back(_healthLarge);
	}

	//�ｺ��

	for (int i = 0; i < 3; ++i)
	{
		healthBig* _healthBig = new healthBig;
		_healthBig->init("�ｺ��", PointMake(3400 + i * 100, 2150 ), i);
		_vHealthBig.push_back(_healthBig);
	}
	for (int i = 0; i < 2; ++i)
	{
		healthBig* _healthBig = new healthBig;
		_healthBig->init("�ｺ��", PointMake(9280 + i * 100, 2650), i);
		_vHealthBig.push_back(_healthBig);
	}






	for (int i = 0; i < 4; ++i)
	{
		manaBig* _manaBig = new manaBig;
		_manaBig->init("������", PointMake(750, 2000 + i * 100), i);
		_vManaBig.push_back(_manaBig);
	}

	for (int i = 0; i < 4; ++i)
	{
		manaSmall* _manaSmall = new manaSmall;
		_manaSmall->init("��������", PointMake(850, 2000 + i * 100), i);
		_vManaSmall.push_back(_manaSmall);
	}

	//����//

	////��ȭ
	//for (int i = 0; i < 1; ++i)
	//{
	//	goldCoin* _goldCoin = new goldCoin;
	//	_goldCoin->init("��ȭ", PointMake(1300, 2000 + i * 30), i, PI / 2);
	//	_vCoinGold.push_back(_goldCoin);
	//}
	////��ȭ
	//for (int i = 0; i < 1; ++i)
	//{
	//	silverCoin* _silverCoin = new silverCoin;
	//	_silverCoin->init("��ȭ", PointMake(1300, 2000 + i * 30), i, PI * 73 / 150);
	//	_vCoinSilver.push_back(_silverCoin);
	//}
	////��ȭ
	//
	//for (int i = 0; i < 1; ++i)
	//{
	//	bronzeCoin* _bronzeCoin = new bronzeCoin;
	//	_bronzeCoin->init("��ȭ", PointMake(1300, 2000 + i * 30), i, PI * 77 / 150);
	//	_vCoinBronze.push_back(_bronzeCoin);
	//}

}

void itemManager::dropCoin()
{
	for (int i = 0; i < gold; ++i)
	{
		goldCoin* _goldCoin = new goldCoin;
		_goldCoin->init("��ȭ", PointMake(enemyX, enemyY), i, PI / 2 + i*0.03);
		_vCoinGold.push_back(_goldCoin);
	}
	//��ȭ
	for (int i = 0; i < silver; ++i)
	{
		silverCoin* _silverCoin = new silverCoin;
		_silverCoin->init("��ȭ", PointMake(enemyX, enemyY), i, PI * 73 / 150);
		_vCoinSilver.push_back(_silverCoin);
	}
	//��ȭ
	
	for (int i = 0; i < bronze; ++i)
	{
		bronzeCoin* _bronzeCoin = new bronzeCoin;
		_bronzeCoin->init("��ȭ", PointMake(enemyX, enemyY), i, PI * 77 / 150);
		_vCoinBronze.push_back(_bronzeCoin);
	}

	gold = 0;
	silver = 0;
	bronze = 0;
}

//void itemManager::dropCoin()
//{
//	for (int i = 0; i < _eMG->getVBug().size(); ++i)
//	{
//		if (_eMG->getVBug()[i]->getIsDrop())
//		{
//			//��ȭ
//			for (int i = 0; i < _eMG->getVBug()[i]->getGold(); ++i)
//			{
//				goldCoin* _goldCoin = new goldCoin;
//				_goldCoin->init("��ȭ", PointMake(_eMG->getVBug()[i]->getX(), _eMG->getVBug()[i]->getY()), i, PI / 2);
//				_vCoinGold.push_back(_goldCoin);
//			}
//			//��ȭ
//			for (int i = 0; i < _eMG->getVBug()[i]->getSilver(); ++i)
//			{
//				silverCoin* _silverCoin = new silverCoin;
//				_silverCoin->init("��ȭ", PointMake(_eMG->getVBug()[i]->getX(), _eMG->getVBug()[i]->getY()), i, PI * 73 / 150);
//				_vCoinSilver.push_back(_silverCoin);
//			}
//			//��ȭ	
//			for (int i = 0; i < _eMG->getVBug()[i]->getBronze(); ++i)
//			{
//				bronzeCoin* _bronzeCoin = new bronzeCoin;
//				_bronzeCoin->init("��ȭ", PointMake(_eMG->getVBug()[i]->getX(), _eMG->getVBug()[i]->getY()), i, PI * 77 / 150);
//				_vCoinBronze.push_back(_bronzeCoin);
//			}
//		}
//	}
//
//
//}

//void itemManager::pixelCollision(vector<item*> vCoin)
//{
//	vector<item*> _tmp;
//
//	_tmp = vCoin;
//
//	for (int k = 0; k < 1; ++k)
//	{
//		for (int i = _tmp[k]->getRect().left; i < _tmp[k]->getRect().right; i += 2)
//		{
//			for (int j = _tmp[k]->getRect().bottom - 10; j <_tmp[k]->getRect().bottom; j += _tmp[k]->getItemImage()->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
//			{
//				COLORREF color = GetPixel(IMAGEMANAGER->findImage("��������1 �ȼ�")->getMemDC(), i, j);
//				int r = GetRValue(color);
//				int g = GetGValue(color);
//				int b = GetBValue(color);
//
//				if ((r == 0 && g == 255 && b == 255))
//				{
//					_tmp[k]->setY(j - _tmp[k]->getItemImage()->getFrameHeight() / 2);
//					_tmp[k]->setGravity(0);
//
//					if (_tmp[k]->getSpeed() > 0)
//						_tmp[k]->setSpeed(_tmp[k]->getSpeed() - 0.02f);
//
//					else
//						_tmp[k]->setSpeed(0);
//
//
//					break;
//				}
//			}
//		}
//	}
//
//	/*
//	for (int k = 0; k < 4; ++k)
//	{
//	for (int i = _vCoinGold[k]->getRect().left; i < _vCoinGold[k]->getRect().right; i += 2)
//	{
//	for (int j = _vCoinGold[k]->getRect().bottom - 10; j <_vCoinGold[k]->getRect().bottom; j += _vCoinGold[k]->getItemImage()->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
//	{
//	COLORREF color = GetPixel(_player->getTestBgImage()->getMemDC(), i, j);
//	int r = GetRValue(color);
//	int g = GetGValue(color);
//	int b = GetBValue(color);
//
//	if ((r == 0 && g == 255 && b == 255))
//	{
//	_vCoinGold[k]->setY(j - _vCoinGold[k]->getItemImage()->getFrameHeight() / 2);           // = j - _image[E_MOVE]->getFrameHeight();
//	_vCoinGold[k]->setGravity(0);
//	_vCoinGold[k]->setSpeed(_vCoinGold[k]->getSpeed() - 0.5f);
//	//_vPlantFrog[k]->setIsJump(false);
//	break;
//	}
//	}
//	}
//	}
//
//	for (int k = 0; k < 4; ++k)
//	{
//	for (int i = _vCoinSilver[k]->getRect().left; i < _vCoinSilver[k]->getRect().right; i += 2)
//	{
//	for (int j = _vCoinSilver[k]->getRect().bottom - 10; j <_vCoinSilver[k]->getRect().bottom; j += _vCoinSilver[k]->getItemImage()->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
//	{
//	COLORREF color = GetPixel(_player->getTestBgImage()->getMemDC(), i, j);
//	int r = GetRValue(color);
//	int g = GetGValue(color);
//	int b = GetBValue(color);
//
//	if ((r == 0 && g == 255 && b == 255))
//	{
//	_vCoinSilver[k]->setY(j - _vCoinSilver[k]->getItemImage()->getFrameHeight() / 2);           // = j - _image[E_MOVE]->getFrameHeight();
//	_vCoinSilver[k]->setGravity(0);
//	_vCoinSilver[k]->setSpeed(_vCoinSilver[k]->getSpeed() - 0.5f);
//
//	//_vPlantFrog[k]->setIsJump(false);
//	break;
//	}
//	}
//	}
//	}
//
//	for (int k = 0; k < 4; ++k)
//	{
//	for (int i = _vCoinBronze[k]->getRect().left; i < _vCoinBronze[k]->getRect().right; i += 2)
//	{
//	for (int j = _vCoinBronze[k]->getRect().bottom - 10; j <_vCoinBronze[k]->getRect().bottom; j += _vCoinBronze[k]->getItemImage()->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
//	{
//	COLORREF color = GetPixel(_player->getTestBgImage()->getMemDC(), i, j);
//	int r = GetRValue(color);
//	int g = GetGValue(color);
//	int b = GetBValue(color);
//
//	if ((r == 0 && g == 255 && b == 255))
//	{
//	_vCoinBronze[k]->setY(j - _vCoinBronze[k]->getItemImage()->getFrameHeight() / 2);           // = j - _image[E_MOVE]->getFrameHeight();
//	_vCoinBronze[k]->setGravity(0);
//	_vCoinBronze[k]->setSpeed(_vCoinBronze[k]->getSpeed() - 0.5f);
//
//	//_vPlantFrog[k]->setIsJump(false);
//	break;
//	}
//	}
//	}
//	}
//	*/ //  ������ �ʿ��� ��,
//
//
//}
//