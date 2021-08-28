

/*
APPROACH :
1. Apply BFS and find the shortest distance from beginWord(A) to endWord(B).Let the shortest distance be X.
2. Apply DFS from beginWord(A) of depth exactly X.If at depth we find the end word then :
   a)push the current path (A->B)
   else
   b)backtrack and try another path

How to call DFS()?   
Reference : https://www.youtube.com/watch?v=mIZJIuMpI2M

*/