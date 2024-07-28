/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int tpetrol=0,tdist=0;
        for(int i=0;i<n;i++){
            tpetrol+=p[i].petrol;
            tdist+=p[i].distance;
        }
        if(tpetrol<tdist) return -1;
        int s=0,t=0;
        for(int i=0;i<n;i++){
            t+=p[i].petrol-p[i].distance;
            if(t<0){
                t=0;
                s=i+1;
            }
        }
        return s;
    }
};