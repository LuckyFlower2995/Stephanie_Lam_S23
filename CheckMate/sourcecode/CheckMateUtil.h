#pragma once

#ifdef CHECKMATE_WINDOWS
	#ifdef CHECKMATE_LIB
		#define CHECKMATE_API __declspec(dllexport)
	#else
		#define CHECKMATE_API __declspec(dllimport)
	#endif
#else
	#define CHECKMATE_API
#endif

#define CHECKMATE_GAME_START(ClassName)\
int main() {\
	ClassName game;\
	game.Run();\
	return 0;\
}

#if CHECKMATE_DEBUG==2
	#define CHECKMATE_LOG(x) std::clog << "Log:" << x << std::endl;
	#define CHECKMATE_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#elif CHECKMATE_DEBUG ==1
	#define CHECKMATE_LOG(x)
	#define CHECKMATE_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#else 
	#define CHECKMATE_LOG(x)
	#define CHECKMATE_ERROR(x)
#endif