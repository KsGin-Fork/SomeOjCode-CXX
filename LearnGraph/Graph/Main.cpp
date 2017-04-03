#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include "AdjacencyMatrixGraph.h"
#include "AdjacencytableGraph.h"

int main(int argc , char* argv[])
{
	//_CrtSetBreakAlloc(167);
	auto c_p = new int*[5]
	{ 
		new int[3]{0 , 1 ,4} , new int[3]{ 0 , 2,  -1} ,
		new int[3]{1 , 2 ,3} , new int[3]{ 1 , 3 , 5} ,
		new int[3]{3 , 4 ,10}
	};


	auto *g = new AdjacencyTableGraph("12345" , 5 , c_p , 5 , false);
	//std::cout << g->TPS().c_str() << std::endl;
	//std::cout << "A => " << "Out = " << g->OutDeGreeOf('A') << " In = " << g->InDegreeOf('A') << std::endl;
	//std::cout << "B => " << "Out = " << g->OutDeGreeOf('B') << " In = " << g->InDegreeOf('B') << std::endl;
	//std::cout << "C => " << "Out = " << g->OutDeGreeOf('C') << " In = " << g->InDegreeOf('C') << std::endl;
	//std::cout << "D => " << "Out = " << g->OutDeGreeOf('D') << " In = " << g->InDegreeOf('D') << std::endl;
	//std::cout << "E => " << "Out = " << g->OutDeGreeOf('E') << " In = " << g->InDegreeOf('E') << std::endl;
	/*std::cout << g->DFS().c_str() << std::endl;
	std::cout << g->BFS().c_str() << std::endl;
	std::cout << g->UCT() << std::endl;*/

	//std::cout << g->NLC().size() << std::endl;

	/*auto s = g->MLP();
	auto money = 0;
	for (auto i = 11 ; i < 11 + s ; i++)
	{
		money += i;
	}
	std::cout << money;*/
	std::cout << 
	g->MST(new int[5] {-1 , 10 ,10 ,1, 1} , 5)
	<< std::endl;
	for (auto i = 0; i < 4; i++)
		delete[] c_p[i];
	delete[] c_p;
	delete g;
	
	_CrtDumpMemoryLeaks();
	system("Pause");
	return 0;
}

