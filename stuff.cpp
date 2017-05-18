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
	//check if parameters are NULL ***alternatetive***
	//if (*bit1 != NULL) { delete (*bit1); *bit1 = NULL; };
	//if (*bit2 != NULL) delete *bit2;
	//if (*ent != NULL) delete *ent;

	//Qbit inds
	Vector2cd* ind1 = new Vector2cd;   //allocating memory for vectors
	Vector2cd* ind2 = new Vector2cd;
	*ind1 = Vector2cd::Random();	   //generating random to simulate noise
	*ind1 = sqrt(1 - fid)*(*ind1 / sqrt(ind1->cwiseAbs2().sum()));  // norm with 1-fid
	*ind2 = Vector2cd::Random();
	*ind2 = sqrt(1 - fid)*(*ind2 / sqrt(ind2->cwiseAbs2().sum()));
	// Entangle bits
	Vector2cd* ebit1a = new Vector2cd;  // allocating memory for entangled parts
	Vector2cd* ebit2a = new Vector2cd;
	*ebit1a << sqrt(fid)* ampls->operator()(states->operator()(0, 0)),sqrt(fid)* ampls->operator()(states->operator()(1, 0)); // norm with fid
	*ebit2a << sqrt(fid)* ampls->operator()(states->operator()(0, 1)),sqrt(fid)* ampls->operator()(states->operator()(1, 1));
	
	Entbit* ebit1 = new Entbit(*ent,ebit1a); // allocating entbit parts
	Entbit* ebit2 = new Entbit(*ent,ebit2a); 
	//Entanglement
	Matrix2i* estates = new Matrix2i; // allocating entangled variables
	Vector2cd* eampl = new Vector2cd;
	*estates = *states;
	*eampl = *ampls;
	*ent = new Entanglement2(estates, eampl, ebit1, ebit2); // creating Entang 2 class
	ebit1->ent = *ent;		//pointing entbit1 and entbit 2 to entang class
	ebit2->ent = *ent;		

	*bit1 = new Qbit2(ind1,ebit1); //creating qbit2-s
	*bit2 = new Qbit2(ind2,ebit2);
	(*bit1)->ent->qbit = *bit1;  //setting qbit->ent->qbits
	(*bit2)->ent->qbit = *bit2;

	// cleanup
	delete ebit1a;
	delete ebit2a;
	delete estates;
	delete eampl;
	delete ind1;
	delete ind2;

	return true;
}


