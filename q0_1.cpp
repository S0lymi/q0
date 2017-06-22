#include "qrep.h"
#include "stuff.h"
#include <time.h>

/*
int main()
{
	double a = 1;
	cin >> a;
	while ( a != 5)
	{
		srand((unsigned int)time(0));
		*/
		/*
		Matrix2cd m1 = Matrix2cd::Random();
		cout << endl << m1 << endl;
		cout <<endl<< m1.cwiseAbs()<<endl;
		*/
		
		/*Vector2cd v2= Vector2cd::Random();
		cout << endl << v2 << endl << v2.cwiseAbs() << endl;
		cout << endl << v2.cwiseAbs2() << endl;
		cout << endl <<sqrt(v2.cwiseAbs2().sum()) << endl;
		cout << endl << v2 / sqrt(v2.cwiseAbs2().sum()) << endl;
		cout << endl << (v2 / sqrt(v2.cwiseAbs2().sum())).cwiseAbs2().sum() << endl;
		*/
		/*Qbit2 *q1 = NULL;
		Qbit2 *q2 = NULL;
		EPR2 ep2(1.0,a);
		ep2.generate(&q1, &q2, NULL);
		cout << endl << *(q1->ind) << endl << (q1->ind)->cwiseAbs2().sum() << endl;
		cout << endl << *(q2->ind) << endl << (q2->ind)->cwiseAbs2().sum() << endl;
		*/
		/*Matrix2i m1;
		m1 << 0, 1, 1, 0;
		Vector2cd v1;
		v1 << 0.5, 0.8;
		Vector2cd v2,v3;
		Vector2cd* vp1 = &v1;
		cout << endl << m1 << endl;
		//v2 << v1(m1(0, 0)) ,v1(m1(1, 0));
		//v3 << v1(m1(0, 1)), v1(m1(1, 1));
		//cout << endl << v1 << endl << endl << v2 << endl << v3 << endl;
		cout << vp1->operator()(1);
		*/


		//meresteszt

		/*
		double dob = 0.5;
		VectorXcd a1(4);
		a1 << 0.707, 0, 0 , 0.707;
		MatrixXcd p1(4, 4);
		p1 = a1*a1.adjoint();
		VectorXcd a2(4);
		a2 << 0, 0, 0, 1;
		cout << a1 << endl << p1 << endl << a2 << endl <<endl<< a1.adjoint()*p1*a1 << endl;
		cout << endl << "merni: " << endl << a2 << endl << "meres: " << endl << (a2.adjoint()*p1*a2).norm() << endl;

		//cout << endl << (a1.adjoint()*p1*a1).norm() << endl;
		//cout << ((a1.adjoint()*p1*a1).norm() > dob) << endl;
		*/


		//Matrix2d r1 = Matrix2d::Random();
		//double r = (r1(1) + 1) / 2;

