#pragma once
#include<list>
#include<memory>
#include"../../gamesystem/Object.h"
#include"Bullet.h"
#include"BulletStatus.h"
#include"Bullet.h"

class BulletManager : public Object {
public:
	
	BulletManager();

	//bulletはstatuslistに登録
	std::list<std::shared_ptr<BulletStatus>> bullets_;

	std::string imgname;
	std::vector<std::vector<std::string>> loadBullet;

	void CreateBullet(const int type, const tnl::Vector3 start_pos, bulletmove desc);

	void BulletErase();//is_alive_がfalseになったらlistから削除

	void Update(float deltatime) override;
	void Render(Camera* camera) override;
};
