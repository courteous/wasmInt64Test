#ifndef MAIN_WASM
#define MAIN_WASM

#include <iostream>
#include <emscripten/emscripten.h>

using namespace std;

namespace wasm {

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE void intTest(
		int32_t int32TypeArg,
		uint32_t uint32TypeArg,
		int64_t int64TypeArg,
		uint64_t uint64TypeArg
	){
	std::cout << " int32_t     :" << int32TypeArg << std::endl;
	std::cout << " uint32_t    :" << uint32TypeArg << std::endl;
	std::cout << " int64_t     :" << int64TypeArg << std::endl;
	std::cout << " uint64_t    :" << uint64TypeArg << std::endl;

}

int main(int argc, char **argv) {
 	cout << argc << endl;
 	cout << argv << endl;

	return 0;
}


#ifdef __cplusplus
}
#endif

}

#endif
