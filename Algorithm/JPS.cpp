//JPS(Jump Point Search)
#include<stdio.h>
#include "JPS.h"
#include <windows.h>

static int map[7][7]
{
	  {1,1,0,0,0,0,0},
	  {0,1,1,1,1,0,0},
	  {0,1,0,0,1,1,1},
	  {0,1,1,1,1,1,0},
	  {0,1,0,0,0,1,0},
	  {0,1,0,0,0,1,0},
	  {0,1,1,1,1,1,1},
};


void JPSClass::Start()
{
	system("cls");
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
	{
		for (int j = 0; j < sizeof(map[0]) / sizeof(int); j++)
		{
			if (map[i][j] == 1)
			{
				printf("бр");
			}
			else if(map[i][j] == 0)
			{
				printf("бс");
			}
		}
		printf("\n");
	}
	printf("в├");
}
