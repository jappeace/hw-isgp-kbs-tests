/* 
 * File:   Point.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#ifndef POINT_H
#define	POINT_H
namespace isgp {
	class Point {
	public:
		void SetY(double _y);
		double GetY() const;
		void SetX(double _x);
		double GetX() const;
	
	private:
		double _x;
		double _y;
	};
}
#endif	/* POINT_H */