//BellMeasure
BellMeasure::BellMeasure()
{
	projectors = new Matrix4cd[4];
	Vector4cd a1;
	a1 << 1 / sqrt(2.0), 0, 0,( 1 / sqrt(2.0));  //00+11
	projectors[0] = a1*a1.adjoint();
	a1 << 1 / sqrt(2.0), 0, 0, -1 / sqrt(2.0);   //00-11
	projectors[1] = a1*a1.adjoint();
	a1 <<0, 1 / sqrt(2.0), 1 / sqrt(2.0),0;		 //01+10
	projectors[2] = a1*a1.adjoint();
	a1 << 0, 1 / sqrt(2.0), -1 / sqrt(2.0), 0;	 //01-10
	projectors[3] = a1*a1.adjoint();

	// measure map set
	measuremap = new Vector4cd[32];
	//for intype=0
	measuremap[0] << 1, 0, 1, 0; measuremap[1] << 0, 1, 0, 1; measuremap[2] << 1, 0, 1, 0; measuremap[3] << 0, -1, 0, 1;
	measuremap[4] << 1, 0, 0, 1; measuremap[5] << 0, 1, 1, 0; measuremap[6] << 1, 0, 0, 1; measuremap[7] << 0, -1, 1, 0;
	//for intype=1
	measuremap[8] << 1, 0, 1, 0; measuremap[9] << 0, 1, 0, 1; measuremap[10] << 1, 0, 1, 0; measuremap[11] << 0, -1, 0, 1;
	measuremap[12] << 1, 0, 0, 1; measuremap[13] << 0, 1, 1, 0; measuremap[14] << 1, 0, 0, 1; measuremap[15] << 0, -1, 1, 0;
	//for intype=2
	measuremap[16] << 1, 0, 0, 1; measuremap[17] << 0, 1, 1, 0; measuremap[18] << -1, 0, 0, 1; measuremap[19] << 0, 1, 1, 0;
	measuremap[20] << 1, 0, 1, 0; measuremap[21] << 0, 1, 0, 1; measuremap[22] << -1, 0, 1, 0; measuremap[23] << 0, 1, 0, 1;
	//for intype=3
	measuremap[24] << 1, 0, 0, 1; measuremap[25] << 0, 1, 1, 0; measuremap[26] << -1, 0, 0, 1; measuremap[27] << 0, 1, 1, 0;
	measuremap[28] << 1, 0, 1, 0; measuremap[29] << 0, 1, 0, 1; measuremap[30] << -1, 0, 1, 0; measuremap[31] << 0, 1, 0, 1;
	/*for (int i = 0; i < 32; i++)
	{
		measuremap[i] = measuremap[i] * (1 / sqrt(2));
	}*/

	// measure type set
	measuretmap = new bool[16];
	measuretmap[0] = 0; measuretmap[1] = 0; measuretmap[2] = 1; measuretmap[3] = 1;     //intype=0
	measuretmap[4] = 1; measuretmap[5] = 1; measuretmap[6] = 0; measuretmap[7] = 0;     //intype=1
	measuretmap[8] = 1; measuretmap[9] = 1; measuretmap[10] = 0; measuretmap[11] = 0;   //intype=2
	measuretmap[12] = 0; measuretmap[13] = 0; measuretmap[14] = 1; measuretmap[15] = 1; //intype=3
}

BellMeasure::~BellMeasure()
{
	delete[] projectors;
	delete[] measuremap;
	delete[] measuretmap;
}

