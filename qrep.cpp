#include "qrep.h"


// Qbit

Qbit2::Qbit2(Vector2cd * indk, Entbit * entk)
{
	ind = indk;
	ent = entk;
}

Qbit2::~Qbit2()
{
}

void Qbit2::print()
{
	if (ind != NULL) cout << endl << "ind:" << endl << *ind << endl;
	if (ent != NULL) { cout << "Entbit"; ent->print(); }
}

//Entbit
Entbit::Entbit(Entanglement2 * entk, Vector2cd * amplsk)
{
	ent = entk;
	ampls = amplsk;
}

Entbit::~Entbit()
{
}

void Entbit::print()
{
	if (ampls != NULL) cout << endl << "ampls:" << endl << *ampls << endl;
}

//Entanglement2

Entanglement2::Entanglement2(Matrix2i * statesk, Vector2cd * amplsk, Entbit * bit1, Entbit * bit2)
{
	states = statesk;
	ampls = amplsk;
	bits[0] = bit1;
	bits[1] = bit2;
}

Entanglement2::~Entanglement2()
{
}

void Entanglement2::print()
{
	if (states != NULL) cout << endl << "states:" << endl << *states << endl;
	if (ampls != NULL) cout << endl << "ampls:" << endl << *ampls << endl;
	//for (int i = 0; i < 2; i++) if (bits[i] != NULL) bits[i] -> print();
}
