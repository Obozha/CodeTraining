#include<iostream>
using namespace std;

class Bed{
	public:
		Bed():weight(0){
		}
		
		void Sleep(){
			cout<<"Sleeping..."<<endl;	
		}
	
		void SetWeight(int i){
			weight=i;
		}
	protected:
		int weight;
};

class Sofa{
	public:
		Sofa():weight(0){
		}
		
		void WatchTV(){
			cout<<"Watching TV"<<endl;
		}
		
		void SetWeight(int i){
			weight=i;
		}
	protected:
		int weight; 
};

class SleeperSofa:public Bed,public Sofa{
	public:
		SleeperSofa(){
		}
		void FoldOut(){ // ÕÛµþÓë´ò¿ª 
			cout<<"Fold out the sofa."<<endl;
		}
};

int main(){
	SleeperSofa ss;
	ss.WatchTV();
	ss.FoldOut();
	ss.Sofa::SetWeight(5);
}
