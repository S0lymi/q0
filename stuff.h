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
class BellMeasure
{
public:
	Matrix4cd * projectors;
	Vector4cd * measuremap;
	bool *measuretmap;

	//konst
	BellMeasure();
	//dest
	~BellMeasure();
	//fgv

	int measure(Qbit2* bit1, Qbit2* bit2);


};
class Purification2
{
public:
	int buffer;
	double newfid;
	Entanglement2 ** entbuff;

	//const
	Purification2(int bufferk=2,double newfidk=1);
	//dest
	~Purification2();
	//other
	Entanglement2* pupdate(Entanglement2** entin);
	Entanglement2* pupdate2(Entanglement2** entin);

};

class Channel
{
public:
	double alength;
	double length;

	//const
	Channel(double alengthk, double lengthk);
	//dest
	~Channel();

	//other
	void through(Qbit2* bit);
};