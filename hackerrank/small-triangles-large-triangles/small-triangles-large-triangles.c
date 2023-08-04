#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *tr, int n)
{
    double p , s;
    float erea[n];
    for(int i = 0 ; i < n ; i++)
    {
        p = (tr[i].a + tr[i].b + tr[i].c )/2.0;
        s = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p- tr[i].c));
        erea[i] = s;
    }
    
    int swapped = 0;
    int count = n;
    
    do {
        swapped = 0;
        for (int i = 0; i < count-1; i++) {
            if (erea[i] > erea[i+1]) 
            {
                double erea_tmp = erea[i];
                erea[i] = erea[i+1];
                erea[i+1] = erea_tmp;
                
                int tmp = tr[i].a;
                tr[i].a = tr[i+1].a;
                tr[i+1].a = tmp;
                
                tmp = tr[i].b;
                tr[i].b = tr[i+1].b;
                tr[i+1].b = tmp;
                
                tmp = tr[i].c;
                tr[i].c = tr[i+1].c;
                tr[i+1].c = tmp; 
                
                
                swapped = 1;
            }
        }
        count--;
    }while (swapped == 1);
    
    
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}