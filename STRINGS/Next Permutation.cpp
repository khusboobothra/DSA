//Problem :

//Reference : https://www.youtube.com/watch?v=LuLCLgMElus

//Code :
 vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i,j;
    for(i=arr.size()-1;i>0;i--)
    {
        if(arr[i]>arr[i-1])
            break;
    }
    if(i==0)
    {
        sort(arr.begin(),arr.end());
        return arr;
    }
    int ind1=i-1;
    int ind2;
    for(int j=arr.size()-1;j>ind1;j--)
    {
        if(arr[j]>arr[ind1])
        {
            ind2=j;
            break;
        }
    }
    swap(arr[ind1],arr[ind2]);
    sort(arr.begin()+i,arr.end());
    return arr;
    }