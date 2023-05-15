namespace hailEngine {
	class Line {
	public:
		Line(Vector2 * point1, Vector2 * point2);
		Vector2 * point1;
		Vector2 * point2;
		bool colliding (Line * other);
		Vector2 * topLeft();
		Vector2 * bottomRight();
	};
	class LineList {
	public:
		LineList * prev;
		Line * self;
		LineList * next;
		LineList(LineList * prev, Line * self);
		void remove();
		LineList * getLastInList();
	};
}