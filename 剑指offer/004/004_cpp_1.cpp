#include<iostream>
#include<vector>
#include<stdlib.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL),
 *     right(NULL) {}
 * };
 */

class Solution{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in){
		int inlength = in.size();
		if(inlength == 0)
			return NULL;
		vector<int> left_pre, right_pre, left_in, right_in;
		//创建根节点，根节点肯定是前序遍历的第一个数
		TreeNode* root = new TreeNode(pre[0]);

		//找到中序遍历根节点所在位置,存放于变量index_root中
		int index_root = 0;
		for(int i = 0; i < inlength; i++){
			if(in[i] == pre[0]){
				index_root = i;
				break;
			}
		}
	
		//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
		//利用上述这点，对二叉树节点进行归并
		for(int i = 0; i < index_root; i++){
			//不论前序遍历还是中序遍历，根结点的左子树和右子树上的结点个数是一样的
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i+1]);
		}
		for(int i = index_root + 1; i < inlength; i++){
			right_in.push_back(in[i]);
			right_pre.push_back(pre[i]);
		}
	

		//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
		//递归，再对其进行上述所有步骤，即再区分子树的左、右子子树，直到叶节点
		head->left = reConstructBinaryTree(left_pre, left_in);
		head->right = reConstructBinaryTree(right_pre, right_in);
		
		return head;
	}
};
