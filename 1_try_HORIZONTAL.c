#include <stdio.h>
#include <stdbool.h>

int find_result(int* wys, int n)
{	
		int tmp=0;
		int location=0;
		int result=0;
		
	while(1)
    {	
    	
    	location=0;
    
        for (int i = 1; i < n+1; i++)  
	  	{  
	  		
		    if(wys[i]!=0)
		    {
		    location = i;	
		    break;  	/
			}
		    	    	
		}	       
	    
		
	  	for (int i = 1; i < n+1; i++)  
	  	{  
	  		
		    if (wys[i] < wys[location] && wys[i]!=0) 
		    {	
		    	location = i;  
			    			
			    	
			}	     
	    }
	    
	   tmp=location;
	   location = wys[location]; 
	    
	    for (int i = tmp ; i < n+1; i++) 
	  	{  

			if(wys[i] == location && wys[i] != 0)
			 {
			 
				tmp = i;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp--;	
				}
				
				
				tmp=i;
				wys[tmp] = location;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp++;
					i++;	
				}
				result++;
				//oki ale teraz lecimy dalej
			}
			 
			if(wys[i-1] == 0 && wys[i+1] == 0 && wys[i] != 0 ) 
	  	 	 {
			  	 result++;
				 wys[i] = 0; //eliminowanie "wiezowcow"	 
		 	 } 	         
	    }
	    
	    
	    if(location==0)
	    {
	    return result;
		}
 
	}
}

int main(int argc, char** argv) 
{
	
	int n;
	int wys[270000]; 
	int result=0;
	
	scanf("%d\n", &n);
      
	    for(int i=1;i<n+1;i++)
		{      	
			scanf("%d %d\n", &wys[i] , &wys[i]); 
		}
		
		
	
	

	result=find_result(wys, n);
	
	printf("%d",result);
	
 return 0;
}
