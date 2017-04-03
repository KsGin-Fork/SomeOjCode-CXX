#define CRTDBG_MAP_ALLOC
#include "BinaryTree.hpp"
#include "Tree.hpp"
#include "HuffmanTree.hpp"
#include <iomanip>

using namespace std;
//≤‚ ‘¥˙¬Î
int main(int argc , char* argv[])
{

	typedef stack<char> stack;
	stack s;
	cout << s.empty() << endl;

	//auto list = new int[6];
	//for (auto i = 0 ; i < 6 ; i++)
	//{
	//	cin >> list[i];
	//}
	//string str1 , str2;
	//cin >> str1 >> str2;
	//auto *tree = new HuffmanTree("ABCDEF" , new int[6] {3 ,4 ,10 , 8, 6 ,5});
	//cout << "A:" << tree->Binarycode('A') << endl;
	//cout << "B:" << tree->Binarycode('B') << endl;
	//cout << "C:" << tree->Binarycode('C') << endl;
	//cout << "D:" << tree->Binarycode('D') << endl;
	//cout << "E:" << tree->Binarycode('E') << endl;
	//cout << "F:" << tree->Binarycode('F') << endl;
	//cout << tree->Coding(str1) << endl;
	//cout << tree->Translate(str2) << endl;
	//delete tree;
	//delete[] list;

	//_CrtSetBreakAlloc(161);

	auto data = new char[200];
	cin.getline(data , 200 , '#');
	string codebuf;
	cin >> codebuf;
	auto tree = new HuffmanTree(data);
	//tree->PrintTree();
	cout << "After coding => \n"<< tree->Coding(data) << endl;
	cout << "After translate => \n"<< tree->Translate(codebuf) << endl;
	/*cout << tree->Binarycode('w') << "\t" << tree->Binarycode('.') << "\t" << tree->Binarycode('g');
	cout << tree->Weight('w') << '\t' << tree->Weight('.') << "\t" << tree->Weight('g');*/
	cout << setprecision(3) << tree->AverageCodeLength() << endl;
	delete[] data;
	delete tree;
	_CrtDumpMemoryLeaks();              //ºÏ≤‚ƒ⁄¥Ê–π¬©
	system("Pause");
	return 0;
}
