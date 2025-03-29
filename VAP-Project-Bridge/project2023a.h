#include<string.h>
struct hand
{
     char number[13];
     char color[13];
};
//////////////////////////////////////////////////////////////
int readFromInput(struct hand A[MAX])
{
    int N,i,j;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++)
    {
        for (j=0;j<13;j++)
        {
           scanf(" %c", &A[i].number[j]);
           scanf(" %c", &A[i].color[j]);
        }
    }
    return N;
}
//////////////////////////////////////////////////////////////
void printHand(struct hand A)
{
    int i ;
    char S[13],H[13],D[13],C[13],si=0,hi=0,di=0,ci=0;
    for (i=0;i<13;i++)
    {
        if (A.color[i]=='S')
        {
            S[si]=A.number[i];
            si++;
        }
        else if (A.color[i]=='H')
        {
            H[hi]=A.number[i];
            hi++;
        }
        else if (A.color[i]=='D')
        {
            D[di]=A.number[i];
            di++;
        }
        else if (A.color[i]=='C')
        {
            C[ci]=A.number[i];
            ci++;
        }
    }
    printf("SPADES:   ");
    if (si>0)
    {
      for(i=0;i<si;i++)
        printf("%c ",S[i]);
    }
    printf("\n");
    printf("HEARTS:   ");
    if (hi>0)
    {
      for(i=0;i<hi;i++)
        printf("%c ",H[i]);
    }
    printf("\n");
     printf("DIAMONDS: ");
    if (di>0)
    {
      for(i=0;i<di;i++)
        printf("%c ",D[i]);
    }
    printf("\n");
    printf("CLUBS:    ");
    if (ci>0)
    {
      for(i=0;i<ci;i++)
        printf("%c ",C[i]);
    }
    printf("\n");
}
////////////////////////////////////////////////////////////////////
bool balanced(struct hand A)
{
    int i,spades=0,hearts=0,diamonds=0,clubs=0,Exactly[4],exactly2=0;
    for (i=0;i<13;i++)
    {
       if (A.color[i]=='S')
           spades++;
       else if (A.color[i]=='H')
           hearts++;
       else if (A.color[i]=='D')
           diamonds++;
       else if (A.color[i]=='C')
           clubs++;
    }
    Exactly[0]=spades;
    Exactly[1]=hearts;
    Exactly[2]=diamonds;
    Exactly[3]=clubs;
    if (spades>=2 && hearts>=2 && diamonds>=2 && clubs>=2)
    {
       for(i=0;i<4;i++)
       {
           if(Exactly[i]==2)
              exactly2++;
       }
       if(exactly2>1)
          return false ;
       return true;
    }
    else
        return false;
}
///////////////////////////////////////////////////////////////////////
int hcp(struct hand A)
{
    int i,onerpoints=0;
    for (i=0;i<13;i++)
    {
        if(A.number[i]=='A')
            onerpoints+=4;
        else if (A.number[i]=='K')
            onerpoints+=3;
        else if (A.number[i]=='Q')
           onerpoints+=2;
        else if (A.number[i]=='J')
           onerpoints++;
    }
    return onerpoints;
}
/////////////////////////////////////////////////////////////////
int declarer(struct hand A)
{
    int i ,dpoints=0,Colors[4]={0};
    for (i=0;i<13;i++)
    {
        if(A.color[i]=='S')
            Colors[0]++;
        else if (A.color[i]=='H')
            Colors[1]++;
        else if (A.color[i]=='D')
            Colors[2]++;
        else if (A.color[i]=='C')
            Colors[3]++;
    }
    for(i=0;i<4;i++)
    {
        if (Colors[i]>4)
            dpoints+=Colors[i]-4;
    }
    return dpoints;
}
//////////////////////////////////////////////////////////////////
void response(struct hand A)
{
    int i,spades=0,hearts=0,diamonds=0,clubs=0;
    for(i=0;i<13;i++)
    {
        if(A.color[i]=='S')
            spades++;
        else if(A.color[i]=='H')
            hearts++;
        else if (A.color[i]=='D')
            diamonds++;
        else if (A.color[i]=='C')
            clubs++;
    }
    if (balanced(A) && hcp(A)>=15 && hcp(A)<=17)
        printf("1NT\n");
    else if (balanced(A) && hcp(A)>=20 && hcp(A)<=21)
        printf("2NT\n");
    else if (hcp(A)>=22)
        printf("2 CLUBS\n");
    else if (hcp(A)<22 && hcp(A)+declarer(A)>=13)
    {
       if (spades>=5 && hearts<=5)
            printf("1 SPADES\n");
       else if (hearts>=5 && spades<hearts)
            printf("1 HEARTS\n");
       else if (diamonds>=4 && spades<5 && hearts<5 && clubs<5)
            printf("1 DIAMONDS\n");
       else if (spades<5 &&hearts<5&&diamonds<4)
            printf("1 CLUBS\n");
    }
    else if(hcp(A)+declarer(A)<13)
        printf("PASS\n");
}
///////////////////////////////////////////////////////////////
 int readFromFile(struct hand A[MAX])
{
    char k[112];
    int N,i,j;
    FILE *fp;
    scanf("%s",k);
    getchar();
    fp=fopen(k,"r");
    fscanf(fp,"%d",&N);
    for(i=0;i<N;i++)
    {
        for (j=0;j<13;j++)
        {
           fscanf(fp," %c", &A[i].number[j]);
           fscanf(fp," %c", &A[i].color[j]);
        }
    }
    fclose(fp);
    return N;
}
////////////////////////////////////////////////////////////////
void saveData(struct hand A[MAX],int N)
{
    char k[112];
    int i,j;
    FILE *fp;
    scanf("%s",k);
    getchar();
    fp=fopen(k,"w");
    for(j=0;j<N;j++)
    {
       char S[13],H[13],D[13],C[13],si=0,hi=0,di=0,ci=0;
       for (i=0;i<13;i++)
       {
         if (A[j].color[i]=='S')
         {
             S[si]=A[j].number[i];
             si++;
         }
         else if (A[j].color[i]=='H')
         {
             H[hi]=A[j].number[i];
             hi++;
         }
         else if (A[j].color[i]=='D')
         {
             D[di]=A[j].number[i];
             di++;
         }
         else if (A[j].color[i]=='C')
         {
             C[ci]=A[j].number[i];
             ci++;
         }
        }
     fprintf(fp,"SPADES:   ");
     if (si>0)
     {
       for(i=0;i<si;i++)
         fprintf(fp,"%c ",S[i]);
     }
     fprintf(fp,"\n");
     fprintf(fp,"HEARTS:   ");
     if (hi>0)
     {
       for(i=0;i<hi;i++)
         fprintf(fp,"%c ",H[i]);
     }
     fprintf(fp,"\n");
      fprintf(fp,"DIAMONDS: ");
     if (di>0)
     {
       for(i=0;i<di;i++)
         fprintf(fp,"%c ",D[i]);
     }
     fprintf(fp,"\n");
     fprintf(fp,"CLUBS:    ");
     if (ci>0)
     {
       for(i=0;i<ci;i++)
         fprintf(fp,"%c ",C[i]);
     }
     fprintf(fp,"\n\n");
   }
}
