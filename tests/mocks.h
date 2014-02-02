/* 
 * File:   stubs.h
 * Author: jappie
 *
 * Created on February 2, 2014, 3:37 PM
 */

#ifndef MOCKS_H
#define	MOCKS_H
#include "../IGridTraveller.h"
using namespace isgp;
namespace isgp_test{
	class GridTravellerMock : public IGridTraveller{
	public:
		int nrCalled;
		GridTravellerMock(){
			nrCalled = 0;
		}
		virtual void receiveTile(Tile* tile, Point* coordinates){
			nrCalled++;
		}
	};
}
#endif	/* STUBS_H */

