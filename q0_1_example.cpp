#include "qrep.h"
#include "stuff.h"
#include <time.h>


int main()										//Simple example  
												//Note that its only to illustrate the functions

{
		double fidelty = 1;						// setting initial variables+ setting up random number seed
		srand((unsigned int)time(0));
		Vector2cd v1;							//creating vector for EPR (these will determine the generated state amplitudes)
		v1 << 0.707, 0.707;
		Matrix2i m1;							//creating matrix for EPR (this will determine entanglement type)
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, fidelty, &m1, &v1);			// creating EPR object with parameters
		BellMeasure bellmeas1;					// creating Bell Measurement object
		Purification2 purif1(3, 0.9);			// creating purification object
		Channel ch1(1, 1);					    // creating channel object	
		Entanglement2* entout;					// creating global pointer for our output entanglement
		while (fidelty != 5)					// just to keep the program in a loop as long as we want for multiple tests
		{
			cin >> fidelty;						// gets the desired fidelty value
			for (int i = 0; i < 1; i++)			// can be more, 1 only for more understandable demo
			{
				ep1.fid = fidelty;				// setting	the fidelty for the EPR generator
				Qbit2* q1, *q2, *q3, *q4;		// Qbit pointers to reference qubits
				Entanglement2 *ent1, *ent2;		// Entanglement pointers to reference entanglements
				ep1.generate(&q1, &q2, &ent1);  // generating EPR pairs. Note thet multiple differen EPR objects can do the different entanglements
				ep1.generate(&q3, &q4, &ent2);	// I'm only using one because we set one fidelty, so its easier
				ch1.through(q1); ch1.through(q2); ch1.through(q3); ch1.through(q4); // sending the qubits throught the channel
				bellmeas1.measure(q2, q3);		// doing Bell Measurement
				cout << "fidin: " << q1->ent->ampls->cwiseAbs2().sum() << "  "; //the fidelty of the qubits befor purification
				entout = purif1.pupdate2(&q1->ent->ent); // doing purification, and getting the purified entanglement if there's already one
			}
			if (entout != NULL) 
			{ 
				entout->print();				// Printing the purified entanglement
				cout << "fidout: " << entout->bits[0]->ampls->cwiseAbs2().sum(); //The fidelty of the purified entanglement
			}
			if (entout == NULL) cout << "done"; // feedback that the qubit is in the purification buffer
			//cout << endl << "asdasd " << exp(-ch1.length / ch1.alength) << endl;
		}
	return 0;
}


