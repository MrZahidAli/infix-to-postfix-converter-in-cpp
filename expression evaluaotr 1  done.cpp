//infix to postfix converter
#include<iostream>
#include<string.h>
using namespace std;
#define size 50
class node
	 {
	 public:
		int data;
		node*next;
};
class stack{
	public:
		node*head;
		node*tail;
	public:
		stack(){	
			head=NULL;
			tail=NULL;
		}
    	void push(char n);
    	char pop ();
    	char top ();	
};
void stack::push(char n){
   	node* tptr;
	tptr = head;

	node* nptr = new node();
	nptr->data = n;
	tail=nptr;
	tail->next =NULL ;

	if (head == NULL)
	{
		head = nptr;
		tail = nptr;
		tail->next=NULL;
	}
	
	else {
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			
    	}
      tptr->next=nptr;
	}
}
char stack::pop(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			head = head -> next;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
			previous -> next = current -> next;
	    	return n ;
		}
		
	}
}
char stack::top(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
	    	return n ;
		}
		
	}
}

int preseidence(char opera){
	if(opera == '(' || opera == ')'){
		return 0;
	}
	if(opera == '+' || opera == '-'){
		return 1;
	}
	if(opera == '*' || opera == '/'){
		return 2;
	}
	if(opera == '^'){
		return 3;
	}
	return 0;
}
int postfix(){
	int c = 0;
	int b = 0;
	stack P;
	char temp;
	int j = 0;
	char infix[size];
	char operand[size];
	cout << "Enter infix Expression: " << endl;
	cin >> infix;
	int length = strlen(infix);
	for(int i = 0; i < length; i++){
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
        	operand[j] = infix[i];
        	j++;
		}
		else{
			if(P.head == NULL){
				P.push(infix[i]);
				c++;
			}
			else{
				if(infix[i] != '(' && infix[i] != ')'){
					if(preseidence(infix[i]) <= preseidence(P.top())){
						temp = P.pop();
						c--;
						operand[j++] = temp;
						P.push(infix[i]);
						c++;
					}
					else{
						P.push(infix[i]);
						c++;
					}
				}
				else{
					if(infix[i] == '('){
						P.push(infix[i]);
						c++;
						b++;
					}
					if(infix[i] == ')'){
						temp = P.pop();
						c--;
						b++;
						while(temp != '('){
							operand[j++] = temp;
							temp = P.pop();
							c--;
						}
					}
				}
			}
		}
	}
	int n = 0;
	while(n<c){
		operand[j++] = P.pop();
		n++;
	}
	string postfixString = "";
	cout << "postfix expression is: ";
	for(int i=0; i < length - b; i++){
		cout << operand[i];
		postfixString = postfixString + operand[i];
	}

}
int main(){
	postfix();
	return 0;
}
