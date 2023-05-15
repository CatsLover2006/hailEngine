namespace hailEngine {
	class Collider {
	public:
		Collider (Vector2 * pos);
		bool colliding(Collider * other);
		void setLocation(Vector2 * pos);
		virtual void recreateEdges();
		void addLine(Line * add);
		Vector2 * getClosestPoint(Collider * other);
		Vector2 * topLeft();
		Vector2 * bottomRight();
		Vector2 * pos;
		Vector2 * offset;
		double rotation;
		LineList * lines;
	};
	class BoxCollider: public Collider {
	public:
		BoxCollider (Vector2 * pos, Vector2 * size);
		void recreateEdges();
		Vector2 * size;
	};
	class ColliderList {
	public:
		ColliderList * prev;
		Collider * self;
		ColliderList * next;
		ColliderList(ColliderList * prev, Collider * self);
		void remove();
		ColliderList * getLastInList();
	};
}