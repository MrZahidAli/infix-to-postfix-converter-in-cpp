#include<iostream>
#include<string.h>
using namespace std;
class node{
	public:
		node *next;
		char data;
};
class stack{
	public:
		node *head, *tail;
	public:
		stack(){
			head = NULL;
			tail = NULL;
		}
		void push(char value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
		}
		char pop(){
			node *current, *previous;
			char poped;
			current = head;
			previous = head;
			if(head == NULL){
				return 'z';
			}
			else if(head->next==NULL)
			{
				poped=head->data;
				head=NULL;
			}
			else
			{
				while(current->next!=NULL)
				{
					previous=current;
					current=current->next;
				}
				poped=current->data;
				previous->next=current->next;
			}
			return poped;
		}
		
		char top(){
			node *current, *previous;
			current = head;
			previous = head;
			while(current -> next != NULL){
				previous = current;
				current = current -> next;
			}
			char poped = current -> data;	
			return poped;
		}
};
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
	stack P;
	int j = 0;
	string infix;
	char operand[50];
	cout << "Enter infix Expression: " << endl;
	cin >> infix;
	int length = infix.length();
	for(int i = 0; i < length; i++){
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
        	operand[j] = infix[i];
        	j++;
		}
		else{
			if(P.head == NULL){
				P.push(infix[i]);
			}
			else{
				if(infix[i] != '(' && infix[i] != ')'){
					if(preseidence(infix[i]) <= preseidence(P.top())){
						operand[j++] = P.pop();
						P.push(infix[i]);
					}
					else{
						P.push(infix[i]);
					}
				}
				else{
					if(infix[i] == '('){
						P.push(infix[i]);
					}
					if(infix[i] == ')'){
						char temp = P.pop();
						while(temp != '('){
							operand[j++] = temp;
							temp = P.pop();
						}
					}
				}
			}
		}
	}
	char temp = P.pop();
	while(temp != 'z'){
		operand[j++] = temp;
		temp = P.pop();

	}
	for(int i=0; i<infix.length(); i++){
		cout << operand[i]; 
	}

}
int main(){
	postfix();
	return 0;
}
