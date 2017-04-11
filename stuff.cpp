#include "stuff.h"

EPR2::EPR2(double ratek, double fidk, Matrix2i * statesk, Vector2cd* amplsk)
{
	rate = ratek;
	fid = fidk;
	states = statesk;
	ampls = amplsk;
}

EPR2::~EPR2()
{
}

bool EPR2::generate(Qbit2 ** bit1, Qbit2 ** bit2, Entanglement2 ** ent)
{
	//Qbit inds
	Vector2cd* ind1 = new Vector2cd;
	Vector2cd* ind2 = new Vector2cd;
	*ind1 = Vector2cd::Random();
	*ind1 = sqrt(1 - fid)*(*ind1 / sqrt(ind1->cwiseAbs2().sum()));
	*ind2 = Vector2cd::Random();
	*ind2 = sqrt(1 - fid)*(*ind2 / sqrt(ind2->cwiseAbs2().sum()));
	// Entangle bits
	Vector2cd* ebit1a = new Vector2cd;
	Vector2cd* ebit2a = new Vector2cd;
	*ebit1a << sqrt(fid)* ampls->operator()(states->operator()(0, 0)),sqrt(fid)* ampls->operator()(states->operator()(1, 0));
	*ebit2a << sqrt(fid)* ampls->operator()(states->operator()(0, 1)),sqrt(fid)* ampls->operator()(states->operator()(1, 1));
	
	Entbit* ebit1 = new Entbit(*ent,ebit1a);
	Entbit* ebit2 = new Entbit(*ent,ebit2a);
	//Entanglement
	Matrix2i* estates = new Matrix2i;
	Vector2cd* eampl = new Vector2cd;
	*estates = *states;
	*eampl = *ampls;
	*ent = new Entanglement2(estates, eampl, ebit1, ebit2);


	*bit1 = new Qbit2(ind1,ebit1);
	*bit2 = new Qbit2(ind2,ebit2);

	return true;
}
