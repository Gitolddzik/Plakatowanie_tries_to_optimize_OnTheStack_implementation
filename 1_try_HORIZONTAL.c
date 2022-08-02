#include <stdio.h>
#include <stdbool.h>

/*wymysliłem ten algorytm ze świadomością, że nie będzie
ani najszybszy ani najwydajniejszy, jeżeli chciałbym, żeby
taki był, zformatował bym kod z rozwiązań wzorcowych, ale
raczej nie do końca o to chodziło w zadaniu*/

//debugger i lecisz rano xd
//ale luzik to jakis maly nieistotyl blad


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
		    break;  	//ustawienie lokacjji //jesli mamy tablice najmniejszych wartosci to to jest tez niepotrzebne!
			}
		    	    	
		}	       
	    
		
	  	for (int i = 1; i < n+1; i++)  
	  	{  
	  		
		    if (wys[i] < wys[location] && wys[i]!=0) 
		    {	
		    	location = i;  //pomysł (to zajmuje w chuj czasu ogolnie bo lecimy po całej tablicy za kazdym razem
			    			//pomysł Stworzenie drugiej tablicy ktora na samym poczatku bedzie po kolei miala w sobie indeksy do najmniejszych do najwiekszych
			    	
			}	       //WYSZUKIWANIE NAJMNIEJSZEJ WARTOSCI 
	    }
	    
	   tmp=location;
	   location = wys[location]; //przypisanie do wartosci wartosci z array
	    
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
	int wys[270000]; //tutaj jest kwestia 	int wys[270000][1]; 
	int result=0;
	
	scanf("%d\n", &n);
      
	    for(int i=1;i<n+1;i++)
		{      	
			scanf("%d %d\n", &wys[i] , &wys[i]); //szerokosc jest kompletnie nie potrzebna, daltego nie tworzyłem nawet zmiennej dla niej, zostaje nadpisana  za każdym razem.	
		}
		
		
	
	

	result=find_result(wys, n);
	
	printf("%d",result);
	
 return 0;
}