/*
		//bázisváltó
		complex<double> a1, a2,a3,a4;
		cin >> a1;
		cin >> a2;
		cin >> a3;
		cin >> a4;
		Matrix4cd m1;
		double d = 1 / sqrt(2);
		m1 << d, d, 0, 0,
			0, 0, d, d,
			0, 0, d, -d,
			d, -d, 0, 0;
		cout << endl << m1 << endl;
		cout << endl << m1.inverse() << endl;
		Vector4cd vp;
		vp << a1, a2, a3, a4;
		cout << endl << vp << endl;
		cout << endl << "at:" << endl << m1.inverse()*vp << endl;
		cout << endl << "vissza:" << endl << m1*(m1.inverse()*vp) << endl;
		*/



		// Entanglement generation;
	/*
		
		double f1, f2;
		Vector2cd v1,v2;
		cin >> f1 >> f2 >> v1(0);
		Matrix2i m1;
		v1(1) = sqrt(1.0 - v1(0)*v1(0));
		m1 << 0, 1, 1, 0;
		v2 << 0.707, 0.707;
		EPR2 ep1(1,f1,&m1,&v1);
		EPR2 ep2(1, f2, &m1, &v2);
		Entanglement2* ent1,*ent2;
		Qbit2* q1;
		Qbit2* q2, *q3,*q4;
		ep1.generate(&q1, &q2, &ent1);
		ep2.generate(&q3, &q4, &ent2);
		ent1->print();
		q1->print();
		q2->print();
		cout << endl << "q3, q4" << endl;
		ent2->print();
		q3->print();
		q4->print();
		//cout << endl << "states:" << q1->ent->ent->states << endl;

		//Bellmeasure  teszt
		BellMeasure measure1;
		cout << endl <<"eredmeny "<< measure1.measure(q2, q3) << endl;
		cout << endl << endl << "q2 q3:" << endl;
		q2->print();
		q3->print();
		cout << endl << "ent=:" << (q2->ent->ent == q3->ent->ent) << endl;
		q2->ent->ent->print();
		cout << endl << endl << "q1 q4:" << endl;
		q1->print();
		q4->print();
		cout << endl << "ent=:" << (q1->ent->ent == q4->ent->ent) << endl;
		q1->ent->ent->print();
		cout << endl << "amplsabs:" << q1->ent->ent->ampls->cwiseAbs2().sum() << endl;
		
		*/

		// Vector arithmetic
		/*
		Vector4cd v1;
		v1 << 1, 2, 3, 4;
		Vector4cd v2;
		v2 << 0, 1, 0, -1;
		Matrix2i m1;
		//cout << v1.transpose()*v2;
		Vector4cd ki1;
		for (int i = 0; i < 4; i++)
		{ 
			ki1(i) = v1(i)*v2(i);
			if (ki1(i) == 0.0) ki1(i) = 1;
		}
		//cout << endl << ki1 << endl << endl << ki1(0)*ki1(1)*ki1(2)*ki1(3) << endl;
		cout << m1;
		cin >> a;
		*/

		// Measure method test
		/*
		Matrix4cd * projectors;	
		projectors = new Matrix4cd[4];
		Vector4cd a1;
		a1 << 1 / sqrt(2.0), 0, 0, (1 / sqrt(2.0));
		projectors[0] = a1*a1.adjoint();
		a1 << 1 / sqrt(2.0), 0, 0, -1 / sqrt(2.0);
		projectors[1] = a1*a1.adjoint();
		a1 << 0, 1 / sqrt(2.0), 1 / sqrt(2.0), 0;
		projectors[2] = a1*a1.adjoint();
		a1 << 0, 1 / sqrt(2.0), -1 / sqrt(2.0), 0;
		projectors[3] = a1*a1.adjoint();
		Vector3d plus1;
		plus1 << 1, 1, 1;
		Vector3d r1 = (Vector3d::Random() + plus1) / 2;
		int result=23;
		Vector4cd v4m;
		complex<double> v1, v2, v3, v4;
		cin >> v1 >> v2 >> v3 >> v4;
		v4m << v1, v2, v3, v4;
		cout << endl << "state: " << endl << v4m << endl;

		double prob = 0;
		for (int i = 0; i < 4; i++)
		{
			prob = prob + (v4m.adjoint() *projectors[i] * v4m).norm();
			if (prob >= r1(2))
			{
			result = i;
			i = 5;
			}

		}
		cout << endl << "eredmeny:   " << result << endl;
		*/

		//átszmolás teszt
		/*
		cout << "q1 ind vsz:" << endl << q1->ind->cwiseAbs2().sum() << endl << "q1 ent abs vsz:" << endl << q1->ent->ampls->cwiseAbs2().sum() << endl;
		//cout << "q2 ind vsz:" << endl << q2->ind->cwiseAbs2().sum() << endl << "q2 ent abs vsz:" << endl << q2->ent->ampls->cwiseAbs2().sum() << endl;
		cout << endl << (1 / sqrt(q1->ind->cwiseAbs2().sum()))*(*q1->ind) << endl << ((1 / sqrt(q1->ind->cwiseAbs2().sum()))*(*q1->ind)).cwiseAbs2().sum() << endl;
		*/
		/*
		Vector2cd vm1, vm2;
		vm1 << 0.6, 0.8;
		vm2 << 2, 3;
		MatrixXcd mm = vm1*vm2.transpose();
		cout << mm << endl << " " << mm(0,0) << " " << mm(0,1) << " " << mm(1,0) << " " << mm(1,1) << endl;
		*/
		/*
		// aftter measure test
		Vector2cd v1, v2;
		v1 << 0.8, 0.6;
		v2 << 0.707, 0.707;
		Matrix2i m1;
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, 0.8, &m1, &v1);
		EPR2 ep2(1, 0.9, &m1, &v2);
		Qbit2* q1, *q2, *q3, *q4;
		Entanglement2* ent1, *ent2;
		Entanglement2 * newent;
		ep1.generate(&q1, &q2, &ent1);
		ep2.generate(&q3, &q4, &ent2);
		cout << "ent1:" << endl;
		ent1->print(); q1->print(); q2->print();
		cout << "ent2:" << endl;
		ent2->print(); q3->print(); q4->print();
		Qbit2* bit1, *bit2;
		bit1 = q2; bit2 = q3;
		Matrix2i newstates;
		newstates << 0, 1, 1, 0;
		Vector2cd newampls;
		newampls << 0.6, 0.8;

		//EPR2 epr(1, bit1->ent->ampls->cwiseAbs2().sum()* bit2->ent->ampls->cwiseAbs2().sum(), &newstates, &newampls); //creating epr instance for new entangled pair generation
		//epr.generate(&bit1->ent->ent->bits[(bit1->ent == bit1->ent->ent->bits[0])]->qbit, &bit2->ent->ent->bits[(bit2->ent == bit2->ent->ent->bits[0])]->qbit, &newent); // generating new entanglement for the qubits not in measurement		
		newent = new Entanglement2(&newstates, &newampls, q2->ent->ent->bits[(q2->ent == q2->ent->ent->bits[0])], q3->ent->ent->bits[(q3->ent == q3->ent->ent->bits[0])]);

		cout << endl << "==?:" << (q4->ent == newent->bits[1]);
		double nfid = 1;
		*newent->bits[0]->ampls << sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(0, 0)),
								   sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(0, 1));
		*newent->bits[1]->ampls << sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(1, 0)),
								   sqrt(nfid)* newent->ampls->operator()(newent->states->operator()(1, 1));
		*newent->bits[0]->qbit->ind << 3, 6;
		cout << endl << "uj:" << endl;
		newent->print(); q1->print(); q4->print();
		*/

		
		//Simple purif test

