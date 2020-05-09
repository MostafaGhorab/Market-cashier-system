
#include "header.h"
#define de; printf("\ndebug\n");

node *head=NULL ;
node *newNode=NULL;
char *order [15];
char ordercount=0;
int TotalPrice =0;

//char  getter[20];
//node *NODE=NULL;
void  FileReading(void)
    {
        char *array =  (char*) calloc(10 , sizeof(char)); ///used to get all arrays in then calloc is used again with efficient size for each string ,this space may be freed end
        int z = 0;
        char ch;    ///used to get read characters from the file
        char flag=99; ///used to know the type of string entered with 3 cases the string may be a category or element or price
        char ElementsCount=0; ///to know the number of elements in each category
        char i=0;
        char charcs=0; ///count for the number of characters inside each string to use calloc efficiently
        int o;
        char j;
        char sum =0;  ///sum and weight variables are used to get the price and change it from characters to real numbers
        char weight =0; ///used to know whether the price is from one digit or two and handle it
      // printf("Enter name of the database file:\n");
       //gets(file_name);
       ///gets can be used to get the name of file from the user
       fp = fopen("data_base.txt", "r"); // read mode
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }

       //printf("\nThe contents of %s file are:\n", file_name);
      while((ch = (fgetc(fp))) != EOF)
	   {




	            if((ch=='\n'))  ///check for the end of the line to add the null character and the flag check the entered string being category or element
		   {



		       if (flag ==1)
               {
                 //  * (newNode->PtrCat) = '\0';


                  array[charcs] = '\0'; ///appending the null character


                  //printf("\n%d\n",newNode->NoOfElements);

                 (newNode->PtrCat) =  (char*) calloc(charcs , sizeof(char));

                 strcpy ((newNode->PtrCat),array );


                 printf("\n****%s***",(newNode->PtrCat));
               }
               else if ((flag==0)&&(i!=0))
               {

                 array [i] = '\0';
               //  printf("\n***%d\n",ElementsCount);
               //  printf("\n****%d\n",i);
                // printf("\n%s",array);

                (newNode->counter) =  (char*) malloc(sizeof(char));
                (newNode->counter)[ElementsCount] = 0;
                (newNode->price)[ElementsCount] =sum;
                 j= ElementsCount;
              //   printf("HEREEEEEEEEEEE%d\n",( (newNode->price)[j]));
               //  printf("%d\n",(newNode->price)[ElementsCount]);



                 weight =0;
                 sum =0;

                 (newNode->Elements)[ElementsCount] =  (char*) calloc(i+1 , sizeof(char)); ///allocating space for the name of element
                 if ((newNode->Elements)[ElementsCount] ==NULL)
                 {
                     printf("\n\nERRRRRORRRR NULL POINTER, LOW HEAP!");
                 }

                 strcpy ((newNode->Elements)[ElementsCount],array );
                 printf("\n%s",((newNode->Elements)[ElementsCount]));
                 printf("\nThe price is %d\n",(newNode->price)[ElementsCount] );
                 ElementsCount++;
                  // (newNode->price)++;
                 newNode->NoOfElements =  ElementsCount;
                 printf("no of elemnts in category = %d\n",newNode->NoOfElements );

               }
               else
               {
                    //printf("error");
               }

		         flag =0;
		         i =0;




		   }

              if (ch == '%') ///new category will be born (node)
                {

                    newNode = addNode();
                    (newNode->price) =  (char*) calloc(6,sizeof(char));


                    flag = 1;
                    ElementsCount=0; ///indication for number of elements
                    charcs =0;       ///indication for number of characters of the string


                }

                if (ch == ','||((ch>='0')&&(ch<='9'))) ///case of converting the price from type character to real number
                {
                    flag = 2;
                }



                switch (flag)
                {
                    case 0:
                           if((ch=='\n'))
                           {

                           }
                           else
                            {
                       array [i] = ch;
                       i++;

                             }

                    break;

                    case 1:
                        if (ch == '%')
                        {

                        }
                        else

                            {
                            array[charcs] = ch;
                            charcs++;

                            }


                        break;

                    case 2:

                              if (ch == ',')
                              {

                              }
                              else
                              {
                                  if (weight ==0)
                                  {
                                  sum = ch -'0';
                                  }
                                  else
                                  {
                                      sum = sum*10;
                                      sum = sum + (ch-'0');

                                  }

                                  weight ++;

                              }
                            flag=0;





                         break;

                    default : printf("ERROR");



                }


		   }



       fclose(fp);
      // while(1);

    }


 node* addNode (void)
{


    newNode = (node*)malloc(sizeof(node)) ;
    newNode->next = NULL;
    node*Temp;


     Temp = head;


    if (Temp==NULL) ///first NODE
    {

       head = newNode;
      // printf("first node\n");


    }
    else if ((Temp ->next) == NULL) ///second node
    {

    head-> next = newNode;


    }
    else ///appending new nodes
    {


        while (Temp->next != NULL)
    {
        Temp = Temp->next;

    }
    (Temp->next) = newNode;

    }


   return newNode;

}
void OrderReading (void)
{
     // char *order [6];

      char *arr =  (char*) calloc(10 , sizeof(char)); ///used to get all arrays in ,then  may be freed
      char ch;
      char i=0;
      fp = fopen("order.txt", "r"); // read mode
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }

       //printf("\nThe contents of %s file are:\n", file_name);
      while((ch = (fgetc(fp))) != EOF)
	   {


                            if((ch=='\n'))
                           {

                           }
                           else
                            {
                       arr [i] = ch;
                       i++;

                             }

                           if((ch=='\n'))
                           {
                               arr[i] = '\0';

                 order[ordercount] =  (char*) calloc(i+1 , sizeof(char));
                 if (order[ordercount]  ==NULL)
                 {
                     printf("\n\nERRRRRORRRR NULL POINTER, LOW HEAP!");
                 }

                 strcpy (order[ordercount],arr );
                // printf("\n%s",(order[ordercount]));
                 ordercount++;
                 i=0;
                           }






       }
