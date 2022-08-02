#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

#include <string.h>

/*Program nadal wolniejszy od wzorcowego rozwiązania, wydawało się
jakoby jedyną wadą "na stosie" było nie do końca zoptymalizowane
zliczanie horyzontalne, mimo wszystko nie udało uzyskać lepszych efektów*/

struct str 
{
    int value;
    int index;
};

struct str objects[270000];

int cmp(const void * v1,
    const void * v2) 
	{
    const struct str * p1 = (struct str * ) v1;
    const struct str * p2 = (struct str * ) v2;

    if (p1 -> value < p2 -> value)
    return -1;

    else if (p1 -> value > p2 -> value)
    return +1;

    else
    return 0;
	}	

int find_result(int * wys, int n, int up, int down) 
{
    int tmp = 0, location = 0, result = 0;

    for (int i = 1; i < n + 1; i++) {
        if (wys[up - 1] == 0 && wys[down + 1] == 0) 
        {
            break;
        }
        if (wys[objects[i].index] != 0) 
		{
            location = wys[objects[i].index];

            tmp = objects[i].index;

            while (wys[tmp] != 0) 
			{
                wys[tmp] -= location;
                tmp--;
            }

            tmp = objects[i].index;

            wys[tmp] = location;

            while (wys[tmp] != 0) 
			{
                wys[tmp] -= location;
                tmp++;
            }
            result++;
        }
    }

    return result;
}

int destroy_stairs(int * wys, int up, int down) 
{
    int cntr = 1, result = 0, i = up;

    while (i != down) 
	{
        i++;
        while ((cntr > 0) && (wys[cntr - 1] > wys[i])) 
		{
            cntr--;
        }
        if ((cntr == 0) || (wys[cntr - 1] < wys[i])) 
		{
            result++;
            wys[cntr++] = wys[i];
        }
    }
    return result;
}

int main(int argc, char ** argv) 
{

    int n = 0, result = 0, init_stairs = 1, up = 0, down = 0, wys[270000];
    bool upstairs = false;

    scanf("%d\n", & n);

    for (int i = 1; i < n + 1; i++) 
	{
        scanf("%d %d\n", & objects[i].value, & objects[i].value);
        wys[i] = objects[i].value;
    }

    for (int i = 1; i < n + 1; i++) 
	{
        objects[i].index = i;
    }

    qsort(objects, n + 1, sizeof(objects[0]), cmp);

    for (int i = 1; i < n + 1; i++) 
	{

        if (wys[i] >= wys[i - 1] && upstairs != true) 
		{
            init_stairs++;
        } else 
		{
            init_stairs = 0;
        }
        if (init_stairs == 10000) 
		{
            upstairs = true;
            init_stairs = 0;
            up = i;
            i += 1;
        }
        if (wys[i] <= wys[up] && upstairs == true) 
		{
            down = i;
            upstairs = false;
        }
    }

    result += find_result(wys, n, up, down);

    result += destroy_stairs(wys, up, down);

    printf("%d", result);

    return 0;
}