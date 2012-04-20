#pragma once
#include "../GameObject.h"
#include "Elevator.h"

namespace OT {
	namespace Item {
		class ElevatorCar : public GameObject, public sf::Drawable
		{
		public:
			Elevator * const elevator;
			ElevatorCar(Elevator * elevator) : GameObject(elevator->game), elevator(elevator) { altitude = elevator->position.y; init(); }
			
			virtual void init();
			
			double altitude;
			void setAltitude(double a);
			void reposition();
			
			Sprite sprite;
			void updateSprite();
			
			Item::People passengers;
			
			virtual void Render(sf::RenderTarget & target) const;
			
			virtual void encodeXML(tinyxml2::XMLPrinter& xml);
			virtual void decodeXML(tinyxml2::XMLElement& xml);
		};
	}
}