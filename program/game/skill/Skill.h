#pragma once
#include"../gamesystem/Object.h"

class SkillState : public Object {
public:
};

class Skill : public SkillState {
public:
	Skill(const tnl::Vector3 start_pos,const int type);
	//画面内にいる敵オブジェクトを消す
	void OnDisplayDead();

	int hp_ = 4;
	int radius_ = 15;
	int type_ = 0;

	bool b_option_create_bullet_ = false;

private:

	tnl::Vector3 hoz_distancemoved_;

	float bom_speed_ = 6;
	int img_bom[3];
	int img_explosion[16];

	double hoz_x[40];
	double hoz_y[40];
	int img_option[2];
	const int OPTION_POS = 30;//(仮)

	int img_barrier_ = 0;
	int img_barrier2_ = 0;
	const int barrier_hp_ = 2;

	//アニメーション
	int anime_flame_ = 0;
	int time_count_ = 0;

	//-------------------動き-------------------------------
	//関数ポインタ(fanctionでラップ)引数はクラスに
	std::function<void(Skill*,float deltatime)> move;
	//ボムの動き
	void Bommove(float deltatime);
	//バリアの動き
	void Barriermove(float deltatime);
	//オプションの動き(後ろからついてくる)
	void Optionmove(float deltatime);
	//オプションが出す弾の処理
	void OptionBulletShot();

	//------------------描画-------------------------------
	std::function<void(Skill*, Camera* camera)> draw;
	void Bomdraw(Camera* camera);
	void Barrierdraw(Camera* camera);
	void Optiondraw(Camera* camera);

	void Update(float deltatime) override;
	void Render(Camera* camera) override;

};