/* 
 * File:   Size.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#ifndef SIZE_H
#define	SIZE_H
namespace isgp {
	class Size {
	private:
		int _width;
		int _height;
	public:
		Size(int width, int height){
			_width = width;
			_height = height;
		}

        void SetHeight(int _height) {
        	this->_height = _height;
        }

        int GetHeight() const {
        	return _height;
        }

        void SetWidth(int _width) {
        	this->_width = _width;
        }

        int GetWidth() const {
        	return _width;
        }
	};
}
#endif	/* SIZE_H */

