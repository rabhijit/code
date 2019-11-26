#include <stdio.h> 
#include <string.h> 


#define NUM_DISCS 4

typedef struct
{
    int peg[3][NUM_DISCS];
    char name[30];
} Towers;

void make_moves(Towers *t, int n, int src, int des, int aux);
void init_towers(Towers *t, const char name[]);
void print_towers(Towers t);
void move_disc(Towers *t, int src, int des);

int main(void)
{
    Towers t;
    init_towers(&t, "Hanoi");
    printf("Towers of %s\n", t.name);
    print_towers(t);
    make_moves(&t, NUM_DISCS, 0, 2, 1);
    return 0;
}

void make_moves(Towers *t, int n, int src, int des, int aux)
{
    if (n <= 0)
        return;
    make_moves(t, n - 1, src, aux, des);
    move_disc(t, src, des);
    make_moves(t, n - 1, aux, des, src);
    return;
}

//


void print_towers(Towers t)
{
    for (int i = 0; i < 3; i++)
    {
        printf("[ ");
        for (int j = 0; j < NUM_DISCS; j++)
        {
            if (t.peg[i][j] == 1) {
                printf("%d ", j);
            }
        }
        if (i!=2) {
            printf("], ");
        }
        else {
            printf("]\n");
        }
    }
}

void init_towers(Towers * t, const char name[])
{
    strcpy(t->name, name);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < NUM_DISCS; j++)
        {
            if (i == 0)
            {
                t->peg[i][j] = 1;
            }
            else
            {
                t->peg[i][j] = 0;
            }
        }
    }
}

void move_disc(Towers * t, int src, int des)
{
    for (int j = NUM_DISCS-1; j >= 0; j--) {
        if (t->peg[src][j] == 1) {
            t->peg[src][j] = 0;
            t->peg[des][j] = 1;
            break;
        }
    }
    print_towers(*t);
    return;
}