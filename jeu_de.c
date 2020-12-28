#include <stdio.h>

int main(int argc, char* argv[])
{
    //dés player1
    int a=0;
    int b=0;
    int c=0;
    //dés player2
    int m=0;
    int n=0;
    int o=0;
    //tri player1
    int x1=0;
    int y1=0;
    int z1=0;
    //tri player2
    int x2=0;
    int y2=0;
    int z2=0;
    //combinaisons possible
    int player1_421=0;
    int player2_421=0;
    int player1_triplet=0;
    int player2_triplet=0;
    int player1_fiche=0;
    int player2_fiche=0;
    int player1_suite=0;
    int player2_suite=0;
    int player1_quelconque=0;
    int player2_quelconque=0;

    //les entrées
    scanf("%d %d %d %d %d %d", &a, &b, &c, &m, &n, &o);
    //printf("player 1 : %d %d %d\n", a, b, c);
    //printf("player 2 : %d %d %d\n", m, n, o);

    //player1
    //a est le plus grand
     if ((a>=b && a>=c))
    {
        if (b>=c)
        {
            x1=a;
            y1=b;
            z1=c;
        }
        else if (c>=b)
        {
            x1 =a;
            y1 =c;
            z1 =b;
        }
    }

    //b est le plus grand
    else if ((b>=a && b>=c))
    {
        if (a>=c)
        {
            x1 =b;
            y1 =a;
            z1 =c;
        }
        else if (c>=a)
        {
            x1 =b;
            y1 =c;
            z1 =a;
        }
    }

    //c est le plus grand
    else if ((c >=b && c>=a))
    {
        if (a>=b)
        {
            x1=c;
            y1=a;
            z1=b;
        }
        else if (b>=a)
        {
            x1=c;
            y1=b;
            z1=a;
        }
    }

    //player2
    //m est le plus grand
    if ((m>=n && m>=o))
    {
        if (n>=o)
        {
            x2=m;
            y2=n;
            z2=o;
        }
        else if (o>=n)
        {
            x2 =m;
            y2 =o;
            z2 =n;
        }
    }

    //n est le plus grand
    else if ((n>=m && n>=o))
    {
        if (m>=o)
        {
            x2=n;
            y2 =m;
            z2 =o;
        }
        else if (o>=m)
        {
            x2=n;
            y2=o;
            z2=m;
        }
    }

    //o est le plus grand
    else if ((o >=n && o>=m))
    {
        if (m>=n)
        {
            x2=o;
            y2=m;
            z2=n;
        }
        else if (n>=m)
        {
            x2=o;
            y2=n;
            z2=m;
        }
    }


    if ((x1==4)&&(y1==2)&&(z1==1))
        player1_421=1;

    if ((x2==4)&&(y2==2)&&(z2==1))
        player2_421=1;

    if ((x1==y1)&&(y1==z1))
        player1_triplet=1;

    if ((x2==y2)&&(y2==z2))
        player2_triplet=1;

    if ((y1==1)&&(z1==1)&&(x1>=2 && x1<=6))    //doute sur x en dernier
        player1_fiche=1;

    if ((y2==1)&&(z2==1)&&(x2>=2 && x2<=6))
        player2_fiche=1;

    if ((x1==y1+1)&&(y1==z1+1))
        player1_suite=1;

    if ((x2==y2+1)&&(y2==z2+1))
        player2_suite=1;

    if (!(player1_suite || player1_fiche || player1_triplet || player1_421))
        player1_quelconque=1;

    if (!(player2_suite || player2_fiche || player2_triplet || player2_421))
        player2_quelconque=1;


    //traitement
    //player1 wins
    if ((player1_421 &&(player2_triplet || player2_fiche || player2_suite || player2_quelconque))
        || ((player1_triplet && (player2_fiche || player2_suite || player2_quelconque)))
        || ((player1_fiche && (player2_suite || player2_quelconque)))
        || ((player1_suite && (player2_quelconque)))
        || ((player1_suite && player2_suite)&& ((x1>x2)&&(y1>y2)&&(z1>z2)))
        || ((player1_fiche && player2_fiche) && (x1>x2))
        || ((player1_triplet && player2_triplet) && (x1>x2))
        || ((player1_quelconque && player2_quelconque)
                && ((x1>x2) || (x1==x2 && y1>y2) || (x1==x2 && y1==y2 && z1>z2))))
        printf("Player1 wins\n");


    //player2 wins
    else if ((player2_421 &&(player1_triplet || player1_fiche || player1_suite || player1_quelconque))
        || ((player2_triplet && (player1_fiche || player1_suite || player1_quelconque)))
        || ((player2_fiche && (player1_suite || player1_quelconque)))
        || ((player2_suite && (player1_quelconque)))
        || ((player2_suite && player1_suite)&& ((x2>x1)&&(y2>y1)&&(z2>z1)))
        || ((player2_fiche && player1_fiche) && (x2>x1))
        || ((player2_triplet && player1_triplet) && (x2>x1))
        || ((player1_quelconque && player2_quelconque)
                && ((x2>x1) || (x2==x1 && y2>y1) || (x2==x1 && y2==y1 && z2>z1))))
        printf("Player2 wins\n");


    //autres
    else if ((player1_421 && player2_421)
             || (player1_suite && player2_suite) && (z1==z2)
             || (player1_fiche && player2_fiche) && (x1==x2)
             || (player1_triplet && player2_triplet) && (x1==x2)
             || (player1_quelconque && player2_quelconque) && (x1==x2)&&(y1==y2)&&(z1==z2))
        printf("Draw\n");


    return 0;
}