int BellMeasure::measure(Qbit2 * bit1, Qbit2 * bit2)
{
	int result;
	bool indent[2];
	Vector2cd vm[2];
	// generate 3 randoms between 0-1
	Vector3d plus1;
	plus1 << 1, 1, 1;
	Vector3d r1 = (Vector3d::Random()+plus1 )/2;
	// mérendõ rész kiválasztása
	indent[0] = (r1(0) > bit1->ent->ampls->cwiseAbs2().sum()); // random0 > fidelty1
	indent[1] = (r1(1) > bit2->ent->ampls->cwiseAbs2().sum()); // random1 > fidelty2
	//normálás a méréshez
	if (indent[0]) vm[0] = (1 / sqrt(bit1->ind->cwiseAbs2().sum()))*(*bit1->ind); // 
	else vm[0] = ((1 / sqrt(bit1->ent->ampls->cwiseAbs2().sum()))*(*bit1->ent->ampls));
	if (indent[1]) vm[1] = (1 / sqrt(bit2->ind->cwiseAbs2().sum()))*(*bit2->ind);
	else vm[1] = ((1 / sqrt(bit2->ent->ampls->cwiseAbs2().sum()))*(*bit2->ent->ampls));
	// debug couts
	//cout << endl << "indent0: " << indent[0] << endl << "vm0: " << endl  << vm[0] << endl;
	//cout << "indent1: " << indent[1] << endl << "vm1: " << endl  << vm[1] << endl;
	//cout << "abs: " << vm[0].cwiseAbs2().sum() << "   " << vm[1].cwiseAbs2().sum() << endl;
	//measure elõkészítés

	Vector4cd v4m;
	Matrix2cd mm = vm[0] * vm[1].transpose();
	for (int i = 0; i < 4; i++) v4m(i) = mm(i);
	//test if qubits to be measured are entangled
	if (!indent[0] && !indent[1]) //true if we measure entangled parts
	{
		if (bit1->ent->ent == bit2->ent->ent)
		{
			v4m << 0, 0, 0, 0; // resetting v4m
			// setting v4m according to entangled state
			int c1 = bit1->ent->ent->states->operator()(0, 0) + bit1->ent->ent->states->operator()(0, 1);
			int c2 = 3 - c1;
			v4m(c1) = bit1->ent->ent->ampls->operator()(0);
			v4m(c2) = bit1->ent->ent->ampls->operator()(1);
			//debug
			//cout << endl << "c1,c2: " << c1 << " " << c2 << endl;
		}
	}
	// debug
	//cout << endl << "v4m: " << endl << v4m << endl;
	// measure
	double prob=0;
	for (int i = 0; i < 4; i++)																					
	{
		prob = prob + (v4m.adjoint()*projectors[i] * v4m).norm();
		if (prob >= r1(2))
		{
			result = i;
			i = 5;
		}
	}
	//result=0  00+11
	//result=1  00-11
	//result=2  01+10
	//result=3  01-10

	
	//entangled part aftermeasure
	//setting post measurement state (only the new entangled part is of importance for now)
	Vector4cd stateamps, efaux;
	stateamps << bit1->ent->ent->ampls->operator()(0), // for easier use
		bit1->ent->ent->ampls->operator()(1),
		bit2->ent->ent->ampls->operator()(0),
		bit2->ent->ent->ampls->operator()(1);
	// getting types of interacting entangled states
	int intype;
	if (bit1->ent->ent->states->operator()(0, 1) == 0 && bit2->ent->ent->states->operator()(0, 1) == 0) intype = 0; // 00+11 & 00+11
	if (bit1->ent->ent->states->operator()(0, 1) == 0 && bit2->ent->ent->states->operator()(0, 1) == 1) intype = 1; // 00+11 & 01+10
	if (bit1->ent->ent->states->operator()(0, 1) == 1 && bit2->ent->ent->states->operator()(0, 1) == 0) intype = 2; // 01+10 & 00+11
	if (bit1->ent->ent->states->operator()(0, 1) == 1 && bit2->ent->ent->states->operator()(0, 1) == 1) intype = 3; // 01+10 & 01+10
	
	// calculating new amplitude values(e,f)
	//setting e
	for (int i = 0; i < 4; i++)
	{
		efaux(i) = stateamps(i)*measuremap[8*intype+2*result+0](i);
		if (efaux(i) == 0.0) efaux(i) = 1;
	}
	Vector2cd newampls;
	newampls(0) = efaux(0)*efaux(1)*efaux(2)*efaux(3) *sqrt(2);
	//setting f
	for (int i = 0; i < 4; i++)
	{
		efaux(i) = stateamps(i)*measuremap[8 * intype + 2 * result + 1](i);
		if (efaux(i) == 0.0) efaux(i) = 1;
	}
	newampls(1) = efaux(0)*efaux(1)*efaux(2)*efaux(3)*sqrt(2) ;
	//setting entanglement type matrix
	Matrix2i newstates;
	bool newtype;
	newtype = measuretmap[4 * intype + result];
	if (!newtype)
		newstates << 0, 0, 1, 1;
	if (newtype)
		newstates << 0, 1, 1, 0;
	
	// creating new after measurement states
	// creating new entanglement
	Entanglement2 * newent;
	newent = new Entanglement2(&newstates, &newampls, bit1->ent->ent->bits[(bit1->ent == bit1->ent->ent->bits[0])], bit2->ent->ent->bits[(bit2->ent == bit2->ent->ent->bits[0])]); //new entanglement between the other non-measured bits
		
	double nfid = bit1->ent->ampls->cwiseAbs2().sum()*bit2->ent->ampls->cwiseAbs2().sum();// calculating new fidelty (f1*f2)
	// setting the new entanled parts
	*newent->bits[0]->ampls << sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(0, 0)),
								sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(1, 0));
	*newent->bits[1]->ampls << sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(0, 1)),
								sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(1, 1));
	// setting new non-entangled parts
	*newent->bits[0]->qbit->ind = Vector2cd::Random();// generating random to simulate noise
	*newent->bits[0]->qbit->ind = sqrt(1 - nfid)*(*newent->bits[0]->qbit->ind / sqrt(newent->bits[0]->qbit->ind->cwiseAbs2().sum()));//normalizing with 1-(new fidelty)
	*newent->bits[1]->qbit->ind = Vector2cd::Random();// generating random to simulate noise
	*newent->bits[1]->qbit->ind = sqrt(1 - nfid)*(*newent->bits[1]->qbit->ind / sqrt(newent->bits[1]->qbit->ind->cwiseAbs2().sum()));//normalizing with 1-(new fidelty)
	
	newent->bits[0]->ent = newent; //setting new entbit entanglement pointers
	newent->bits[1]->ent = newent;
	
	// setting new state for the measured bits
	// deleting old entanglements
	*bit1->ent->ent = NULL;
	*bit2->ent->ent = NULL;
	delete bit1->ent->ent;
	delete bit2->ent->ent;
	
	//setting new state
	if (result == 0 || result == 1)
		newstates << 0, 0, 1, 1;
	if (result == 2 || result == 3)
		newstates << 0, 1, 1, 0;
	if (result == 0 || result == 2)
		newampls << 1 / sqrt(2.0), 1 / sqrt(2.0);
	if (result == 1 || result == 3)
		newampls << 1 / sqrt(2.0), -1 / sqrt(2.0);
	//Entanglement for the measured states (reusing newent pointer)
	newent = new Entanglement2(&newstates,&newampls,bit1->ent,bit2->ent);
	*newent->bits[0]->ampls << newent->ampls->operator()(newent->states->operator()(0, 0)), // setting entbits (same as before, but nfid=1)
								newent->ampls->operator()(newent->states->operator()(1, 0));
	*newent->bits[1]->ampls << newent->ampls->operator()(newent->states->operator()(0, 1)),
								newent->ampls->operator()(newent->states->operator()(1, 1));

	newent->bits[0]->ent = newent; //setting new entbit entanglement pointers
	newent->bits[1]->ent = newent;
	//setting inds
	*bit1->ind << 0, 0;
	*bit2->ind << 0, 0;

	// cleanup

