#include "Fixed.hpp"
#include "Point.hpp"

static Fixed abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static Fixed triangleArea(Point const A, Point const B, Point const C)
{
	// | Xa * (Yb - Yc) + Xb * (Ya - Yc) + Xc * (Ya - Yb) / 2 |
	return (
		abs((
			A.get_x() * (B.get_y() - C.get_y())
			+ B.get_x() * (C.get_y() - A.get_y())
			+ C.get_x() * (A.get_y() - B.get_y())
		) / 2)
	);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = triangleArea(a, b, c);
	Fixed pbc = triangleArea(point, b, c);
	Fixed apc = triangleArea(a, point, c);
	Fixed abp = triangleArea(a, b, point);

	if (abp == 0 || pbc == 0 || apc == 0)
		return (false);
	return ((abc == (pbc + apc + abp)));
}
