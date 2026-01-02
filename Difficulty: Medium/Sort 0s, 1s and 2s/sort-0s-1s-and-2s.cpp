class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        // //2N T.C.
        // int zero=0, one=0, two=0;
        
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==0){
        //         zero++;
        //     } else if(arr[i]==1){
        //         one++;
        //     } else{
        //         two++;
        //     }
        // }
        
        // for(int i=0;i<arr.size();i++){
        //     if(zero){
        //         arr[i]=0;
        //         zero--;
        //     } else if(one){
        //         arr[i]=1;
        //         one--;
        //     } else{
        //         arr[i]=2;
        //     }
        // }
        
        
        int n=arr.size();
        
        int start=0;
        int curr=0;
        int end=n-1;
        
        while(curr<=end){
            if(arr[curr]==0){
                swap(arr[start],arr[curr]);
                start++;
                curr++;
            } else if(arr[curr]==1){
                curr++;
            } else{
                swap(arr[curr],arr[end]);
                end--;
            }
        }
    }
};