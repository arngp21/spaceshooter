#include"BulletManager.h"
#include"../../gamesystem/GameManager.h"

BulletManager::BulletManager() {
	loadBullet = tnl::LoadCsv("csv/LoadBullet.csv");//csvからimageを取得
}

void BulletManager::CreateBullet(const int type, const tnl::Vector3 start_pos, bulletmove desc, std::shared_ptr<Object> parent) {
	imgname = loadBullet[type][0];
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(type, start_pos, desc, imgname, parent);
	bullets_.emplace_back(bullet);
	bullet->initialize();
}

void BulletManager::BulletErase() {
	{
		auto it = bullets_.begin();
		while (it != bullets_.end()) {
			if (!(*it)->is_alive_) {
				it = bullets_.erase(it);
				continue;
			}
			it++;
		}
	}
}

void BulletManager::Update(float deltatime) {
	BulletErase();
}
void BulletManager::Render(Camera* camera) {

}