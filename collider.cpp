#include <string>
#include <cstdint>
#include "hailEngine.hpp"

namespace hailEngine {
	ColliderList::ColliderList(ColliderList * prev, Collider * self) {
		this->self = self;
		prev->prev = this;
	}

	void ColliderList::remove() {
		prev->next = next; // Update reference
		next->prev = prev; // Update reference
		delete self; // Clear object memory
		delete this; // Suicide after memory clean
	}

	ColliderList * ColliderList::getLastInList() {
		if (next == NULL) return this;
		return next->getLastInList();
	}

	Collider::Collider(Vector2 * pos) {
		setLocation(pos);
	}

	void Collider::setLocation(Vector2 * pos) {
		this->pos = pos;
	}

	bool Collider::colliding(Collider * other) {
		Vector2 * temp1;
		Vector2 * temp2;
		temp1 = topLeft();
		temp2 = other->bottomRight();
		if (temp2->y > temp1->y) goto exit;
		if (temp2->x > temp1->x) goto exit;
		delete temp1;
		delete temp2;
		temp1 = bottomRight();
		temp2 = other->topLeft();
		if (temp2->y < temp1->y) goto exit;
		if (temp2->x < temp1->x) goto exit;
		// TODO: check lines
		return true;
		exit:
		delete temp1;
		delete temp2;
		return false;
	}

	Vector2 * Collider::topLeft() {
		LineList * ref = lines;
		Line * line = ref->self;
		Vector2 * temp = line->topLeft();
		double top = temp->y, left = temp->x;
		while (true) {
			ref = ref->next;
			if (ref == NULL) {
				delete temp;
				return new Vector2(left, top);
			}
			line = ref->self;
			delete temp;
			temp = line->topLeft();
			if (top < temp->y) top = temp->y;
			if (left < temp->x) left = temp->x;
		}
	}

	Vector2 * Collider::bottomRight() {
		LineList * ref = lines;
		Line * line = ref->self;
		Vector2 * temp = line->bottomRight();
		double top = temp->y, left = temp->x;
		while (true) {
			ref = ref->next;
			if (ref == NULL) {
				delete temp;
				return new Vector2(left, top);
			}
			line = ref->self;
			delete temp;
			temp = line->bottomRight();
			if (top > temp->y) top = temp->y;
			if (left > temp->x) left = temp->x;
		}
	}

	void Collider::recreateEdges() {
		// Null
	}

	BoxCollider::BoxCollider (Vector2 * pos, Vector2 * size) : Collider(pos) {
		this->size = size;
	}

	void BoxCollider::recreateEdges() {

	}
}