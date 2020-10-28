#include <stdio.h>
#include <stdlib.h>

int mat1[10][10];// Matrix 1
int mat2[10][10];// Matrix 2
int matf[10][10];// Final Matrix
int row1,row2,column1,column2;
int main()
{
    int x;
    printf("Enter the number of rows of matrix 1\n");
    scanf("%d",&row1);
    printf("Enter the number of columns of matrix 1\n");
    scanf("%d",&column1);
    printf("Enter the elements\n");
    //Entry of Matrix 1
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            printf("Matrix[%d][%d]\n",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
    }
    print(mat1,row1,column1);//Calling Print Function
    re:printf("for add 1 and for subtract 2 for print 3 and exit 4 , 5 for multiply,6 for operations\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        add();
        print(mat1,row1,column1);
        break;
    case 2:
        subtract();
        print(mat1,row1,column1);
        break;
    case 3:
        print(mat1,row1,column1);
        break;
    case 4:
        exit(1);
        break;
    case 5:
        multiplication();
        break;
    case 6:
        operations();
        break;
    }
    goto re;
}
//Prints any matrix that is passes as argument
void print(int mat[10][10],int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("A[%d][%d]=",i+1,j+1);
            printf("%d     ",mat[i][j]);
        }
        printf("\n");
    }
}
//Adds 2 Matrices of Same Order
int add()
{
    printf("Enter the Second Matrix details\n");
    printf("Enter the number of rows of matrix 2\n");
    scanf("%d",&row2);
    printf("Enter the number of columns of matrix 2\n");
    scanf("%d",&column2);
    if(row1==row2&&column1==column2)
    {
        printf("Enter the elements\n");
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column1;j++)
            {
                printf("Matrix[%d][%d]\n",i+1,j+1);
                scanf("%d",&mat2[i][j]);
            }
        }
    }
    else
    {
       printf("Order is not same");
       return 0;
    }
    print(mat2,row2,column2);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            mat1[i][j]+=mat2[i][j];
        }
    }

}
//Subtracts 2nd matrix from 1st
int subtract()
{
    printf("Enter the Second Matrix details\n");
    printf("Enter the number of rows of matrix 2\n");
    scanf("%d",&row2);
    printf("Enter the number of columns of matrix 2\n");
    scanf("%d",&column2);
    if(row1==row2&&column1==column2)
    {
        printf("Enter the elements\n");
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column1;j++)
            {
                printf("Matrix[%d][%d]\n",i+1,j+1);
                scanf("%d",&mat2[i][j]);
            }
        }
    }
    else
    {
       printf("Order is not same");
       return 0;
    }
    print(mat2,row2,column2);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            mat1[i][j]-=mat2[i][j];
        }
    }

}
//Gives the product of 2 matrices
int multiplication()
{
    printf("\n\nEnter the Second Matrix details\n");
    printf("Enter the number of rows of matrix 2\n");
    scanf("%d",&row2);
    printf("Enter the number of columns of matrix 2\n");
    scanf("%d",&column2);
    if(row2==column1)
    {
        printf("Enter the elements\n");
        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<column2;j++)
            {
                printf("Matrix[%d][%d]\n",i+1,j+1);
                scanf("%d",&mat2[i][j]);
            }
        }
    }
    else
    {
       printf("Order is not same");
       return 0;
    }
    print(mat2,row2,column2);
    for(int i=0;i<row1;i++)
    {
        for(int k=0;k<column2;k++)
        {
            int sum=0;
            for(int j=0;j<column1;j++)
            {
                sum=sum+(mat1[i][j])*(mat2[j][k]);
            }
            matf[i][k]=sum;
        }
    }
    print(matf,row1,column2);

}
//Performs row and column operations
void operations()
{
    //Function Row declaration starts
    void rowop()
    {
        int rowx,rowy,cffx,cffy,choice_op;
        void raddop()//addition operation among rows
        {
            printf("Enter the row on which operation should be applied\n");
            scanf("%d",&rowx);
            printf("Enter the row from which operation will be applied\n");
            scanf("%d",&rowy);
            printf("Integral multiple coefficient with row %d\n",rowx);
            scanf("%d",&cffx);
            printf("Integral multiple coefficient with row %d\n",rowy);
            scanf("%d",&cffy);
            rowx--;
            rowy--;
            for(int i=0;i<column1;i++)
            {
               mat1[rowx][i]=cffx*mat1[rowx][i]+cffy*mat1[rowy][i] ;
            }
            print(mat1,row1,column1);
        }

        void rsubop()//subtraction operation among rows
        {
            printf("Enter the row on which operation should be applied\n");
            scanf("%d",&rowx);
            printf("Enter the row from which operation will be applied\n");
            scanf("%d",&rowy);
            printf("Integral multiple coefficient with row %d\n",rowx);
            scanf("%d",&cffx);
            printf("Integral multiple coefficient with row %d\n",rowy);
            scanf("%d",&cffy);
            rowx--;
            rowy--;
            for(int i=0;i<row1;i++)
            {
               mat1[rowx][i]=cffx*mat1[rowx][i]-cffy*mat1[rowy][i] ;
            }
            print(mat1,row1,column1);
        }

        void rmulop()//Multiplication of a constant in any  row
        {
            int fact;
            printf("Enter the row on which operation should be applied\n");
            scanf("%d",&rowx);
            printf("Enter the factor\n");
            scanf("%d",&fact);
            rowx--;
            for(int i=0;i<column1;i++)
            {
                mat1[rowx][i]*=fact;
            }
            print(mat1,row1,column1);
        }
        void rinterch() // Interchanging row operation
        {
            printf("Enter the rows-you want to interchange\n");
            scanf("%d  %d",&rowx,&rowy);
            rowx--;
            rowy--;
            for(int i=0;i<column1;i++)
            {
                int temp;
                temp=mat1[rowx][i];
                mat1[rowx][i]=mat1[rowy][i];
                mat1[rowy][i]=temp;
            }
            printf("Row Interchanged SUCCESSFULLY\n");
            print(mat1,row1,column1);
        }
        //start of program
        printf("For add press 1, 2 for sb,3 for mul\n");
        scanf("%d",&choice_op);
        switch(choice_op)
        {
        case 1:
            raddop();
            break;
        case 2:
            rsubop();
            break;
        case 3:
            rmulop();
            break;
        case 4:
            rinterch();
            break;
        default:
            printf("\nSorry wrong input\n");
        }
    }
    //Function Column Declaration restarts
    void colop()
    {
        int columnx,columny,cffx,cffy,choice_op;
        void caddop() //addition operation among columns
        {
            printf("Enter the row on which operation should be applied\n");
            scanf("%d",&columnx);
            printf("Enter the row from which operation will be applied\n");
            scanf("%d",&columny);
            printf("Integral multiple coefficient with row %d\n",columnx);
            scanf("%d",&cffx);
            printf("Integral multiple coefficient with row %d\n",columny);
            scanf("%d",&cffy);
            columnx--;
            columny--;
            for(int i=0;i<row1;i++)
            {
               mat1[i][columnx]=cffx*mat1[i][columnx]+cffy*mat1[i][columnx] ;
            }
            print(mat1,row1,column1);
        }

        void csubop() //Subtraction operation among columns
        {
            printf("Enter the row on which operation should be applied\n");
            scanf("%d",&columnx);
            printf("Enter the row from which operation will be applied\n");
            scanf("%d",&columny);
            printf("Integral multiple coefficient with row %d\n",columnx);
            scanf("%d",&cffx);
            printf("Integral multiple coefficient with row %d\n",columny);
            scanf("%d",&cffy);
            columnx--;
            columny--;
            for(int i=0;i<row1;i++)
            {
               mat1[i][columnx]=cffx*mat1[i][columnx]-cffy*mat1[i][columny] ;
            }
            print(mat1,row1,column1);
        }

        void cmulop() //Multiplication operation among columns
        {
            int fact;
            printf("Enter the column on which operation should be applied\n");
            scanf("%d",&columnx);
            printf("Enter the factor\n");
            scanf("%d",&fact);
            columnx--;
            for(int i=0;i<row1;i++)
            {
                mat1[i][columnx]*=fact;
            }
            print(mat1,row1,column1);
        }
        //start of program
        printf("For add press 1, 2 for sb,3 for mul\n");
        scanf("%d",&choice_op);
        switch(choice_op)
        {
        case 1:
            caddop();
            break;
        case 2:
            csubop();
            break;
        case 3:
            cmulop();
            break;
        }
    }
    void deter(int mat[10][10],int row,int column)//Finds the determinant of matrix
    {
        int determinant=11;
        if(row!=column)
        {
           printf("SORRY! Matrix is not Square");
           return 0;
        }
        if(row==2)
        {
            determinant=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
        }
        if(row==3)
        {
            determinant=(mat[0][0]*((mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2])))-(mat[0][1]*((mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][0])))+(mat[0][2]*((mat[2][1]*mat[1][0])-(mat[1][1]*mat[2][0])));
        }
        printf("\nDeterminant=%d\n",determinant);

    }

    //Function Declaration Ends
    //Start of PROGRAM
    int CHOICE_OPER;
    printf("For Row operation press1, 2 for Column OP, 3 for Determinant, 4 For inverse, 5 for exit\n");
    scanf("%d",&CHOICE_OPER);
    switch(CHOICE_OPER)
    {
        case 1:
            rowop();
            break;
        case 2:
            colop();
            break;
        case 3:
            deter(mat1,row1,column1);
            break;

    }
}
