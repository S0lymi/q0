#pragma once
#include "qrep.h"

class EPR2
{
public:
	double rate;
	double fid;
	Matrix2i* states;
	Vector2cd* ampls;

	//konst
	EPR2(double ratek=1, double fidk=1,Matrix2i* statesk=NULL,Vector2cd* amplsk=NULL);
	//dest
	~EPR2();
	//mas
	bool generate(Qbit2** bit1, Qbit2** bit2, Entanglement2** ent);

};