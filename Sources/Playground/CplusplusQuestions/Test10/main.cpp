#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
	int info;
	node *link;
};

class lstack
{
	node *top;
public:
	lstack() {top=0;}
	void push();
	int pop();
	int isempty(){
		if(top==0)
			return(1);
		else
			return(0);
	}
	void display();
};
void lstack ::push()
{
	node *newnode;
	newnode=new node;
	int item;
	cout<<"\nEnter item\t";
	cin>>item;
	newnode->info=item;
	newnode->link=top;
	top=newnode;
}
int lstack ::pop()
{
	node *del_node;
	int temp;
	del_node=top;
	top=top->link;
	temp=del_node->info;
	delete del_node;
	return(temp);
}
void lstack ::display()
{
	node *ptr=top;
	while(ptr != 0)
	{
		cout<<endl<<ptr->info;
		ptr=ptr->link;
	}
}

int main()
{
	int exit=0;
	class lstack st;
	char ch;
	system("CLS");
	while(!exit){
		cout<<"\na: PUSH\nb: POP\nc: View Stack\nd: Exit\n";
		ch=getch();
		system("CLS");
		switch(ch)
		{
			default:
				cout<<"\ninvalid option";
				break;
			case 'a':
				st.push();
				break;
			case 'b':
				if(st.isempty())
					cout<<"\nUnderflow\n";
				else
					cout<<"\nitem="<<st.pop();
				break;
			case 'c':
				st.display();
				break;
			case 'd':
				exit=1;
		}
	}
	getch();
	return 0;
}
