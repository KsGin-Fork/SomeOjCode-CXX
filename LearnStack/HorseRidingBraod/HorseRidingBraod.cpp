/*
*Created 2016 10 14
*Author:Yangfan
*Email:imqqyangfan@gmail.com
*Github:https://www.Github.com/Amnnny
*
*/

#include <cstdio>
#include <cstdlib>
using namespace std;


//课本上有
//C++风格 不懂问我

/////////--------------------------------------------------定义信息-------------------------------------------------------
#define STACK_SIZE 100              //存储空间初始分配量
#define STACKINCREAMENT 10          //存储空间分配增量
#define N 8                         //棋盘横纵大小
int weight[N][N];                   //各点的权值
int Board[N][N][8];                 //按各点权值递升存放待走方向，每个点都有八个
                                    //马走'日'
                                    //设马位于(x , y)  则应走方向为 (i+1 , j-2) , (i+1 , j+2) , (i-1 , j+2) , (i-1 , j-2)
                                    //							  (i-2 , j+1) , (i-2 , j-1) , (i+2 , j-1) , (i+2 , j+1)

///定义位置结构体，存储马当前的位置
typedef struct                      
{
	int x_pos_;//X值的坐标
	int y_pos_;//Y值的坐标
} PosType;

typedef struct 
{
	int ord;
	PosType seat;          //马当前的位置
	int direction;         //马的下一步方向
}
ElemType;
///定义栈
typedef struct                 //栈中存储马的每一步操作
{
	ElemType *base;            //栈
	ElemType *top;             //栈顶
	int stacksize;             //栈的大小
}SqStack;


SqStack sq_stack;             //定义一个全局变量栈  之后就以此栈操作
/////////----------------------------------------------定义信息----------------------------------------------------------------

/////////----------------------------------------------函数定义----------------------------------------------------------------

///初始化一个空栈
bool InitEmptyStack()
{
	sq_stack.base = static_cast<ElemType *>(malloc(STACK_SIZE * sizeof(ElemType)));
	if (!sq_stack.base) return false;       //判断内存是否分配成功
	sq_stack.top = sq_stack.base;           //栈顶 = 栈底  （空栈）
	sq_stack.stacksize = STACK_SIZE;        //(这书上写法，个人侵向于使用MAXSIZE 与 Cursize描述总大小和当前大小 ， 都可以)
	return true;
}

///查看栈顶的值,不出栈
ElemType GetTopElem()
{
	if (sq_stack.top == sq_stack.base) exit(0);   //由于仅仅是为了本题需要写的栈  所以若为空可以直接退出
	return *(sq_stack.top - 1);                   
}

///元素入栈
void Push(ElemType elem)                   
{
	*sq_stack.top++ = elem;
}

///元素出栈
bool Pop(ElemType *elem)
{
	if (sq_stack.top == sq_stack.base) return false;         //bool型
	*elem = *(--sq_stack.top);
	return true;
}

///判断栈空
bool IsEmpty()                                         //判空
{
	if (sq_stack.top == sq_stack.base) return true;
	return false;
}

///输出马走过的路径
void ShowPath()
{
	auto t_stack = sq_stack;                       //由于要对栈进行遍历操作  所以使用临时引用指向栈
	int path[N][N] = {};                        
	for (auto i = 0 ; t_stack.top != t_stack.base ; i++)
	{
		//下面这一步的意思是：
		//从栈的底部开始遍历（就是从马所走的第一步开始遍历，然后给对应的x，y点（path二维数组）上赋值当前是第几步 
		//比如栈底的马的位置元素是（3，2），就给path[3][2]赋值 1 ，然后给下一个位置赋值 2
		path[(*t_stack.base).seat.x_pos_][(*t_stack.base).seat.y_pos_] = i + 1;
		++t_stack.base; //栈底指针自增  到达下一步的位置
	}
	for (auto i = 0 ; i < N ; i ++)             //输出二维数组
	{
		printf("\n");
		for (auto j = 0 ; j < N ; j++)
		{
			printf("\t%d" , path[i][j]);
		}
		printf("\n");
	}
}

///判断当前位置是否合法
bool Pass(PosType curpos)
{
	auto t_stack = sq_stack;
	if (curpos.x_pos_ < 0 || curpos.x_pos_ > (N - 1) || curpos.y_pos_ < 0 || curpos.y_pos_ > (N - 1)) //判断位置是否合法
		return false; 
	for (; t_stack.base != t_stack.top; )                   //判断这一步是否已经走过（从栈顶到底部开始循环对比  如果有相等说明这一个点马已经走过了）
	{
		--t_stack.top;
		if (curpos.x_pos_ == (*t_stack.top).seat.x_pos_ && curpos.y_pos_ == (*t_stack.top).seat.y_pos_)
		{
			return false;
		}
	}
	return true;
}

///8个候选方向
PosType NextPos(PosType curpos , int direction)     //两个参数，用一个switch计算下一步马的位置（使用一个二维坐标轴可以找到这些点并且总结出规律）
{
	switch (direction)
	{
		case 1: curpos.x_pos_ += 1 , curpos.y_pos_ -= 2; break;
		case 2: curpos.x_pos_ += 2 , curpos.y_pos_ -= 1; break;
		case 3: curpos.x_pos_ += 2 , curpos.y_pos_ += 1; break;
		case 4: curpos.x_pos_ += 1 , curpos.y_pos_ += 2; break;
		case 5: curpos.x_pos_ -= 1 , curpos.y_pos_ += 2; break;
		case 6: curpos.x_pos_ -= 2 , curpos.y_pos_ += 1; break;
		case 7: curpos.x_pos_ -= 2 , curpos.y_pos_ -= 1; break;
		case 8: curpos.x_pos_ -= 1 , curpos.y_pos_ -= 2; break;
		default: break;
	}
	return curpos;
}

