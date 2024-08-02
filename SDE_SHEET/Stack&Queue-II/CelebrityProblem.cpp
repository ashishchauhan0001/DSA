int celebrity(vector<vector<int> >& mat) {
        // code here 
        int top=0;
        int down=mat.size()-1;
        while(top<down){
            if(mat[top][down]==1) top++; // skip the row bcz top knows down
            else if(mat[down][top]==1) down--; // skip the row bcz down knows top so cant be a celeb.
            else{
                top++;
                down--;
            }
            
        }
        
        if(top>down) return -1;
        
        for(int i=0;i<mat.size();i++){
            if(i==top) continue; // skip checking itself
            if(mat[top][i]==0 && mat[i][top]==1) continue;
            else return -1;
        }
        
        return top;
    }