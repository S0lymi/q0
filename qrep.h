#pragma once
#include <iostream>
#include "Eigen/Dense"



using namespace Eigen;
using namespace std;


class Entbit;
class Entanglement2;
class Entanglement;
class Qbit2
{
public:

	Vector2cd* ind;
	Entbit* ent;
	double age;

	//konst
	Qbit2(Vector2cd *indk = NULL, Entbit* entk = NULL, double agek = 0);
	//dest
	~Qbit2();
	//mas
	void print();

};
class Entbit
{
public:
	Entanglement2* ent;
	Vector2cd* ampls;
	Qbit2 * qbit;

	//konst
	Entbit(Entanglement2* entk = NULL, Vector2cd* amplsk = NULL, Qbit2 * qbitk = NULL);
	//dest
	~Entbit();
	//mas
	void print();
};

class Entanglement2
{
public:
	Matrix2i* states;
	Vector2cd* ampls;
	Entbit* bits[2];

	//konst
	Entanglement2(Matrix2i* statesk = NULL, Vector2cd* amplsk = NULL, Entbit* bit1 = NULL, Entbit* bit2 = NULL);
	//dest
	~Entanglement2();
	//mas
	void print();
};
class Entanglement
{
	VectorXi* states;
	Vector2cd* ampls;
	Entbit* bits;
	//konst
	Entanglement(VectorXi* statesk = NULL, Vector2cd*amplsk = NULL, Entbit* bitsk = NULL);
	//dest
	~Entanglement();

};