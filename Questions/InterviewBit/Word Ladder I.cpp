/*
Problem : Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:
Constraints :
1.You must change exactly one character in every transformation.
2.Each intermediate word must exist in the dictionary.
3.Return 0 if there is no such transformation sequence.
4.All words have the same length.
5.All words contain only lowercase alphabetic characters.

https://www.interviewbit.com/problems/word-ladder-i/
*/

/*
Approach : 
Goal : Convert A(beginWord) to B(endWord) in minimum number of steps.

HOW THIS IS A GRAPH PROBLEM?
Assume each word as a node and each transformation as an edge. Now the goal becomes : 
Goal : Find the shortest path between  A(beginWord) and B(endWord) such that all edges have same weight(let's assume that weight to be 1).

CAN WE USE DFS/BFS?
Dfs is not used to find the shortest path in undirected-graphs but only in trees because in trees we have unique paths between nodes in Tree but we can have exponential number of unique path between 2 nodes in a graph.
Hence DFS will run in exponential time whereas BFS will run in polynomial time. Hence, BFS is always used to find the shortest distance in graph.

Reference : https://www.youtube.com/watch?v=ZVJ3asMoZ18
*/

//Solution:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  
        unordered_set<string> myset;
        bool isPresent = false; //Checks if endWord is present in Dict
        //Insert all words from Dict in myset
        for(auto word: wordList)
        {
            if(endWord.compare(word)==0)
                isPresent = true;
            myset.insert(word);    //Insert word in Dict
        }
        if(isPresent==false)    //endWord is not present in Dict
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth+=1;
            int lsize = q.size();   //No of elements at a level
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth words
                for(int i=0;i<curr.length();++i)  //For each index
                {
                    string temp = curr;
                    for(char c='a';c<='z';++c)  //Try all possible chars
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;   //Skip the same word
                        if(temp.compare(endWord)==0)
                            return depth+1; //endWord found
                        if(myset.find(temp)!=myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                    //revert back the change
                    temp[i]=cuur[i];
                }
            }
        }
        return 0;
    }