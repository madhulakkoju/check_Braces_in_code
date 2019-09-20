// CHECK BRACES IN THE CODE

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int length=0;
struct node
{
  int val;
  struct node *prev;
};
struct node *head;
struct node *temp;
void push(char value)
{
  temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    return;
  }
  else
  {
    if(head != NULL)
    {
      temp->prev = head;
      temp->val = value;
      head = temp;
    }
    else
    {
      head = temp;
      head->val = value;
      head->prev =NULL;
    }
  }
}

char pop()
{
	char valu;
	if(head==NULL)
	{
		printf("EMPTY STACK\n");
		return -1;
	}
	temp=head;
	head=head-> prev;
	valu=temp-> val;
	free(temp);
	return valu;
}

char peek()
{
	char valu;
	if(head==NULL)
	{
		return -1;
	}
	valu=head-> val;
	return valu;
}

char* scan(char *string)
{
    int c; //as getchar() returns `int`
    string = malloc(sizeof(char)); //allocating memory

    string[0]='\0';

    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char)); 
        string[i] = (char) c; 
        string[i+1] = '\0'; 
    }
    return string;
}

int main()
{
  char ch;
    long long int i =0;
    char *arr; 
    while( strcmp((arr=scan(arr)),"\n") ) 
    {
        while(arr[i]!='\0')
  {
    if(arr[i]=='{'||arr[i]=='['||arr[i]=='(')
    {
      push(arr[i]);
    }
    else if(arr[i]=='}'||arr[i]==']'||arr[i]==')')
    {
      if(peek()=='{' && arr[i]=='}')
      {
        ch = pop();
        if(ch==-1)
        {
          printf("%d",i+1);
          exit(0);
        }
      }
      else if(peek()=='[' && arr[i]==']')
      {
        ch = pop();
        if(ch==-1)
        {
          printf("%d",i+1);
          exit(0);
        }
      }
      else  if(peek()=='(' && arr[i]==')')
      {
        ch = pop();
        if(ch==-1)
        {
          printf("%d",i+1);
          exit(0);
        }
      }
      else
      {
         printf("%d",i+1); 
         exit(0);
      }
    }
    i++;
  }
  if(peek() != -1)
  {
    printf("%d",i+1);
  }
  else
  {
    printf("SUCCESS");
  }
break;
    }


  return 0;
}

/*
OUTPUT

((){{}}[][]][])()
12


((((((((())))))))))
19

(())
SUCCESS




*/
