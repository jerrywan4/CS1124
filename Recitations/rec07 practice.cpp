#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Instrument{
public:
	virtual void makeNoise(){}
};

class Brass : public Instrument{
	int mouthPiece;
public:
	virtual void makeNoise(){}
};

class Strings : public Instrument{
	int pitch;
public:
	virtual void makeNoise(){}
};

class Percussion : public Instrument{
public:
	virtual void makeNoise(){}
};

class Trombone : public Brass{
	int mouthPiece;
public:
	Trombone(int mouthPiece) : mouthPiece(mouthPiece){}
	void makeNoise(){cout << "yo yo yo i'm a trombone muthafucka" << endl;}
};

class Trumpet : public Brass{
	int mouthPiece;
public:
	Trumpet(int mouthPiece) : mouthPiece(mouthPiece){}
	void makeNoise(){cout << "i wish i didn't have trump in my name :(" << endl;}
};

class Drum : public Percussion{
public:
	void makeNoise(){cout << "bombaclat bombaclat" << endl;}
};

class Cymbal : public Percussion{
public:
	void makeNoise(){cout << "ted cruz is the zodiac killer" << endl;}
};

class Violin : public Strings{
	int pitch;
public:
	Violin(int pitch) : pitch(pitch){}
	void makeNoise(){cout << "i am the world's smallest violin" << endl;}
};

class Cello : public Strings{
	int pitch;
public:
	Cello(int pitch) : pitch(pitch){}
	void makeNoise(){cout << "yo yo ma ma" << endl;}
};

class Mill{
	Instrument*
};


int main(){
  cout << "Define some instruments ----------------------------------------\n";
  Drum drum;
  Cello cello(673);
  Cymbal cymbal;
  Trombone tbone( 4 );
  Trumpet trpt( 12 ) ;
  Violin violin( 567 ) ;

   // // use the debugger to look at the mill
  // cout << "Define the MILL ------------------------------------------------\n";
  // MILL mill;
  
  // cout << "Put the instruments into the MILL ------------------------------\n";
  // mill.receiveInstr( trpt );
  // mill.receiveInstr( violin );
  // mill.receiveInstr( tbone );
  // mill.receiveInstr( drum );
  // mill.receiveInstr( cello );
  // mill.receiveInstr( cymbal );
}