//printf ("%d",ordercount);
       fclose(fp);

}

    void  Search (void)
    {
    node *Temp;
    Temp =head ;
   // ( (Temp->counter)[0] )=0;
    char i =0;
    char j=0;
    char available =0; ///to check whether the element is available in database or not
    char m;
    FILE *file_pointer;



file_pointer = fopen("receipt.txt","w+");

//fprintf(file_pointer,"%s %s %s %s %s %s \n","The","ID","of","Process","terminated","is");

    if (Temp == NULL)
    {
        return NULL;
    }
     while ( Temp != NULL ) ///loops the whole categories searching of  elements  in order exists in store or not
     {
         for (j=0;j<(Temp->NoOfElements) ; j++) ///j maps for elements index inside each category
         {
             (Temp->counter)[j] =0;
         }
         Temp = ( Temp->next);
     }
//printf("%d",ordercount);
      for (i=0;i<ordercount;i++) ///i maps for order index
         {
             Temp =head ;
             available=0;


     while ( Temp != NULL ) ///loops the whole categories searching of  elements  in order exists in store or not
     {
         for (j=0;j<(Temp->NoOfElements) ; j++) ///j maps for elements index inside each category
         {
         if( !(strcmpi ( order[i],(Temp->Elements)[j] )) )  ///strcmp returns zero if both strings are the same
         {

            ( (Temp->counter)[j] )++;
             //printf("\n%s is available\n",(Temp->Elements)[j]);
             //printf("%d\n",( (Temp->counter)[j]));
             //printf("%d\n",( (Temp->price)[j]));

             Temp->flagOrder = 1; ///indication that this category contains an ordered element
             available =1;

         }
         }

     Temp = ( Temp->next);




      }

      if (available ==0)
      {
          printf("\nSORRY!,%s is not available at this moment",order[i]);
          fprintf(file_pointer,"SORRY!,%s is not available at this moment",order[i]);
      }
         }
         Temp =head ;
         printf("\n\n\n\n\n\n");
         printf("\n\nCategory     Element          Number      Cost\n");
         fprintf(file_pointer,"\n\nCategory     Element          Number      Cost\n");
         printf("----------------------------------------------\n");
         fprintf(file_pointer,"----------------------------------------------\n");

     while ( Temp != NULL ) ///loops the whole categories searching of  elements  in order exists in store or not
     {
         if (Temp->flagOrder==1)
         {
             printf("%s",Temp->PtrCat);
             fprintf(file_pointer,"%s",Temp->PtrCat);

             for (j=0;j<(Temp->NoOfElements) ; j++) ///j maps for elements index inside each category
         {
         if( ((Temp->counter)[j]) >0 )
         {
             if (j>0)
             {
                 for(m=0;m<strlen (Temp->PtrCat );m++) ///THOSE FOR LOOPS ARE USED FOR PRINTING ALLIGNMENT
                 {
                 printf(" ");
                 fprintf(file_pointer," ");
                 }
             }
                for (m=0;m<=(13-strlen (Temp->PtrCat ));m++)  ///where 13,17 are the needed space
                {
             printf(" ");
             fprintf(file_pointer," ");
                }
            printf("%s",(Temp->Elements)[j]);
            fprintf(file_pointer,"%s",(Temp->Elements)[j]);
            for(m=0;m<=(17-strlen( (Temp->Elements)[j]));m++)
            {
                printf(" ");
                fprintf(file_pointer," ");
            }
           printf("%d",(Temp->counter)[j]);
           fprintf(file_pointer,"%d",(Temp->counter)[j]);
           printf("           %d",( (Temp->counter)[j] ) *(Temp->price)[j] );
           fprintf(file_pointer,"           %d",( (Temp->counter)[j] ) *(Temp->price)[j]);
           TotalPrice = TotalPrice+ ( (Temp->counter)[j] ) *(Temp->price)[j];
           printf("\n");
           fprintf(file_pointer,"\n");

         }
         }
         printf("----------------------------------------------\n");
         fprintf(file_pointer,"----------------------------------------------\n");
         }


     Temp = ( Temp->next);




      }
printf("\nTotal price = %d",TotalPrice);
fprintf(file_pointer,"\nTotal price = %d",TotalPrice);
fclose(file_pointer);

    }

void display(void)
{
    node *temp;
    temp=head;
    char i=0;
    printf("\n");
    while(temp!=NULL)
    {
    printf("\n%s\n",temp->PtrCat);
    temp=temp->next;
    }
}