/*
		double fid;
		int buf;
		cin >> fid >> buf;
		Purification2 purif(buf,fid);
		//
		Vector2cd v1;
		v1 << 0.707, 0.707;
		Matrix2i m1;
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, 0.7, &m1, &v1);
		EPR2 ep2(1, 0.7, &m1, &v1);
		Qbit2 *q1, *q2, *q3, *q4;
		Entanglement2 * ent1, *ent2;
		ep1.generate(&q1, &q2, &ent1);
		ep2.generate(&q3, &q4, &ent2);
		ent2->print();
		q3->print(); q4->print();
		purif.pupdate(&ent1);
		purif.pupdate(&ent2);
		cout << endl << "után:" << endl;
		ent2->print();
		q3->print(); q4->print();
		*/

		// memfix test
/*
		Vector2cd v1;
		v1 << 0.707, 0.707;
		Matrix2i m1;
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, 0.7, &m1, &v1);
		EPR2 ep2(1, 0.7, &m1, &v1);
		Qbit2 *q1, *q2, *q3, *q4;
		Entanglement2 * ent1, *ent2;
		ep1.generate(&q1, &q2, &ent1);
		ep2.generate(&q3, &q4, &ent2);
		ent2->print();
		q3->print(); q4->print();
		//delete q3;
		//delete q4;
		//delete q3->ent;
		delete ent2;
		delete q3->ent;
		delete q4->ent;
		delete q3;
		delete q4;



	*/


// teszteset1
		
/*
		Vector2cd v1;
		v1 << 0.707, 0.707;
		Matrix2i m1;
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, 0.7, &m1, &v1);
		BellMeasure bellmeas1;
		Purification2 purif1(6,0.9);
		Entanglement2* eredmeny;

		
		for (int i = 0; i < 7; i++)
		{
			Qbit2 * q1, *q2, *q3, *q4;
			Entanglement2 *ent1, *ent2;
			ep1.generate(&q1, &q2, &ent1);
			ep1.generate(&q3, &q4, &ent2);
			bellmeas1.measure(q2, q3);
			eredmeny=purif1.pupdate(&q1->ent->ent);
			cout << i << endl;
			for (int j = 0; j < purif1.buffer; j++ ) { cout << purif1.entbuff[j] << endl; }

		}


		if (eredmeny != NULL) eredmeny->print();

		Channel ch1(2, 1);
		eredmeny->bits[0]->qbit->print();
		cout << endl << "ind2: " << eredmeny->bits[0]->qbit->ind->cwiseAbs2().sum() << " ent: " << eredmeny->bits[0]->ampls->cwiseAbs2().sum() << endl;
		ch1.through(eredmeny->bits[0]->qbit);
		eredmeny->bits[0]->qbit->print();
		cout << endl << "ind2: " << eredmeny->bits[0]->qbit->ind->cwiseAbs2().sum() << " ent: " << eredmeny->bits[0]->ampls->cwiseAbs2().sum() << endl;
		*/

		//Teszteset2
		/*
		Vector2cd v1;
		v1 << 0.707, 0.707;
		Matrix2i m1;
		m1 << 0, 0, 1, 1;
		EPR2 ep1(1, a, &m1, &v1);
		BellMeasure bellmeas1;
		Purification2 purif1(3, 0.9);
		Channel ch1(1, 2);
		Entanglement2* entout;
		while (a != 5)
		{
			for (int i = 0; i < 1; i++)
			{
				ep1.fid = a;
				Qbit2* q1, *q2, *q3, *q4;
				Entanglement2 *ent1, *ent2;
				ep1.generate(&q1, &q2, &ent1);
				ep1.generate(&q3, &q4, &ent2);
				ch1.through(q1); ch1.through(q2); ch1.through(q3); ch1.through(q4);
				bellmeas1.measure(q2, q3);
				cout << "fidin: " << q1->ent->ampls->cwiseAbs2().sum() << "  ";
				entout = purif1.pupdate2(&q1->ent->ent);
			}
			if (entout != NULL) 
			{ 
				entout->print(); 
				cout << "fidout: " << entout->bits[0]->ampls->cwiseAbs2().sum();
			}
			if (entout == NULL) cout << "done";

			cin >> a;
		}
	}
	return 0;
}*/
