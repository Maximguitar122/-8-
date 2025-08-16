#include <iostream>
using namespace std;
class Herbivore {
	friend class Carnivore;
	
	int weight;
	string name;
public:
	Herbivore(int w, string n) {
		weight = w;
		name = n;
	}
	virtual void  EatGrass() {
		weight += 10;
		cout << name << "Eating\n";
	}
	virtual ~Herbivore() {};
};
class Wildebeest : public Herbivore {
public:
	Wildebeest() : Herbivore(40, "Antilope") {};
};
class Bisson : public Herbivore {
public:
	Bisson() : Herbivore(40, "Bisson") {};
};
class Carnivore {
	string name;
	int power;
public:
	Carnivore(int p, string n) {
		power = p;
		name = n;
	}
	virtual void Eat(Herbivore& herb) {
		if (herb.weight > power) {
			power = -10;
			cout << name << "couldn't eat\n";
		}
		else {
			power = +10;
			cout << name << "could eat\n";
		}
	}
	virtual  ~Carnivore() {};
};
class Lion : public Carnivore {
public:
	Lion() : Carnivore(50, "Lion") {};
};
class Wolf : public Carnivore {
public:
	Wolf():Carnivore(40, "Wolf") {};
};


class Continent {
	string name;
	Herbivore*herb;

	Carnivore*carn;

	
public:
	Continent(string n, Herbivore*h,Carnivore*c ){
		name = n;
		herb = h;
		carn = c;
	};
	virtual void Life() {
		cout << "континент\n" << name;
		herb->EatGrass();
		carn->Eat(*herb);
		
	}
	~Continent() {
		delete herb;
	;
		delete carn;
	
	};
};
class Africa : public Continent {
public:
	Africa() :Continent("Африка", new Wildebeest(), new Lion()) {}
};
class Europe : public Continent {
public:
	Europe() : Continent("Європа", new Bisson(), new Wolf()){}
};


int main()
{
	Africa a;
	a.Life();
	Europe e;
	e.Life();

}

