#include<stdio.h> 
#include<string.h>
void main() {
	char v,w,ch,string[100],arr[4][7],key[10],a,b,enc[100];
	int temp,i,j,k,l,a1,a2,b1,b2;
	int count = 0;
	int t = 0;
	FILE * fp;
	fp=fopen("sk.txt","r");
	//keep message in sk.txt (e.g. jamia)
	//clrscr();
	printf("Enter the key\n");
	fflush(stdin);
	scanf("%s",key);
	l=0;
	while(1) {
		ch=fgetc(fp);
		if(ch!=EOF) {
			string[l++]=ch;
		}
		if(ch==EOF) 
		    break;
	}
	string[l]='\0';
	puts(string);
	/*for (i=0;key[i]!='\0';i++) {
		for (j=i+1;key[j]!='\0';j++) {
			if(key[i]==key[j]) {
				temp=1;
				break;
			}
		}
	}*/
	if(temp==1) 
	printf("invalid key"); else {
		k=0;
		a='a';
		//printf("%c",b); 
		for (i=0;i<7;i++) {
			for (j=0;j<4;j++) {
				if(k<strlen(key)) 
				    arr[i][j]=key[k]; else if(k==strlen(key)) {
					b: 
					    for (l=0;l<strlen(key);l++) {
						if(key[l]==a) {
							a++;
							goto b;
						}
					}
					arr[i][j]=a;
					a++;
				}
				if(k<strlen(key)) 
				    k++;
			if(i == 6 && j == 2)
			 arr[i][j] = '*';
			if(i == 6 && j == 3)
			 arr[i][j] = '#';
			}
		}
		printf("\n");
		printf("The matrix is\n");
		for (i=0;i<7;i++) {
			for (j=0;j<4;j++) {
				printf("%c\t",arr[i][j]);
			}
			printf("\n");
		}
		
           }
        for (i = 0; i<strlen(string); i++)//Elimination of spaces from the text 
         if (string[i] != ' ')
            string[count++] = string[i];
        string[count] = '\0';
       
       /*for(i=0;i<=strlen(string);i++)
        if(string[i] == '\0')
         printf("%d  ",i);*/
         
       for(i=0;i<strlen(string);i+=2)
        { 
        for(j=0;j<7;j++)
         {
          for(k=0;k<4;k++)
           {
            if(string[i] == arr[j][k])
             {
              a1 = j;
              b1 = k;
             }
            if(string[i+1] == '\n')
             string[i+1] = '#';
            if(string[i+1] == arr[j][k])
             {
              a2 = j;
              b2 = k;
             }
            }
           }
          if(a1 == a2)
           {
            enc[t++] = arr[a1][(b1+1)%4];
            enc[t++] = arr[a1][(b2+1)%4];
           }
          else if(b1 == b2)
           {
            enc[t++] = arr[(a1+1)%7][b1];
            enc[t++] = arr[(a2+1)%7][b1];
           }
          else
           {
           enc[t++] = arr[a1][b2];
           enc[t++] = arr[a2][b1];
           }
         }
        printf("The encrypted text is \n");
        for(i=0;i<t;i++)
         printf("%c ",enc[i]);
         printf("\n");  
        
        }


