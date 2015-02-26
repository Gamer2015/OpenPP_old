#include <iostream>
using namespace std;

unsigned int twoDeep = 0;
unsigned int threeDeep = 0;
unsigned int fourDeep = 0;
unsigned int fiveDeep = 0;
unsigned int sixDeep = 0;
unsigned int sevenDeep = 0;
unsigned int eightDeep = 0;
unsigned int nineDeep = 0;

struct point{
	bool touched;
	unsigned int number;
	unsigned short rt;
	unsigned short * rlist;
};
point makePoint( unsigned short num){
	point p;
	p.touched = false;
	p.number = num;
	switch ( num ){
	case 0:
		p.rt = 3;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 1;
		p.rlist[1] = 3;
		p.rlist[2] = 4;
		break;
	case 1:
		p.rt = 5;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 0;
		p.rlist[1] = 2;
		p.rlist[2] = 3;
		p.rlist[3] = 4;
		p.rlist[4] = 5;
		break;
	case 2:
		p.rt = 3;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 1;
		p.rlist[1] = 4;
		p.rlist[2] = 5;
		break;
	case 3:
		p.rt = 5;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 0;
		p.rlist[1] = 1;
		p.rlist[2] = 3;
		p.rlist[3] = 6;
		p.rlist[4] = 7;
		break;
	case 4:
		p.rt = 8;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 0;
		p.rlist[1] = 1;
		p.rlist[2] = 2;
		p.rlist[3] = 3;
		p.rlist[4] = 5;
		p.rlist[5] = 6;
		p.rlist[6] = 7;
		p.rlist[7] = 8;
		break;
	case 5:
		p.rt = 5;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 1;
		p.rlist[1] = 2;
		p.rlist[2] = 4;
		p.rlist[3] = 7;
		p.rlist[4] = 8;
		break;
	case 6:
		p.rt = 3;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 3;
		p.rlist[1] = 4;
		p.rlist[2] = 7;
		break;
	case 7:
		p.rt = 5;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 3;
		p.rlist[1] = 4;
		p.rlist[2] = 5;
		p.rlist[3] = 6;
		p.rlist[4] = 8;
		break;
	case 8:
		p.rt = 3;
		p.rlist = new unsigned short[p.rt];
		p.rlist[0] = 4;
		p.rlist[1] = 5;
		p.rlist[2] = 7;
		break;
	default:
		break;
	}
	return p;
}
void getRoutes( point * p ){
	static unsigned int depth = 0;                    // Start a static counter to keep track
	depth++;                                          // of the depth of the recursive loop.
	p->touched = true;                                // Mark the current point as visited
	cout << "Point: "<< p->number <<" - "<< p->rt << " routes via [ ";
		for(int i = 0; i < p -> rt; i++)
			cout << p -> rlist[i] << " ";
		cout << "]\n";
	for(int i = 0; i < p -> rt; i++){
		int jmpSize = p->rlist[i] - p->number;        //distance between the route and the current value
		cout << "Jump size = " << jmpSize <<endl;
		if( p->rlist[i] != '\0' && !(p + jmpSize)->touched && (p -> number + jmpSize) < 9)
			getRoutes((p + jmpSize));
	}
	p->touched = false;
}
int main(){
	point position[9];
	for( unsigned short i=0; i < 9; i++ )
		position[i] = makePoint(i);
	getRoutes(&position[0]);
	return 0;
}
/*
#include <iostream>
#include <vector>

struct point {
	bool touched;
		unsigned int number;  /// Not needed anywhere
	std::vector<unsigned short> rlist;
};

point makePoint(unsigned short num){
	point p;
	p.touched = false;
	switch ( num ){
		case 0:
			p.rlist.push_back(1);
			p.rlist.push_back(2);
			p.rlist.push_back(3);
			break;

		case 1:
			p.rlist.push_back(0);
			p.rlist.push_back(2);
			p.rlist.push_back(3);
			break;

		case 2:
			p.rlist.push_back(0);
			p.rlist.push_back(1);
			p.rlist.push_back(3);
			break;

		case 3:
			p.rlist.push_back(0);
			p.rlist.push_back(1);
			p.rlist.push_back(2);
			break;
		/*
	case 0:
		p.rlist.push_back(1);
		p.rlist.push_back(3);
		p.rlist.push_back(4);
		break;
	case 1:
		p.rlist.push_back(0);
		p.rlist.push_back(2);
		p.rlist.push_back(3);
		p.rlist.push_back(4);
		p.rlist.push_back(5);
		break;
	case 2:
		p.rlist.push_back(1);
		p.rlist.push_back(4);
		p.rlist.push_back(5);
		break;
	case 3:
		p.rlist.push_back(0);
		p.rlist.push_back(1);
		p.rlist.push_back(3);
		p.rlist.push_back(6);
		p.rlist.push_back(7);
		break;
	case 4:
		p.rlist.push_back(0);
		p.rlist.push_back(1);
		p.rlist.push_back(2);
		p.rlist.push_back(3);
		p.rlist.push_back(4);
		p.rlist.push_back(5);
		p.rlist.push_back(6);
		p.rlist.push_back(7);
		p.rlist.push_back(8);
		break;
	case 5:
		p.rlist.push_back(1);
		p.rlist.push_back(2);
		p.rlist.push_back(4);
		p.rlist.push_back(7);
		p.rlist.push_back(8);
		break;
	case 6:
		p.rlist.push_back(3);
		p.rlist.push_back(4);
		p.rlist.push_back(7);
		break;
	case 7:
		p.rlist.push_back(3);
		p.rlist.push_back(4);
		p.rlist.push_back(5);
		p.rlist.push_back(6);
		p.rlist.push_back(8);
		break;
	case 8:
		p.rlist.push_back(4);
		p.rlist.push_back(5);
		p.rlist.push_back(7);
		break;

	default:
		break;
	}
	return p;
}
int GetCombinations(int start, std::vector<point> points)
{
	points[start].touched = true;
	int combinations = 0;

	for(int i = 0; i < points[start].rlist.size(); i++)
	{
		if(points[points[start].rlist[i]].touched == false)
		{
			combinations += 1; // When a Point is not touched yet, increase counter by 1
						// look for all combinations with that points that are not touched
			combinations += GetCombinations(points[start].rlist[i], points);
		}
	}

	points[start].touched = false;
	return combinations;
}
void GetCombinations(std::vector<point> points)
{
	int combinations = 0;

	for(int i = 0; i < points.size(); i++)
		combinations += GetCombinations(i, points);

	std::cout << "Possible Combinations: " << combinations << std::endl;
}

int main(void)
{
	std::vector<point> Points;
	for( unsigned short i=0; i < 4; i++)
		Points.push_back(makePoint(i));
	GetCombinations(Points);
	return 0;
}
		*/
