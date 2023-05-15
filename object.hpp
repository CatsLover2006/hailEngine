namespace hailEngine {
	class Object {
	public:
		double x, y;
		ColliderList * colliders;
		Object (double x, double y);
		void addCollider(Collider * collider);
		bool isColliding(Object * other);
	};
	class ObjectList {
	public:
		ObjectList * prev;
		Object * self;
		ObjectList * next;
		ObjectList(ObjectList * prev, Object * self);
		void remove();
		ObjectList * getLastInList();
	};
}