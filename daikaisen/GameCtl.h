#pragma once
#include <array>

using KEY_ARRAY = std::array<char, 256>;

enum KEY_TYPE
{
	KEY_TYPE_NOW,
	KEY_TYPE_OLD,
	KEY_TYPE_MAX
};

class GameCtl
{
public:
	GameCtl();
	~GameCtl();
	bool UpDate(void);		// ｷｰの入力情報の更新をする

	const KEY_ARRAY& GetCtrl(KEY_TYPE type) const;		// 引数に対応したﾀｲﾐﾝｸﾞのｷｰ入力情報を取得する

private:
	KEY_ARRAY keyData;			// 現在のﾌﾚｰﾑのｷｰ入力情報を格納する
	KEY_ARRAY keyDataOld;		// 1ﾌﾚｰﾑ前のﾌﾚｰﾑのｷｰ入力情報を格納する
};

