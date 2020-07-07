#include <stdio.h>                                      //vkluchenie bibliotek
#include <malloc.h>                                    //vkluchenie bibliotek
#include <stdlib.h>                                   //vkluchenie bibliotek
int main(void) {                                     //nachalo programmi
    FILE *Reading,*Writing;
    Reading= fopen("Reading.txt","r");
    Writing=fopen("Writing.txt","w");
    char viebor,z;                                        // ponadobitsia dlya povtornieh raschetov
    do{                                        //tcikl DO WHILE
        float a,b,c,*A,*B,*C;                               // peremenniee i yacheyka otveta
        float d=1;
        int tip,i,n;                                       // i -schetchik dlya stepeni i fact;  n razmer vectora   ukazatel' na masssiv
        fprintf (Writing,"Nachalo rabotie programmie. calc mozhet: +, -, *, /, ^, !   \n");
        fprintf (Writing,"viebor standartnogo calc- '1' , vectornogo- '2'\n");
        fprintf (Writing,"vvedite tip calculyatora\n");
        fscanf (Reading,"%d", &tip);
        if (tip==1)
        {fprintf (Writing,"vash viebor eto: standart\n");
            fprintf (Writing,"a=");                                                   // chtenie i zapic'
            fscanf (Reading,"%f", &a);                                              //peremennieh
            fprintf (Writing,"b=");                                                 //  v stroki;
            fscanf (Reading,"%f", &b);                                            //schitivanie a, b, z.
            fprintf (Writing,"vieberite deyystviye");                                               //smotri etot block
            fscanf (Reading," %c", &z);
            switch (z) {              // block zapici deystviy nizhe perebranie vse vozmozhniee dly moego calculyztora
                case '+':                    //0 means "+"
                    c=a+b;
                    break;
                case '-':                    //0 means "-"
                    c=a-b;
                    break;
                case '*':                    //0 means "*"
                    c=a*b;
                    break;
                case '/':                    //0 means "/"
                    if (b==0) puts("b=0 nedopustimaya operatcia"); else c=a/b;
                    break;
                case '^':                    //0 means "^"
                    c=1;
                    for (i=0; i < b; i++){        //stepen'
                        c=a*c;}
                    break;
                case '!':                    //0 means "!"
                    c=a;
                    for (i=0; i < a; i++){        //fact
                        a=a-1;c=c*a;}
                    break;
                default:
                    fprintf (Writing,"Vvedite poriadkoviy nomer deystvia!\n");}        // esli ne vveden nomer znaka deystvia  a kakiye-to drugie simvolie
        }
        else if (tip==2)
        {fprintf (Writing,"vash viebor eto: vector\n");
            {
                fprintf(Writing,"razmer vectorov: ");
                fscanf(Reading,"%d", &n);                                                    // viedelenie pamyaty
                A =malloc(n*sizeof(int));
                B =malloc(n*sizeof(int));
                fprintf(Writing,"vvedite 1-st vector");
                for (i=0; i<n; i++) fscanf(Reading,"%f", &A[i]);
                fprintf(Writing,"vvedite 2-nd vector");
                for (i=0; i<n; i++) fscanf(Reading,"%f", &B[i]);
                fprintf (Writing,"vieberite deyystviye");
                fscanf (Reading," %c", &z);
                switch (z) {
                    case '+':
                        fprintf(Writing,"slozheniye vectorov\n");
                        for (i=0; i<n; i++){ fprintf (Writing,"%f\n",A[i]+B[i]);}
                        break;
                    case '-':
                        fprintf(Writing,"viechetaniye vectorov\n");
                        for (i=0; i<n; i++){ fprintf(Writing,"%f\n",A[i]-B[i]);}
                        break;
                    case '*':
                        fprintf(Writing,"skalyarnoye proisvedenie\n");
                        for (i=0; i<n; i++) d=A[i]*B[i]+d;
                        fprintf(Writing,"%f\n", d);
                        break;
                    default:
                        fprintf (Writing,"Vvedite poriadkoviy nomer deystvia!\n");} }}       // esli ne vveden nomer znaka deystvia  a kakiye-to drugie simvolie
        free(A); free(B);
        if (tip=1)
            fprintf (Writing,"Calculator standartnij poschital. otvet: %f", c);                                  // vidacha otveta
        else
            fprintf(Writing,"vectornieye raschetie viepolnenie");
        fflush(stdin);            //reshenie vipolnit' programmu zanovo
        fprintf(Writing,"\n Zhelaete vipolnit' raschetie snova? ('y'-esli hochesh' povtorit')\n");
        viebor=getchar();
    }while(viebor=='y'||viebor=='Y');
    if(viebor !='y'||viebor !='Y')
        fscanf (Reading,"%c", &viebor);
    fclose(Reading); fclose(Writing);
    fprintf(Writing,"Programma zavershena\n");                           //konetc
}