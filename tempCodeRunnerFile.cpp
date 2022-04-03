    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->next[word[i]-'a']==NULL){
                curr->next[word[i]-'a']=new Node;
            } 
            curr=curr->next[word[i]-'a']; //go to next character
        }
        curr->word=word; //we add that word to last ele no checking 
    }