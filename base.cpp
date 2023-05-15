#include <string>
#include <cstdint>
#include "hailEngine.hpp"

namespace hailEngine {
	Vector2::Vector2 (double x, double y) {
		this->x = x;
		this->y = y;
	}
	Vector2::Vector2 (Vector2 * copy) {
		this->x = copy->x;
		this->y = copy->y;
	}
}