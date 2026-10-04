class Solution {
public:
    string defangIPaddr(string address) {
        
        //ans string to store the output in defanged version
        string s;

        //traverse in adress and         
        for(int i = 0; i < address.length(); i++){
            
            //check if '.' found then covert it
            //'.' = [.]
            if(address[i] == '.'){
                s += "[.]";
            }
            else{
                s.push_back(address[i]);
            }
        }

        //finally return the output
        return s;
    }
};