#pragma once
#pragma once
#include "world.h"
class sceneManager
{
private:
	std::map<int, world*> sceneList;
	world* currentWorld;
public:

	~sceneManager() {
		for (auto scenes : sceneList)
			delete scenes.second;
		sceneList.clear();
		delete currentWorld;
		delete this;
	}

	inline bool addWorld(world* scene, int& id)
	{
		for (auto scenes : sceneList)
		{
			if (scenes.second == scene)
			{
				std::cout << "scene already exists in sceneList" << std::endl;
				return false;
			}
		}
		if (scene->getID() == -1)
		{

			id = scene->setID((sceneList.size() + 1));
			this->sceneList.emplace(scene->getID(), scene);
		}
	}

	inline bool loadWorld(int ID, world*& loadedWorld)
	{
		for (auto scene : sceneList)
		{
			if (scene.first == ID && currentWorld != scene.second)
			{
				loadedWorld = scene.second;
				this->currentWorld = scene.second;
				return true;
				break;
			}
			else {
				if (currentWorld == scene.second)
					std::cout << "world is already loaded!" << std::endl;
			}
		}
		return false;
	}

	inline void updateCurrent()
	{
		if (currentWorld != NULL)
			currentWorld->update();
	}

	inline void startCurrent()
	{
		if (currentWorld != NULL)
			currentWorld->start();
	}
};