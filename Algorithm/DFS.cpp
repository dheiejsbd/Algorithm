#include<stdio.h>
#include"Vector.h"
#include<Windows.h>

//DFS (Depth First Search) ���� �켱 Ž��
//Ʈ�� ������ȸ
//1. ��带 �湮
//2. ���� ����Ʈ���� ������ȸ��
//3. ������ ����Ʈ���� ������ȸ��

//		   A
//		  / \
//		 B	 C
//		/ \ / \
//     D  E F  G
//
//  ���� Ʈ���� ��� A - B - D - E - C - F - G�� ������ Ž���Ѵ�.


// �Ʒ��� �ڵ�� DFS�� Ȱ���Ͽ� �ִܰŸ��� ���ϴ� �˰���

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

int minDist;//�ִܰŸ�
int mapRow; //mapX
int mapColumn; //mapY
int n = 0;

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
	map[y][x] = 0;//�湮Ȯ��

	Sleep(500);
	DrawMap();
	PrintMinDist();

	if (CanMoveUp(x, y)) DFS(x, y-1,l+1);
	if (CanMoveDown(x, y)) DFS(x, y+1,l+1);
	if (CanMoveLeft(x, y)) DFS(x-1, y,l+1);
	if (CanMoveRight(x, y)) DFS(x+1, y,l+1);

	map[y][x] = 1;//�湮�������

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