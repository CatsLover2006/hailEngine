#include <string>
#include <cstdint>
#include "hailEngine.hpp"

namespace hailEngine {
	LineList::LineList(LineList * prev, Line * self) {
		this->self = self;
		prev->prev = this;
	}
	
	void LineList::remove() {
		prev->next = next; // Update reference
		next->prev = prev; // Update reference
		delete self; // Clear object memory
		delete this; // Suicide after memory clean
	}

	LineList * LineList::getLastInList() {
		if (next == NULL) return this;
		return next->getLastInList();
	}

	Line::Line(Vector2 * point1, Vector2 * point2) {
		this->point1 = point1;
		this->point2 = point2;
	}

	Vector2 * Line::topLeft() {
		double x, y;
		if (point1->x > point2->x) x = point1->x;
		else x = point2->x;
		if (point1->y > point2->y) y = point1->y;
		else y = point2->y;
		return new Vector2(x, y);
	}

	Vector2 * Line::bottomRight() {
		double x, y;
		if (point1->x < point2->x) x = point1->x;
		else x = point2->x;
		if (point1->y < point2->y) y = point1->y;
		else y = point2->y;
		return new Vector2(x, y);
	}

	bool Line::colliding (Line * other) {
		double uA = (((other->point2->x)-(other->point1->x))*((this->point1->y)-(other->point1->y)) -
					((other->point2->y)-(other->point1->y))*((this->point1->x)-(other->point1->x))) /
					(((other->point2->y)-(other->point1->y))*((this->point2->x)-(this->point1->x)) - 
					((other->point2->x)-(other->point1->x))*((this->point2->y)-(this->point1->y)));
	  	double uB = (((this->point2->x)-(this->point1->x))*((this->point1->y)-(other->point1->y)) - 
	  				((this->point2->y)-(this->point1->y))*((this->point1->x)-(other->point1->x))) / 
	  				(((other->point2->y)-(other->point1->y))*((this->point2->x)-(this->point1->x)) - 
	  				((other->point2->x)-(other->point1->x))*((this->point2->y)-(this->point1->y)));
		return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1); 
	}
}