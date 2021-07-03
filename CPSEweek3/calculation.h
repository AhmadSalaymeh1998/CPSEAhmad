#ifndef CALCULAION_H
#define CALCULAION_H

#include "hwlib.hpp"
#include <math.h>



constexpr double radians_from_degrees(int degrees ){
	return 2 * 3.1416 * ((degrees) / 360.0);
}


constexpr double pow(double g, int n){
	double result = 1;
	while(n>0){
		result *= g;
		--n;
	}
	return result;
}

constexpr double Fac( int n ){
	double result =1;
	while(n>0){
		result *= n;
		--n;
	}
	return result;
}

//constexpr double mysin( double d ){
//	return d
//		-pow(d,3) / Fac(3)
//		+pow(d,5) / Fac(5)
//		-pow(d,7) / Fac(7)
//		+pow(d,9) / Fac(9)
//		-pow(d,11) / Fac(11)
//		+pow(d,13) / Fac(13)
//		-pow(d,15) / Fac(15)
//		+pow(d,17) / Fac(17);
//}
//
//constexpr double mycos( double d ){
//	return d
//		-pow(d,2) / Fac(2)
//		+pow(d,4) / Fac(4)
//		-pow(d,6) / Fac(6)
//		+pow(d,8) / Fac(8)
//		-pow(d,10) / Fac(10)
//		+pow(d,12) / Fac(12)
//		-pow(d,14) / Fac(14)
//		+pow(d,16) / Fac(16);
//}

constexpr int scaled_sine_from_degrees(int degrees){
	return 64 + (32 *  sin(radians_from_degrees(degrees)));	
}

constexpr int scaled_cosine_from_degrees(int degrees){
	return 32 + (32 *  cos(radians_from_degrees(degrees-180)));	// -180 omdat de klok gespigeld was in y-as.
}

template <int N, typename T>
class lookup{
private:
	std::array<T,N> values={};
public:
	template<typename F>
	constexpr lookup(F function){
		for(int i=0; i<N; i++){
			values[i]=function(6 * i);
		}
	}
	constexpr T get(int n) const{
		return values[n/6];
	}
};


#endif