///求各点权值
void setWeight()                   //假设当前点为a点，a的下一个点有b点和c点，b点下一个点有四个可以走的地方，c点下一个点有三个可以走的，则b点权值大
{
	//这里算出了每一个点下一步可以走的合法点的个数，使用全局变量weight存储起来
	PosType m;
	ElemType elem;
	for (auto i = 0 ; i < N ; i++)
	{
		for (auto j = 0 ; j < N ; j++)
		{
			elem.seat.x_pos_ = i;
			elem.seat.y_pos_ = j;
			weight[i][j] = 0;
			for (auto k = 0 ; k < 8 ; k++)
			{
				m = NextPos(elem.seat , k + 1);       //获得当前点的下一个点
				if (m.x_pos_ >= 0 && m.y_pos_ >= 0 && m.x_pos_ < N && m.y_pos_ < N)      //如果下一个点合法，这个点的权值+1
					weight[i][j]++;                                                      //(i , j)点下一步可以移动多少个方向即为这点的权值
			}
		}
	}
}

///对下一个点的八个位置排序
void SortMapByWeight()    
{
	//Board三维数组是用来存储当马在(x,y)点的时候的第n个点(即(x,y,n))的权值大小  然后使用权值大小排序
	int arr[8] , min;
	PosType n1 , n2;
	for (auto i = 0 ; i < N ; i++)
	{
		for (auto j = 0 ; j < N ; j++)
		{
			//前两个循环遍历棋盘的每一个点，循环里边则对这一个点的权值进行了赋值排序，并且存入到最终的board全局变量里边
			//我觉得这里有点重复的问题  有时间会好好改改
			for (auto k = 0 ; k < 8 ; k++)                       //遍历8个点
			{
				n2.x_pos_ = i;
				n2.y_pos_ = j;
				n1 = NextPos(n2 , k + 1);
				if (n1.x_pos_ >= 0 && n1.x_pos_ < N && n1.y_pos_ >= 0 && n1.y_pos_ < N)
				{
					arr[k] = weight[n1.x_pos_][n1.y_pos_];            //将权值赋值给arr                   
				}
				else
				{
					arr[k] = 0;
				}
			}
			auto s = 0;
			//排序
			//对方向索引权值升序排列存入Board
			for (auto f = 0 ; f < 8 ; f++) 
			{
				min = 9;
				for (auto m = 0 ; m < 8 ; m++)
				{
					if (min > arr[m])
					{
						min = arr[m];
						Board[i][j][f] = m;
						s = m;
					}
				}
				arr[s] = 9;   //选过的设为9
			}
		}
	}
}


bool HorsePath(PosType start)
{
	auto curpos = start;
	int horsestep = 0 , off;
	ElemType elem = {};
	do
	{
		if (Pass(curpos))   //如果当前的位置合法,就将这一步压入栈中
		{
			horsestep++;    
			elem.direction = 0; 
			elem.ord = horsestep;
			elem.seat = curpos;
			Push(elem);  //入栈
			if (N * N == horsestep) return true;   //且判断是否已经到了N*N（即最后一步），如果到了直接结束
			off = Board[elem.seat.x_pos_][elem.seat.y_pos_][elem.direction]+1;     //没到的话找下一步
			curpos = NextPos(elem.seat , off);                                    //获得下一步的位置并且继续循环
		}
		else              //如果当前位置不合法。则需要从上一个位置重新找
		{
			if (!IsEmpty())    //如果为空的话也就是没有上一个位置了（当初始输入位置就不合法的时候）
			{
				while (!IsEmpty() && elem.direction == 8)      //如果栈顶的direction为8，则说明上一个点的所有有可能的下一步都走完了，就需要从上上一个点继续查找（可能看着我写的有点乱）
				{
					Pop(&elem);             //将栈顶值弹出（已经不可行了，需要回溯到可行的位置）
					if (!IsEmpty())     //判断弹出后是否为空
					{
						elem = GetTopElem();
						horsestep = elem.ord;
					}
				}
				if (!IsEmpty() && elem.direction < 8)     //如果directtion小于8，则说明这个点还有其他方向没有试过，则一一去试。
				{
					Pop(&elem);
					off = Board[elem.seat.x_pos_][elem.seat.y_pos_][++elem.direction];
					curpos = NextPos(elem.seat , off + 1);
					Push(elem);
				}
			}
		}
	}
	while (!IsEmpty());
	printf("走不通!");   //一般是会以上边的走到最后一步结束，如果没有说明走不通，给出提示
	return false;
}
/////////----------------------------------------------函数定义----------------------------------------------------------------

int main(int argc , char **args)
{
	system("color 0b");  //这一行是设置cmd窗口的颜色，可以不看
	PosType start;           //定义start结构体元素
	InitEmptyStack();        //初始化
	printf("输入起始位置(X , Y):");
	// ReSharper disable once CppDeprecatedEntity
	scanf("%d%d" , &start.x_pos_ , &start.y_pos_);
	setWeight();      //对每一个位置求权值
	SortMapByWeight();  //权值排序
	HorsePath(start);   //从初始位置开始走
	ShowPath();     //输出
	system("Pause");  //这一行是暂停窗口，可以不看
	return 0;
}
