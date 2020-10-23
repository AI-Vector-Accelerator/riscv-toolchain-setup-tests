/*
 * Data_suduko.h
 *
 *  Created on: 23 Oct 2020
 *      Author: Harry
 */

#ifndef DATA_SUDUKO_H_
#define DATA_SUDUKO_H_

#include <string>

using namespace std;

string getData(){
	string data="";
	switch (3){
	case 1:
		data="000000000 000000000 000000000 070009080 000000000 000000000 000000000 000000000 000000000";
		break;
	case 2:
		data="300200000 000107000 706030500 070009080 900020004 010800050 009040301 000702000 000008006";
		break;
	case 3:
		data="100007090 	030020008	009600500	005300900	010080002	600004000	300000010	040000007	007000300	";
		break;
	}
	return data;
}




#endif /* DATA_SUDUKO_H_ */
