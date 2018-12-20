#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int word_count(char s1[]);
void search(FILE *f,int *count,int num,char word_holder[num][20]);

int main()
{

    int num;//num of words
    int i=0;
    int j=0;
    int k=0;
    FILE *pf,*nf;
    //reading the positive and negative text files which contains a list of positive and negative words.
    pf=fopen("./pos_mod.txt","r");
    nf=fopen("./neg_mod.txt","r");
    if(pf!=NULL && nf!=NULL)/*checking whether the file is open or not*/
        printf("...........\n");
    else

        printf("xxxxxxxxx\n");

    char str[100];/*stores the users' sentence*/



    printf("enter string:");
    scanf("%[^\n]s",str);
    num=word_count(str);/*count the number of words in the sentence*/
    char word_holder[num][20];  /*declaring a 2-d array */

    /* Converts the string into 2D array */
    for (i = 0; str[i]!= '\0'; i++)
    {
        if (str[i]==' ')
        {
            word_holder[k][j] = '\0';
            k++;
            j = 0;
        }
        else
        {
            word_holder[k][j] = str[i];
            j++;
        }
    }
    word_holder[k][j] = '\0';/*to put a null character at the end of the last word in th sentence*/

    int pwc=0;//positive word count
    int nwc=0;//negative word count

    search(pf,&pwc,num,word_holder);/*for positive word search*/
    search(nf,&nwc,num,word_holder);/*for negative word search*/
    printf("negative words =%d  positive words =%d \n",nwc,pwc);
    if(pwc>nwc)
        {
            if(strstr(str,"not"))
                printf("negative sentence:\n");
            else
            printf("positive sentence \n");

        }
    else if(nwc>pwc)
        {
            if(strstr(str,"not"))
                printf("positive sentence ^_^  ^_^\n");
            else
            printf("negative sentence -_- -_-\n");
        }
    else
        {
            printf("neutral #_# #_#\n");
        }

}

int word_count(char s1[])
{
    int n=strlen(s1);
    if(n==0)//if no input return 0
        return 0;
    int i=0;
    int word=0;
    fflush(stdin);
    for(i=0;s1[i]!='\0';i++)
        {
            if(s1[i]==' ')
                word++;
        }
    word++;
    return (word);
}
void search(FILE *f,int *count,int num,char word_holder[num][20])
{
    char w[72000];//to store the entire file
    fgets(w,72000,f);
    char *tok;
    int i;
    tok=strtok(w,",");
    while(tok!=NULL)
    {
        for(i=0;i<num;i++)
        {
            if(strcmp(word_holder[i],tok)==0)
                *count=*count+1;
        }
        tok=strtok(NULL,",");
    }
}
