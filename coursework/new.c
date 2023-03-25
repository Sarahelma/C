#include <stdio.h>
#include <math.h>


typedef struct
{
    int id;
    double charge;
    double energy;

}battery;




int main()
{   
    
    FILE *file;
    file = fopen("/workspaces/C/coursework/Dataset.txt","r");
    if (file== NULL)
    {
        printf("FILE OPENING ERROR!!\n");
        return -1;
    }
    
    
    battery batteries[100];

    int columns = 0;
    int rows = 0;
    
    do 
    {
        columns = fscanf(file,"%d,%lf,%lf\n",
                        &batteries[rows].id,
                        &batteries[rows].charge,
                        &batteries[rows].energy);
        if (columns == 3) rows ++;
        if (columns != 3 && !feof(file))
        {
            printf("FILE FORMATING ERROR!!");
            return -1;
        }
        if (ferror(file))
        {
            printf("FILE READING ERROR!!");
            return -1;
        }
        

    }while (!feof(file));

    fclose(file);

    printf("\n%d lines have been read. \n\n",rows);

   
   
   
    double sum_q=0;
    double mean_q;
    double std_q=0;
    
    for (int i=0 ; i < 100; i++)
        sum_q+= batteries[i].charge;
    sum_q= 
    
    printf("Sum of Charge=%lf \n \n",sum_q);
    
    mean_q=sum_q/100;
    printf("Mean of Charge=%lf \n \n",mean_q);

    //testing maths functions//
    double p, j;
    p=pow(5,2);
    j = sqrt(100);
    printf("5 squared=%lf \n",p);
    printf("square root of 100 = %lf \n",j);


    for (int i=0 ; i < 100; i++)
        //std_q += pow( (batteries[i].charge - mean_q),2);
        std_q += (batteries[i].charge - mean_q) * (batteries[i].charge - mean_q);
    // std_q= sqrt((std_q/100));//

    printf("Standard deviation of Charge=%lf \n \n",std_q);

    
    
    
    double sum_E=0;
    double mean_E;
    double std_E=0;
    
    for (int i=0 ; i < 100; i++)
        sum_E+= batteries[i].energy;
    
    printf("Sum of energy=%lf \n \n",sum_E);
    
    mean_E=sum_E/100;
    printf("Mean of energy=%lf \n \n",mean_E);

    /*for (int i=0 ; i < 100; i++)
        std_q += pow( (batteries[i].charge -mean_q),2);*/
    
    printf("Standard deviation of energy=%lf \n \n",std_E);
    
    printf("| 4355|  Charge |  Energy |\n"
           "|-----|---------|---------|\n"
           "| Mean|         |         |\n"
           "| Sdev|         |         |\n"
           "| Min |         |         |\n"
           "| Max |         |         |\n ");
    
    
    
    for (int i=0 ; i < 100; i++)
        printf("%d %lf %lf\n",
                batteries[i].id,
                batteries[i].charge,
                batteries[i].energy);
    return 0;
}

