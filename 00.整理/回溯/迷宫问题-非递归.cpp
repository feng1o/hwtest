	//tip:sum不能是引用，，，但是ans， iVec必须是引用，，，，，，，，，
	//如果只是让判定有无这样的路径呢，，如何优化，，，sto 66题，这里是树结构，所以不会存在问题，
    bool deal(TreeNode* root,int sum, int exp, vector<vector<int>>& ans, vector<int>& ivec){
        if(root == nullptr){
            sum = 0;
            return false;
        }
        sum += root->val;
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right) 
			//tip2:此时就是默认到叶节点的路径
			//如果任意路径如何求？
            ans.push_back(ivec);
		//此处说明找到了，如果加return，最终只是找有没有，存在问题，，不加是找所有问题..
        if(root->left){
            deal(root->left, sum, exp, ans, ivec);
        }
        
        /*sum += root->val;  //此处就是中序遍历，这样不是深度优先了
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right)
            ans.push_back(ivec);*/
        
		if(root->right){
            deal(root->right, sum, exp, ans, ivec);
        }
		//5.注意回溯的时候，最后的清除前一步问题
			ivec.pop_back();
        return true;
    }