#include "qrep.h"
#include "stuff.h"
#include <time.h>


int main()
{
	double a = 1;
	while ( a != 5)
	{
		srand((unsigned int)time(0));
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
		double f;
		cin >> f;
		Matrix2i m1;
		m1 << 0, 1, 1, 0;
		Vector2cd v1;
		v1 << 0.6, 0.8;
		EPR2 ep1(1,f,&m1,&v1);
		Entanglement2* ent1;
		Qbit2* q1;
		Qbit2* q2;
		ep1.generate(&q1, &q2, &ent1);
		ent1->print();
		q1->print();
		q2->print();

		cin >> a;
	}
	return 0;
}