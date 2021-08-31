//Problem :

//Code :
bool ispar(string x)
{
    stack<char>st;
    char c;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
        {
            st.push(x[i]);
            continue;
        }
        if(st.empty())
        return false;

        switch (x[i]){
            case ')':
                      c=st.top();
                      st.pop();
                      if(c=='[' || c=='{')
                      return false;
                      break;

            case ']':
                      c=st.top();
                      st.pop();
                      if(c=='(' || c=='{')
                      return false;
                      break;

            case '}':
                      c=st.top();
                      st.pop();
                      if(c=='[' || c=='(')
                      return false;
                      break;
        }
    }
        return st.empty();
}