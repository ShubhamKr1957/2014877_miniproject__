#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

// Structure 
struct Medicine
{
    int id, price, quantity;
    char medicneName[100], Company[100], Mfg_Date[11], Exp_Date[11], info[5000];
}m[100];

// Fucntion Declaration
void medicinePurchase(int);
void enterMedicineInfo(int);
void stockInfo(int);
void getMedicineInfo(int);
void addMedicine(int,struct Medicine[]);
void removeMedicine(int);
void updateDetails(int);

// Driver Function 
// Main function
int main()
{
    int i,j,choice,number=0,c;
    for(i=0;i<100;i++)
    {
        m[i].id=0;
        m[i].price=0;
        m[i].quantity=0;
        strcpy(m[i].Mfg_Date,"");
        strcpy(m[i].Exp_Date,"");
        strcpy(m[i].medicneName,"");
        strcpy(m[i].Company,"");
        strcpy(m[i].info,"");
    }
    m[0].id=1;
    m[0].price=120;
    m[0].quantity=30;
    strcpy(m[0].Mfg_Date,"23-04-2016");
    strcpy(m[0].Exp_Date,"24-04-2020");
    strcpy(m[0].medicneName,"Paracetmol");
    strcpy(m[0].Company,"ABCD");
    strcpy(m[0].info,"Good Medicine for Fever");
    do{
        system("cls");
        printf("____________________________________________________________________________________________________________");
        printf("\n\n\t\t                                MEDICINE STORE ");
        printf("\n____________________________________________________________________________________________________________");
        printf("\n\n\t                                             MENU                                                               ");
        printf("\n\n          1 - Purchase Medicine");
        printf("\n          2 - Enter Information about a Medicine");
        printf("\n          3 - Stock of Medicine in Store");
        printf("\n          4 - Medicine Information");
        printf("\n          5 - Add Medicine");
        printf("\n          6 - Delete a Medicine");
        printf("\n          7 - Change Quantity of Medicine");
        printf("\n\n\t      Enter your choice : ");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                medicinePurchase(number+1);
                break;
            }
            case 2:
            {
                enterMedicineInfo(number+1);
                break;
            }
            case 3:
            {
                stockInfo(number+1);
                break;
            }
            case 4:
            {
                getMedicineInfo(number+1);
                break;
            }
            case 5:
            {
                ++number;
                addMedicine(number,m);
                break;
            }
            case 6:
            {
                removeMedicine(number+1);
                break;
            }
            case 7:
            {
                updateDetails(number+1);
                break;
            }
        }
        printf("To Continue with other Options Enter 1 Else any other number To Exit : ");
        scanf("%d",&c);
    }while(c==1);

    return 0;
}

