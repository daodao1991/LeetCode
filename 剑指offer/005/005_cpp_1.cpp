#include<stack>
#include<iostream>
#include<stdlib.h>

/*****************思路分析****************
 
最终实现队列的主要特点就是，先进先出FIFO

入队：将元素压入栈1
出队：判断栈2是否为空，若为空，则将栈1中的所有元素出栈，压入栈2中，
	  栈2出栈；若不为空，则栈2直接出栈
	  (按照栈1中元素出栈，再压入栈2中的顺序可知，先压入栈1中的元素可实现先行出栈，
	  即实现了队列的FIFO)
*******************************************/

using namespace std;

class Solution {
public:
	//入栈
	void push(int node){
		stack1.push(node);
	}

	//出栈
	int pop(){
		int temp;
		//若栈2为空，则将栈1中的所有元素都压入栈2中
		if(stack2.empty()){
			while(!stack1.empty())
			{		
				temp = stack1.top();
				stack2.push(temp);
				stack1.pop();
			}
		}
		//若栈2不为空，则直接出栈
		temp = stack2.top();
		stack2.pop();
		return temp;
	}



private:
	stack<int> stack1;
	stack<int> stack2;
}
