#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct str
{
    int value;
    int index;
};

struct str objects[270000];

int cmp(const void* pa, const void* pb)
{
    int a = ((struct str*)pa)->value;
    int b = ((struct str*)pb)->value;
    return (a > b) - (a < b);
}

int find_result(int* wys, int n)
{	
		int tmp=0;
		int location=0;
		int result=0;  
		
	for(int i=1 ; i<n+1 ; i++) 
    {	
    	if(wys[objects[i].index] != 0) 
			{
				location = wys[objects[i].index];
				
				tmp = objects[i].index;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp--;	
				}
				
				
				tmp=objects[i].index;
				
				wys[tmp] = location;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp++;	
				}
				result++;    
	    	}
	 
  
	}
			    
	return result;
}

int main(int argc, char** argv) 
{
	
	int n;
	int wys[270000];
	wys[0]=0;
	int result=0;
	
	//int stairs;
	
	scanf("%d\n", &n);
      
	    for(int i=1;i<n+1;i++)
		{      	
			scanf("%d %d\n", &objects[i].value , &objects[i].value); 
			wys[i]=objects[i].value;
		}
		
    for (int i = 1; i < n+1; i++)
    {
        objects[i].index = i;
    }
    
     qsort(objects, n+1 , sizeof(objects[0]), cmp);
     
   
    
	result=find_result(wys, n);
	
	printf("%d",result);
	
 return 0;
}
