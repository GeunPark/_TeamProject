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
	bool _isNotSelect;
	int _selectCount;
	int _selectNumber;
	int _sellMagicNum;
	int upgnum[3];
	int magicNum[3];
	float _x, _y;
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


	void setPlayerManager(foxPlayer* player);


	shop() {}
	~shop() {}
};

