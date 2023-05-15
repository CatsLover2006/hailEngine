#include <string>
#include <cstdint>
#include "hailEngine.hpp"

namespace hailEngine {
	void Object::addCollider(Collider * collider) {
		new ColliderList(colliders->getLastInList(), collider);
	}

	ObjectList::ObjectList(ObjectList * prev, Object * self) {
		this->self = self;
		prev->next = this;
	}

	void ObjectList::remove() {
		prev->next = next; // Update reference
		next->prev = prev; // Update reference
		delete self; // Clear object memory
		delete this; // Suicide after memory clean
	}

	ObjectList * ObjectList::getLastInList() {
		if (next == NULL) return this;
		return next->getLastInList();
	}
}