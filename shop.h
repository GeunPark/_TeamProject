#pragma once
#include "gameNode.h"
#define MAXHPITEM 5
#define MAXMANAITEM 3
#define MAXGREENARROW 1

#define MAXMAGICITEM 3

class foxPlayer;

enum kindShop
{
	UPGRADE,
	MAGIC
};



struct tagShopBox
{
	float _x, _y;
	RECT _rc;
	image * _img;
	int _count;
	int _index;
	int price;
	int _sellCount;
	int _maxNum;
};


class shop : public gameNode
{
private:

	tagShopBox _backImage;
	tagShopBox _Item[3];
	tagShopBox _ItemInfo[3];
	tagShopBox _selectOj;
	tagShopBox _priceNum[4];

	foxPlayer * _player;

	int num[4];
	kindShop _kindShop;
	bool _isSelect;
	bool _isNotSelect[2];
	int _selectCount;
	int _selectNumber;
	int _sellMagicNum;
	int upgnum[3];
	int magicNum[3];
	int upgMaxNum[3];
	int magicMaxNum[3];

	bool frameNumChk[4];
	
	float _x, _y;

	bool _isOpen = false;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();

	void ItemList();
	void frameImageMove();
	void selectObjectInIt();
	void selectObject();
	void ItemSell();

	void setKindShop(kindShop kd) { _kindShop = kd; }


	void setPlayerManager(foxPlayer* player);

	bool getOpen() { return _isOpen; }
	void setOpen(bool isOpen) { _isOpen = isOpen; }

	shop() {}
	~shop() {}
};

