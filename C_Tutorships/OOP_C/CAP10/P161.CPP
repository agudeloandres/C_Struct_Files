A A::operator+ (A &b) {
	A t;
	t.x = x + b.x;
	t.y = y + b.y;
	return t;
}