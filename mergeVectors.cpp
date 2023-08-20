void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0;
    vector<int>temp;
    while(i < A.size() && j < B.size())
    {
        if(A[i] < B[j])
        {
            temp.push_back(A[i]);
            i++;
        }
        else if(A[i] > B[j])
        {
            temp.push_back(B[i]);
            j++;
        }
        else{
            temp.push_back(A[i]);
            temp.push_back(B[j]);
            i++;
            j++;
        }
    }
    for(int i = 0; i < temp.size(); i++)
    {
        A[i] = temp[i];
    }
}
