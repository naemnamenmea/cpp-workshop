#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <iomanip>

double arithmSum(const double& a, const double& d, const int& n) {
	return (2 * a + (n - 1)*d) / 2 * n;
}

std::tuple<int, double, double> solveQuadEq(const double &a, const double &b, const double &c) {
	double x1, x2;
	double d = (b*b) - (4. * a*c);
	if (d > 0)
	{
		double tx1, tx2;
		tx1 = (-b + sqrt(d)) / (2 * a);
		tx2 = (-b - sqrt(d)) / (2 * a);
		x1 = ((tx1 > tx2) ? tx2 : tx1);
		x2 = ((tx1 > tx2) ? tx1 : tx2);
		return std::make_tuple(2, x1, x2);
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		return std::make_tuple(1, x1, x1);
	}
	else return std::make_tuple(-2, 0., 0.);
}

template <typename T = int>
std::vector< std::vector<T> > getSpiralMatrix(const int& n, const int& m,
	const T& step = 1,
	const std::pair<bool, bool>& corner = std::pair<bool, bool>(true, true))
{
	std::vector< std::vector<T> > spMtrx(n, std::vector<T>(m, 0));

	T cnt = 0;
	int minX = 0;
	int minY = 0;
	int maxX = m - 1;
	int maxY = n - 1;

	bool axe = corner.first; // axe == true  -- X axe OR axe == false -- Y axe
	bool dir = corner.second;

	int i = dir ? 0 : maxY; // Y
	int j = (axe ^ dir) ? maxX : 0; // X

	while (minX <= maxX && minY <= maxY) {
		spMtrx[i][j] += (cnt += step);
		if (axe) {
			if (dir) {
				if (j < maxX) {
					++j;
				}
				else {
					i = ++minY;
					axe = !axe;
				}
			}
			else {
				if (j > minX) {
					--j;
				}
				else {
					i = --maxY;
					axe = !axe;
				}
			}
		}
		else {
			if (dir) {
				if (i < maxY) {
					++i;
				}
				else {
					j = --maxX;
					dir = !dir;
					axe = !axe;
				}
			}
			else {
				if (i > minY) {
					--i;
				}
				else {
					j = ++minX;
					dir = !dir;
					axe = !axe;
				}
			}
		}
	}
	return spMtrx;
}

class SpiralMatrix {
private:
public:
	static std::tuple<int, int, bool> getPosCoord(int n, int m, int pos) {
		auto res = solveQuadEq(-4, 2 * (n + m), -pos);

		if (std::get<0>(res) < 1) {
			return std::make_tuple(0, 0, false);
		}

		int k = (int)std::ceil(std::get<1>(res));
		--k;
		int newN = n - k * 2;
		int newM = m - k * 2;
		int newPos = pos - (int)arithmSum(2 * (n + m) - 4, -8, k);

		if (newPos <= newM) {
			return std::make_tuple(k + newPos - 1, k, true);
		}
		else if (newPos <= newM + newN - 1) {
			return std::make_tuple(k + newM - 1, k + newPos - newM, true);
		}
		else if (newPos <= 2 * (newM - 1) + newN) {
			return std::make_tuple(k + 2 * (newM - 1) - newPos + newN, k + newN - 1, true);
		}
		else {
			return std::make_tuple(k, k + 2 * (newM + newN) - 4 - newPos + 1, true);
		}
	}

	static std::vector< std::vector<int> > create(const int n, const int m) {

		const int _m = m > 0 ? m : 0;
		const int _n = n > 0 ? n : 0;

		std::vector< std::vector<int> > spMtrx(_n, std::vector<int>(_m, 0));
		for (int i = _m*_n; i > 0; i--) {
			auto ij = getPosCoord(_n, _m, i);
			spMtrx[std::get<1>(ij)][std::get<0>(ij)] = i;
		}
		return spMtrx;
	}

	static void print(const std::vector<std::vector<int>>& matrx) {
		if (!matrx.size() || !matrx[0].size()) return;
		for (size_t i = 0; i < matrx.size(); ++i) {
			for (size_t j = 0; j < matrx[0].size() - 1; ++j) {
				std::cout << std::setw(3) << matrx[i][j] << ' ';
			}
			if (matrx[0].size() - 1 >= 0)
				std::cout << std::setw(3) << matrx[i][matrx[0].size() - 1] << std::endl << std::endl;
		}
		std::cout << std::endl;
	}
};