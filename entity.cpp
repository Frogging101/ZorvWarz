#include "entity.h" 

int idCounter = 0;

/**
  * Super constructor for Entities that assignes them an ID
  */
Entity::Entity(){
	ID = idCounter;
	idCounter++;
}

/*
EntityManager::~EntityManager(){
	//Delete all alocated entities from the entity list
	for(int i=0;i<entityList.size();i++){
		delete entityList[i];
	}
}*/ // Don't think I acutally need to delete all entities if I pass them by &entity to the list

/**
  * Loop through all entities, update them if they are ready to update
  * Kill the entities if they are not alive anymore
  */
void EntityManager::updateEntities(int framecount){
	//Loop through all entities
	for(int i=0;i<entityList.size();i++){
		//Call entities update funciton only if it is ready to update
		if(entityList[i]->readyToUpdate){
			entityList[i]->update(framecount);
			//if entity is dead kill it! possibly with fire
			if(entityList[i]->alive == false){
				removeByID(entityList[i]->ID);
			}
		}
	}
}

/**
  * Loop through all entities, and if they are collidable check if they had collided
  */
void EntityManager::collideEntities(){
}

/**
  * Loop Through all entities and draw them if they are drawable
  */
void EntityManager::drawEntities(sf::RenderWindow *screen){
	for(int i=0;i<entityList.size();i++){
		if(entityList[i]->drawable){
			entityList[i]->draw(screen);
		}
	}
}

/**
  * Loop through all entities and if the entitiy has the same ID delete it
  */
void EntityManager::removeByID(int ID){
	for(int i=0;i<entityList.size();i++){
		if(entityList[i]->ID == ID){
			//delete entityList[i];
			entityList.erase(entityList.begin() + i);
			break;
		}
	}
}