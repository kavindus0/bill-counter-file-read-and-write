//
// Created by kavindu on 2024-08-25.
//
#include "stdio.h"
#define maxDatas 10

typedef struct{
    char customer[50];
    char item[50];
    int unit;
    float price;
}Data_set;


int main(){

    FILE *fptrRead = fopen("user.txt", "r");
    FILE *fptrWrite = fopen("output.txt", "w");
    int i = 0;
    Data_set dset[maxDatas];
    if (fptrRead == NULL){
        printf("Error opening file\n");
        return 1;
    } else{
        while (fscanf(fptrRead,"%s %s %d %f",dset[i].customer,dset[i].item,&dset[i].unit,&dset[i].price)!=EOF){
            i++;
        }
        float sumOfBill = 0;
        fprintf(fptrWrite,"Customer_Name\t\t");
        fprintf(fptrWrite,"Items\t\t");
        fprintf(fptrWrite,"Price\n");

        for (int i=0; i<maxDatas; i++) {
            fprintf(fptrWrite,"%s\t\t",dset[i].customer);
            fprintf(fptrWrite,"%s\t\t",dset[i].item);
            fprintf(fptrWrite,"%.2f \n",dset[i].unit * dset[i].price);
            sumOfBill += dset[i].unit * dset[i].price;

        }
        
        fprintf(fptrWrite,"\n\n\t\tTotal Bill Is :%.2f",sumOfBill);
        
        fclose(fptrWrite);
        fclose(fptrRead);
        
    }

    return 0;
}
