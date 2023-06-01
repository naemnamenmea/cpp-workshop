#include "SpiralMatrix.hpp"

int main()
{	
    int n = 2;
	int m = 7;
	auto mtrx = SpiralMatrix::create(n, m);
	SpiralMatrix::print(mtrx);

	//int pos = 27;
	//auto ij = SpiralMatrix::getPosCoord(n, m, pos);
	//std::cout << "pos = " << pos << ". (i,j) = (" << std::get<0>(ij) << "," << std::get<1>(ij) << ")." << std::endl << std::endl;
    return 0;
}

