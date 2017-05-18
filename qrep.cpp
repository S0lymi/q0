#include "qrep.h"


// Qbit

Qbit2::Qbit2(Vector2cd * indk, Entbit * entk)
{
	if (indk != NULL)
	{
		ind = new Vector2cd;
		*ind = *indk;
	}
	ent = entk;
}

Qbit2::~Qbit2()
{
	if (ent != NULL)
	{
		if (ent->qbit != NULL) { ent->qbit = NULL; }
	}
	delete ind;
	//delete ent;
		 
}

void Qbit2::print()
{
	if (ind != NULL) cout << endl << "ind:" << endl << *ind << endl;
	if (ent != NULL) { cout << "Entbit"; ent->print(); }
}

//Entbit
Entbit::Entbit(Entanglement2 * entk, Vector2cd * amplsk, Qbit2 * qbitk)
{
	ent = entk;
	if (amplsk != NULL)
	{
		ampls = new Vector2cd;
		*ampls = *amplsk;
	}
	qbit = qbitk;
}

Entbit::~Entbit()
{
	if (ent != NULL)
	{
		if (ent->bits[(ent->bits[1] == this)] != NULL) ent->bits[(ent->bits[1] == this)] = NULL;
	}
	if (qbit != NULL)
	{
		if (qbit->ent != NULL) qbit->ent = NULL;
	}
	delete ampls;

}

void Entbit::print()
{
	if (ampls != NULL) cout << endl << "ampls:" << endl << *ampls << endl;
}

//Entanglement2

Entanglement2::Entanglement2(Matrix2i * statesk, Vector2cd * amplsk, Entbit * bit1, Entbit * bit2)
{
	if (statesk != NULL)
	{
		states = new Matrix2i;
		*states = *statesk;
	}
	else
	states = statesk;
	if (amplsk != NULL)
	{
		ampls = new Vector2cd;
		*ampls = *amplsk;
	}
	else
	ampls = amplsk;

	bits[0] = bit1;
	bits[1] = bit2;
}

Entanglement2::~Entanglement2()
{
	for (int i = 0; i < 2; i++)
	{
		if (bits[i] != NULL)
		{
			if (bits[i]->ent != NULL) bits[i]->ent = NULL;
		}
	}
	delete states;
	delete ampls;

}

void Entanglement2::print()
{
	if (states != NULL) cout << endl << "states:" << endl << *states << endl;
	if (ampls != NULL) cout << endl << "ampls:" << endl << *ampls << endl;
	//for (int i = 0; i < 2; i++) if (bits[i] != NULL) bits[i] -> print();
}


//Entanglement
Entanglement::Entanglement(VectorXi* statesk , Vector2cd*amplsk , Entbit* bitsk )
{
	states = statesk;
	ampls = amplsk;
	bits = bitsk;
}


Entanglement::~Entanglement()
{
}