void medicinePurchase(int number)
{
    system("cls");
    int id,check,i,quantity,flag=0;
    char name[100];
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    printf("\n\nEnter 1 if you know ID else any other number to enter Name of Medicine : ");
    fflush(stdin);
    scanf("%d",&check);
    if(check==1)
    {
        printf("\nEnter Id to purchase Medicine : ");
        fflush(stdin);
        scanf("%d",&id);
        for(i=0;i<number;i++)
        {
            if(m[i].id==id)
            {
                flag=1;
                int c;
                printf("\n\nThese are the details of Medicine\n");
                printf("\nName%s",m[i].medicneName);
                printf("\nPrice=%d",m[i].price);
                printf("\nAvailable Quantity=%d",m[i].quantity);
                printf("\nCompany=%s",m[i].Company);
                printf("\nMfg Date=%s",m[i].Mfg_Date);
                printf("\nExp Date=%s\n",m[i].Exp_Date);
                if(strcmp(m[i].info,"")==0)
                {
                    printf("Medicine Review/Info=Not Available\n");
                }
                else
                {
                    printf("Medicine Review/Info=%s\n",m[i].info);
                }
                printf("\nDo you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
                fflush(stdin);
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\nEnter Quantity to Purchase\n");
                    scanf("%d",&quantity);
                    if(m[i].quantity>quantity)
                    {
                        printf("Total Price to be paid=%d\n",quantity*m[i].price);
                    }
                    else{
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if(flag==0)
        {
        printf("\nEntered Id Not Found\n");
        }
    }
    else
    {
        printf("Enter Name to search and Purchase : ");
        fflush(stdin);
        gets(name);
        for(i=0;i<number;i++)
        {
            if(strcmp(m[i].medicneName,name)==0)
            {
                flag=1;
                int c;
                printf("These are the details of Medicine\n");
                printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
                if(strcmp(m[i].info,"")==0)
                {
                    printf("Medicine Review/Info=Not Available\n");
                }
                else
                {
                    printf("Medicine Review/Info=%s\n",m[i].info);
                }
                printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
                fflush(stdin);
                scanf("%d",&c);
                if(c==1)
                {
                    printf("Enter Quantity to Purchase\n");
                    scanf("%d",&quantity);
                    if(m[i].quantity>quantity)
                    {
                        printf("Total Price to be paid=%d\n",quantity*m[i].price);
                    }
                    else{
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if(flag==0)
        {
            printf("Entered Name Not Found\n");
        }
    }
}

void enterMedicineInfo(int number)
{
    system("cls");
    int i,flag=0,c;
    char name[100],info[100];
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    printf("\n\nEnter Name of the medicine you want to Review or include Info : ");
    fflush(stdin);
    gets(name);
    for(i=0;i<number;i++)
    {
        if(strcmp(m[i].medicneName,name)==0)
        {
            flag=1;
            printf("These are the details of Medicine\n");
            printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
            if(strcmp(m[i].info,"")!=0)
            {
                printf("Review Already Available!\nIf you want to Add a Review Enter 1 else Any other number : ");
                fflush(stdin);
                scanf("%d",&c);
            }
            else
            {
                printf("Enter review(less than 100 Characters)\n");
                fflush(stdin);
                gets(m[i].info);
            }
            if(c==1)
            {
                printf("Enter review(less than 100 Characters)\n");
                fflush(stdin);
                gets(info);
                strcat(m[i].info,"; ");
                strcat(m[i].info,info);
            }

        }
    }
    if(flag==0)
    {
        printf("Entered Name Not Found\n");
    }
}

void getMedicineInfo(int number){
    
    system("cls");
    int i,flag=0;
    char name[100];
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    printf("\n\nEnter Name of the medicine you want to see Review and Info : ");
    fflush(stdin);
    gets(name);
    for(i=0;i<number;i++)
    {
        if(strcmp(m[i].medicneName,name)==0)
        {
            flag=1;
            printf("These are the details of Medicine\n");
            printf("\nName%s",m[i].medicneName);
            printf("\nPrice=%d",m[i].price);
            printf("\nAvailable Quantity=%d",m[i].quantity);
            printf("\nCompany=%s",m[i].Company);
            printf("\nMfg Date=%s",m[i].Mfg_Date);
            printf("\nExp Date=%s\n",m[i].Exp_Date);
            if(strcmp(m[i].info,"")!=0)
            {
                printf("Review or Info=%s\n",m[i].info);
            }
            else
            {
                printf("Review or Info=Not Available\n");
            }   
        }
    }
    if(flag==0)
    {
    printf("Entered Name Not Found\n");
    }
}

void stockInfo(int number){
    system("cls");
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    int i;
    if(number!=0)
    {
        printf("\n\nAll Available Items are\n");
        for(i=0;i<number;i++)
        {
            if(m[i].id!=0)
            {
                printf("\nName%s",m[i].medicneName);
                printf("\nPrice=%d",m[i].price);
                printf("\nAvailable Quantity=%d",m[i].quantity);
                printf("\nCompany=%s",m[i].Company);
                printf("\nMfg Date=%s",m[i].Mfg_Date);
                printf("\nExp Date=%s\n",m[i].Exp_Date);

                if(strcmp(m[i].info,"")!=0)
                {
                    printf("Review or Info=%s\n",m[i].info);
                }
                else
                {
                    printf("Review or Info=Not Available\n");
                }
            }
        }  
    }
    else{
        printf("No Items or Medicines Available\n");
    } 
}

void addMedicine(int number,struct Medicine m[])
{
    system("cls");
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    char name[100];
    printf("\n\nEnter Medicine Id : ");
    scanf("%d",&(m[number].id));
    fflush(stdin);
    printf("Enter Medicine Name : ");
    fflush(stdin);
    gets(name);
    strcpy(m[number].medicneName,name);
    printf("Enter Company Name : ");
    fflush(stdin);
    gets(m[number].Company);
    printf("Enter Manufactured Date : ");
    fflush(stdin);
    gets(m[number].Mfg_Date);
    printf("Enter Expiry Date : ");
    fflush(stdin);
    gets(m[number].Exp_Date);
    printf("Enter Quantity : ");
    fflush(stdin);
    scanf("%d",&(m[number].quantity));
    printf("Enter Price : ");
    fflush(stdin);
    scanf("%d",&(m[number].price));
    strcpy(m[number].info,"");
    printf("Medicine with id %d Added Successfully\n",m[number].id);
}

void removeMedicine(int number)
{
    system("cls");
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    int id,i,flag=0,num;
    printf("\n\nEnter Id to be deleted : ");
    fflush(stdin);
    scanf("%d",&id);
    for(i=0;i<number;i++)
        {
        if(m[i].id==id)
        {
            flag=1;
            m[i].id=0;
            m[i].price=0;
            m[i].quantity=0;
            strcpy(m[i].medicneName,"");
            strcpy(m[i].Company,"");
            strcpy(m[i].Mfg_Date,"");
            strcpy(m[i].Exp_Date,"");
            strcpy(m[i].info,"");
            num=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("Medicine with %d is Deleted Successfully\n",id);
    }
}

void updateDetails(int number)
{
    system("cls");
    printf("____________________________________________________________________________________________________________");
    printf("\n\n\t\t                                MEDICINE STORE ");
    printf("\n____________________________________________________________________________________________________________");
    int id,quantity,choice,c,i;
    printf("\n\nEnter id to change Details : ");
    scanf("%d",&id);
    for(i=0;i<number;i++)
    {
    if(m[i].id==id && m[i].id!=0)
    {
        do
        {
            printf("Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\n7 - Change Info\nAny other number to exit");
            scanf("%d",&choice);
            if(choice==1)
            {
                int quantity;
                printf("Enter Quantity to be changed\n");
                fflush(stdin);
                scanf("%d",&quantity);
                m[i].quantity=quantity;
                printf("Quantity changed Successfully\n");
            }
            if(choice==2)
            {
                int price;
                printf("Enter Price to be changed\n");
                fflush(stdin);
                scanf("%d",&price);
                m[i].price=price;
                printf("Price changed Successfully\n");
            }
            if(choice==3)
            {
                char name[100];
                printf("Enter Name to be changed\n");
                fflush(stdin);
                gets(name);
                strcpy(m[i].medicneName,name);
                printf("Medicine Name changed Successfully\n");
            }
            if(choice==4)
            {
                char company[100];
                printf("Enter company to be changed\n");
                fflush(stdin);
                gets(company);
                strcpy(m[i].Company,company);
                printf("Company changed Successfully\n");
            }
            if(choice==5)
            {
                char mfg[11];
                printf("Enter Manufacturing date to be changed\n");
                fflush(stdin);
                gets(mfg);
                strcpy(m[i].Mfg_Date,mfg);
                printf("Manufacturing Date changed Successfully\n");
            }
            if(choice==6)
            {
                char exp[11];
                printf("Enter Expiry date to be changed\n");
                fflush(stdin);
                gets(exp);
                strcpy(m[i].Exp_Date,exp);
                printf("Expiry Date changed Successfully\n");
            }
            if(choice==7)
            {
                char info[100];
                printf("Enter Info to be changed(Less than 100 Characters)\n");
                fflush(stdin);
                gets(info);
                strcpy(m[i].info,info);
                printf("Info changed Successfully\n");
            }
            if(choice<=0 && choice>7)
            {
                printf("Enter valid Choice\n"); 
            }
            printf("Enter 1 to Change other Details Else any other number\n");
            fflush(stdin);
            scanf("%d",&c);
        }while(c==1);

        break;
        }
    }
}

