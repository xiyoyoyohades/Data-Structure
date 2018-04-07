#include "test.h"

int generate_data()
{


    FILE* fp=fopen("data.xls","w");
    char first='A';
    char second='A';
    //char third='A';
    //char forth='A';
    //char fifth='A';

    int j,k,l,m;
    int i=1;


        for(j=0;j<26;j++)
        {
            for(k=0;k<26;k++)
            {
                //for(l=0;l<26;l++)
                //{
                    //for(m=0;m<26;m++)
                    //{

                            fprintf(fp,"%d\t%c%c\n",i,first+j,second+k);
                            i++;


                    //}
                //}


            }
        }

    printf("done\n");
    fclose(fp);

    FILE* hobby_file=fopen("hobby.txt","w");

    fprintf(hobby_file,"%s\n","reading");
    fprintf(hobby_file,"%s\n","bike");
    fprintf(hobby_file,"%s\n","writing");
    fprintf(hobby_file,"%s\n","movie");
    fprintf(hobby_file,"%s\n","sing");
    fprintf(hobby_file,"%s\n","dance");
    fprintf(hobby_file,"%s\n","alcohol");
    fprintf(hobby_file,"%s\n","TV");
    fprintf(hobby_file,"%s\n","poem");
    fprintf(hobby_file,"%s\n","novel");
    fprintf(hobby_file,"%s\n","swim");
    fprintf(hobby_file,"%s\n","animation");
    fprintf(hobby_file,"%s\n","draw");
    fprintf(hobby_file,"%s\n","farming");
    fprintf(hobby_file,"%s\n","BBQ");
    fprintf(hobby_file,"%s\n","math");
    fprintf(hobby_file,"%s\n","physics");
    fprintf(hobby_file,"%s\n","sciencefiction");
    fprintf(hobby_file,"%s\n","horror");
    fprintf(hobby_file,"%s\n","cooking");
    fprintf(hobby_file,"%s\n","AI");
    fprintf(hobby_file,"%s\n","BigData");
    fprintf(hobby_file,"%s\n","BlockChain");
    fprintf(hobby_file,"%s\n","dataStructure");
    fprintf(hobby_file,"%s\n","algorithm");
    fprintf(hobby_file,"%s\n","Unix");
    fprintf(hobby_file,"%s\n","Linux");
    fprintf(hobby_file,"%s\n","frontEnd");
    fprintf(hobby_file,"%s\n","backEnd");
    fprintf(hobby_file,"%s\n","C++");
    fprintf(hobby_file,"%s\n","Java");
    fprintf(hobby_file,"%s\n","Go");
    fprintf(hobby_file,"%s\n","Lisp");
    fprintf(hobby_file,"%s\n","Python");
    fprintf(hobby_file,"%s\n","Perl");
    fprintf(hobby_file,"%s\n","Security");
    fprintf(hobby_file,"%s\n","cryptology");
    fprintf(hobby_file,"%s\n","GpuProgram");
    fprintf(hobby_file,"%s\n","data mining");
    fprintf(hobby_file,"%s\n","database");
    fprintf(hobby_file,"%s\n","SoftwareEngineer");
    fprintf(hobby_file,"%s\n","compilation");
    fprintf(hobby_file,"%s\n","OS");
    fprintf(hobby_file,"%s\n","Verilog");
    fprintf(hobby_file,"%s\n","Network");
    fprintf(hobby_file,"%s\n","FP");
    fprintf(hobby_file,"%s\n","OOP");
    fprintf(hobby_file,"%s\n","MachineLearning");
    fprintf(hobby_file,"%s\n","optimalization");
    fprintf(hobby_file,"%s\n","3Dmodeling");
    fprintf(hobby_file,"%s\n","3Danimation");
    fprintf(hobby_file,"%s\n","music");
    fprintf(hobby_file,"%s\n","english");
    fprintf(hobby_file,"%s\n","psycology");
    fprintf(hobby_file,"%s\n","politics");
    fprintf(hobby_file,"%s\n","french");
    fprintf(hobby_file,"%s\n","spanish");
    fprintf(hobby_file,"%s\n","programming");
    fprintf(hobby_file,"%s\n","travel");
    fprintf(hobby_file,"%s\n","videogame");
    fprintf(hobby_file,"%s\n","poker");
    fprintf(hobby_file,"%s\n","basketball");
    fprintf(hobby_file,"%s\n","baseball");

    fclose(hobby_file);





    return 0;
}

void auto_input(HashTable_Ptr hashtable)
{
    int id;
    char name[20];
    char new_hobby[20];
    int max_num=0;

    FILE* fp=fopen("data.xls","r");
    while(fscanf(fp,"%d\t%s\n",&id,name)==2)
    {
        if(max_num>=250) break;
        Add_user(hashtable,id,name);
        max_num++;
    }
    fclose(fp);


    srand((unsigned int)time(NULL));

    int low,high;
    int i,j,k;
    for(i=1;i<=hashtable->record_num;i++)
    {
        low=rand()%(hashtable->record_num)+1;
        high=rand()%(hashtable->record_num)+1;
        int hobby_num=0;
        int line_num=0;

        if(low>high)
        {
            int tmp=low;
            low=high;
            high=tmp;
        }
        for(j=low;j<=high;j++)
        {
            if(i!=j)
            {
                Add_friend(hashtable,i,j,1);
                Add_follower(hashtable,i,j,1);
                Add_following(hashtable,i,j,1);
            }

        }



        hobby_num=rand()%5+1;

        for(k=1;k<=hobby_num;k++)
        {
            FILE* hobby_file=fopen("hobby.txt","r");
            line_num=rand()%HOBBY_TOTAL+1;
            printf("%d\n",line_num);
            while(line_num-1)
            {
                fscanf(hobby_file,"%s\n",new_hobby);
                memset(new_hobby,0,20*sizeof(char));
                line_num--;
            }
            fscanf(hobby_file,"%s\n",new_hobby);
            printf("hobby: %s\n",new_hobby);
            Add_hobby(hashtable,i,new_hobby);
            memset(new_hobby,0,20*sizeof(char));
            printf("************************************************\n");
            fclose(hobby_file);

        }


    }

}
