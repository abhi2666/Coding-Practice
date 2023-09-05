/*
Given A and B you have to find all stepping numbers in the range A to B (both inclusive).

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

For e.g. 123 is a stepping number, but 358 is not a stepping number
*/

// vector<int> Solution::stepnum(int A, int B) {
//     vector<int>res;
//     vector<int>values;
//     for(int i = A; i <= B; i++)
//     {
//         int temp = i, prev = 0;
//         values.clear();
//         while(temp > 0)
//         {
//             int dig = temp%10;
//             values.push_back(dig);
//             temp /= 10;
//         }
//         bool flag = true;
//         for(int i = 0; i < values.size()-1; i++)
//         {
//             if(abs(values[i] - values[i + 1]) != 1) flag = false; 
//         }

//         if(flag) res.push_back(i);

//     }
//     return res;
// }


vector<int> Solution::stepnum(int A, int B) {
    vector<int>res;
    
}