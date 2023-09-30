#pragma once
#include <iostream>
#include <string>
#include <map>

class component
{
public:
	virtual ~component() { }
	virtual void update() = 0;
	virtual void start() = 0;
	int ID = -1;
};


class entity // each component has a unique ID
{
private:
	std::map<int, component*> componentList; // first = key , second = value 
	int ID = -1;
public:

	inline int getEID() { return this->ID; }
	inline int setEID(int Id) { this->ID = Id; return ID; }
	std::map<int, component*> getComponentList() { return this->componentList; }

	template<typename T>
	T getComponent(int ID)
	{

		for (auto var1 : this->componentList) // iterate through comp list if ID matches then do this
		{
			if (var1.first == ID)
				return dynamic_cast<T>(var1.second);
		}

	}

	template<typename T>
	T getComponentEX() // get component via class
	{
		for (auto component : componentList)
		{

			std::string n1 = typeid(T).name();
			n1.erase(n1.end() - 10, n1.end());
			std::string n2 = typeid(*component.second).name();
			if (n1 == n2) {
				return dynamic_cast<T>(component.second);
				break;
			}
		}
		std::cout << "Error comp does not exist" << std::endl;
		return nullptr;
	}

	inline int addComponent(component* pointerToBeAdded)
	{
		if (componentList.size() > 0)
		{
			for (auto vars : componentList)
			{
				if (vars.first == pointerToBeAdded->ID)
				{
					std::cout << "Component already exists inside entity" << std::endl;
					return -1;
				}
			}
		}
		if (pointerToBeAdded->ID == -1)
			pointerToBeAdded->ID = (int)componentList.size() + 1;

		componentList.emplace(pointerToBeAdded->ID, pointerToBeAdded);
		return pointerToBeAdded->ID;


	}

	void update();
	void start();
};