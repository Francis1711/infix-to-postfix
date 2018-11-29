#include<iostream>
#include<string.h>
using namespace std;
	void accept(char *,char *);
	void display(char *);
	void convert(char *);
	int push(char *arrstring,int top,char ch);
	char pop(char *arrstring,int top);
	char display_top(char *arrstring,int top);
	void display(char *arrstring,int top);
	int isfull(int top,int arrsize);
	int isempty(int top);


int main()
{

	int c,arrsize=20;
	char arrstring[arrsize],copyarrstring[arrsize];
	do
	{
		cout<<"\n\n\n enter your choice \n 1.Accept expression \n 2.Display infix expresion \n 3.Display postfix expression \n 4.convert infix to postfix. \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
				accept(arrstring,copyarrstring);
				break;
				}
			case 2:{
			    cout<<"\n The infix expression is:";
				display(arrstring);
				break;
				}
			case 3:{
			    if(strcmp(arrstring,copyarrstring)==0)
                {
                    cout<<"\n not coverted to postfix!!! \n Select option 4 to convert...";
                }
                else
                {
                    cout<<"\n The postfix expression is:";
                    display(copyarrstring);
                }
				break;
				}
            case 4:{
				convert(copyarrstring);
				break;
				}

			 default:{
					cout<<"\n wrong input entered!!!";
					break;
				      }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<5 && c>0);
	return 0;
}

	void accept(char *arrstring,char *copyarrstring)
	{
		cout<<"\n Enter the infix expression:";
        cin>>arrstring;
        strcpy(copyarrstring,arrstring);
        cout<<"\n The infix expression is:";
        display(arrstring);
	}

	void display(char *arrstring)
		{
			cout<<arrstring;
		}

void convert(char *copyarrstring){
    char symbolstack[20],outputstack[20];
    int i=0,topsymbolstack=-1,topoutputstack=-1;
    while(copyarrstring[i]!='\0')
    {
       if((int)copyarrstring[i]==')'||(int)copyarrstring[i]==']'||(int)copyarrstring[i]=='}')
        {
                 if(isempty(topsymbolstack)==1&&i==0)
                {
                    cout<<"\n error!!! Wrong input";
                    break;
                }else
                {
                   if((int)copyarrstring[i]==')')
                    {
                        char popped;
                        while((int)symbolstack[topsymbolstack]!=(int)copyarrstring[i]-1)
                        {

                            popped=pop(symbolstack,topsymbolstack);
                            topsymbolstack--;
                            topoutputstack=push(outputstack,topoutputstack,popped);
                            outputstack[topoutputstack+1]='\0';
                        }
                        popped=pop(symbolstack,topsymbolstack);
                        topsymbolstack--;
                    }
                    else
                    {
                        if((int)copyarrstring[i]==']'||(int)copyarrstring[i]=='}')
                        {
                            char popped;
                             while((int)symbolstack[topsymbolstack]!=(int)copyarrstring[i]-2)
                            {

                                popped=pop(symbolstack,topsymbolstack);
                                topsymbolstack--;
                                topoutputstack=push(outputstack,topoutputstack,popped);
                                outputstack[topoutputstack+1]='\0';
                                }
                                popped=pop(symbolstack,topsymbolstack);
                                topsymbolstack--;
                            }
                      }
                    }
                    i++;
        }
        else
        {
            if((int)copyarrstring[i]>64&&(int)copyarrstring[i]<91||(int)copyarrstring[i]>96&&(int)copyarrstring[i]<123)
        {
            topoutputstack=push(outputstack,topoutputstack,copyarrstring[i++]);
            outputstack[topoutputstack+1]='\0';


        }else
        {
            topsymbolstack=push(symbolstack,topsymbolstack,copyarrstring[i++]);
            symbolstack[topsymbolstack+1]='\0';
        }
        }

    }

strcpy(copyarrstring,outputstack);
}








    int push(char *arrstring,int top,char ch)//pass the address of the string array,top index of the stack
	{
        arrstring[++top]=ch;
        return top;
	}


    char pop(char *arrstring,int top)//pass the address of the string array,top index of the stack
{
    return arrstring[top--];
}


 char display_top(char *arrstring,int top)//pass the address of the string array,top index of the stack
 {
        return arrstring[top];
}


void display(char *arrstring,int top)//pass the address of the string array,top index of the stack
{
        if(top==-1){
            cout<<"\n stack is empty";
        }else
        {
            cout<<"\n top "<<"\n  :\n";
            for(int i=top;i>=0;i--)
            {
                cout<<"| "<<arrstring[i]<<" |"<<"\n";
            }
        }
}



int isfull(int top,int arrsize){
    if((top+1)==arrsize)//top+1 as top array starts from 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(int top){
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