/**/

	return result;
}

//Purification

Purification2::Purification2(int bufferk, double newfidk)
{
	buffer = bufferk;
	newfid = newfidk;
	entbuff = new Entanglement2 *[buffer];
	for (int i = 0; i < buffer; i++) entbuff[i] = NULL;

}

Purification2::~Purification2()
{
	delete entbuff;
}

Entanglement2 * Purification2::pupdate(Entanglement2 ** entin)
{
	for (int i = 0; i < buffer; i++)
	{
		if (entbuff[i] == NULL)
		{
			entbuff[i] = *entin;
			return nullptr;
		}
	}
	//buffer full-> purification
	*(*entin)->bits[0]->ampls = (*(*entin)->bits[0]->ampls / sqrt((*entin)->bits[0]->ampls->cwiseAbs2().sum()))*sqrt(newfid); //norming to newfid;
	*(*entin)->bits[1]->ampls = (*(*entin)->bits[1]->ampls / sqrt((*entin)->bits[1]->ampls->cwiseAbs2().sum()))*sqrt(newfid); //norming to newfid;
	*(*entin)->bits[0]->qbit->ind = (*(*entin)->bits[0]->qbit->ind / sqrt((*entin)->bits[0]->qbit->ind->cwiseAbs2().sum()))*sqrt(1 - newfid); // norming ind part
	*(*entin)->bits[1]->qbit->ind = (*(*entin)->bits[1]->qbit->ind / sqrt((*entin)->bits[1]->qbit->ind->cwiseAbs2().sum()))*sqrt(1 - newfid); // norming ind part
	//delete others - TODO
	for (int i = 0; i < buffer; i++)
	{
		delete (entbuff[i])->bits[0]->qbit;
		delete (entbuff[i])->bits[1]->qbit;
		delete (entbuff[i])->bits[0];
		delete (entbuff[i])->bits[1];
		delete entbuff[i];
	}
	//empty buffer
	for (int i = 0; i < buffer; i++) entbuff[i] = NULL;

	return *entin;
}
