Usage:
position2D* pos = new position2D; - Create a new component, In this case its Position 2D
pos->position.x = 100; - Setting data
world* level1 = new world; - creating a world
world* cWorld; - a pointer to current world. Not needed just can be useful but it will take up space in memory. 
sManager->addWorld(level1, level1ID); -- add the new world to the scenemanager
sManager->loadWorld(level1ID,cWorld); - Load world so its set as the current world. 
entity*& ent = level1->createEntity(); - Create a new entity in the world and store a reference here. Is not really required.
ent->addComponent(pos); - Adds a component to the entity.

ent->getComponentEX<position2D*>()->x = 100 - getting the component inside and then changing its x to 100. It returns NULLPTR if the component already exists in the entity.
so you may want to use this carefully.
You can also use getComponent<position2D*>(ID) which takes a ID if that is known and it returns the component.

To make a component you can do:

struct sprite : component
{
public:
inline void start(); - AS long as the start and update calls exist you can create any objects inside.
inline void update();
}
