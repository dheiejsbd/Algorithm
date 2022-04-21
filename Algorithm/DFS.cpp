#include<stdio.h>
#include<Windows.h>

//DFS (Depth First Search) 깊이 우선 탐색
//트리 전위순회
//1. 노드를 방문
//2. 왼쪽 서브트리를 전위순회함
//3. 오른쪽 서브트리를 전위순회함

//		   A
//		  / \
//		 B	 C
//		/ \ / \
//     D  E F  G
//
//  위의 트리의 경우 A - B - D - E - C - F - G의 순서로 탐색한다.


// 아래의 코드는 DFS를 활용하여 최단거리를 구하는 알고리즘

int map[7][7] =
{
	  {1,1,0,0,0,0,0},
	  {0,1,1,1,1,0,0},
	  {0,1,0,0,1,1,0},
	  {0,1,1,1,1,1,0},
	  {0,1,0,0,0,1,0},
	  {0,1,0,0,0,1,0},
	  {0,1,1,1,1,1,1},
};

int minDist;//최단거리
int mapRow; //mapX
int mapColumn; //mapY

bool EndPoint(int x,int y)
{
	return x == mapRow-1 && y == mapColumn-1;
}

#pragma region CanMove
bool CanMoveRight(int x, int y)
{
	return x < mapRow - 1 && map[y][x + 1] == 1;
}

bool CanMoveLeft(int x, int y)
{
	return x > 0 && map[y][x - 1] == 1;
}

bool CanMoveUp(int x, int y)
{
	return y > 0 && map[y - 1][x] == 1;
}

bool CanMoveDown(int x, int y)
{
	return y < mapColumn-1 && map[y + 1][x] == 1;
}
#pragma endregion
void DrawMap()
{
	system("cls");
	for (int i = 0; i < mapRow; i++)
	{
		for (int e = 0; e < mapColumn; e++)
		{
			printf("%d ", map[i][e]);
		}
		printf("\n");
	}
}

void PrintMinDist()
{
	if (minDist == mapRow * mapColumn + 1)
	{
		printf("Can't Find Path\n");
	}
	else
	{
		printf("minDist: %d\n", minDist);
	}
}

void DFS(int x, int y, int l)
{
	if (EndPoint(x, y))
	{
		if (l < minDist) minDist = l;
		return;
	}
	map[y][x] = 0;//방문확인

	Sleep(500);
	DrawMap();
	PrintMinDist();

	if (CanMoveUp(x, y)) DFS(x, y-1,l+1);
	if (CanMoveDown(x, y)) DFS(x, y+1,l+1);
	if (CanMoveLeft(x, y)) DFS(x-1, y,l+1);
	if (CanMoveRight(x, y)) DFS(x+1, y,l+1);

	map[y][x] = 1;//방문기록제거 - 이전분기점까지 돌아감

	Sleep(100);
	DrawMap();
	PrintMinDist();
}



int main()
{
	mapRow = sizeof(map[0]) / sizeof(int);
	mapColumn = sizeof(map) / sizeof(map[0]);
	minDist = mapRow * mapColumn + 1;

	DrawMap();
	PrintMinDist();

	DFS(0, 0, 0);
	
	return 0;
}
