#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void	fill(char **tab, t_point size, char target, int y, int x)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return ;
	if (tab[y][x] == 'F' || tab[y][x] != target)
		return ;
	tab[y][x] = 'F';
	fill(tab, size, target, y - 1, x);
	fill(tab, size, target, y + 1, x);
	fill(tab, size, target, y, x - 1);
	fill(tab, size, target, y, x + 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}

int main(void)
{
	char row0[] = {'0', '1', '0', '0'};
	char row1[] = {'0', '0', '0', '1'};
	char row2[] = {'1', '0', '1', '0'};
	char row3[] = {'1', '1', '1', '1'};
	char *grid[] = {row0, row1, row2, row3};
	t_point size = {4, 4};
	t_point start = {2, 3}; // Middle position
	printf("Before flood fill:\n");
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			printf("%c ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	flood_fill(grid, size, start);
	printf("\nAfter flood fill:\n");
	i = 0;
	while (i < 4) {
		int j = 0;
		while (j < 4) {
			printf("%c ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
