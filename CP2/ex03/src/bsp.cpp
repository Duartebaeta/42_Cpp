#include "../incl/bsp.hpp"

Fixed	aot(Point a, Point b, Point c)
{
	Fixed area;

	area = (a.get_x() *(b.get_y() - c.get_y()) + b.get_x() *(c.get_y() - a.get_y()) + c.get_x() *(a.get_y() - b.get_y()));
	if (area < 0)
		area = area * -1;
	area = area * 0.5f;
	return area;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return false;

	Fixed final_area(aot(a, b, c));
	Fixed old;

	Fixed compare(aot(a, c, point));
	old = compare;
	if (old == 0)
		return false;
	compare = compare + aot(a, b, point);
	if (old == compare)
		return false;
	old = compare;
	compare = compare + aot(b, c, point);
	if (old == compare)
		return false;
	if (final_area == compare)
		return true;
	else
		return false;
}